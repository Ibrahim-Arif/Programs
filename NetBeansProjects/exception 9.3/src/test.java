
public class test {
    
    public static void main(String[] args) {
        try{
//            throw new exceptionA("demo for A");
            throw new exceptionB("demo for B");
            
        }
        catch(exceptionB e){
            e.printStackTrace();
        }
        catch(exceptionA e){
            e.printStackTrace();
        }
    }
    
}
