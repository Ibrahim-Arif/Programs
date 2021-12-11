import java.io.Serializable;

public class TransactionRecord implements Serializable {
    private int account_number;
    private double trans_amount;
    
    public TransactionRecord(int an, double ta){
        this.account_number=an;
        this.trans_amount=ta;
    }
    
    public String toString(){
        return String.format("Account number: %d \nAmount: %.2f", this.account_number,this.trans_amount);
    }

    public int getAccount_number() {
        return account_number;
    }
    public void setAccount_number(int account_number) {
        this.account_number = account_number;
    }

    public double getTrans_amount() {
        return trans_amount;
    }
    public void setTrans_amount(double trans_amount) {
        this.trans_amount = trans_amount;
    }   
}