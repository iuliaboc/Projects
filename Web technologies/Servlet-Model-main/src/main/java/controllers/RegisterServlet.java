package controllers;

import dbRunTime.UserDAO;
import dbRunTime.Users;
import model.User;
import model.UsersEntity;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Date;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

@WebServlet(name = "RegisterServlet", urlPatterns = "/register")
public class RegisterServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String name = request.getParameter("name");
        String password = request.getParameter("password");
        String address = request.getParameter("address");
        String birthdate = request.getParameter("birthdate");
        String repeatPassword = request.getParameter("repeatPassword");
        java.sql.Date date = Date.valueOf(birthdate);

        response.setContentType("text/html");
        if(password.equals(repeatPassword)) {
            DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDateTime now = LocalDateTime.now();
            String tdy = dtf.format(now);
            Date today = Date.valueOf(tdy);
            Date input = Date.valueOf(birthdate);

            if(input.before(today)) {
                UserDAO help = new UserDAO();
                UsersEntity user = help.getUserByName(username);
                if (user.getUsername() == null) {
                    help.addUser(username, password, name, date, address);

                    request.setAttribute("username", username);
                    request.setAttribute("name", name);
                    request.setAttribute("address", address);
                    request.setAttribute("birthdate", birthdate);
                    request.setAttribute("today", tdy);
                    RequestDispatcher rd = request.getRequestDispatcher("/home");
                    rd.forward(request, response);
                }
            } else {
                RequestDispatcher rd = request.getRequestDispatcher("/register.jsp");
                rd.include(request, response);
            }
        } else {
            RequestDispatcher rd = request.getRequestDispatcher("/register.jsp");
            rd.include(request, response);
        }

    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
