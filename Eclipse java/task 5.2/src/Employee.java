public class Employee {
	
	public Employee(){
		this(10,"ibrahim");
	}

	public Employee(int id, String name){
		this(20,"burhan",50000);
		System.out.println("ID: "+id);
		System.out.println("Name: "+name);
	}
	public Employee(int id, String name, int salary) {
		System.out.println("salary: "+salary);	
	}
}
