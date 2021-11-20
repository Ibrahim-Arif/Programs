public class PrettyTally extends TallyCounter{
    private String name;
    
    public PrettyTally(String name){
        this.name = name;
    }
    
    public void decrement(){
        this.count--;
    }
    
    public String toString(){
        return this.count + " " + this.name;
    }
}
