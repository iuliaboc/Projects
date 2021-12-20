import com.google.gson.Gson;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.nio.file.Files;
import java.nio.file.Paths;

import static java.lang.Math.sqrt;

public class ServerThread extends Thread{
    private Socket socket = null;
    private ObjectInputStream in = null;
    private ObjectOutputStream out = null;
    public static String filePath = "E:\\Cursuri\\Anul 3\\TW\\Client-Server\\Server\\src\\main\\java\\weatherDetails.json";
    City[] cities = null;

    public ServerThread(Socket socket) {
        this.socket = socket;
        try {
            //For receiving and sending data
            this.in = new ObjectInputStream(socket.getInputStream());
            this.out = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void run() {
        try {
            Packet recivePacket = (Packet) this.in.readObject();
            System.out.println("Recived: " + recivePacket.message);
            if(recivePacket.message.equals("y"))
            {
                executeAdmin(recivePacket.message);
            }
            else if (recivePacket.message.equals("n")){
                executeUser(recivePacket.message);
            }


        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void refreshJson() throws IOException {
        Gson gson = new Gson();
        String data = new String(Files.readAllBytes(Paths.get(filePath)));
        cities = gson.fromJson(data, City[].class);
    }

    public City getNearest(String message)
    {
        double minim = 10000;
        City nearest = new City();
        String[] coordonate = message.split(" ");
        Double latitudine = Double.parseDouble(coordonate[0]); // 004
        Double longitudine = Double.parseDouble(coordonate[1]); // 034556
        for (City city : cities) {
            double resultat = sqrt(((city.getLatitudine() - latitudine) * (city.getLatitudine() - latitudine)) + ((city.getLongitudine() - longitudine) * (city.getLongitudine() - longitudine)));
            if (resultat < minim) {
                minim = resultat;
                nearest = city;
            }
        }
        return nearest;
    }

    private void executeUser(String message) throws IOException {
        try {
            Packet recivePacket = (Packet) this.in.readObject();
            System.out.println("Recived: " + recivePacket.message);
            refreshJson();
            City nearest = getNearest(recivePacket.message);
            this.out.writeObject(nearest);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void executeAdmin(String message) {
        try {
            Packet recivePacket = (Packet) this.in.readObject();
            System.out.println("Recived: " + recivePacket.message);
            filePath = recivePacket.message;
            refreshJson();
            Packet packet = new Packet("Incarcarea a avut loc cu succes");
            this.out.writeObject(packet);
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
