import java.util.*;
public class StudentTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		course course1 = new course("", "");
		course course2 = new course("", "");
		PhoneNumber phoneNo = new PhoneNumber(0,0,0);
		Address address = new Address("", "", "", "", phoneNo);
		Student s1 = new Student("", "", address,course1,course2);
		
		System.out.print("Enter name: ");
		s1.setName(input.nextLine());
		System.out.print("Enter email: ");
		s1.setEmail(input.nextLine());
		System.out.print("Enter CNIC: ");
		s1.setCnic(input.nextLine());
		
		try {
		s1.getCourse1().setterCC("OOP-101");
		s1.getCourse1().setterCT("OOP");
		s1.getCourse2().setterCC("MP_111");
		s1.getCourse2().setterCT("Modern Physics");
		s1.getAddress().getPhoneNumber().setCountryCode(92);
		s1.getAddress().getPhoneNumber().setCityCode(48);
		s1.getAddress().getPhoneNumber().setLineNumber(3226791);
		s1.getAddress().setCity("Sargodha");
		s1.getAddress().setCountry("Pakistan");
		s1.getAddress().setStreetAddress("403-D");
		s1.getAddress().setTown("Satelite town");
		
		} catch(NullPointerException e) {
			System.out.println(e);
		}
		
		System.out.println("Name: "+s1.getName());
		System.out.println("Email: "+s1.getEmail());
		System.out.println("Cnic: "+s1.getCnic());
		System.out.println("Course code 1: "+s1.getCourse1().getterCC());
		System.out.println("Course title 1: "+s1.getCourse1().getterCT());
		System.out.println("Course code 2: "+s1.getCourse2().getterCC());
		System.out.println("Course title 2: "+s1.getCourse2().getterCT());
		System.out.println("Street address: "+s1.getAddress().getStreetAddress());
		System.out.println("Town: "+s1.getAddress().getTown());
		System.out.println("City: "+s1.getAddress().getCity());
		System.out.println("Country: "+s1.getAddress().getCountry());
		System.out.println("Phone no: "+s1.getAddress().getPhoneNumber().getCountryCode()+"-"+s1.getAddress().getPhoneNumber().getCityCode()+"-"+s1.getAddress().getPhoneNumber().getLineNumber());
		
	}
}
