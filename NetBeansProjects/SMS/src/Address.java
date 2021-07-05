
import java.io.Serializable;

public class Address implements Serializable {
    private int house;
    private int street;
    private String town;
    private String city;
    public Address(){
    }
    public Address(int h, int s, String t, String c){
        this.house = h;
        this.street = s;
        this.town = t;
        this.city = c;
    }
    
    public boolean using_string(String address){
        String[] add = address.split(" ");
        if(add.length == 4){
            this.house = Integer.parseInt(add[0]);
            this.street = Integer.parseInt(add[1]);
            this.town = add[2];
            this.city = add[3];
            return true;
        }else{
            return false;
        }
    }
    
    public String toString(){
        return String.format("%d %d, %s, %s", this.house, this.street, this.town, this.city);
    }

    public int getHouse() {
        return house;
    }
    public void setHouse(int house) {
        this.house = house;
    }

    public int getStreet() {
        return street;
    }
    public void setStreet(int street) {
        this.street = street;
    }
    
    public String getTown() {
        return town;
    }
    public void setTown(String town) {
        this.town = town;
    }

    public String getCity() {
        return city;
    }
    public void setCity(String city) {
        this.city = city;
    }   
}