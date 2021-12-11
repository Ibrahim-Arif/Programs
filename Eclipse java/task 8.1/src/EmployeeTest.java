import java.util.*;
public class EmployeeTest {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		address add = new address();
		add.streetNumberSetter("402-D");
		add.citySetter("Sargodha");
		add.countrySetter("Pakistan");
		
		
		employee employee1 = new employee(33,add);
		System.out.println("Employee 1 ID: 33");
		System.out.print("Enter name of employee: ");
		String name = input.nextLine();
		employee1.setterName(name);
		System.out.println("Employee 1 name: "+employee1.getterName());
		System.out.println("Employee 1 address: ");
		System.out.println(employee1.getterAddress().streetNumberGetter());
		System.out.println(employee1.getterAddress().cityGetter());
		System.out.println(employee1.getterAddress().countryGetter());
		
	}
}