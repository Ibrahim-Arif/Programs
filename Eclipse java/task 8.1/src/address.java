public class address {
	private String streetNumber;
	private String city;
	private String country;
	
	void streetNumberSetter(String SN) {
		streetNumber = SN;
	}
	String streetNumberGetter() {
		return streetNumber;
	}
	
	
	void citySetter(String C) {
		city = C;
	}
	String cityGetter() {
		return city;
	}
	
	
	void countrySetter(String C) {
		country = C;
	}
	String countryGetter() {
		return country;
	}
}
