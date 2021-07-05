package pkgfinal;

public class BankAccount {
    private double balance;
    private int number;
    
    public BankAccount(int number){
        this.number=number;
    }
    
    public BankAccount(double bal,int number){
        this.balance = bal ;
        this.number = number;
    }
    
    public void deposit(double i){
        this.balance+= i;
    }
    
    public void widthdraw(double i) throws InsufficientFundsException{
        if(i <= balance ){
            balance -= i;
        }else{
            double required = i - balance;
            throw new InsufficientFundsException(required);
        }
    }

    public double getBalance() {
        return balance;
    }

    public int getNumber() {
        return number;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void setNumber(int number) {
        this.number = number;
    }   
}