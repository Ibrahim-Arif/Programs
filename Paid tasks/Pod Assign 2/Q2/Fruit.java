public class Fruit {
    private int weight;
    private int age;
    
    public Fruit(int weight, int age){
        this.weight = weight;
        this.age = age;
    }
    
    public int getWeight(){
        return this.weight;
    }
    public int getAge(){
        return this.age;
    }
    
    public void setWeight(int weight){
        this.weight = weight;
    }
    public void setAge(int age){
        this.age = age;
    }
    
    public String toString(){
        return "This is the Fruit toString method. It should be extended by its subclass.";
    }
}
