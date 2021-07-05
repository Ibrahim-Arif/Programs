public class StaticMethods {
	public static void display()
    {
        System.out.printf("Non-static Method in class StaticMethods");
    }
    
    public static void show()
    {
        System.out.printf("Static Method in class StaticMethods");
        display();
    }

}
