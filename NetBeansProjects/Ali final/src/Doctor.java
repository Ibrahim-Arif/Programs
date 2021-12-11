
public class Doctor {
    private String docName;
    private int docId;
    private double docFee;
    
    public Doctor(String dn, int di, double df){
        this.docName = dn;
        this.docId = di;
        this.docFee = df;
    }
    
    public int getDocID(){
        return this.getDocId();
    }
    
    public String toString(){
        return String.format("docname: %s \ndoc id: %d \ndocFee: %.2f \n", this.getDocName(), this.getDocId(), this.getDocFee());
    }

    public String getDocName() {
        return docName;
    }
    public void setDocName(String docName) {
        this.docName = docName;
    }
    public int getDocId() {
        return docId;
    }
    public void setDocId(int docId) {
        this.docId = docId;
    }
    public double getDocFee() {
        return docFee;
    }
    public void setDocFee(double docFee) {
        this.docFee = docFee;
    }
}
