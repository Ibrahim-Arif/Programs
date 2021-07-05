public class Medicine {
    private int medId;
    private String medName;
    private int medQty;
    private double medPrice;
    
    public Medicine(int mi, String mn, int mq, double mp){
        this.medId = mi;
        this.medName = mn;
        this.medQty = mq;
        this.medPrice = mp;
    }
    
    public String toString(){
        return String.format("Med id: %d \nMed name: %s \nMed quantity: %d \nmed price: %.2f \n", this.getMedId(), this.getMedName(), this.getMedQty(), this.getMedPrice());
    }
    
    
    public int getMedId() {
        return medId;
    }
    public void setMedId(int medId) {
        this.medId = medId;
    }
    public String getMedName() {
        return medName;
    }
    public void setMedName(String medName) {
        this.medName = medName;
    }
    public int getMedQty() {
        return medQty;
    }
    public void setMedQty(int medQty) {
        this.medQty = medQty;
    }
    public double getMedPrice() {
        return medPrice;
    }
    public void setMedPrice(double medPrice) {
        this.medPrice = medPrice;
    }
}