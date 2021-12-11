public class fact {
	
	int value=1;
	int orig;
	void factorial(){
		for(int i=orig;i>1;i--)
			value=value*i;
	}
}