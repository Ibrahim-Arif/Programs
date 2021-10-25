public class TallyCounter {
    private int count;

    public TallyCounter(){
        this.count = 0;
    }
    
    public void increment(){
        this.count++;
    }
    
    public int get(){
        return this.count;
    }
}
