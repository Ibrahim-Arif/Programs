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
    
    public void display(){
        Node temp = head;
        
        while(temp != null){
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        
        System.out.println("");
    }
    
    public void add(int position, String data){
	if(position == 0){
            this.addFirst(data);
            return;
        }
        
        Node newNode = new Node(data);
        Node target = new Node(head.data);
        target = head;
        
        for(int i=0; i<position; i++) {
            if(target != null){
                target = target.next;
            }
        }
        
        if(target != null){
            newNode.next = target.next;
            newNode.previous = target;
            target.next = newNode;  

            if(newNode.next != null){
                newNode.next.previous = newNode;
            }   
        }
    }
    
    public String remove(int position) {
        Node deleted = new Node("");
        
    	if (position == 0 && head != null) { 
            Node temp = head;
            head = head.next;
            
            if (head != null){
                head.previous = null;
            }
    
	    return temp.data;

        } else {
            Node target = new Node(head.data);
            target = head;

            for(int i=0; i<position-1; i++) {
                if(target != null){
                    target = target.next;
                }
            }
            
            if(target != null && target.next != null) {
                deleted = target.next;
                target.next = target.next.next; 
                if(target.next != null && target.next.next != null){
                    target.next.next.previous = target.next;  
                }
            }
        }
            
        return deleted.data;
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
