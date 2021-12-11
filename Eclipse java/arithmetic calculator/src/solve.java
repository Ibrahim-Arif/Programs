import java.util.Scanner;


public class solve {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		int choice;
		float first=0, second=0;
		float sum, subtract, multiple, division;
		
		System.out.print("Enter 1st number: ");
		first=input.nextFloat();
		
		System.out.print("Enter 2nd number: ");
		second=input.nextFloat();
		
		System.out.println("Enter 1 for addition \nEnter 2 for subtraction \nEnter 3 for multiplication\nEnter 4 for division\n");
		System.out.print("Enter your choice: ");
		choice = input.nextInt();
		
		if(choice == 1) {
			sum = first + second;
			System.out.print("sum: " +sum);
		}
		else if(choice == 2) {
			subtract = first - second;
			System.out.print("Subtract: " +subtract);
		}
		else if(choice == 3) {
			multiple = first * second;
			System.out.print("Multiple: " +multiple);
		}
		else if(choice ==4) {
			division = first / second;
			System.out.print("Division: " +division);
		}
		
	}
}
