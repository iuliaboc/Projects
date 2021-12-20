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
    <form method="post" action="/login">
        <h1> Login Page </h1>
        <div class="form-group">
            <label for="inputUsername">Username</label>
            <input name="username" type="text" class="form-control" id="inputUsername"
                   placeholder="Enter username" required>
        </div>
        <div class="form-group">
            <label for="inputPass">Password</label>
            <input name="password" type="password" class="form-control" id="inputPass"
                   placeholder="Password">
        </div>
        <div class="form-group">
            <button name="reset" type="submit" class="btn btn-link">Forgot password?</button>
        </div>
        <button name="login" type="submit" class="btn btn-success">Login</button>
        <a href="register.jsp">
            <button type="button" class="btn btn-primary">Sign Up</button>
        </a>
    </form>
</div>
</body>
</html>
