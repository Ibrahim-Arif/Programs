import java.util.Scanner;
public class test {
	static String color;
	static float radius;
	static float height;

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.print("Enter color: ");
		color = input.nextLine();
		System.out.print("Enter radius: ");
		radius = input.nextFloat();
		System.out.print("Enter height: ");
		height = input.nextFloat();
		
		System.out.println("color is "+color);
		System.out.println("radius is "+radius);
		System.out.println("height is "+height);
		System.out.println();
		
		circle circle = new circle(radius,color);
		cylinder cylinder = new cylinder(height,radius);
		circle.Circle();
		cylinder.calculateVolume();
		
	}
}
