import java.util.*;

public class testCity {
    public static void main(String[] args) {
        int maxPop = 0, pop = 0, choice = 0;
        String cn;
        City current = null;
        
        Scanner input = new Scanner(System.in);
        Scanner str = new Scanner(System.in);
        
        System.out.println("1) Add new city. "
                + "\n2) Print detail of current city. "
                + "\n3) Print maximum population encountered. "
                + "\n4) Exit. \n");
        
        while(choice != 4){
            System.out.print("\nEnter your choice: ");
            choice = input.nextInt();
            
            switch(choice){
                case 1:{
                    System.out.print("Enter city name: ");
                    cn = str.next();
                    System.out.print("Enter city population: ");
                    pop = input.nextInt();
                    if(pop != 0) 
                        current = new City(cn, pop);
                    else
                        current = new City(cn);
                    
                    if(current.getCityPopulation() > maxPop){
                        maxPop = current.getCityPopulation();
                    }
                    break;
                }
                case 2:{
                    System.out.println(current.toString());
                    break;
                }
                case 3:{
                    System.out.println("Max populated city so far: " +maxPop);
                    break;
                }
                case 4:{
                    break;
                }
                default:{
                    System.out.println("Wrong input!");
                    break;
                }
            }
            
        }
    }
}
