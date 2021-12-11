public class test {
    
    static void excpB() throws exceptionA{
        System.out.println("inside excpB");
        throw new exceptionB("demo for B");
    }
    static void excpC() throws exceptionA{
        System.out.println("inside excpC");
        throw new exceptionC("demo for C");
    }
    
    public static void main(String[] arg){
        try{
//            excpB();
            excpC();
        }
        catch(exceptionA e){
            e.printStackTrace();
        }
//        try{
//            excpC();
//        }
//        catch(exceptionA e){
//            e.printStackTrace();
//        }
    }   
}