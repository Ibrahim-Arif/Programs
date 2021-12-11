public class Address {
	private String street;
	private String town;
	private  String city;
	
	public Address(String street, String town, String city) {
		super();
		this.street = street;
		this.town = town;
		this.city = city;
	}
	public Address() {
	}

	public String getStreet() {
		return street;
	}
	public String getTown() {
		return town;
	}
	public String getCity() {
		return city;
	}
}