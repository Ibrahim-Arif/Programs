public class PhoneNumber {
	private int countryCode;
	private int cityCode;
	private int lineNumber;
	
	public PhoneNumber(int countryCode, int cityCode, int lineNumber) {
		super();
		this.countryCode = countryCode;
		this.cityCode = cityCode;
		this.lineNumber = lineNumber;
	}
	
	public int getCountryCode() {
		return countryCode;
	}
	public void setCountryCode(int countryCode) {
		this.countryCode = countryCode;
	}
	

	public int getCityCode() {
		return cityCode;
	}
	public void setCityCode(int cityCode) {
		this.cityCode = cityCode;
	}
	
	public int getLineNumber() {
		return lineNumber;
	}
	public void setLineNumber(int lineNumber) {
		this.lineNumber = lineNumber;
	}	
}
