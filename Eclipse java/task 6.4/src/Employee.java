public class Employee {
	static int count=0;
	private String firstName;
	private String secondName;
	
	Employee(String f, String s){
		count++;
		firstName = f;
		secondName = s;
		
		System.out.println("First name: "+firstName);
	}
	static int employeeCount() {
		return count;
	}
}