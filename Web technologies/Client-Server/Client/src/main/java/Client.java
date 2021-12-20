import java.io.File;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.nio.file.InvalidPathException;
import java.nio.file.Paths;
import java.util.Scanner;

public class Client {
    public static final int PORT = 6543;

    public void start() throws Exception {

        User user = new User();
        Socket socket = null;
        System.out.println("Welcome! Enter your name: ");
        Scanner scnr = new Scanner(System.in);
        String name = scnr.nextLine();
        boolean corect = false;
        System.out.println("Do you wish to log in as admin?[y/n]");
        String logAsAdmin = null;
        while (!corect) {
            logAsAdmin =  scnr.nextLine();
            switch (logAsAdmin){
                case "y":
                    user.setUserName(name);
                    user.setAdmin(true);
                    corect = true;
                    break;
                case "n":
                    user.setUserName(name);
                    user.setAdmin(false);
                    corect = true;
                    break;
                default:
                    System.out.println("That's not a valid answer.");
            }
        }

        System.out.println("UserName:"+user.getUserName()+','+user.isAdmin());
        //For receiving and sending data
        boolean isClose = false;
        while (!isClose) {
            socket = new Socket("localhost", PORT);

            ObjectOutputStream outputStream = new ObjectOutputStream(socket.getOutputStream());
            ObjectInputStream inputStream = new ObjectInputStream(socket.getInputStream());

            if(user.isAdmin){
                Packet packet = new Packet("y");
                outputStream.writeObject(packet);
                String path = null;
                System.out.println("Introduceti calea catre fisierul JSON: ");
                Scanner scanner = new Scanner(System.in);
                boolean valid = false;
                while(!valid)
                {
                    path = scanner.nextLine();
                    if(isValidPath(path)) {
                        packet = new Packet(path);
                        outputStream.writeObject(packet);
                        valid = true;
                    } else {
                        System.out.println("Aceasta nu este o cale valida. Introduceti calea catre fisierul JSON: ");
                    }
                }
                Packet recivePacket = (Packet) inputStream.readObject();
                System.out.println(recivePacket.message);
            }
            else {
                Packet packet = new Packet("n");
                outputStream.writeObject(packet);
                String latitudine = null;
                String longitudine = null;
                String answer = null;
                System.out.println("Introduceti latitudinea(Integer): ");
                Scanner scanner = new Scanner(System.in);
                boolean ok = false;
                while (!ok) {
                    answer = scanner.nextLine();
                    if (isDouble(answer) && Double.parseDouble(answer) < 90 && Double.parseDouble(answer) > 0) {
                        latitudine = answer;
                        ok = true;
                    } else {
                        System.out.println("This is not a valid Integer. Try again:");
                    }
                }
                ok = false;
                System.out.println("Introduceti longitudinea: ");
                while (!ok) {
                    answer = scanner.nextLine();
                    if (isDouble(answer) && Double.parseDouble(answer) < 180 && Double.parseDouble(answer) > 0) {
                        longitudine = answer;
                        ok = true;
                    } else {
                        System.out.println("This is not a valid Integer. Try again:");
                    }
                }

                packet = new Packet(latitudine+' '+longitudine);
                outputStream.writeObject(packet);
                City reciveCity = (City) inputStream.readObject();
                System.out.println("Cel mai apropiat oras este: ");
                reciveCity.print();
            }

            System.out.println("Doriti sa va delogati[y/n]: ");
            boolean valid = false;
            String logOut = null;
            while(!valid) {
                logOut =  scnr.nextLine();
                switch (logOut){
                    case "y":
                        isClose = true;
                        valid = true;
                        break;
                    case "n":
                        valid = true;
                        break;
                    default:
                        System.out.println("That's not a valid answer.");
                }
            }

        }

        socket.close();
    }

    public static boolean isValidPath(String path) {
        File f = new File(path);
        if (!f.exists()) {
            return false;
        }
        else{
            return true;
        }
    }

    boolean isDouble(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

}
