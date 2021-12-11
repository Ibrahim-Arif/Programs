import java.io.Serializable;
import java.util.Date;
import java.util.regex.Pattern;

public class Person implements Serializable {
    private String fName;
    private String lName;
    private Address address = new Address();
    private String phone;
    private String email;
    private String gender;
    
    public Person(String fn, String ln, String a, String p, String e, String g){
        this.fName = fn;        
        this.lName = ln;
        this.setAddress(a);
        this.phone = p;
        this.setEmail(e);
        this.gender = g;
    }
    
    public String toString(){
        return String.format("Name: %s %s \nAddress: %s \nPhone number: %s "
                             + "\nEmail: %s \nGender: %s ",this.fName,
                                                                  this.lName,
                                                                  this.address.toString(),
                                                                  this.phone,
                                                                  this.email,
                                                                  this.gender
        );
    }
    
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        if(Pattern.matches("[a-zA-Z0-9]+@gmail.com", email))
            this.email = email;
        else{
            this.email = "";
            System.out.println("Wrong Email !! \nSaving Failed");
        }
    }

    public String getfName() {
        return fName;
    }
    public void setfName(String fName) {
        this.fName = fName;
    }
    
    public String getlName() {
        return lName;
    }
    public void setlName(String lName) {
        this.lName = lName;
    }

    public Address getAddress() {
        return address;
    }
    public void setAddress(String address) {
        if(!this.address.using_string(address)){
            System.out.println("incomplete address");
            this.address = null;
        }
    }

    public String getPhone() {
        return phone;
    }
    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getGender() {
        return gender;
    }
    public void setGender(String gender) {
        this.gender = gender;
    }
}