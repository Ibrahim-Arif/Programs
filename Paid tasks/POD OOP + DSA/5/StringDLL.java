public class StringDLL {
    protected Node head;
    protected Node tail;
    protected int size;

    public StringDLL(){
        head = null;
        tail = null;
        size = 0;
    }

    public Node getHead() {
        return head;
    }

    public Node getTail() {
        return tail;
    }
    
    
    public void addFirst(String data){
        Node toAdd = new Node(data);
        
        if(head == null) {
            head = tail = toAdd;  
        }  
        else {  
            toAdd.next = head;
            head.previous = toAdd;    
            head = toAdd;  
        }  
    }



    public String removeLast(){
      if(head == null || tail == null){
        return null;
      }
      
      Node last = new Node(tail.data);
      tail = tail.previous;
      return last.data;
    }
    
    public String reverseToString(){
    	//Complete your code here
        String output = "";
        
        Node temp = tail;
        while(temp != null){
            output += temp.data;
            output += " -> ";
            
            temp = temp.previous;
        }
   
        return output.substring(0, output.length() -4);
    }

    protected class Node{
        protected Node next;
        protected Node previous;
        protected String data;

        protected Node(String data){
            this.data = data;
            this.next = null;
            this.previous = null;
        }
    }
}
