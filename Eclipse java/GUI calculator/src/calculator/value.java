package calculator;

import javax.swing.JOptionPane;

public class value {
	public double value=0;
	public double first=0;
	public double result;
	public int flag=0;
	public int firstTimeFlag=0;
	public int decimalFlag=0;
	String StringInput = "";
	
	
	public void val(int v) {
		value = (value*10) + v;
		if(decimalFlag==1) {
			value/=10;
			decimalFlag=0;
		}
	}
	public void decide() {
		if(flag == 1) {
			if(firstTimeFlag==0) {
				result = first / value;
				firstTimeFlag=1;
			}
			else
				result = result / value;
		}
		else if(flag == 2) {
			if(firstTimeFlag==0) {
				result = first * value;
				firstTimeFlag=1;
			}
			else
				result = result * value;
		}
		else if(flag == 3) {
			if(firstTimeFlag==0) {
				result = first - value;
				firstTimeFlag=1;
			}
			else
				result = result - value;
		}
		else if(flag == 4) {
			if(firstTimeFlag==0) {
				result = first + value;
				firstTimeFlag=1;
			}
			else
				result = result + value;
		}
	}
	public void display() {
		
		JOptionPane.showMessageDialog(null, result);
	}
	public String remove(String str) {
		   String result = null;
		   if ((str != null) && (str.length() > 0)) {
		      result = str.substring(0, str.length() - 1);
		   }
		   return result;
		}
}