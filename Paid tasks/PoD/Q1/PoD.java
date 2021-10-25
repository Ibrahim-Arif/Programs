import java.util.Scanner;

public class PoD{
    public static void main(String[] args){    
        Scanner in = new Scanner(System.in);

        String courseName = in.nextLine();
        String instructor = in.nextLine();
        int crn = in.nextInt();
        int creditHours = in.nextInt();

        Course newCourse = new Course(crn, creditHours, courseName, instructor);
        System.out.println(newCourse.toString());
        System.out.println("END OF OUTPUT");
    }
}