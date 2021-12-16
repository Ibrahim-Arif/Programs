import java.util.*;

public class Problem1 {    
    public static List<String> shares(List<String> firstList, List<String> secondList){
        List <String> result = new ArrayList<>();

        for(int i=0; i<firstList.size(); i++){
            if(secondList.contains(firstList.get(i))){
                if(!result.contains(firstList.get(i))){
                    result.add(firstList.get(i));
                }
            }
        }

        return result;
    }
    

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        //DO NOT MODIFY THE VARIABLE TYPE
        List <String> firstList = new ArrayList<>(); //LinkedList or ArrayList or Vector?
        List <String> secondList = new ArrayList<>(); //LinkedList or ArrayList or Vector?

        String first = input.nextLine();
        String[] firstSplits = first.split(" ");

        for(int i=0; i < firstSplits.length-1; i++){
            firstList.add(firstSplits[i]);
        }

        String second = input.nextLine();
        String[] secondSplits = second.split(" ");

        for(int i=0; i < secondSplits.length-1; i++){
            secondList.add(secondSplits[i]);
        }

        System.out.println(firstList);
        System.out.println(secondList);

        System.out.println(shares(firstList, secondList));
    }
}