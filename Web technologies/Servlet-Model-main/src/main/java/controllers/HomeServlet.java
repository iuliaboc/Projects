package controllers;

import dbRunTime.UserDAO;
import model.UsersEntity;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

@WebServlet(name = "HomeServlet", urlPatterns = "/home")
public class HomeServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String name = request.getParameter("name");
        String birthdate = request.getParameter("birthdate");
        String address = request.getParameter("address");
        Date date = Date.valueOf(birthdate);

        UserDAO help = new UserDAO();
        UsersEntity user = help.getUserByName(username);

        if(!user.getName().equals(name) || !user.getAddress().equals(address) || !user.getBirthdate().equals(date)) {
           help.updateUser(username, name, date, address);
        }
        request.setAttribute("username", username);
        request.setAttribute("name", name);
        request.setAttribute("address", address);
        request.setAttribute("birthdate", birthdate);

        RequestDispatcher rd = request.getRequestDispatcher("/home.jsp");
        rd.forward(request, response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.sendRedirect("https://www.google.com");
        System.out.println("I am in Home servlet");
    }
}
