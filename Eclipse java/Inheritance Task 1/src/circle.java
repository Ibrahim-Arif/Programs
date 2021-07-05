public class circle {
	private String color;
	public float radius;
	public float height;
	private double area;
	
	circle(float y, String x){
		color = x;
		radius = y;
	}
	public void Circle(){
		area = (3.1415 * (radius*radius));
		System.out.println("Area: "+area);		
	}
}