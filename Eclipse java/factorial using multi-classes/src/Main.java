import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner input= new Scanner(System.in);
		fact a = new fact();
		int n, choice;
		System.out.println("1 for factorial \n2 for table");
		System.out.print("Enter your choice: ");
		choice = input.nextInt();
		System.out.println();
		if(choice==1) {
			System.out.print("Enter a number: ");
			n=input.nextInt();
			a.value=1;
			a.factorial(n);
			System.out.println("factorial: "+a.value);
		}
		else if(choice==2) {
			System.out.print("Enter a number: ");
			n=input.nextInt();
			table b = new table();
			b.value=n;
			for(int i=1;i<11;i++){
				b.tab(i);
				System.out.println(b.value+" * "+i+" = "+b.result);
			}
		}
		else
			System.out.println("Wrong choice.");
	}

}
