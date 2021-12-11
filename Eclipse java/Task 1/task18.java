public class task18{
	public static void main(String[] arg){
		int a = 10;
		int b = 64;
		int c = 876;
		int d = 48;
		int e = 53;		
		
		if(a > b && a > c && a > d && a > e){
			System.out.println(a+" is largest");
		} else if(b > a && b > c && b > d && b > e){
			System.out.println(b+" is largest");
		} else if(c > a && c > b && c > d && c > e){
			System.out.println(c+" is largest");
		} else if(d > a && d > c && d > b && d > e) {
			System.out.println(d+" is largest");
		} else if(e > a && e > c && e > d && e > b){
			System.out.println(e+" is largest");
		}
	}
}
		