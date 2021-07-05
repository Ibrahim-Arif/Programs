import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		getdata getdata = new getdata();
		sum sum = new sum();
		subt subt = new subt();
		multi multi = new multi();
		div div = new div();
		
		int first, second;
		System.out.print("Enter 1st number: ");
		first = input.nextInt();
		System.out.print("Enter 2nd number: ");
		second = input.nextInt();
		
		getdata.get(first,second);
		subt.sub();
		sum.summ();
		multi.multiply();
		div.divi();
	}
}
