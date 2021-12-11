import java.util.Scanner;
public class gettingdata {
	static Scanner input = new Scanner(System.in);
	static char arr[] = new char[10];
	static int n;
	static char sym;
	
	public static void input() {
		System.out.print("Enter location: ");
		n=input.nextInt();
		if(Main.count%2 == 0)
			arr[n]= 'O';
		else
			arr[n]= 'X';
	}
}
