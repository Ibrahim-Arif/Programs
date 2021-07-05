import java.io.*;
import java.nio.file.Paths;
import java.util.*;

public class test {
    private static Formatter output;
    static double average(int a[]){
        double sum=0;
        for(int aa: a){
            sum+=aa;
        }
        return sum/a.length;
    }
    
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        Scanner input1 = new Scanner(System.in);
        
        System.out.print("1: write a file. \n2: read a file. \nEnter your choice: ");
        int choice=input.nextInt();
        
        if(choice==1){
            output = new Formatter("SessionalResult.txt");
            System.out.println("Enter student id and marks of four subjects: ");
            for(int i=0; i<4; i++){
                output.format("%s %d %d %d %d \n", input.next(), 
                                                   input.nextInt(), input.nextInt(),
                                                   input.nextInt(), input.nextInt());
            }
            if(output != null)
                output.close();
        }
        
        if(choice==2){
            input1 = new Scanner(Paths.get("SessionalResult.txt"));
            
            System.out.println("\nID: \t\tAverage:");
            while(input1.hasNext()){
                String n = input1.next();
                int a[]=new int[4];
                for(int i=0; i<4; i++){
                    a[i]=input1.nextInt();
                }
                System.out.println(n+"\t "+test.average(a));
            }
            input1.close();
        }
    }   
}