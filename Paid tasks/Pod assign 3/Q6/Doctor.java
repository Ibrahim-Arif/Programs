public class Doctor {
    private String fullName;
    private String registryNumber;
    private String speciality;
    
    public Doctor(String fullName, String registryNumber, String speciality){
        this.fullName = fullName;
        this.registryNumber = registryNumber;
        this.speciality = speciality;
    }
    
    public String getName(){
        return this.fullName;
    }
    
    public String getRegistryNumber(){
        return this.registryNumber;
    }
    
    public String getSpeciality(){
        return this.speciality;
    }
    
    public void setName(String name){
        this.fullName = name;
    }
    
    public boolean equals(Doctor d){
        if(this.registryNumber == d.getRegistryNumber()){
            return true;
        }else{
            return false;
        }
    }
    
    public String toString(){
        return this.fullName + ", Speciality: " + this.speciality;
    }
}
