import java.util.*;

public class FruitBasket {
    protected ArrayList<Fruit> basket = new ArrayList<>();
    
    public FruitBasket(){}
    
    public void addFruit(Fruit fruitToAdd){
        this.basket.add(fruitToAdd);
    }
    
    public String toString(){
        String basketContents = "FRUIT BASKET:\n";
        for(Fruit fruit: basket){
            basketContents += fruit.toString() + "\n";    
        }
        return basketContents;
    }
}
