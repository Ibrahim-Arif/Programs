import java.util.*;

public class SessionalTest{
	
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		
		Medicine med[];
		String name;
		double price;
		int size;
		Date d = new Date(21,5,2018);
		
		
		System.out.print("Enter number of medicines: ");
		size = input.nextInt();
		med = new Medicine[size];
		
		for(int i=0; i<size; i++){
		
			System.out.print("Enter name of med: ");
			name = input.nextLine();
			name = input.nextLine();
			System.out.print("Enter Price of med: ");
			price = input.nextDouble();
			
			med[i] = new  Medicine(name, price, d, d);
		}
		System.out.println("\n------Medicine Information-------\n");
		for(int i=0;i<size;i++){
			System.out.println("Medicine name: "+med[i].name);
			System.out.printf("Manufacture Date: %d-%d-%d\n",med[i].getMFD().getDay(),med[i].getMFD().getMonth(),med[i].getMFD().getYear());
			System.out.printf("Expiry Date: %d-%d-%d",med[i].getED().getDay(),med[i].getED().getMonth(),med[i].getED().getYear());
			med[i].calculatePrice();
			System.out.println();
		}
	}
}