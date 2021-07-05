import java.util.Scanner;
public class Main {
	static int count=0;

	public static void main(String[] args) {
		cls clrscr = new cls();
		Scanner input = new Scanner(System.in);
		output grid = new output();
		win win = new win();
		
		
		String name1, name2;
		
		System.out.print("Enter 1st player name: ");
		name1=input.nextLine();
		System.out.print("Enter 2nd player name: ");
		name2=input.nextLine();		
		System.out.println("player 1: "+name1+" has X");
		System.out.println("player 2: "+name2+" has O");
		System.out.println();
		
		do {
			count++;
			//clrscr.cls1();
			grid.grid();
			if(count%2==0)
				System.out.println(name2+"'s turn");
			else
				System.out.println(name1+"'s turn");
			gettingdata.input();
			//clrscr.cls1();
			System.out.println("----------------------");
			grid.grid();
			win.winner();
			if(win.flag==1)
				System.out.print(name1+" IS WINNER.");
			else if(win.flag==2)
				System.out.print(name2+" IS WINNER.");
			else if(win.flag==3)
				System.out.print("Match Tied");
		}while(win.flag == 0);		
		}
	}