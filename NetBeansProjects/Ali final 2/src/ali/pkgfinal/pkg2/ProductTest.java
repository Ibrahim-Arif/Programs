package ali.pkgfinal.pkg2;
import java.util.*;

public class ProductTest {
    
    static final double billTotal(ArrayList<Product> p){
        double total = 0;
        p.forEach((n -> total += n.getPrice());
        return total;
    }
    
    public static void main(String[] args) {  

       ArrayList <Product> bill = new ArrayList<Product>();
       bill.add(new WeightedProduct(1, "Rice",3.00));
       bill.add(new WeightedProduct(10,"Pens",4.5));
       bill.add(new CountedProduct(10,"Pens",20));
       System.out.println(billTotal(bill));
       ArrayList <CountedProduct> cp = new ArrayList<CountedProduct>();
       cp.add(new CountedProduct(10,"Pens",4.5));
       cp.add(new CountedProduct(10,"Pens",20));
       System.out.println(billTotal(cp));
       ArrayList <WeightedProduct> wp = new ArrayList<WeightedProduct>();
       wp.add(new WeightedProduct(1,"Rice",3.00));
       System.out.println(billTotal(wp));

   }
}