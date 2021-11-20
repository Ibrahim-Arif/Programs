import java.util.*;

public class FruitBasket {
    private ArrayList<Fruit> basket;
    
    public FruitBasket(){
        this.basket = new ArrayList<>();
    }
    
    public void addFruit(Fruit newFruit){
        this.basket.add(newFruit);
    }
    
    public String toString(){
        String basketContents = "FRUIT BASKET:\n";
        for(Fruit fruit : this.basket){
             basketContents += fruit.toString() + "\n";
        }
        return basketContents;
    }
}
