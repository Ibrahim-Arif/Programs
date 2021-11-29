import java.util.LinkedList;

public class Queue {
    LinkedList<String> battersName = new LinkedList<String>();
  
    public void add(String s) {
        battersName.add(s);
    }

	
  public String remove() {
      return battersName.remove(0);
  }
}