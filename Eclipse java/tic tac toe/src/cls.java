import java.io.IOException;
public class cls {
	public void cls1() {
		try {
			new ProcessBuilder("cmd","/c","cls").inheritIO().start().waitFor();	
		}
		catch(Exception e){
			System.out.println(e);
		}
	}
}
