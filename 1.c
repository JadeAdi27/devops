//Myapp.java
import java.util.ResourceBundle;
public class MyApp {
    public int userLogin(String inUser, String inPwd) {
        ResourceBundle rb = ResourceBundle.getBundle("config");
        String username = rb.getString("username");
        String password = rb.getString("password");
        if (inUser.equals(username) && inPwd.equals(password)) {
            return 1;
        } else {
            return 0;
        }
    }
}
--------------------------------------
// Config.properties
  
username=abc
password=abc@1234
  ------------------------------------
  -----------------------------------
  //MyAppTest.java code
  
  package myproject;
import org.testng.Assert;
import org.testng.annotations.Test;
import com.myproject.MyApp;
public class MyAppTest {
    @Test
    public void testLogin1() {
        MyApp myApp = new MyApp();
        Assert.assertEquals(myApp.userLogin("abc", "abc1234"), 0);
    }
    @Test
    public void testLogin2() {
        MyApp myApp = new MyApp();
        Assert.assertEquals(myApp.userLogin("abc", "abc@1234"), 1);
    }
}
-----------------------------------
  //pop
  <dependencies>
  <!-- https://mvnrepository.com/artifact/org.testng/testng -->
  <dependency>
    <groupId>org.testng</groupId>
    <artifactId>testng</artifactId>
    <version>7.5.1</version>
    <scope>test</scope>
  </dependency>
</dependencies>
-------------------------------
  gradle init


    for gradel go to properties go to that perticular file open cmd on that path and run gradel init
