import java.util.*;

public class Billing implements Payable{
    private int billId;
    private Doctor docInfo;
    private Patient pInfo;
    private ArrayList<Medicine> medList;
    private ArrayList<MedicalTest> medTest;
    private int totalBills=0;
    
    public Billing(Doctor docInfo, Patient pInfo, ArrayList<Medicine> medList, ArrayList<MedicalTest> medTest){
        this.docInfo = docInfo;
        this.pInfo = pInfo;
        this.medList = medList;      
        this.medTest = medTest;
    }
    
    public double getPaymentAmount(){
        this.medList.forEach((n) -> this.totalBills+=n.getMedPrice());
        this.medTest.forEach((n) -> this.totalBills+=n.getTestPrice());
        this.totalBills += this.docInfo.getDocFee();
        
        return this.totalBills;
    }
    
    public Doctor getDoc(){
        return this.docInfo;
    }
    
    public String toString(){
        return String.format("bill id: %d \nDoc info: %s \nPatient: %s \n total bills: %.2f \n", this.billId,  this.docInfo.toString(), this.pInfo.toString(), this.getPaymentAmount());
    }
}