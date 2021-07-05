import java.util.*;

public class main {
    public static void main(String[] arg){
        Scanner input = new Scanner(System.in);
        
        ArrayList<Billing> payable = new ArrayList<Billing>();
        ArrayList<Medicine> m = new ArrayList<Medicine>();
        ArrayList<MedicalTest> mt = new ArrayList<MedicalTest>();
        
        m.add(new Medicine(1, "aspirine", 3, 20));
        m.add(new Medicine(2, "panadol", 6, 60));
        mt.add(new MedicalTest(1, "blood test", 1300));
        payable.add(new Billing(new Doctor("ibrahim", 1, 1000), new Patient("faizan", 201, "Stomach issue"), m, mt));
        
        
        m.add(new Medicine(3, "flagel", 1, 40));
        mt.add(new MedicalTest(2, "brain test", 5000));
        payable.add(new Billing(new Doctor("bilal", 2, 800), new Patient("ali", 202, "headache"), m, mt));
        payable.add(new Billing(new Doctor("burhan", 3, 1800), new Patient("arif", 202, "muscles issue"), m, mt));
        
        System.out.print("Enter bill guess: ");
        int guess = input.nextInt();
        
        for(Billing b: payable){
            if(b.getPaymentAmount() >= guess)
                System.out.println(b.toString());
        }
        
        Doctor doc[] = new Doctor[2];
        int i = 0;
        
        for(Billing b: payable){
            if(b.getDoc().getDocID() == 2)
                doc[i++] = b.getDoc();
        }
        
        for(int j=0; j<i; j++)
            System.out.println(doc[j].toString());
        
    }
}