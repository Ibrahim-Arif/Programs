import java.util.*;

public class A1Q4 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int meterNum, date;
        double prevReading, presReading, usage, 
                basicCharge = 8.62, 
                perUsageCharge = 0.08740, 
                energyCharge, subTotal, gst, pst, electCharge;
        
        System.out.print("Enter meter number: ");
        meterNum = scanner.nextInt();
        System.out.print("Enter date from: ");
        date = scanner.nextInt();
        
        System.out.print("Enter previous reading: ");
        prevReading = scanner.nextDouble();
        System.out.print("Enter presend reading: ");
        presReading = scanner.nextDouble();
        
        usage = presReading - prevReading;
        energyCharge = usage * perUsageCharge;
        subTotal = basicCharge + energyCharge;
        gst = subTotal * 0.05;
        pst = subTotal * 0.07;
        electCharge = subTotal + gst + pst;
        
        System.out.println("");
        System.out.format("%-15s| %-10s| %-10s| %-15s| %-15s| %-15s \n", "Meter", "Date", "Date", "Previous", "Presend", "Usage");
        System.out.format("%-15s| %-10s| %-10s| %-15s| %-15s| %-15s \n", "number", "from", "to", "meter", "meter", "");
        System.out.format("%-15s| %-10s| %-10s| %-15s| %-15s| %-15s \n", "", "", "", "reading", "reading", "");
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15d| %-10d| %-10d| %-15.2f| %-15.2f| %-15.2f \n", meterNum, date, date+10000, prevReading, presReading, usage);
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15s| %-10s  %-10s  %-15s  %-15s| $%-15.2f \n", "Basic Charge" , "", "", "", "", basicCharge);
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15s| %-10s  %-10s    %-30s| $%-15.2f \n", "Energy Charge" , "", "", String.format("(%.2f x $0.08740)", usage), energyCharge);
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15s| %-10s  %-10s  %-15s  %-15s| $%-15.2f \n", "Sub Total" , "", "", "", "", subTotal);
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15s| %-10s  %-10s  %-15s  %-15s| $%-15.2f \n", "GST (5%)" , "", "", "", "", gst);
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15s| %-10s  %-10s  %-15s  %-15s| $%-15.2f \n", "PST (7%)" , "", "", "", "", pst);
        System.out.println("_____________________________________________________________________________________");
        System.out.format("%-15s| %-10s %-10s %-15s    %-15s| $%-15.2f \n", "Electricity" , "", "", "", "", electCharge);
        System.out.format("%-15s| %-10s %-10s %-15s %-15s %-15s \n", "Charge ($)" , "", "", "", "", "");
    }
}
