public class employeeTest {

	public static void main(String[] args) {
		System.out.println("Employee count before instantiation: "+Employee.employeeCount());
		Employee obj1 = new Employee("ibrahim", "arif");
		Employee obj2 = new Employee("Burhan", "Arif");
		
		System.out.println("Employee count after instantiation: "+Employee.employeeCount());
	}
}