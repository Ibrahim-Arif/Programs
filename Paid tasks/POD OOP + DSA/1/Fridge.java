import java.util.*;

public class Fridge{
    protected Stack<String> topShelf = new Stack<String>();
    protected Stack<String> middleShelf = new Stack<String>();
    protected Stack<String> bottomShelf = new Stack<String>();

    public Fridge(){}
    
    public void addGroceries(String[] groceries, Stack<String> shelf){
        for(int i=0; i<groceries.length; i++){
            shelf.push(groceries[i]);
        }
    }
    
    public void getIngredient(String ingredient, Stack<String> shelf){
        Stack<String> temp = new Stack<String>();
        ingredient = ingredient.replaceAll("\\s+","");
        
        int size = shelf.size();
        for(int i=0; i<size; i++){
            String choosen = shelf.pop();
            choosen = choosen.replaceAll("\\s+","");
            
            if(ingredient.equalsIgnoreCase(choosen)){          
                int tempSize = temp.size();
                for(int j=0; j<tempSize; j++){
                    shelf.push(temp.pop());
                }
                break;
            }else{
                temp.push(choosen);
            }
        }
    }

    public String toString(){
        String fridgeContents = "--- FRIDGE CONTENTS ---\n"
                + "Top Shelf:" + topShelf + "\n"
                + "Middle Shelf:" + middleShelf + "\n"
                + "Bottom Shelf:" + bottomShelf + "\n";
        return fridgeContents;
    }
}