import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Panel extends JPanel implements ActionListener, KeyListener{

    Timer t = new Timer(300,this); // timer to delay animation
    ImageIcon[] car1images = new ImageIcon[16];
    int speedx = 0;
    int x = 427 ,y = 500; // car 1 coordinates    
    int imagechanger = 0;
    //------------------//
    ImageIcon[] car2images = new ImageIcon[17];
    int speedy = 0; 
    int x1 = 427 ,y1 = 550; // car 2 coordinates
    int imagechanger1 = 0;
    //------------------//
    int n = 0, k =0;
    int distance = 100;

    public Panel(){
        
       
        t.start();
        addKeyListener(this); // add Key Listener to java
        setFocusable(true);   // Enable Key Listener 
        setFocusTraversalKeysEnabled(false); //Turns extra keys unavaliable     
        for(int i = 0 ;i <= 15; i++){
            //importing files
            car1images[i] = new ImageIcon("images/car1images/sprite"+(i+1)+".jpg"); 
           // car2images[i] = new ImageIcon("images/car1sprite"+(i+1)+".jpg");
        }     
    }
    
    @Override
    public void actionPerformed(ActionEvent e){

         
       
      
        car1_coordination();
       // car2_coordination();

        // limiting speed

        //--------------------
        
        if(x < 50 ){
            x = 50;
        }
        if(y < 100){
            y = 100;
        }
        if(x > 750){
            x = 750;
        }
        if(y > 550){
            y = 550;
        }
        //--------------------

        if(x1 < 50 ){
            x1 = 50;
        }
        if(y1 < 100){
            y1 = 100;
        }
        if(x1 > 750){
            x1 = 750;
        }
        if(y1 > 550){
            y1 = 550;
        }
        //---------
        if(x == x1 ){
            x = x - 50;
        }
        if(y == y1){
            y = y -50;
        }
        if(x1 == x){
            x1 = x1 - 50;
        }
        if(y1 == y){
            y1 = y1 -50;
        }
        repaint();
    }
      
   
  
    @Override
    public void keyPressed(KeyEvent e){
            

            //-----------Car 1 Keys---------//
            if(e.getKeyCode() == KeyEvent.VK_UP){

                    speedx = speedx + 10;
                
               
                

            }

            if(e.getKeyCode() == KeyEvent.VK_DOWN){

                    speedx = speedx - 10;
                
               
               

            }
            
            if(e.getKeyCode() == KeyEvent.VK_LEFT){
                if(imagechanger == 15){
                    imagechanger = 0;
                } else {
                    imagechanger++;

                        n--;
                    
                    
                    
                }
                
                
            }
            
            if(e.getKeyCode() == KeyEvent.VK_RIGHT){
                if(imagechanger == 0){
                    imagechanger = 15;
                }else {
                    imagechanger--;

                        n++;
                                       
                   
                }
               

            }

            /*
            //------------Car 2 Keys-----------//
            if(e.getKeyCode() == KeyEvent.VK_W){

                    speedy = speedy + 10;
                
                
                

            }

            if(e.getKeyCode() == KeyEvent.VK_S){
 
                    speedy = speedy - 10;
                }
                
               

            }
            
            if(e.getKeyCode() == KeyEvent.VK_A){
                if(imagechanger1 > 15){
                    imagechanger1 = 0;
                } else {
                    imagechanger1++;
                    
                    k--;
                    
                }
                
                
            }

            
            
            if(e.getKeyCode() == KeyEvent.VK_D){
                if(imagechanger1 < 0){
                    imagechanger1 = 15;
                }else {
                    imagechanger1--;
                    k++;
                   
                }
               

            }*/
    }

    @Override
    public void keyTyped(KeyEvent e){
    }

    @Override
    public void keyReleased(KeyEvent e){
        imagechanger = imagechanger;
        imagechanger1 = imagechanger1;
        

    }
  
    public void paintComponent(Graphics gk){
        
        super.paintComponent(gk);
        

        Graphics2D g = (Graphics2D) gk;

        Color c1 = Color.green;  
        Color c2 = Color.black;
        Color c3 = Color.yellow; 
        Color c4 = Color.white;  

        g.setColor( c2 );
        g.fillRect(51, 101, 750, 500); //road  

        
        g.setColor( c1 );           
        g.fillRect( 150, 200, 550, 300 ); //grass  
         
        g.setColor( c2 );
        g.drawRect(50, 100, 750, 500);  // outer edge 
        g.drawRect(150, 200, 550, 300); // inner edge 
        
        
        g.setColor( c3 );  
        g.drawRect( 100, 150, 650, 400 ); // mid-lane marker 
        
         
        g.setColor( c4 ); 
        g.drawLine( 425, 500, 425, 600 ); // start line 
        car1images[imagechanger].paintIcon(this,gk,x,y);
       // car2images[imagechanger1].paintIcon(this,gk,x1,y1);

       
        
        
    }

    public void car1_coordination() {
        if(speedx > 100){
            speedx = 100;
        } else if( speedx < 0){
            speedx = 0;
        }else {
            speedx =  speedx + (distance/60);
        }
        if(n > 3){
            n =3;
        }
        if(n < -3){
            n = -3;
        } 

        switch(imagechanger){

            case 0 :
                x = x - speedx;
                y = y;
                break;

            case 1 :
                x = x - speedx;
                y = y - n;
                break;
            case 2 :
                x = x - speedx;
                y = y - n;
                
                break;

            case 3 : 
                x = x - n;; 
                y = y + speedx; 
                break;

            case 4:
                x = x ;
                y = y + speedx;
                break;

            case 5:

                x = x +speedx;
                y = y -n;
                break;


            case 6:
                x = x +speedx;
                y = y -2*n;
                break;

            case 7:
                x = x + speedx;
                y = y;
                break;   

                
            case 8:
                x = x + speedx;
                y = y - n;
                break;

            case 9:
                x = x + speedx;
                y = y  - n*2;           
                break;

            case 10:
                x = x + speedx;
                y = y  - n;
                break;

            case 11:
                x = x ;
                y = y - speedx;
                break;

            case 12:
                x = x - n*3;
                y = y - speedx;
                break;

            case 13:
                x = x - speedx;
                y = y - n*3;
                break;

            case 14:
                x = x - speedx;
                y = y - n*2;
                break;

        }
        /*
        if(x < 50 ){
            x = 50;
        }
        if(y < 100){
            y = 100;
        }
        if(x > 750){
            x = 750;
        }
        if(y > 550){
            y = 550;
        }*/
        int boundary = 1;

        if( y < 500){
            boundary = 2;
        }
        if(y < 150){
            boundary = 3;
        }if(y > 150 && x > 700){
            boundary = 4;
        }

        if(boundary == 1){
            if( y < 500 ){
                y = 500;
    
            }
        } else if(boundary == 2){
            if(x > 100){
                x = 100;
            }

        } else if(boundary == 3){
            if(y < 150){
                y = 150;
            }

        } else if(boundary == 4){
            if(x < 700){
                x = 700;
            }

        }

        


       


        //speedx = speedx + 10;
        System.out.println("Speed: "+speedx);
        System.out.println("Distance: "+distance+"km");
        System.out.println("Changer: "+imagechanger);
        System.out.println("x: "+x+" y:"+y+"n:"+n);
        //repaint();
    }
    //-----------------------------------------------------------------------------//
    public void car2_coordination() {
        speedy =  speedy + (distance/60);
     
        switch(imagechanger1){

            case 0 :
                x1 = x1 - speedy;
                y1 = y1;
                break;

            case 1 :
                x1 = x1 - speedy;
                y1 = y1 - k;
                break;
            case 2 :
                x1 = x1 - speedy;
                y1 = y1 - k;
                
                break;

            case 3 : 
                x1 = x1; 
                y1 = y1 + speedy; 
                break;

            case 7:
                x1 = x1 + speedy;
                y1 = y1;
                break;   
                
            case 8:
                x1 = x1 + speedy;
                y1 = y1 - k;
                break;

            case 11:
                x1 = x1 ;
                y1 = y1 - speedy;
                break;

            case 12:
                x1 = x1 - speedy;
                y1 = y1 - k;
                break;

            case 13:
                x1 = x1 - speedy;
                y1 = y1 - k;
                break;

            case 14:
                x1 = x1- speedy;
                y1 = y1 - k;
                break;

        }
        
       


        //speedx = speedx + 10;
        System.out.println("Speed1: "+speedy);
        System.out.println("Distance: "+distance+"km");
        System.out.println("Changer1: "+imagechanger1);
        System.out.println("x1: "+x1+" y1:"+y1+"k:"+k);
        //repaint();
        
    }
   
}