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
    <h1 class="text-center">Welcome to this site</h1>
    <p class="text-center">To acces this site please login or register.</p>
    <form method="get" action="/login">
        <button type="submit"></button>
    </form>
</div>
</body>
</html>
