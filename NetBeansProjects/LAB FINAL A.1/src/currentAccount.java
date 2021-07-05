
import java.util.regex.Pattern;


public class currentAccount extends Account{
    private float serviceFeeRate;
    private static int count;
    
    public currentAccount(String cn, long an, String at, double b, int c, float sfr){
        super(cn, an, at, b, c);
        this.serviceFeeRate = sfr;
        count++;
    }
    public currentAccount(){
        super("", 0, "", 0, 0);
    }
    
    public currentAccount addAccount(String cnic, long an, String at, double balance, float sfr){
        if(Pattern.matches("\\d+", cnic)){
            this.cnic = cnic;
        }
        if(Pattern.matches("1\\d*", String.valueOf(an))){
            this.accountNumber = an;
        }
        if(Pattern.matches("[A-Z]{1}[a-zA-Z]*", at)){
            this.accountTitle = at;
        }
        if(balance != 0){
            this.balance = balance;
        }
        if(sfr >= 0){
            this.serviceFeeRate = sfr;
        }
        return new currentAccount(cnic, an, at, balance, count, sfr);
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
    
    public double calServiceFee(){
        this.serviceFeeRate = (float) (this.balance-1000);
        return this.serviceFeeRate;
    }

    public void checkBalance(){
        System.out.println("Current balance: "+this.balance);
    }
}
