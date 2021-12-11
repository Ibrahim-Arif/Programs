import javax.swing.*;
import java.awt.*;

class Car extends JFrame {
        
        Panel p = new Panel();

        public Car(){
                
                this.setTitle("Rectangle");
                this.setSize(850,650);
                this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                Dimension expectedDimension = new Dimension(850, 650);

                p.setPreferredSize(expectedDimension);
                p.setMaximumSize(expectedDimension);
                p.setMinimumSize(expectedDimension);
        
                Box box = new Box(BoxLayout.Y_AXIS);
        
                box.add(Box.createVerticalGlue());
                box.add(p);     
                box.add(Box.createVerticalGlue());

                this.add(box);
                this.setVisible(true);
                
        }
        public static void main(String args[]) {
                
                new Car();
                
        }
}