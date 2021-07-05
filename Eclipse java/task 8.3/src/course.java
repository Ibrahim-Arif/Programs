public class course {
	private String courseCode;
	private String courseTitle;
	
	public course(String courseCode, String courseTitle) {
		super();
		this.courseCode = courseCode;
		this.courseTitle = courseTitle;
	}
	
	public void setterCC(String CC) {
		courseCode = CC;
	}
	public String getterCC() {
		return courseCode;
	}
	
	public void setterCT(String CT) {
		courseTitle = CT;
	}
	public String getterCT() {
		return courseTitle;
	}	
}