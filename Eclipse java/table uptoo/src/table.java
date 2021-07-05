import java.util.Scanner;

public class table {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n, i, result, e;
		
		System.out.print("Enter number for table: ");
		n=input.nextInt();
		System.out.print("Enter length of table: ");
		e = input.nextInt();
		
		for(i=1;i<=e;i++) {
			result= n*i;
			System.out.printf("%d * %d = %d\n",n,i,result);
			
		}

	}

}
