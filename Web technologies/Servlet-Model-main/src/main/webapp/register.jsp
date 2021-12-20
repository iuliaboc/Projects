<%--
  Created by IntelliJ IDEA.
  User: PC
  Date: 11/12/2020
  Time: 2:18 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<body>
<jsp:include page="template/header.jsp"/>
<div class="container">
    <form method="post" action="/register">
        <h1> Registration Page </h1>
        <div class="form-group">
            <label for="inputUsername">Username</label>
            <input name="username" type="text" class="form-control" id="inputUsername"
                   placeholder="Enter username" required>
        </div>
        <div class="form-group">
            <label for="inputPass">Password</label>
            <input name="password" type="password" class="form-control" id="inputPass"
                   placeholder="Password" required>
        </div>
        <div class="form-group">
            <label for="repeatInputPass">Repeat Password</label>
            <input name="repeatPassword" type="password" class="form-control" id="repeatInputPass"
                   placeholder="Password" required>
        </div>
        <div class="form-group">
            <label for="inputName">Name</label>
            <input name="name" type="text" class="form-control" id="inputName"
                   placeholder="Enter name" required>
        </div>
        <div class="form-group">
            <label for="inputAddress">Addresss</label>
            <input name="address" type="text" class="form-control" id="inputAddress"
                   placeholder="Address" required>
        </div>
        <div class="form-group">
            <label for="inputBirthdate">Birthdate</label>
            <input name="birthdate" type="date" class="form-control" id="inputBirthdate"
                   min="1910-01-01" required>
        </div>

        <a href="login.jsp">
            <button type="button" class="btn btn-danger">Exit</button>
        </a>
        <button type="submit" class="btn btn-success">Register</button>
    </form>
</div>
</body>
</html>
