public class Orange extends Fruit {
    
    public Orange(int weight, int age){
        super(weight, age);
    }
    
    public String toString(){
        return "Orange: " + this.getWeight() + ", " + this.getAge();
    }
}
