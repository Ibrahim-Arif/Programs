public class Address {
	private String streetAddress;
	private String town;
	private String city;
	private String country;
	private PhoneNumber phoneNumber;
	
	public Address(String streetAddress, String town, String city, String country, PhoneNumber phoneNumber) {
		super();
		this.streetAddress = streetAddress;
		this.town = town;
		this.city = city;
		this.country = country;
		this.phoneNumber = phoneNumber;
	}
	
	public String getStreetAddress() {
		return streetAddress;
	}
	public void setStreetAddress(String streetAddress) {
		this.streetAddress = streetAddress;
	}
	
	public String getTown() {
		return town;
	}
	public void setTown(String town) {
		this.town = town;
	}
	
	public String getCity() {
		return city;
	}
	public void setCity(String city) {
		this.city = city;
	}
	
	public String getCountry() {
		return country;
	}
	public void setCountry(String country) {
		this.country = country;
	}
	
	public PhoneNumber getPhoneNumber() {
		return phoneNumber;
	}
	public void setPhoneNumber(PhoneNumber phoneNumber) {
		this.phoneNumber = phoneNumber;
	}
}
