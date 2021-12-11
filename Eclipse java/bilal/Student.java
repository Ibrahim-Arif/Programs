

public class Student{

	
	public Address address[];
	
	public String name;
	public int roll;
	
	public Student(){
		
	}
	
	public Student(int roll,String name,Address[] address){
	this.roll = roll;
	this.name = name;
	this.address = address;
		
		
	}

	public String getName(){
		return name;
	}
	
	public int getRoll(){
		
		return roll;
		
	}
	
	public Address[] getAddress(){
		
		return address;
	}
	
}