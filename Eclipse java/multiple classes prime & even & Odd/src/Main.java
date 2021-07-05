import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n;
		
		System.out.print("Enter number to check Prime & Even||odd: ");
		n=input.nextInt();
		
		evenORodd a = new evenORodd();
		a.n=n;
		a.evenorodd();
		if(a.flag == 0)
			System.out.println(n+" is a even number");
		else
			System.out.println(n+" is a odd number");
			
		
		if(a.flag == 1) {
			prime b = new prime();
			b.n = n;
			b.Prime();
			if(b.flag == 1)
				System.out.println(n+" is not a prime number.");
			else
				System.out.println(n+" is a prime number.");
		}
		else
			System.out.print(n+" is not a prime number");
	}
}

