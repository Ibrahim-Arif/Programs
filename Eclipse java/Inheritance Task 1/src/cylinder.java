public class cylinder {
	private float height;
	private double volume;
	private float radius;
	
	cylinder(float x, float y){
		height = x;
		radius = y;
	}
	
	public void calculateVolume(){
		volume = 3.1415*(radius*radius)*height;
		System.out.println("Volume: "+volume);		
	}
}