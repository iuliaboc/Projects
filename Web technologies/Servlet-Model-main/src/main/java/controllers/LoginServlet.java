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
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;

@WebServlet(name = "LoginServlet", urlPatterns = "/login")
public class LoginServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String reset = request.getParameter("reset");
        String login = request.getParameter("login");

        UserDAO help = new UserDAO();
        response.setContentType("text/html");
        if(reset == null) {
            if (password != null) {
                UsersEntity user = help.getUser(username, password);
                if (user.getUsername() == null) {
                    RequestDispatcher rd = request.getRequestDispatcher("/login.jsp");
                    rd.include(request, response);
                } else {
                    DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy-MM-dd");
                    LocalDateTime now = LocalDateTime.now();
                    String tdy = dtf.format(now);
                    DateFormat targetFormat = new SimpleDateFormat("yyyy-MM-dd");
                    String formattedDate = targetFormat.format(user.getBirthdate());

                    request.setAttribute("username", user.getUsername());
                    request.setAttribute("name", user.getName());
                    request.setAttribute("address", user.getAddress());
                    request.setAttribute("birthdate", formattedDate);
                    request.setAttribute("today", tdy);
                    RequestDispatcher rd = request.getRequestDispatcher("/home.jsp");
                    rd.forward(request, response);
                }
            } else {
                RequestDispatcher rd = request.getRequestDispatcher("/login.jsp");
                rd.include(request, response);
            }
        } else {
            UsersEntity user = help.getUserByName(username);
            if (user.getUsername() != null) {
                request.setAttribute("username", user.getUsername());
                request.setAttribute("alert", "");
                RequestDispatcher rd = request.getRequestDispatcher("/forgotPass.jsp");
                rd.forward(request, response);
            } else {
                RequestDispatcher rd = request.getRequestDispatcher("/login.jsp");
                rd.include(request, response);
            }

        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
