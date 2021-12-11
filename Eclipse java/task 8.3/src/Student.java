public class Student {
	private String name;
	private String email;
	private String cnic;
	private course course1;
	private course course2;
	private Address address;

	public Student(String name, String email, Address address, course crs1, course crs2) {
		super();
		this.name = name;
		this.email = email;
		this.address = address;
		this.course1 = crs1;
		this.course2 = crs2;
	}

	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}

	public course getCourse1() {
		return course1;
	}
	public void setCourse1(course course1) {
		this.course1 = course1;
	}

	public course getCourse2() {
		return course2;
	}
	public void setCourse2(course course2) {
		this.course2 = course2;
	}

	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}

	public String getCnic() {
		return cnic;
	}
	public void setCnic(String cnic) {
		this.cnic = cnic;
	}

	public Address getAddress() {
		return address;
	}
	public void setAddress() {
		//address = add;
	}
}
