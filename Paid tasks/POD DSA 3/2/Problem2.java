import java.util.*;

public class Problem2 {    
    public static List<String> noDuplicates(List<String> list){
        List <String> result = new LinkedList<>();

        for(int i=0; i<list.size(); i++){
           if(!result.contains(list.get(i))){
               result.add(list.get(i));
           }
        }

        return result;
    }
    

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        List <String> list = new LinkedList<>();

        String temp = input.nextLine();
        String[] listSplit = temp.split(" ");

        for(int i=0; i < listSplit.length-1; i++){
            list.add(listSplit[i]);
        }

        System.out.println(list);
        System.out.println(noDuplicates(list));
    }
}