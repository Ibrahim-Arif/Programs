public class employee {
	private int employeeID;
	private String employeeName;
	private address employeeAddress;
	
	employee(int EID, address address){
		employeeID = EID;
		employeeAddress = address;
	}
	
	address getterAddress(){
		return employeeAddress;
	}
	
	void setterName(String name){
		employeeName = name;
	}
	String getterName(){
		return employeeName;
	}
	
	int getterID(){
		return employeeID;
	}	
	
}
