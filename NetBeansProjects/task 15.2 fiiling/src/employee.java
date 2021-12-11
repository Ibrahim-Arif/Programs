import java.io.Serializable;

public class employee implements Serializable{
    String name;
    int id;
    double hourlyIncome;
    
    public employee(){
        this("",0,0);
    }
    public employee(String n, int id, double hi){
        this.name=n;
        this.id=id;
        this.hourlyIncome=hi;
    }
    
    public String toString(){
        return String.format("Employee: %s(ID: %d), Income: %.2f", this.name, this.id, this.hourlyIncome);
    }
}
