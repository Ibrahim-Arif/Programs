package demo;

public class AccountTest {

	public static void main(String[] args) {
		Account a1 = new Account(111, "NAME", 10000);
		
		a1.display();
		a1.checkBalance();
		System.out.println("\nAfter deposit 40000");
		a1.deposit(40000);
		a1.checkBalance();
		System.out.println("\nAfter withdraw 12000");
		a1.withdraw(12000);
		a1.checkBalance();
	}
}
