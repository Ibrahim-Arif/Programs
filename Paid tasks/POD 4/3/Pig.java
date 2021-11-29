public class Pig implements Comparable<Pig>{
    private int age;
    private int weight;
    
    public Pig(int age, int weight){
        this.age = age;
        this.weight = weight;
    }
    
    public int getAge(){
        return this.age;
    }
    public int getWeight(){
        return this.weight;
    }
    
     public int compareTo(Pig p){
        if(this.weight == p.getWeight()){
            if(this.age == p.getAge() ){
                return 0;
            }else if(this.age > p.getAge()){
                return 1;
            }
            return -1;
        } else if(this.weight > p.getWeight()){
            return 1;
        }
        return -1;
    }
    
    @Override
    public String toString(){
        return String.format("Age: %d, weight: %d kg", this.age, this.weight);
    }
}
