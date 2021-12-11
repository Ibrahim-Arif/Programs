public class GeneralPractitioner  extends Doctor {
    private String practiceName;
    private String address;
    
    public GeneralPractitioner(String fullName, String registryNumber, String speciality, String practiceName, String address){
        super(fullName, registryNumber, speciality);
        this.practiceName = practiceName;
        this.address = address;
    }
    
    public String toString(){
        return this.getName() + ", Speciality: "+ this.getSpeciality() + ", Practice: " + this.practiceName;
    }
}
