
import java.util.regex.Pattern;


public class savingAccount extends Account{
    private float monthlyInterestRate;
    private static int count;
    
    public savingAccount(String cn, long an, String at, double b, int c, float mir){
        super(cn, an, at, b, c);
        this.monthlyInterestRate = mir;
        count++;
    }
    public savingAccount(){
        super("", 0, "", 0, 0);
    }
    
    public savingAccount addAccount(String cnic, long an, String at, double b, float mir){
        if(Pattern.matches("\\d+", cnic)){
            this.cnic = cnic;
        }
        if(Pattern.matches("2\\d*", String.valueOf(an))){
            this.accountNumber = an;
        }
        if(Pattern.matches("[A-Z]{1}[a-zA-Z]*", at)){
            this.accountTitle = at;
        }
        if(balance != 0){
            this.balance = balance;
        }
        if(mir != 0){
            this.monthlyInterestRate = mir;
        }
        return new savingAccount(cnic, an, at, b, count, mir);
    }
    
    public void deposit(double amount){
        this.balance += amount;
    }
    
    public void withDraw(double amount){   
        if(amount > this.balance){
            System.out.println("Insufficient balance!");
        }else{
            this.balance -= amount;
        }
    }
    
    public int totalAccount(){
        return this.count;
    }
    
    public void setInterestRate(float rate){
        this.monthlyInterestRate = rate;
    }
    public float calculateInterest(){
        this.balance += this.monthlyInterestRate;
        return this.monthlyInterestRate;
    }
    public int totalAccounts(){
        return super.totalAccount();
    }
    public void checkBalance(){
        System.out.println("Current balance: "+this.balance);
    }
}
