
public class account {
    private int acoName;
    private String userName;
    private double balance;
    
    public account(int ac, String un, double b){
        acoName = ac;
        userName = un;
        balance = b;
    }

    public int getAcoName() {
        return acoName;
    }
    public String getUserName() {
        return userName;
    }
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }
    
    public String toString(){
        return String.format("\nAccount number: %d \nUserName: %s \nBalance: %.2f", acoName, userName, balance);
    }
}
