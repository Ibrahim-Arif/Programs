import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class writeFiles {
    private static Scanner input;
    
    public static void clearFiles(){
        try {
            ObjectOutputStream oos = new ObjectOutputStream(Files.newOutputStream(Paths.get("trans.txt")));
            ObjectOutputStream oos2 = new ObjectOutputStream(Files.newOutputStream(Paths.get("oldmast.txt")));
            oos.close();
            oos2.close();
            
        } catch (IOException ex) {
            Logger.getLogger(writeFiles.class.getName()).log(Level.SEVERE, null, ex);
        }        
    }
    
    public static void writeTransFile(){
        input = new Scanner(System.in);
        try {
            ObjectOutputStream oos2 = new ObjectOutputStream(new FileOutputStream("trans.txt", true)) {
                protected void writeStreamHeader() throws IOException {
                    reset();
                }
            };
            System.out.print("Enter Account number, Amount: ");
            TransactionRecord tr = new TransactionRecord(input.nextInt(), input.nextDouble());
            oos2.writeObject(tr);
            oos2.close();
        } catch (IOException ex) {
            Logger.getLogger(writeFiles.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void writeMasterFile(){
       input = new Scanner(System.in);
        try {
            ObjectOutputStream oos2 = new ObjectOutputStream(new FileOutputStream("oldmast.txt", true)) {
                protected void writeStreamHeader() throws IOException {
                    reset();
                }
            };
            System.out.print("Enter Account, first name, last name, balance: ");
            Account a = new Account(input.nextInt(), input.next(), input.next(), input.nextDouble());
            oos2.writeObject(a);
            oos2.close();
        } catch (IOException ex) {
            Logger.getLogger(writeFiles.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
