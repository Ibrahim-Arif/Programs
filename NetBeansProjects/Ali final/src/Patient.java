
public class Patient {
    private String pName;
    private int pId;
    private String pDisease;
    
    public Patient(String pn, int pi, String pd){
        this.pName = pn;
        this.pId = pi;
        this.pDisease = pd;
    }
    
    public String toString(){
        return String.format("Pname: %s \nP id: %d \nP disease: %s \n", this.getpName(), this.getpId(), this.getpDisease());
    }
    
    public String getpName() {
        return pName;
    }
    public void setpName(String pName) {
        this.pName = pName;
    }
    public int getpId() {
        return pId;
    }
    public void setpId(int pId) {
        this.pId = pId;
    }
    public String getpDisease() {
        return pDisease;
    }
    public void setpDisease(String pDisease) {
        this.pDisease = pDisease;
    }
}
