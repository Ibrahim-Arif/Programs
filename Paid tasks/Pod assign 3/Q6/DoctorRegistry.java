import java.util.*;

public class DoctorRegistry {
    private String province;
    private ArrayList<Doctor> doctors = new ArrayList<>();
    
    public DoctorRegistry(int a, String province){
        this.province = province;
    }
    
    public boolean register(Doctor d){
        boolean found = false;
        
        for(int i=0; i<doctors.size(); i++){
            if(doctors.get(i).equals(d)){
                found = true;
            }
        }
        
        if(found){
            return false;
        }
        
        doctors.add(d);
        return true;
    }
    
    public boolean deRegister(String registry){
        for(int i=0; i<doctors.size(); i++){
            if(doctors.get(i).getRegistryNumber().equals(registry)){
                doctors.add(i, null);
                return true;
            }
        }
        
        return false;
    }
    
    public ArrayList<Doctor> getDoctorList(){
        return this.doctors;
    }
}
