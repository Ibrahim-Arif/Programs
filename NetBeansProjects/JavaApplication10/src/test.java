import java.util.*;
import java.util.regex.*;

public class test {
    public static final String identifier_pattern ="[_a-zA-Z][_a-zA-Z0-9]{0,30}";
//    public static final String increment_decrement_pattern ="([++]|[--])?";
    
    public static boolean regno_matcher(String rg){        
        return rg.matches("(CIIT/)?(SP|FA)\\d{2}-(B|M)(CS|SE|BA|CE|EE)-\\d{3}(/{1}LHR|ISB|WAH|ABT)?");
    }
    public static boolean date_matcher(String date){
        return date.matches("([0-3][0-9]){1}-([0-1][0-9]){1}(-\\d{4})?");
    }
    public static boolean print_statement_matcher(String pt){
        return pt.matches("((System.out.)(print|printf|println)){1}([(](((\").*(\")(,)?)?" 
                        + "("+identifier_pattern+")?)?[)]"
                        + "[;]){1}");
    }
    public static boolean for_loop_matcher(String fo){
        return fo.matches("(for\\s*)[(]\\s*(int|float)?\\s*"+identifier_pattern+"\\s*=\\s*\\d+\\s*;\\s*"
                        +identifier_pattern+"\\s*(==|<|>|<=|>=|!=)\\s*(\\d+|"+identifier_pattern+")\\s*;\\s*"
                        +"(\\+{2}|\\-{2})?\\s*"+identifier_pattern+"\\s*(\\+{2}|\\-{2})?\\s*"       
                        +"[)][{](.)*[}]");
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while(true){
            boolean res = false;
            System.out.print("1: ID \t\t 2: Date \n3: SOP \t\t 4: for loop \nEnter your choice: ");
            int choice = input.nextInt();
            System.out.print("Please enter the pattern you want to test: ");
            String str = input.nextLine();
            str = input.nextLine();
            switch(choice){
                case 1:
                    res = test.regno_matcher(str);
                    break;
                case 2:
                    res = test.date_matcher(str);
                    break;
                case 3:
                    res = test.print_statement_matcher(str);
                    break;
                case 4:
                    res = test.for_loop_matcher(str);
                    break;
                default:
                    System.out.println("Ani deya wekh ka paa");       
            }
            if(res==true)
                System.out.println(str+" MATCHED \n");
            else
                System.out.println(str+" NOT MATCHED \n");
        }     
    }
}