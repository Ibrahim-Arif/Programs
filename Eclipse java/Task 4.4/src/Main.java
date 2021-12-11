import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		BankAccount bankaccount = new BankAccount();
		
		int accountNumber;
		String accountTitle;
		
		System.out.print("Account title: ");
		accountTitle = input.nextLine();
		System.out.print("Account number: ");
		accountNumber = input.nextInt();
		
		bankaccount.setterAccountNumber(accountNumber);
		bankaccount.setterAccountTitle(accountTitle);
		
		System.out.println("Account title: "+bankaccount.getterAccountTitle());
		System.out.println("Account number: "+bankaccount.getterAccountNumber());
	}
}