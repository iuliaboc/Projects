package model;

import java.util.Date;

public class User {
    private String userName;
    private String name;
    private String password;
    private String address;
    private Date birthDate;

    public User() {
    }

    public User(String userName, String name, String password, String address, Date birthDate) {
        this.userName = userName;
        this.name = name;
        this.password = password;
        this.address = address;
        this.birthDate = birthDate;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public Date getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(Date birthDate) {
        this.birthDate = birthDate;
    }
}
