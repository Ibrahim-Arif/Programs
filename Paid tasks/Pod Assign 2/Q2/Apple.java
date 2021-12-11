public class Apple extends Fruit {
    
    public Apple(int weight, int age){
        super(weight, age);
    }
    
    public String toString(){
        return "Apple: " + this.getWeight() + ", " + this.getAge();
    }
}
