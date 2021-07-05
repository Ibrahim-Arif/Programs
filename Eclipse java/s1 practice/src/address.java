public class address{
	private String street;
	private String town;
	private String city;
	private String country;
	
	private phoneNumber phone;
	
	public address(String s, String t, String c, String co, phoneNumber phone){
		street = s;
		town = t;
		city = c;
		country = co;
		this.phone = phone;
	}
	
	public void setterStreet(String s){
		street = s;
	}
	public String getterStreet(){
		return street;
	}
	
	public void setterTown(String t){
		town = t;
	}
	public String getterTown(){
		return town;
	}
	
	public void setterCity(String c){
		city = c;
	}
	public String getterCity(){
		return city;
	}
	
	public void setterCountry(String c){
		country = c;
	}
	public String getterCountry(){
		return country;
	}
	
	public void setterPhone(phoneNumber p){
		phone = p;
	}
	public phoneNumber getterPhone(){
		return phone;
	}
}