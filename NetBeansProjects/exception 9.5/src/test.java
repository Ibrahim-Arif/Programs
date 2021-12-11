
import java.util.logging.Level;
import java.util.logging.Logger;


public class test {
    
    static void someMethod() throws Exception{
        try{
            test.someMethod2();
            
        } catch(Exception e){
            throw e;   
        }
    }
    static void someMethod2() throws Exception{
        throw new Exception();
    }
    
    public static void main(String[] args) {
        try {
            test.someMethod();
            
        } catch (Exception e) {
            e.printStackTrace();
        }       
    }
}