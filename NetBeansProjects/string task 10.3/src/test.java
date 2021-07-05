import java.util.*;
public class test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a sentence: ");
        String sen=input.nextLine();
        
        StringTokenizer sit = new StringTokenizer(sen," ");
        while(sit.hasMoreTokens()){
            String tok = sit.nextToken();
           
            if(tok.charAt(0) == 'b'){
                System.out.println("character with 'b': "+tok);
            }
        }
    }
}
