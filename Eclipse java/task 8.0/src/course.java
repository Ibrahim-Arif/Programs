public class course {
	public String courseCode;
	public String courseTitle;
	private student std;
	
	course(String CC, String CT){
		courseCode = CC;
		courseTitle = CT;
	}
	void setStd(student std){
		this.std = std;
	}
	student getStd(){
		return std;
	}
}