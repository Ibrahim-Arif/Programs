public class savingAccount extends account{
    private double interest;
    
    public savingAccount(double i, int san, String n, double b){
        super(san, n, b);
        interest = i;
    }
    public double getInterest(){
        return interest;
    }
    
    public double addInterst(){
        double b= getBalance() ;
        b += interest;
        setBalance(b);
        return getBalance();
    }
    
    public String toString(){
        return String.format("\nAccount number: %d \nUserName: %s \nBalance: %.2f \nBalance after interest: %.2f", getAcoName(), getUserName(), getBalance(), addInterst());
    }
}
