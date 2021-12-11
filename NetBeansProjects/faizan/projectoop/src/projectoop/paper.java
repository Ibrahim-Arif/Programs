package projectoop;

public class paper {
	private String pname;
	private int duration;
	private int price;
	private String type;
	
//	public paper(String pn, int d, int p, String type) {
//            this.pname = pn;
//            this.duration = d;
//            this.price = p;
//            this.type = type;
//	}
        public paper(){
            
        }
	public String getPName() {
		return pname;
	}
	public void setPName(String name) {
		this.pname = name;
	}

	public int getDuration() {
		return duration;
	}
	public void setDuration(int duration) {
		this.duration = duration;
	}
	
	public int getPrice() {
		return price;
	}
	public void setPrice(int price) {
		this.price = price;
	}
	
	
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public void deal(){
            
        }
}