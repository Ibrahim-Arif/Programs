public class Address{
	
	public String Street,City,Country;
	
	
	public Address(String Street,String City,String Country){
		this.Street = Street;
		this.City = City;
		this.Country = Country;
		
	}
	
	public void setStreet(String Street){
		this.Street = Street;
		
	}
	
	public void setCity(String City){
		this.City = City;
		
	}
	public void setCountry(String Country){
		
		this.Country = Country;
		
	
	}
	

	public String getStreet(){
		return this.Street;
	}
	
	public String getCity(){
		return this.City;
	}
	
	public String getCountry(){
		return this.Country;
	}

	
	
}