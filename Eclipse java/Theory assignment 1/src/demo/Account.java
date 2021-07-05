package demo;

public class Account {
	public int accountNo;
	public String accountName;
	private double balance;
	
	public Account(int accountNo, String accountName, double balance) {
		this.accountNo = accountNo;
		this.accountName = accountName;
		this.balance = balance;
	}

	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	void checkBalance() {
		System.out.println("Current balance: "+balance);
	}
	void deposit(int added_amount) {
		balance += added_amount;
	}
	void withdraw(int withdraw_amount) {
		balance -= withdraw_amount;
	}
	void display() {
		System.out.println("Account number: "+accountNo);
		System.out.println("Account name: "+accountName);
		System.out.println("Balance: "+balance);
	}
}