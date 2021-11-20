import java.util.*;

public class A1Q3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double posX, posY, dist, theta;
        double newPosX, newPosY;
        
        System.out.print("Enter posX: ");
        posX = scanner.nextDouble();
        System.out.print("Enter posY: ");
        posY = scanner.nextDouble();
        
        System.out.print("Enter theta: ");
        theta = scanner.nextDouble();
        
        dist = Math.pow((posX - 0), 2) + Math.pow((posY - 0), 2);
        newPosX = posX + Math.sqrt(dist) * Math.cos(theta);
        newPosY = posY + Math.sqrt(dist) * Math.sin(theta);
        
        System.out.println("\nNew position (X, Y): (" + newPosX + ", " + newPosY + ")");
    }
}
