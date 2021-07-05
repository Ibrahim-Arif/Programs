import java.util.Random;
public class test {
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        String[] article = {"the","a","one","some","any"};
        String[] noun = {"boy","girl","dog","town","car"};
        String[] verb = {"drove","jumped","ran","walked","skipped"};
        String[] proposition = {"to","from","over","under","on"};
        
        for(int i=0; i<20; i++){
            String low=article[rand.nextInt(5)];
            String upper= low.replace(low.charAt(0), Character.toUpperCase(low.charAt(0)));
            
            System.out.printf("%d: %s %s %s %s %s %s. \n",(i+1), upper,
                                                     noun[rand.nextInt(5)],
                                                     verb[rand.nextInt(5)],
                                                     proposition[rand.nextInt(5)],
                                                     article[rand.nextInt(5)],
                                                     noun[rand.nextInt(5)] );
        }
    }
}