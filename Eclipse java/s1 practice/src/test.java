import java.util.*;

public class test{
	static int sizeC;
	static int sizeS;
	
	public static void main(String[] arg){
		Scanner input = new Scanner(System.in);
		student s1 = new student();
		phoneNumber ph= new phoneNumber(0,0,0);
		address add1 = new address("","","","",ph);
		address add;
		student std[];
		course crs[] = new course[0];
		
		int i, j;
		int countryCode;
		int cityCode;
		int lineNumber;
		String courseCode;
		String courseTitle;
		String street;
		String town;
		String city;
		String country;
		String name;
		String email;
		String cnic;
		
		/*System.out.print("Enter number of student: ");
		sizeS = input.nextInt();
		std = new student[sizeS];
		
		for(i=0; i<sizeS; i++){
			System.out.printf("\nEnter name of student %d: ",i);
			name = input.nextLine();
			name = input.nextLine();
			System.out.printf("Enter email of student %d: ",i);
			email = input.nextLine();
			System.out.printf("Enter cnic of student %d: ",i);
			cnic = input.nextLine();
			
			System.out.printf("\nEnter country code of student %d: ",i);
			countryCode = input.nextInt();
			System.out.printf("Enter city code of student %d: ",i);
			cityCode = input.nextInt();
			System.out.printf("Enter line number of student %d: ",i);
			lineNumber = input.nextInt();
			ph = new phoneNumber(countryCode, cityCode, lineNumber);
			
			System.out.printf("\nEnter Street number of student %d: ",i);
			street = input.nextLine();
			street = input.nextLine();
			System.out.printf("Enter town of student %d: ",i);
			town = input.nextLine();
			System.out.printf("Enter city of student %d: ",i);
			city = input.nextLine();
			System.out.printf("Enter country of student %d: ",i);
			country = input.nextLine();
			
			add = new address(street, town, city, country, ph);
			
			System.out.printf("\nEnter numbers of subjects assigned to student %d: ",i);
			sizeC = input.nextInt();
			crs = new course[sizeC];
			
			for(j=0; j<sizeC; j++){				
				System.out.printf("\nEnter course code of subject %d: ",j);
				courseCode = input.nextLine();
				courseCode = input.nextLine(); 
				System.out.printf("Enter course title of subject %d: ",j);
				courseTitle = input.nextLine();
				c1.setterCorseCode(courseCode);
				c1.setterCorseCode(courseTitle);
			
				crs[j] = new course(courseCode, courseTitle);
			}
			std[i] = new student(name, email, cnic, crs, add);
			System.out.println();
			crs = null;
		}*/
		i=0;
		System.out.printf("\nEnter country code of student %d: ",0);
		countryCode = input.nextInt();
		System.out.printf("Enter city code of student %d: ",0);
		cityCode = input.nextInt();
		System.out.printf("Enter line number of student %d: ",0);
		lineNumber = input.nextInt();
		add1.getterPhone().setterCountryCode(countryCode);
		add1.getterPhone().setterCityCode(cityCode);
		add1.getterPhone().setterLineNumber(lineNumber);
		
		System.out.println(add1.getterPhone().getterCountryCode());
		System.out.println(add1.getterPhone().getterCityCode());
		System.out.println(add1.getterPhone().getterLineNumber());
		
		System.out.println("\n------------------------------------------------");
		
		/*for(i=0; i<sizeS; i++) {
			s1 = std[i];
			crs = s1.getterCrs();
			
			System.out.printf("\nName of %d is %s",i,s1.getterName());
			System.out.printf("\nCNIC of %d is %s",i,s1.getterCnic());
			System.out.printf("\nEmail of %d is %s",i,s1.getterEmail());
			System.out.printf("\n\nphone number: %s-%s-%s",s1.getAdd().getterPhone().getterCountryCode(),s1.getAdd().getterPhone().getterCityCode(),s1.getAdd().getterPhone().getterLineNumber()); 
			System.out.printf("\n\nStreet of %d is %s",i,s1.getAdd().getterStreet());
			System.out.printf("\nTown of %d is %s",i,s1.getAdd().getterTown());
			System.out.printf("\nCity of %d is %s",i,s1.getAdd().getterCity());
			System.out.printf("\nCountry of %d is %s",i,s1.getAdd().getterCountry());
			
			for(j=0; j<sizeC; j++) {
				System.out.printf("\n\ncourse code of %d subject %s",j,crs[j].getterCorseCode());
				System.out.printf("\ncourse title of %d subject %s",j,crs[j].getterCourseTitle());
			}
			System.out.println();
		}*/
	}
}