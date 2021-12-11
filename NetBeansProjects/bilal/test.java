import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;

public class test {
    public static void main(String[] args) {
        try {
//            ObjectOutputStream ois = new ObjectOutputStream(Files.newOutputStream(Paths.get("EmployeeData.ser")));
            while(true){
                menu.pattern();
            }
            
        } catch (Exception ex) {
            Logger.getLogger(test.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("\n");   
    }
}