
public class Account {
    protected String cnic;
    protected long accountNumber;
    protected String accountTitle;
    protected double balance;
    protected static int count;
    
    public Account(String cn, long an, String at, double b, int c){
        this.cnic = cnic;
        this.accountNumber = an;
        this.accountTitle = at;
        this.balance = b;
        this.count = c;
    }
    
    public void addAccount(){
        
    }
    public void withDraw(){
        
    }
    public void deposit(){
        
    }
    public int totalAccount(){
        return count;
    }
}
