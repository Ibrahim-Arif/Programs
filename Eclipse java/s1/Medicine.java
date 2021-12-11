public class Medicine{
	public String name;
	public double price;
	private Date manufactureDate;
	private Date expiryDate;
	
	public Medicine(String n, double p, Date m, Date e){
		name = n;
		price = p;
		manufactureDate = m;
		expiryDate = e;
	}
	public Medicine(){
	}
	
	public void setMFD(Date m){
		manufactureDate = m;
	}
	public Date getMFD(){
		return manufactureDate;
	}
	
	public void setED(Date e){
		expiryDate = e;
	}
	public Date getED(){
		return expiryDate;
	}
	
	void calculatePrice(){
		double GT = price + (0.17 * price);
		System.out.println("\nPrice of medicine: "+GT);
	}
}