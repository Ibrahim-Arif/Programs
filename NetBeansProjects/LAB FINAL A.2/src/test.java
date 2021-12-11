import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;

public class test {
    
    private static Scanner input = new Scanner(System.in);
    private static double result = 0.0;
    private static String operation = "";
    private static char operator;
    private static double number;
    
    
    public static void main(String[] args) {
        
        System.out.println("Calculator is on");
        System.out.println("result = 0.0");
        
        while(true){
            operation = input.next();
            if(operation.equalsIgnoreCase("R")){
                System.out.println("Final result: "+result);
                result = 0.0;
                System.out.println("Again? (y/n)");
                operation = input.next();
                if(operation.equalsIgnoreCase("yes") || operation.equalsIgnoreCase("y")){
                    System.out.println("Result: "+result);
                    continue;
                }
                else if(operation.equalsIgnoreCase("no") || operation.equalsIgnoreCase("n")){
                    System.out.println("End of program.");
                    break;
                }
            }
            try {
                operation_to_operatorAndnumber(operation);
                switch(operator){
                    case '+':{
                        result += number;
                        break;
                    }
                    case '-':{
                        result -= number;
                        break;
                    }
                    case '*':{
                        result *= number;
                        break;
                    }
                    case '/':{
                        result /= number;
                        break;
                    }
                }
                System.out.println("Result + "+number+" = "+result);
                System.out.println("New result = "+result);
                
            } catch (UnknownOperatorException ex) {
                System.out.println(ex.getMessage());
                System.out.println("Reenter your last line:");
            }
            
        }
        
    }
    
    public static void operation_to_operatorAndnumber(String op) throws UnknownOperatorException{
        operator = op.charAt(0);
//        System.out.println("here");
        if(check_operator(operator)){
//            System.out.println("there");
//            System.out.println(op.substring(1, op.length()));
            number =  Double.parseDouble( op.substring(1, op.length()) );
            System.out.println(number);
            
        }else{
            String msg = operator+" is an unknown operator.";
            throw new UnknownOperatorException(msg);
        }
    }
    
    public static boolean check_operator(char ope){
        boolean matches=false;
//        !Pattern.matches("[+-*/]{1}", String.valueOf(ope))
        if("+-*/".contains(String.valueOf(ope))){  
            matches = true;
        }
        return matches;
    }
    
}
