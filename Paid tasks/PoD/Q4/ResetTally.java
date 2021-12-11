public class ResetTally {
    protected int count;
    
    public ResetTally(){
        this.count = 0;
    }
    
    public void increment(){
        this.count++;
    }
    
    public int get(){
        return this.count;
    }
    
    public void reset(){
        this.count = 0;
    }
}
