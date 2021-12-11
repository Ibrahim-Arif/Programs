package friends;
import java.util.*;

public class Friends {
    public static void main(String[] args) {
        HashMap<String, String[]> friendsList = new HashMap<String, String[]>();
        Scanner scn = new Scanner(System.in);
        String input = "";
        
        String[] sueFriends = {"Bob", "Jose", "Alex", "Cathy"};
        String[] cathyFriends = {"Alex", "Bob"};
        String[] bobFriends = {"Alex", "Jose", "Jerry"};
        
        friendsList.put("Sue", sueFriends);       
        friendsList.put("Cathy", cathyFriends);       
        friendsList.put("Bob", bobFriends); 
        
        while(true){
            System.out.print("Enter a name ('quit' to end): ");
            input = scn.next();
            
            // capitilizing the first character in case user input all small letters.
            input = input.substring(0, 1).toUpperCase() + input.substring(1);
            
            if(input.equals("Quit")){
                System.out.println("OK, bye for now!");
                break;
            }
            
            if(friendsList.containsKey(input)){
                String[] result = friendsList.get(input);
                
                System.out.println("Here are the friends of Bob:");
                System.out.print("[");
                for(int i=0; i<result.length; i++){
                    System.out.print(result[i]);
                    
                    if(i != result.length - 1)
                        System.out.print(", ");
                }
                    
                System.out.println("] \n");
            }else{
                System.out.println("Awww, "+ input +" has no friends :( \n");
            }
        }
    }
}
