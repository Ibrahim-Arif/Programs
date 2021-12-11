//This is your test case runner DO NOT CHANGE THIS CODE!
//The StringDLLEvaluationSubClass is a hidden subclass of your StringDLL that implements a toString

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class P1Tests {

    public static void main(String[] args) {
        //This is your test case runner DO NOT CHANGE THIS CODE!
        //The StringDLLEvaluationSubClass is a hidden subclass of your StringDLL that implements a toString
        StringDLL list = new StringDLLEvaluationSubClass();

        List<String> names = new LinkedList<>();
        Scanner kb = new Scanner(System.in);
        int numberOfNames = kb.nextInt();
        for (int i = 0; i < numberOfNames; i++) {
            names.add(kb.next());
        }

        System.out.println("Adding the following names with addFirst");
        for (String name : names) {
            System.out.println(name);
            list.addFirst(name);
        }

        System.out.printf("Current List: ");
        System.out.println(list);

        int removeRepetition = kb.nextInt();
        System.out.printf("Calling removeLast %d times\n",removeRepetition);
        for (int i = 0; i < removeRepetition; i++) {
            System.out.printf("Removed: %s\n",list.removeLast());
        }

        System.out.printf("Current List: ");
        System.out.println(list);


    }
}