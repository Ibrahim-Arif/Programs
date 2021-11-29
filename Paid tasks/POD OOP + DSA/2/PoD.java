import java.util.*;

public class PoD
{
    public static String GetName(int PLU, Map<Integer, String> HashMap){
        return HashMap.get(PLU);
    }

    public static double GetPrice(int PLU, Map<Integer, Double> HashMap){
        return HashMap.get(PLU);
    }
    
    public static void main( String [] args ) {
        Scanner in = new Scanner( System.in );
        Map<Integer, String> itemNames = new HashMap<Integer, String>();
        Map<Integer, Double> itemPrices = new HashMap<Integer, Double>();

        //Number of PLUs to expect
        int numberPLUs = Integer.valueOf(in.nextLine());

	//Populate the hashmaps
        for (int i=0; i<numberPLUs; i++){
            String line = in.nextLine();
            String[] groceryItem = line.split(",");
            int plu = Integer.valueOf(groceryItem[0]);
            String nameByPLU = groceryItem[1];
            Double priceByPLU = Double.valueOf(groceryItem[2]);

            itemNames.put(plu, nameByPLU);
            itemPrices.put(plu, priceByPLU);
        }


        while (in.hasNextInt()){
            int pluCode = in.nextInt();
            System.out.println("PLU# " + pluCode + ": " 
                    + GetName(pluCode,itemNames) + " ($" 
                    + GetPrice(pluCode, itemPrices) + ")");
        }

        in.close();
        System.out.print("END OF OUTPUT");
    }


}
