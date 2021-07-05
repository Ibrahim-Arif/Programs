public class phoneNumber{
	private int countryCode;
	private int cityCode;
	private int lineNumber;
	
	public phoneNumber(int CC, int cC, int LN){
		countryCode = CC;
		cityCode = cC;
		lineNumber = LN;
	}
	
	public void setterCountryCode(int CC){
		countryCode = CC;
	}
	public int getterCountryCode(){
		return  countryCode;
	}
	
	public void setterCityCode(int cC){
		cityCode = cC;
	}
	public int getterCityCode(){
		return  cityCode;
	}
	
	public void setterLineNumber(int LN){
		lineNumber = LN;
	}
	public int getterLineNumber(){
		return  lineNumber;
	}
}