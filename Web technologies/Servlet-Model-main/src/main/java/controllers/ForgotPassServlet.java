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

@WebServlet(name = "ForgotPassServlet", urlPatterns = "/forgotPass")
public class ForgotPassServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String username = request.getParameter("username");
        String password = request.getParameter("password");
        String repeatPassword = request.getParameter("repeatPassword");

        response.setContentType("text/html");

        if (password.equals(repeatPassword)) {
            UserDAO help = new UserDAO();
            UsersEntity user = help.getUserByName(username);
            help.resetPass(username, password);

            DateFormat targetFormat = new SimpleDateFormat("yyyy-MM-dd");
            String formattedDate = targetFormat.format(user.getBirthdate());

            request.setAttribute("username", user.getUsername());
            request.setAttribute("name", user.getName());
            request.setAttribute("address", user.getAddress());
            request.setAttribute("birthdate", formattedDate);
            RequestDispatcher rd = request.getRequestDispatcher("/home.jsp");
            rd.forward(request, response);
        } else {
            request.setAttribute("username", username);
            request.setAttribute("alert", "^The passwords need to match.");
            RequestDispatcher rd = request.getRequestDispatcher("/forgotPass.jsp");
            rd.include(request, response);
        }
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    }
}
