import java.util.Scanner;

public class cube {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n, i,cube;
		
		System.out.print("Enter number to find cube upto it: ");
		n=input.nextInt();
		
		for(i=1;i<=n;i++) {
			cube=i*i*i;
			System.out.println("Number is : " +i+" and cube of "+i+" is : "+cube);
			cube=0;
		}	
	}
}
