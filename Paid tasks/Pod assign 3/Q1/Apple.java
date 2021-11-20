public class Apple extends Fruit{
    private int age;
    
    public Apple(String colour, int age){
        super(colour);
        this.age = age;
    }
    
    public int getAge(){
        return this.age;
    }
    
    public void setAge(int age){
        this.age = age;
    }
    
    public String toString(){
        return "Apple: colour=" + this.colour + " age=" + this.age;   
    }
}
