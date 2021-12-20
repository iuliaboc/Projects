import java.io.Serializable;

public class City implements Serializable {
    Integer latitudine;
    Integer longitudine;
    String name;
    String weather;

    public City() {
    }

    public City(Integer latitudine, Integer longitudine, String name, String weather) {
        this.latitudine = latitudine;
        this.longitudine = longitudine;
        this.name = name;
        this.weather = weather;
    }

    public void print() {
        System.out.println("Latitudine: "+ this.latitudine );
        System.out.println("Longitudine: "+ this.longitudine );
        System.out.println("Nume oras: "+ this.name );
        System.out.println("Prognoza meteo: "+ this.weather );

    }

    public Integer getLatitudine() {
        return latitudine;
    }

    public void setLatitudine(Integer latitudine) {
        this.latitudine = latitudine;
    }

    public Integer getLongitudine() {
        return longitudine;
    }

    public void setLongitudine(Integer longitudine) {
        this.longitudine = longitudine;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getWeather() {
        return weather;
    }

    public void setWeather(String weather) {
        this.weather = weather;
    }
}
