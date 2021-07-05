import java.util.Scanner;

public class test {
	public static void main(String[] args) {
		Address address[] = new Address[2];
		Scanner input = new Scanner(System.in);
		student s1;
		int i=0;
		String street, city, town;
		
		for(i=0; i<2; i++) {
			System.out.printf("Enter street of index %d: ",i);
			street = input.nextLine();
			System.out.printf("Enter town of town %d: ",i);
			town = input.nextLine();
			System.out.printf("Enter city of index %d: ",i);
			city = input.nextLine();
			
			address[i] = new Address(street, town, city);
		}
		s1 = new student(address);
		address = null;
		address = s1.getAddress();
		
		for(i=0; i<2; i++) {
			System.out.printf("\nStreet of %d: %s",i,address[i].getStreet());
			System.out.printf("\nTown of %d: %s", i,address[i].getTown());
			System.out.printf("\nCity of %d: %s",i, address[i].getCity());
		}
	}
}