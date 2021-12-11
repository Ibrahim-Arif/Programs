import java.util.Scanner;

public class StudentTest{
		
		
		
		public static void main(String args[]){
			
		
		
		int size = 0 ,size1 = 0,i = 0,loop = 0;
		String name = "";
		int roll = 0;
		Student stu = new Student();
		Scanner input = new Scanner(System.in);
		Address adr[];
		String Street,City,Country;
	
		
		
	
		System.out.println("Enter No of Student");	
		size = input.nextInt();
		Student stus[] = new Student[size];		
		
		for(i = 0;i<size;i++){
			
			System.out.println("Enter name of Student"+(1+i));	
			name = input.nextLine();
			name = input.nextLine();
			System.out.println("Enter roll");
			roll = input.nextInt();
	
			System.out.println("Enter the no of addrees Student have:");
			size1 = input.nextInt();
			adr = new Address[size1];
			
			for(int j = 0; j < size1 ;j++){
				
				System.out.println("Enter the Street:");
				
				Street = input.nextLine();
				Street = input.nextLine();
		
				
				System.out.println("Enter the City");
				
				City = input.nextLine();
				
				
				System.out.println("Enter the Country");
				
				Country = input.nextLine();
			
				
				adr[j] = new Address(Street,City,Country);
				
			}
			
			 stus[i] = new Student(roll,name,adr);
		}
		
		for(i = 0;i<size;i++){
			
			stu = stus[i];
			
			adr = stu.getAddress();
			
			System.out.println("Address Size: "+ adr.length);
			
			System.out.println("Name: "+stu.getName());
			System.out.println("Roll: "+stu.getRoll());
		
			
			for(int j = 0; j < size1 ;j++){
				
				
				
				System.out.println("Address: ");
			
				
				System.out.println("Street: " + adr[j].getStreet());
			
				System.out.println("City: " + adr[j].getCity());
			
				System.out.println("Country: " + adr[j].getCountry());
				
		
						
			}
		
			System.out.println();
		
		
		}
	
	
	}
	
	
	
	
	
}