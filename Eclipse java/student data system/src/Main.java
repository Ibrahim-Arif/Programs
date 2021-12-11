import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		newData newdata = new newData();
		viewData viewdata = new viewData();
		editingData editingdata = new editingData();
		searchData searchdata = new searchData();
		
		int choice;
		System.out.println("1 for entering new student.");
		System.out.println("2 for viewing students data.");
		System.out.println("3 for editing data.");
		System.out.println("4 for searching data.");
		
		do {
			System.out.println();
			System.out.print("Enter your choice: ");
			choice = input.nextInt();
			if(choice == 1) {
				newdata.data();
			}else if(choice == 2) {
				viewdata.view();
			}else if(choice == 3) {
				editingdata.editing();
			}else if(choice ==4) {
				searchdata.search();
			}else if(choice != -1)
				System.out.println("Wrong choice.");
		}while(choice != -1);
		
		System.out.println("The End");
	}

}
