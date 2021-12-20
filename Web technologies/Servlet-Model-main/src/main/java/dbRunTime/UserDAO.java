package dbRunTime;

import model.UsersEntity;

import javax.persistence.EntityTransaction;
import javax.persistence.NoResultException;
import javax.persistence.Query;
import java.sql.Date;
import java.util.List;

public class UserDAO {
    DatabaseConnection connection = new DatabaseConnection();

    public UsersEntity get(long id) {
        return connection.getEntityManager().find(UsersEntity.class, id);
    }

    public List<UsersEntity> getAll() {
        return connection.getEntityManager().createQuery("select a FROM UsersEntity a", UsersEntity.class).getResultList();
    }

    public UsersEntity getUser(String username, String password) {
        String query = "SELECT user FROM UsersEntity user where username =?1 and password =?2";
        try {
            return connection.getEntityManager().createQuery(query, UsersEntity.class).setParameter(1, username).setParameter(2, password).getSingleResult();
        } catch(NoResultException nre) {
            return new UsersEntity();
        }
    }

    public UsersEntity getUserByName(String username) {
        String query = "SELECT user FROM UsersEntity user where username =?1";
        try {
            return connection.getEntityManager().createQuery(query, UsersEntity.class).setParameter(1, username).getSingleResult();
        } catch(NoResultException nre) {
            return new UsersEntity();
        }
    }

    public void updateUser(String username, String name, Date birthdate, String address) {
        String query = "UPDATE UsersEntity user SET user.name =?1, user.birthdate =?2, user.address =?3 where username =?4";

        connection.getEntityManager().getTransaction().begin();
        Query q = connection.getEntityManager().createQuery(query)
                .setParameter(1, name)
                .setParameter(2, birthdate)
                .setParameter(3, address)
                .setParameter(4, username);
        q.executeUpdate();
        connection.getEntityManager().getTransaction().commit();
    }


    public void addUser(String username, String password, String name, Date birthdate, String address) {
        String query = "INSERT INTO users (username, name, password, birthdate, address) VALUES (?1, ?2, ?3, ?4, ?5);";

        connection.getEntityManager().getTransaction().begin();
        Query q = connection.getEntityManager().createNativeQuery(query, UsersEntity.class);
        q.setParameter(1, username);
        q.setParameter(2, name);
        q.setParameter(3, password);
        q.setParameter(4, birthdate);
        q.setParameter(5, address);
        q.executeUpdate();
        connection.getEntityManager().getTransaction().commit();
    }

    public void resetPass(String username, String password) {
        String query = "UPDATE UsersEntity user SET user.password =?1 where username =?2";

        connection.getEntityManager().getTransaction().begin();
        Query q = connection.getEntityManager().createQuery(query)
                .setParameter(1, password)
                .setParameter(2, username);
        q.executeUpdate();
        connection.getEntityManager().getTransaction().commit();
    }

    public void create(UsersEntity usersEntity) {
        connection.executeTransaction(entityManager -> entityManager.persist(usersEntity));
    }
}
