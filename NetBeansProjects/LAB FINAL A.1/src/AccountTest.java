import java.util.*;
public class AccountTest {
    private static int choice;
    private static Scanner input = new Scanner(System.in);
    private static Account acc[] = new Account[10];
    
    public static void main(String[] args) {
        int i=0;
        while(true){
            System.out.println( "\n1. Add Current Account \n" +
                                "2. Add Saving Account\n" +
                                "3. Deposit Money\n" +
                                "4. Withdraw Money\n" +
                                "5. Check Balance\n" +
                                "6. Exit");

            System.out.print("Enter your choice: ");
            choice = input.nextInt();

            switch(choice){
                case 1:{
                    acc[i] = take_input(choice);
//                    take_input(choice);
                    i++;
                    break;
                }
                case 2:{
                    acc[i] = take_input(choice);
                    i++;
                    break;
                }
                case 3:{
                    System.out.print("Enter account number: ");
                    long an = input.nextLong();
                    DWC(an, choice);
                    break;
                }
                case 4:{
                    System.out.print("Enter account number: ");
                    long an = input.nextLong();
                    DWC(an, choice);
                    break;
                }
                case 5:{
                    System.out.print("Enter account number: ");
                    long an = input.nextLong();
                    DWC(an, choice);
                    break;
                }
                case 6:{
                    System.exit(0);
                }
            }       
        }
    }
    
    
    public static Account take_input(int choice){
        System.out.print("Enter CNIC: ");
        String cnic = input.next();
        
        System.out.print("Account number: ");
        long an = input.nextLong();
        
        System.out.print("Account title: ");
        String at = input.next();
        
        System.out.print("Balance: ");
        double balance = input.nextDouble();
        
        if(choice == 1){
            System.out.print("Service fee rate: ");
            float sfr = input.nextFloat();
            currentAccount ca = new currentAccount();
            return ca.addAccount(cnic, an, at, balance, sfr);
            
        }else if(choice == 2){
            System.out.print("Monthly interest rate: ");
            float mir = input.nextFloat();
            savingAccount sa = new savingAccount();
            return sa.addAccount(cnic, an, at, balance, mir);
        }
        return null;
    } 
    
    public static void DWC(long an, int choice){
        boolean found = false;
        try{
            for(Account a: acc){
                if(a.accountNumber == an){
                    if(a instanceof currentAccount){
                        currentAccount ca = (currentAccount) a;
                        if(choice == 3){
                            System.out.print("Enter ammount to deposit: ");
                            double am = input.nextDouble();
                            ca.deposit(am);
                            found = true;

                        }else if(choice == 4){
                            System.out.print("Enter ammount to Withdraw: ");
                            double wd = input.nextDouble();
                            ca.withDraw(wd);
                            found = true;

                        }else if(choice == 5){
                            ca.checkBalance();
                            found = true;
                        }
                    }
                    else if(a instanceof savingAccount){
                        savingAccount sa = (savingAccount) a;
                        if(choice == 3){
                            System.out.print("Enter ammount to deposit: ");
                            double am = input.nextDouble();
                            sa.deposit(am);
                            found = true;

                        }else if(choice == 4){
                            System.out.print("Enter ammount to Withdraw: ");
                            double wd = input.nextDouble();
                            sa.withDraw(wd);
                            found = true;

                        }else if(choice == 5){
                            sa.checkBalance();
                            found = true;
                        }
                    }

                }

            }
        }catch(NullPointerException e){
         }
        if(!found)
            System.out.println(an+" NOT FOUND!");
    } 
}