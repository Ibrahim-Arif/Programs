import java.io.EOFException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.logging.Level;
import java.util.logging.Logger;


public class FileMatch {
    
    public static void read_file(String filename){
        try {
            ObjectInputStream ois = new ObjectInputStream(Files.newInputStream(Paths.get(filename)));
            while(true){
                System.out.println(ois.readObject().toString());
            }
            
        } catch (EOFException ex) {
            System.out.println("EOF");
        } catch (IOException ex) {
            Logger.getLogger(FileMatch.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(FileMatch.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void perform_match(){
        TransactionRecord tr;
        Account a;
        try {
            ObjectInputStream trans = new ObjectInputStream(Files.newInputStream(Paths.get("trans.txt")));
            ObjectInputStream oldmast = new ObjectInputStream(Files.newInputStream(Paths.get("oldmast.txt")));
            ObjectOutputStream  newmast = new ObjectOutputStream(Files.newOutputStream(Paths.get("newMast.txt")));
            ObjectOutputStream  log = new ObjectOutputStream(Files.newOutputStream(Paths.get("log.txt")));
            
            while(true){
                tr= (TransactionRecord) trans.readObject();
                a = (Account) oldmast.readObject();
                
                if(tr.getAccount_number() == a.getAccount()){
                    a.combine(tr);
                    newmast.writeObject(a);
                } 
                if(a.getAccount() != tr.getAccount_number()){
                    newmast.writeObject(a);
                    log.writeObject(tr);
                }
            }
            
        } catch (EOFException ex){
            System.out.println("EOF");
        } catch (IOException ex) {
            Logger.getLogger(FileMatch.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(FileMatch.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
