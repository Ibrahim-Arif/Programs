public class GeneralPractitioner extends Doctor{
  private String practiceName;
  private String address;
  
  public GeneralPractitioner(String fullName, String registryNumber, String speciality, String practiceName, String address){
    super(fullName, registryNumber, speciality);
    this.practiceName = practiceName;
    this.address = address;
  }
  
  public String toString(){
    return "Dr. " + this.getName() + ", Specialty: "+ this.getSpecialty() + ", Practice: " + this.practiceName; 
  }
}