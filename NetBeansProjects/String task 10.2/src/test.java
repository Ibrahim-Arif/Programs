import java.util.*;

public class test {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter phone no. in (***) ***-**** format: ");
        String number= input.nextLine();
        
        StringTokenizer st = new StringTokenizer(number," -");
        
        String area_code= st.nextToken();
        area_code= area_code.substring(1, 4);
        
        String first = st.nextToken();
        
        String last = st.nextToken();
        
        System.out.println("Area code: "+area_code );
        System.out.println("Phone number: "+first.concat(last) );
    }
}
