public class StringStack {
    private StringDLL stack = null;
    
    public StringStack(){
        stack = new StringDLL();
    }
    
    public void push(String data){
        stack.addFirst(data);
    }
    
    public String pop(){
        return stack.remove(0);
    }
    
    public String peek(){
        return stack.getHead().data;
    }
}
