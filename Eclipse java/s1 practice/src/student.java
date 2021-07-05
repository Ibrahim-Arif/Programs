public class student{
	private String name;
	private String email;
	private String cnic;
	private course crs[];
	private address add;
	
	public student(String n, String e, String c, course crs[], address a){
		name = n;
		email = e;
		cnic = c;
		this.crs = crs;
		add = a;
	}
	public student(){
	}
	
	/*public phoneNumber getPhone() {
		return phone;
	}
	public void setPhone(phoneNumber phone) {
		this.phone = phone;
	}*/
	
	public address getAdd() {
		return add;
	}
	public void setAdd(address add) {
		this.add = add;
	}
	
	public void setterName(String n){
		name = n;
	}
	public String getterName(){
		return name;
	}
	
	public void setterEmail(String e){
		email = e;
	}
	public String getterEmail(){
		return email;
	}
	
	public void setterCnic(String c){
		cnic = c;
	}
	public String getterCnic(){
		return cnic;
	}
	
	public void setterCrs(course c[]){
		crs = c;
	}
	public course[] getterCrs(){
		return crs;
	}
}