public class PieceWorker extends Employee{
    private double wage;
    private int pieces;

    public PieceWorker( String fname, String lname, int ssn, double wage, int pieces) {
        super(fname, lname, ssn,"PieceWorker");
        this.wage = wage;
        this.pieces = pieces;
    }
    
    public double getWage() {
        return wage;
    }
    public int getPieces() {
        return pieces;
    }

    public void setWage(double wage) {
        this.wage = wage;
    }
    public void setPieces(int pieces) {
        this.pieces = pieces;
    }
     
    @Override
    public double earnings(){      
        return getPieces()*getWage();
    }

    @Override
    public String toString() {
        return super.toString()+"\nEarnings:"+earnings();
    }
}