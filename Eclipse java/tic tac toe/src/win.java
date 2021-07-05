public class win {
	int flag=0;
	public void winner() {
		//gettingdata gettingdata =new gettingdata();
		
		if(gettingdata.arr[1]=='X' && gettingdata.arr[2]=='X' && gettingdata.arr[3]=='X')
	        flag = 1;
	    else if(gettingdata.arr[1]=='X' && gettingdata.arr[4]=='X' && gettingdata.arr[7]=='X')
	        flag =1;
	    else if(gettingdata.arr[1]=='X' && gettingdata.arr[5]=='X' && gettingdata.arr[9]=='X')
	    	flag =1;
	    else if(gettingdata.arr[1]=='X' && gettingdata.arr[4]=='X' && gettingdata.arr[7]=='X')
	    	flag =1;
	    else if(gettingdata.arr[2]=='X' && gettingdata.arr[5]=='X' && gettingdata.arr[8]=='X')
	    	flag =1;
	    else if(gettingdata.arr[1]=='X' && gettingdata.arr[4]=='X' && gettingdata.arr[7]=='X')
	    	flag =1;
	    else if(gettingdata.arr[3]=='X' && gettingdata.arr[6]=='X' && gettingdata.arr[9]=='X')
	    	flag =1;
	    else if(gettingdata.arr[3]=='X' && gettingdata.arr[5]=='X' && gettingdata.arr[7]=='X')
	    	flag =1;
	    else if(gettingdata.arr[4]=='X' && gettingdata.arr[5]=='X' && gettingdata.arr[6]=='X')
	    	flag =1;
	    else if(gettingdata.arr[7]=='X' && gettingdata.arr[8]=='X' && gettingdata.arr[9]=='X')
	    	flag =1;

	    //Win_Case for O (Player-2)
	    else if(gettingdata.arr[1]=='O' && gettingdata.arr[2]=='O' && gettingdata.arr[3]=='O')
	    	flag =2;
	    else if(gettingdata.arr[1]=='O' && gettingdata.arr[4]=='O' && gettingdata.arr[7]=='O')
	    	flag =2;
	    else if(gettingdata.arr[1]=='O' && gettingdata.arr[5]=='O' && gettingdata.arr[9]=='O')
	    	flag =2;
	    else if(gettingdata.arr[1]=='O' && gettingdata.arr[4]=='O' && gettingdata.arr[7]=='O')
	    	flag =2;
	    else if(gettingdata.arr[2]=='O' && gettingdata.arr[5]=='O' && gettingdata.arr[8]=='O')
	    	flag =2;
	    else if(gettingdata.arr[1]=='O' && gettingdata.arr[4]=='O' && gettingdata.arr[7]=='O')
	    	flag =2;
	    else if(gettingdata.arr[3]=='O' && gettingdata.arr[6]=='O' && gettingdata.arr[9]=='O')
	    	flag =2;
	    else if(gettingdata.arr[3]=='O' && gettingdata.arr[5]=='O' && gettingdata.arr[7]=='O')
	    	flag =2;
	    else if(gettingdata.arr[4]=='O' && gettingdata.arr[5]=='O' && gettingdata.arr[6]=='O')
	    	flag =2;
	    else if(gettingdata.arr[7]=='O' && gettingdata.arr[8]=='O' && gettingdata.arr[9]=='O')
	    	flag =2;
	    else if(Main.count == 9)
	    	flag =3;
	}
}