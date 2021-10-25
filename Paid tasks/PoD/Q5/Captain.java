public class Captain {
    private int age;
    private String name;
    private int yearsOfExperience;
    private int registryNumber;
    
    public Captain(int age, String name, int yearsOfExperience, int registryNumber){
        this.age = age;
        this.name = name;
        this.yearsOfExperience = yearsOfExperience;
        this.registryNumber = registryNumber;
    }
    
    public String getName() {
        return this.name;
    }
    public int getYearsOfExperience(){
        return this.registryNumber;
    }
    public boolean equals(Captain second){
        if(this.name.equals(second.name) && this.registryNumber == second.registryNumber){
            return true;
        }else{
            return false;
        }
    }
    public String toString(){
        return this.name + ", age: " + this.age + "\nYoE: " + this.yearsOfExperience + "\nRegistry: " + this.registryNumber;
    }
}
