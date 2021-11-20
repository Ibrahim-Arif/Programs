public class HospitalDoctor extends Doctor {
    private String staffNumber;
    private String pagerNumber;
    
    public HospitalDoctor(String fullName, String registryNumber, String speciality, String staffNumber, String pagerNumber){
        super(fullName, registryNumber, speciality);
        this.staffNumber = staffNumber;
        this.pagerNumber = pagerNumber;
    }
    
    public String toString(){
        return this.getName() + ", Speciality: "+ this.getSpeciality() + ", Pager: " + this.pagerNumber;
    }
}
