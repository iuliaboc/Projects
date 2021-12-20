<%--
  Created by IntelliJ IDEA.
  User: PC
  Date: 11/12/2020
  Time: 2:41 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<body>
<jsp:include page="template/header.jsp"/>
<div class="container">
    <form method="post" action="/home">
        <h1> Home Page </h1>
        <div class="form-group">
            <label for="inputUsername">Username</label>
            <input name="username" type="text" class="form-control" id="inputUsername"
                   <% String username = (String) request.getAttribute("username"); %>
                   value="<% out.print(username);%>" readonly>
        </div>
        <div class="form-group">
            <label for="inputName">Name</label>
            <input name="name" type="text" class="form-control" id="inputName"
                <% String name = (String) request.getAttribute("name"); %>
                   value="<% out.print(name);%>">
        </div>
        <div class="form-group">
            <label for="inputAddress">Addresss</label>
            <input name="address" type="text" class="form-control" id="inputAddress"
                <% String address = (String) request.getAttribute("address"); %>
                   value="<% out.print(address);%>">
        </div>
        <div class="form-group">
            <label for="inputBirthdate">Birthdate</label>
            <input name="birthdate" type="date" class="form-control" id="inputBirthdate"
                <% String date = (String) request.getAttribute("birthdate"); %>
                <% String today = (String) request.getAttribute("today"); %>
                   value="<% out.print(date);%>" min="1910-01-01" max="<% out.print(today);%>">
        </div>

        <a href="login.jsp">
            <button type="button" class="btn btn-danger">Exit</button>
        </a>
        <button type="submit" class="btn btn-success">Save changes</button>
    </form>
</div>
</body>

</html>
