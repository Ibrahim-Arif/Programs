import java.util.*;

class MovieMagic{
    int year;
    String title;
    float rating;
    
    public MovieMagic(){
        year = 0;
        rating = 0;
        title = "";
    }
    
    public void accept(){
        Scanner s = new Scanner(System.in);
        
        int y = s.nextInt();
        this.year = y;
        s.nextLine();
                
        String t = s.nextLine();
        this.title = t;
           
        float r = s.nextFloat();
        this.rating = r;
    }
    public void display(){
        System.out.printf("%s ", this.title);
        
        if(this.rating <= 2)
            System.out.printf("Flop\n");
        else if(this.rating <= 3.4)
            System.out.printf("Semi-Hit\n");
        else if(this.rating <= 4.5)
            System.out.printf("Hit\n");
        else if(this.rating <= 5)
            System.out.printf("Super Hit\n");
    }
}

class DriverMain{
    public static void main(String[] args){
	MovieMagic movieMagic = new MovieMagic();
	movieMagic.accept();
	movieMagic.display();
    }
}
