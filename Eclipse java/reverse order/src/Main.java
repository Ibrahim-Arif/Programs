import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n, result;
		
		System.out.print("Enter a number: ");
		n=input.nextInt();
		
		while(n != 0) {
			result = n%10;
			n=n/10;
			System.out.print(result);
		}
		
	}

}
