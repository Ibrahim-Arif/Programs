package serverClient;

//A Java program for a Client 
import java.net.*;
import java.util.Scanner;
import java.io.*; 

public class Client 
{ 
	// initialize socket and input output streams 
	private Socket socket		 	= null; 
	private DataInputStream in 		= null; 
	private DataOutputStream out	= null;
	private String outgoing 		= ""; 
	private String incoming 		= "";
	static private String myName	= null;
	private String hisName			= null;
	
	public static void main(String args[]) 
	{ 
		Scanner input = new Scanner(System.in);
		System.out.print("Enter your name: ");
		myName = input.nextLine();
		Client client = new Client("localhost", 5000);
	} 
	
	public Client(String address, int port) 
	{
		Scanner input = new Scanner(System.in);
		
		// establish a connection 
		try
		{ 
			socket = new Socket(address, port); 
			
			in = new DataInputStream( 
				new BufferedInputStream(socket.getInputStream()) 
			);
			out = new DataOutputStream(socket.getOutputStream());
			
			out.writeUTF(myName);
			hisName = in.readUTF();
			System.out.println(hisName+" Connected\n");

		} 
		catch(UnknownHostException u) 
		{ 
			System.out.println(u); 
		} 
		catch(IOException i) 
		{ 
			System.out.println(i); 
		} 

		// keep reading until "Over" is input 
		while (!outgoing.equals("Over")) 
		{ 
			try{ 
				//System.out.print("You: ");
				System.out.print(myName+": ");
				outgoing = input.nextLine(); 
				out.writeUTF(outgoing);
				incoming = in.readUTF(); 
				System.out.println(hisName+": "+incoming);
			} 
			catch(IOException i) 
			{ 
				System.out.println(i);
			}
		} 

		// close the connection 
		try
		{ 
			in.close(); 
			out.close(); 
			socket.close(); 
		} 
		catch(IOException i) 
		{ 
			System.out.println(i); 
		} 
	} 
} 