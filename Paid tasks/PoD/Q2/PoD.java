import java.util.Scanner;

public class PoD {
    public static void main(String[] args) {
       TallyCounter tally = new TallyCounter();
       
       Scanner input = new Scanner(System.in);
       String read = input.nextLine();
       
       while(!read.equals("end")){
           if(read.equals("increment")){
               tally.increment();
           } else if(read.equals("get")){
               System.out.println(tally.get());
           }
           
           read = input.nextLine();
       }
    }
}
