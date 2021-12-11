public class SailBoat {
    private String boatName;
    static int counter;
    private int dockSpace;
    
    public SailBoat(String bn){
        this.boatName = bn;
        this.counter++;
        this.dockSpace = counter;
    }

    @Override
    public String toString() {
        return boatName + " is at dock space " + dockSpace;
    }
}
