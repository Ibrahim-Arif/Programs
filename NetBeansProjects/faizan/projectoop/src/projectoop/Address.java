package projectoop;

public class Address {
	private String HouseNo;
	private String City;
	private String Country;
	
	public Address() {	
	}
	public Address(String houseNo, String city, String country) {
		HouseNo = houseNo;
		City = city;
		Country = country;
	}
	public String getHouseNo() {
		return HouseNo;
	}
	public void setHouseNo(String houseNo) {
		HouseNo = houseNo;
	}
	public String getCity() {
		return City;
	}
	public void setCity(String city) {
		City = city;
	}
	public String getCountry() {
		return Country;
	}
	public void setCountry(String country) {
		Country = country;
	}	
}