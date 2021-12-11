
public class studentTest {

	public static void main(String[] args) {
		student std = new student(33);
		course crs = new course("OOP-101","OOP");
		crs.setStd(std);
		
		System.out.println("ID: "+crs.getStd().id);
		System.out.println("Course title: "+crs.courseTitle); 
		
	}
}
