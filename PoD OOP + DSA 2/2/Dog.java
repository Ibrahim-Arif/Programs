public class Dog extends DomesticAnimal {
    private String breed;

    public Dog(String name, String diet, int age, String breed){
        super(name, diet, age);
        this.breed = breed;
    }

    public int ageInHumamYears(){
        return this.getAge() * 7;
    }

    public String toString(){
        return String.format("Dog: %s (%dyr), eats %s", this.getName(), this.getAge(), this.getDiet());
    }
}
