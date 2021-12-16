import java.util.*;

public class StudentDemo {

    public static void add(List<Student> students, Student std){
        for(int i=0; i<students.size(); i++){
            if(std.getName().compareTo(students.get(i).getName()) < 0){
                students.add(i, std);
                return;
            }
        }

        students.add(std);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Scanner input2 = new Scanner(System.in);

        List<Student> students = new ArrayList<>();
        String name;
        double gpa;

        while(true){
            name = input.nextLine();

            if(name.equals("-1")){
                break;
            }

            gpa = input2.nextDouble();
            add(students, new Student(name, gpa));
        }

        System.out.println(students);
        
        Collections.sort(students);
        System.out.println(students);
    }
}
