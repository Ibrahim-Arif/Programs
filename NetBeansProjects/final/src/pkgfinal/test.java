
package pkgfinal;

import java.util.logging.Level;
import java.util.logging.Logger;

public class test {
    public static void main(String[] args) {
        BankAccount ba = new BankAccount(1);
        
        try {
            System.out.println("Depositing Rs 500\n");
            ba.deposit(500);
            
            System.out.println("Current balance: Rs "+ba.getBalance());
            System.out.println("Withdrawing Rs 100");
            
            ba.widthdraw(100);
            
            System.out.println("Current balance: "+ba.getBalance());
            System.out.println("Withdrawing Rs 600");
            
            ba.widthdraw(600);
            
        } catch (InsufficientFundsException ex) {
            System.out.println("Sorry but you are short of Rs 200");
        }
    }
}
