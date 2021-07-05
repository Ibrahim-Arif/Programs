package projectoop;

public class PersonData{
	private String Name;
	private Address Add;	
        private paper pa = new paper();
	
	public PersonData() {
	}
	public PersonData(String name, Address add) {
		Name = name;
		Add = add;
	}
	public String getName() {
		return Name;
	}
	public void setName(String name) {
		Name = name;
	}
	
	public Address getAdd() {
		return Add;
	}
	public void setAdd(Address add) {
		Add = add;
	}
        
        public paper getPaper(){
            return this.pa;
        }
        
        public void setPaper(String pn, int d, int p, String type){
            this.pa.setPName(pn);
            this.pa.setDuration(d);
            this.pa.setPrice(p);
            this.pa.setType(type);
        }
	public void deal() {
	}
}