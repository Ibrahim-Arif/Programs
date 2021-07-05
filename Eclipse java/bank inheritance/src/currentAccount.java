
public class currentAccount extends account{
    private double overdraftLimit;
    
    public currentAccount(int can, String n, double b){
        super(can, n, b);
        overdraftLimit = b*0.1 ;
    }
   public double getODL(){
       return getBalance()*0.1 ;
   }
   
   public String toString(){
        return String.format("\nAccount number: %d \nUserName: %s \nBalance: %.2f \nOverdraft Limit: %.2f", getAcoName(), getUserName(), getBalance(), getODL());
    }
}
