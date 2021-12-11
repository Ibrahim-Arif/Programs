import java.io.IOException;
import java.util.Scanner;
public class test {
    
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String a = null;
        
        try{
            throw new exceptionA("demo for A");
            
//            throw new exceptionB("demo for B");

//            if(a.equals("abc"))                       //cause null pointer
//                System.out.println("equal");

//            throw new IOException("demo for IO");      //cause IOexcption
            
        } catch(Exception e){
            e.printStackTrace();
        }
    }
}
