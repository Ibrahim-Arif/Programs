public abstract class DomesticAnimal {
    private String name;
    private String diet;
    private int age;

    public DomesticAnimal(String name, String diet, int age){
        this.age = age;
        this.name = name;
        this.diet = diet;
    }

    public String getName(){
        return name;
    }

    public String getDiet(){
        return diet;
    }

    public int getAge(){
        return age;
    }

    public abstract int ageInHumamYears();

    public String toString(){
        return String.format("%s (%dyr), eats %s", this.name, this.age, this.diet);
    }
}
