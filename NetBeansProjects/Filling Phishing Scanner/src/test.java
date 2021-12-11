import java.io.IOException;
import java.nio.file.Paths;
import java.text.NumberFormat;
import java.util.Scanner;
import java.util.regex.Pattern;

public class test {
    static final String[] words = {"ticket","delivery","no","ups","irs","n","notification","8","usps", //9 with 1 point
                      "dhl","financial","statement","fedex","copy","calculation",         //6 with 2 points
                      "postal","document","post","invoice","lable"};                      //5 with 3 points
    static int count[] = new int[20];
    static int total_point=0;
    static int total_words=0;
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_RESET = "\u001B[0m";
    
    public static String punctuation_filter(String n){
        if(Pattern.matches("[0-9]+", n))
            return n;
        else{
            if(!Character.isAlphabetic(n.charAt(0))){
                n = n.replace(n.charAt(0), ' ');
            }
            if(!Character.isAlphabetic(n.charAt(n.length()-1))){
                n = n.replace(n.charAt(n.length()-1), ' ');
            }
            return n.trim();
        }
    }
    
    
    public static void main(String[] args) {
        try {
            Scanner input = new Scanner(Paths.get("demo.txt"));
            NumberFormat myFormat = NumberFormat.getInstance();
            myFormat.setGroupingUsed(true);
            
            while(input.hasNext()){
                String n = input.next();
                total_words++;
                n = punctuation_filter(n);
                for(int i=0; i<20; i++){
                    if(n.equalsIgnoreCase(words[i])){
                        count[i]+=1;
                        if(i<9)
                            total_point+=1;
                        else if(i<15)
                            total_point+=2;
                        else if(i<20)
                            total_point+=3;
                    }
                }
            }
            int j=0;
            for(int i:count){
                if(i>=1){
                     System.out.println("\'" +words[j]+ "\' occurs "+ANSI_GREEN+i+ANSI_RESET+" times.");
                }
                j++;
            }
            System.out.println("\nTotal words in suspicious file: "+ANSI_RED+myFormat.format(total_words)+ANSI_RESET);
            System.out.println("Total points for possible phishing file: "+ANSI_RED+myFormat.format(total_point)+ANSI_RESET);
            System.out.println();
            input.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
}