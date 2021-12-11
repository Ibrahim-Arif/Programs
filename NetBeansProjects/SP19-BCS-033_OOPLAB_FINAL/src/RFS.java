
public class RFS {
    private static boolean eligible = false;
    
    public static boolean check_for_RFS(Student std){
        if(std.getDegree().equalsIgnoreCase("graduate")){
            if(std.getCgpa() >= 3.3){
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
            System.out.println("Stipend: Rs. 20,000/- per month.");
        }
    }
}
