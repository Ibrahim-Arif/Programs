import java.util.Scanner;

public class divide {

	public static void main(String[] args) {
		String d="abc", b="cde", c = "";
		c+=d;
		System.out.println(removeLastCharacter(c));
		Scanner input = new Scanner(System.in);
		String a ="ibrahim";
		System.out.printf("%s\b",a);
		System.out.println();
		
		float first, second;
		float result;
		
		System.out.print("Enter first number: ");
		first = input.nextInt();
		
		System.out.print("Enter second number: ");
		second = input.nextInt();
		
		result = first/second;
		System.out.print("\nResult: "+result);

		
	}
	public static String removeLastCharacter(String str) {
		   String result = null;
		   if ((str != null) && (str.length() > 0)) {
		      result = str.substring(0, str.length() - 1);
		   }
		   return result;
		}
	
}
