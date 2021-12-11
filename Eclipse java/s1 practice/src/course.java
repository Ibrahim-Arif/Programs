public class course{
	private String courseCode;
	private String courseTitle;
	
	public course(){
	}
	public course(String CC, String CT){
		courseCode = CC;
		courseTitle = CT;
	}
	
	public void setterCorseCode(String CC){
		courseCode = CC;
	}
	public String getterCorseCode(){
		return courseCode;
	}
	
	public void setterCourseTitle(String CT){
		courseTitle = CT;
	}
	public String getterCourseTitle(){
		return courseTitle;
	}
}