import java.util.*;

class SavingsAccount {
    static float annualInterestRate = 0;
    private float savingsBalance = 0;
    
    public SavingsAccount(float savingsBalance){
        this.savingsBalance = savingsBalance;
    }
    
    public void calculateMonthlyInterest(){
        this.savingsBalance += (this.savingsBalance * (this.annualInterestRate/12));
    }
    
    static void modifyInterestRate(float p){
        annualInterestRate = p;
    }
    
    public void printSavingsBalance(){
        System.out.printf("%f \n", this.savingsBalance);
    }
    
}

public class ProblemSolution {
    
    public void solution(float initialAnnualInterestRate, float initialSavingsBalance, float annualInterestRateAfterMonth) {
       SavingsAccount sa = new SavingsAccount(initialSavingsBalance);
       System.out.println("");
       
       sa.modifyInterestRate(initialAnnualInterestRate);
       sa.calculateMonthlyInterest();
       sa.printSavingsBalance();
       
       sa.modifyInterestRate(annualInterestRateAfterMonth);
       sa.calculateMonthlyInterest();
       sa.printSavingsBalance();
    }
}
