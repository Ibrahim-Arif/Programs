public class PEEF {
    private static boolean eligible = false;
    
    public static boolean check_for_PEEF(Student std){
        if(std.getDegree().equalsIgnoreCase("undergraduate")){
            if(std.getCgpa() > 3.25){
                eligible = true;
            }
        }
        else if(std.getDegree().equalsIgnoreCase("graduate")){
            if(std.getCgpa() > 3.5){
                eligible = true;
            }
        }
        return eligible;
    }
    
    
    public static void calculate_fee(Student std, boolean eligible){
        if(eligible){
            if(std.getDegree().equalsIgnoreCase("undergraduate")){
                System.out.println("Student: "+std.getName()+"_"+std.getId());
                System.out.println("Fee before scholarship: "+std.getFee());
                std.setFee(std.getFee()- (std.getFee()*0.25) );
                System.out.println("Fee After scholarship: "+std.getFee());
                System.out.println("Stipend: Rs. 5000/- per month.");
            }
            else if(std.getDegree().equalsIgnoreCase("graduate")){
                System.out.println("Student: "+std.getName()+", ID: "+std.getId());
                System.out.println("Fee before scholarship: "+std.getFee());
                std.setFee(std.getFee()- (std.getFee()*0.20) );
                System.out.println("Fee After scholarship: "+std.getFee());
            }
        }
    }
}