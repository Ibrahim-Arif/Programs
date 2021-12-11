import java.util.Scanner;

public class P3Tests {
    public static void main(String[] args) {
        //This is your test case runner DO NOT CHANGE THIS CODE!
        //The StringDLLEvaluationSubClass is a hidden subclass of your StringDLL that implements a addFirst
        StringDLL list = new StringDLLEvaluationSubClass();

        Scanner kb = new Scanner(System.in);
        int numberOfNames = kb.nextInt();
        for (int i = 0; i < numberOfNames; i++) {
            int addPosition = kb.nextInt();
            String name = kb.next();
            System.out.printf("Adding %s in position %d\n",name,addPosition);
            list.add(addPosition,name);
            System.out.print("List: ");
            System.out.println(list.toString());
        }

        int removeCount = kb.nextInt();
        for (int i = 0; i < removeCount; i++) {
            int removePosition = kb.nextInt();
            System.out.printf("Removing from position: %d\n",removePosition);
            System.out.printf("Removed %s", list.remove(removePosition));
            System.out.print("List: ");
            System.out.println(list.toString());
        }


    }
}