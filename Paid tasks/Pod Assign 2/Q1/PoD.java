import java.util.Scanner;

public class PoD {
    public static void main(String[] args) {
       Scanner in = new Scanner(System.in);
       PrettyTally tally = new PrettyTally(in.next());
       
       while(in.hasNext()){
           String nextTask = in.next();
           
           if(nextTask.equals("increment")){
               tally.increment();
           } else if(nextTask.equals("toString")){
               System.out.println(tally);
           } else if(nextTask.equals("decrement")){
               tally.decrement();
           }
       }
       in.close();
    }
}
