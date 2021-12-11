public class student {
	private Address address[] = new Address[2];
	public Address add;
	int i=0;
	
	public student(Address[] address) {
		super();
		this.address = address;
	}
	public student() {
	}
	
	public Address[] getAddress() {
		return address;
	}	
}