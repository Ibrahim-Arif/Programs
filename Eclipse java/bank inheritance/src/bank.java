import java.util.*;
import java.sql.*;

public class bank {
    static Scanner input = new Scanner(System.in);
    static ArrayList<account> acc = new ArrayList<>();
    static savingAccount sa;
    static currentAccount ca;
    static String n;
    static int an=0, search;
    static double b;
    static Connection con;
    
    public static void main(String[] arg){
        int choice=1;
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/bank","root","admin");
            System.out.println("Connected to Database. \n");
        } catch(Exception ex){
            System.out.println(ex);
        }        
        System.out.println("Enter 1 for opening saving account.");
        System.out.println("Enter 2 for opening current account.");
        System.out.println("Enter 3 for account details. ");
        System.out.println("0 for exit. ");
        
        while(choice != 0){
            try{
                System.out.print("\nwhat do you want: ");
                choice = input.nextInt();
                System.out.println();
            }catch(Exception e){
                System.out.println(e);
                break;
            }
            switch(choice){
                case 1:{
                    openAccount(choice);
                    an++;
                    break;
                }
                case 2:{
                    openAccount(choice);
                    an++;
                    break;
                }
                case 3:{
                    System.out.print("Enter account number: ");
                    search = input.nextInt();
                    display(search);
                    System.out.print("\n1 for edit: ");
                    choice = input.nextInt();
                    if(choice == 1){
                    edit(search);
                    } else{
                        System.out.println("invalid input !!!");
                        break;
                    }
                    break;
                }
                /*case 0:{
                    System.exit(an);
                }
                default:
                     System.out.println("invalid input !!!");*/
            }
        }
    }
    
    public static void openAccount(int c){
        //System.out.println("Your account number: "+an);
        System.out.print("Enter account number: ");
        an = input.nextInt();
        System.out.print("Enter username: ");
        n = input.nextLine();
        n = input.nextLine();
        System.out.print("Enter balance: ");
        b = input.nextDouble();
        try {
            Statement s = con.createStatement();
            s.execute("insert into savingaccounts values ("+an+",'"+n+"',"+b+")");
            s.close();
        } catch (SQLException ex) {
            System.out.println(ex);
        }
        /*if(c == 1){         
            sa = new savingAccount((0.1 * b), an, n, b);
            acc.add(an, sa);
        } else if(c == 2){
            ca = new currentAccount(an, n, b);   
            acc.add(ca);
        }*/
    }
    public static void display(int i){
        try {
            Statement s = con.createStatement();
            ResultSet rs = s.executeQuery("select * from savingaccounts where account_number="+i+" ");
            rs.next();
            System.out.println("Account number: "+rs.getInt("account_number"));
            System.out.println("Username: "+rs.getString("username"));
            System.out.println("Balance: "+rs.getDouble("balance"));
            s.close();
        } catch (SQLException ex) {
            System.out.println(ex);
        }
        /*if( acc.get(i) instanceof savingAccount){
            System.out.println("\n------------ Saving Account ------------");
        } else if(acc.get(i) instanceof currentAccount ){
            System.out.println("\n----------- Current Account ------------");
        }
        System.out.println(acc.get(i).toString());*/
    }
    public static void edit(int i){
        System.out.print("Enter new balance: ");
        b = input.nextDouble();
        try {
            Statement s = con.createStatement();
            s.execute("update savingaccounts set balance="+b+" where account_number="+i+" ");
            System.out.println("Balance updated successfully. ");
            s.close(); 
        } catch (SQLException ex) {
            System.out.println(ex);
        }
        //acc.get(i).setBalance(b);
        //System.out.println("Balance updated successfully. ");
    }
}