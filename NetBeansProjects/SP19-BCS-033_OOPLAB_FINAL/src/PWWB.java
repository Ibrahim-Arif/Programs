
public class PWWB {
    private static boolean eligible = false;
    
    public static boolean check_for_PWWB(Student std){
        if(std.getDegree().equalsIgnoreCase("undergraduate")){
            if(std.getCgpa() >= 3.0){
                eligible = true;
            }
        }
        return eligible;
    }
    
    
    public static void calculate_fee(Student std, boolean eligible){
        if(eligible){
            System.out.println("Student: "+std.getName()+", ID: "+std.getId());
            System.out.println("Current fee: "+std.getFee());
            std.setFee(0);
            System.out.println("After Scholarship: "+std.getFee());
        }
    }
}