
public class MedicalTest {
    private int testId;
    private String testName;
    private double testPrice;
    
    public MedicalTest(int ti, String tn, double tp){
        this.testId = ti;
        this.testName = tn;
        this.testPrice = tp;
    }
    
    public String toString(){
        return String.format("Test id: %d \nTest name: %s \nTest price: %.2f \n", this.getTestId(), this.getTestName(), this.getTestPrice());
    }

    public int getTestId() {
        return testId;
    }
    public void setTestId(int testId) {
        this.testId = testId;
    }
    public String getTestName() {
        return testName;
    }
    public void setTestName(String testName) {
        this.testName = testName;
    }
    public double getTestPrice() {
        return testPrice;
    }
    public void setTestPrice(double testPrice) {
        this.testPrice = testPrice;
    }
}