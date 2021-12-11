import java.io.Serializable;

public class Account implements Serializable{
    private int account;
    private String firstName;
    private String lastName;
    private double balance;
    
    public Account(){
        this(0,"","",0);
    }
    public Account(int a, String fn, String ln, double b){
        this.account=a;
        this.firstName=fn;
        this.lastName=ln;
        this.balance=b;
    }
    
    public void combine(TransactionRecord tr){
         this.balance += tr.getTrans_amount();
    }
    
    public String toString(){
        return String.format("\nAccount: %d \nName: %s %s \nBalance: %.2f", this.account,
                                                                          this.firstName,
                                                                          this.lastName,
                                                                          this.balance);
    }
    
    public int getAccount() {
        return account;
    }
    public void setAccount(int account) {
        this.account = account;
    }

    public String getFirstName() {
        return firstName;
    }
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }
    
    public String getLastName() {
        return lastName;
    }
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }
    
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }   
}