import java.util.*;
import java.util.regex.*;

public class CreateTableChecker {
    public static void main(String[] args) {
        // scanner object for user input
        Scanner scanner = new Scanner(System.in);
        String before, after;
        
        // taking user input
        System.out.println("Enter CREATE TABLE command: ");
        before = scanner.nextLine();
        
        // handling last column comma ',' 
        // - regex will expect a comma at the end of each column, 
        // - so if user hasn't added it program will handle it for them
        int indexOfLastBracket = before.lastIndexOf(")");
        after = before.substring(0, indexOfLastBracket) + ',' + before.substring(indexOfLastBracket);
       
        // regex for variable/table name
        String varName = "[a-zA-Z_][a-zA-Z_$0-9]*";
        // data types with length parameter MUST defined
        String datatypesMustParams = "(?:(VARCHAR *\\( *[$0-9]+ *\\))|(VARBINARY *\\( *[$0-9]+ *\\)))";
        // data types with and without length parameter. 
        String datatypesMustNotParams = "(?:(CHAR)|(BINARY)|(TINYBLOB)|(TINYTEXT)|(TEXT)|(MEDIUMTEXT)|(BLOB)"
                + "|(MEDIUMBLOB)|(LONGTEXT)|(LONGBLOB)|(BIT)|(TINYINT)|(BOOL)|(BOOLEAN)|(SMALLINT)|(MEDIUMINT)"
                + "|(INT)|(YEAR)|(TIME)|(TIMESTAMP)|(DATETIME)|(INTEGER)|(BIGINT)|(FLOAT)|(DOUBLE)|(DECIMAL)|(DEC))";
        // choosing from both types of datatypes
        String type = "(?:("+ datatypesMustParams +")|("+ datatypesMustNotParams +"( *\\( *[$0-9]+ *\\))?)) *, *";
        
        // FINAL regex expression
        String exp = "^create *table *"+ varName +" *\\( *("+ varName +" +"+ type +")+? *\\) *;$";
        
        // compiling final regex
        Pattern p = Pattern.compile(exp, Pattern.CASE_INSENSITIVE);        
        // matching user input against regex
        Matcher m = p.matcher(after);
        // getting match result (boolean)
        boolean matchFound = m.matches();
        
        // printing output according to match result. 
        if(matchFound)
            System.out.println("\n=> Valid syntax \n");
        else
            System.out.println("\n=> Invalid syntax \n");
    }
}