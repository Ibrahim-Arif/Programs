public class Cat extends DomesticAnimal {
    private String breed;

    public Cat(String name, String diet, int age, String breed){
        super(name, diet, age);
        this.breed = breed;
    }

    public int ageInHumamYears(){
        return this.getAge() * 5;
    }

    public String toString(){
        return String.format("Cat: %s (%dyr), eats %s", this.getName(), this.getAge(), this.getDiet());
    }
}
