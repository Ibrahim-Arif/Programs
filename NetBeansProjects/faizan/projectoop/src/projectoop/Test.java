package projectoop;

import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner str = new Scanner(System.in);
		Scanner in = new Scanner(System.in);
		Scanner doble = new Scanner(System.in);
		
		int choice,choice1,price=0,duration=0;
		String paper="",Company="";
		
		System.out.println("Online Newspaper application");
		System.out.print("Enter Name : ");
		String Name = str.nextLine();
		System.out.print("Enter House Address : ");
		String Add = str.nextLine();
		System.out.print("Enter City : ");
		String City = str.nextLine();
		System.out.print("Enter Country : ");
		String Country = str.nextLine();
		
		Address A1 = new Address(Add,City,Country);
		PersonData P1 = new PersonData(Name,A1);
		
		System.out.println("Choice Paper Category");
		System.out.println("1 for Newspaper");
		System.out.println("2 for Magzine");
		System.out.println("3 for both");
		System.out.print("Enter Choice : ");
		choice = in.nextInt();
		if(choice == 1) {
			System.out.print("Enter Company Name : ");
			Company = str.nextLine();
			
			System.out.println("Select a Deal");
			System.out.println("1: For 30 days Price 1000 Newspaper only");
			System.out.println("2: For 15 days Price 500 Newspaper only");
			System.out.print("Enter Choice : ");
			choice1 = in.nextInt();
			paper = "Newspaper Only";	
			if(choice1 == 1) {
				price = 1000;
				duration = 30;
			}else if(choice1 == 2) {
				price = 500;
				duration = 15;
			}
		}else if(choice == 2) {
			System.out.print("Enter Company Name : ");
			Company = str.nextLine();
			System.out.println("Select a Deal");
			System.out.println("For 30 days Price 1000 Magzine only Press 1");
			System.out.println("For 15 days Price 500 Magzine only Press 2");
			System.out.print("Enter Choice : ");
			choice1 = in.nextInt();
			paper = "Magzine Only";
			if(choice1 == 1) {
				price = 1000;
				duration = 30;
			}else if(choice1 == 2) {
				price = 500;
				duration = 15;
			}
		}else if(choice == 3) {
			System.out.print("Enter Company Name : ");
			Company = str.nextLine();
			System.out.println("Select a Deal");
			System.out.println("For 30 days Price 1800 (Newspaper + Magzine) Press 1");
			System.out.println("For 15 days Price 900 (Newspaper + Magzine) Press 2");
			System.out.print("Enter Choice : ");
			choice1 = in.nextInt();
			paper = "Newspaper and Magzine";
			if(choice1 == 1) {
				price = 1800;
				duration = 30;
			}else if(choice1 == 2) {
				price = 900;
				duration = 15;
			}
		}
                P1.setPaper(Company, duration, price, paper);
                write_new_costumor(P1);
//
//		System.out.println("Name : "+P1.getName());
//		System.out.println("Address : "+P1.getAdd().getHouseNo()+" "+P1.getAdd().getCity()+" "+P1.getAdd().getCountry() );
//		System.out.println("Newspaper Name : "+P1.getPaper().getPName());
//		System.out.println("Category : "+P1.getPaper().getType());
//		System.out.println("Price : "+P1.getPaper().getPrice()+" Rs");
//		System.out.println("Duration "+P1.getPaper().getDuration()+" Days");
		
		
	}
        
        public static void write_new_costumor(PersonData pd ){
            FileWriter f = null;
            try {
                f = new FileWriter("costumors.txt", true);
                Formatter output = new Formatter(f);
                output.format("Name: %s \nAddress: %s %s, %s \nPaper detail: %s %s %d %d\n\n", pd.getName()
                                                       , pd.getAdd().getHouseNo()
                                                       , pd.getAdd().getCity()
                                                       , pd.getAdd().getCountry()
                                                       , pd.getPaper().getPName()
                                                       , pd.getPaper().getType()
                                                       , pd.getPaper().getPrice()
                                                       , pd.getPaper().getDuration()
                );
                if(output != null)
                    output.close();
                System.out.println("\nDATA SAVED, Successfully.");
                
            } catch (IOException ex) {
                Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
            } finally {
                try {
                    f.close();
                } catch (IOException ex) {
                    Logger.getLogger(Test.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        }
}
