package kickstart.round.b2;     //Kickstart Round B 2020 (Robot pattern)
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
public class KickstartRoundB2 {
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Pattern exp = Pattern.compile("\\d?[(]\\w+[)]");
        System.out.print("Enter Cardinal Direction: ");
        String s=input.nextLine();
        
        while(!Pattern.matches("[a-zA-Z]+",s)){
            Matcher mat = exp.matcher(s);
            while(mat.find()){
                String temp = mat.group();
                char c = temp.charAt(0);
                int n=1;
                if(Character.isDigit(c)){
                    n = (int)c-'0';
                }
                String rep = temp.substring(temp.indexOf("(")+1, temp.length()-1);
                s = s.replace(temp, rep.repeat(n));
//                s = s.replace(mat.group(), mat.group().substring(2, mat.group().length()-1).repeat(mat.group().charAt(0)-'0'));
            }
        }
        System.out.println("Equivalent to: "+s);
        System.out.println();
    }
}