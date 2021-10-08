import java.util.*;

//Your program will be evaluated by this DriverMain class and several test cases.

public class DriverMain {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        
        float initialAnnualInterestRate = s.nextFloat();
        float initialSavingsBalance = s.nextFloat();
        float annualInterestRateAfterMonth = s.nextFloat();
        
        ProblemSolution problemSolution = new ProblemSolution();
        problemSolution.solution(initialAnnualInterestRate, initialSavingsBalance, annualInterestRateAfterMonth);
    }
}