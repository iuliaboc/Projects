<%--
  Created by IntelliJ IDEA.
  User: bocir
  Date: 12/5/2021
  Time: 12:23 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<jsp:include page="template/header.jsp"/>
<body>
<div class="container">
    <form method="post" action="/forgotPass">
        <h1> Reset Password </h1>
        <div class="form-group">
            <label for="inputUsername">Username</label>
            <input name="username" type="text" class="form-control" id="inputUsername"
                <% String username = (String) request.getAttribute("username"); %>
                   value="<% out.print(username);%>" readonly>
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
            <input name="alert" type="text" class="form-control" id="inputAlert"
                <% String alert = (String) request.getAttribute("alert"); %>
                   value="<% out.print(alert);%>"
                   style="border-color: #ffffff; background-color: #ffffff; font-size: large; font-style: italic" readonly>
        </div>

        <a href="login.jsp">
            <button type="button" class="btn btn-danger">Exit</button>
        </a>
        <button type="submit" class="btn btn-success">Save changes</button>
    </form>
</div>
</body>
</html>
