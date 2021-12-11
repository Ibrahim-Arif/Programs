
import java.awt.event.KeyListener;

public class Keys implements KeyListener{

    int speed = 10; 

    @OverRide
    public void KeyPressed(KeyEvent e){
        if(e.getKeyCode() == KeyEvent.VK_RIGHT){
            
            Panel.images.paintIcon(this,gk,427-speed,500);
            speed = speed + 10;
            Panel.repaint();
        }
    }
}