package serverClient;

//A Java program for a Server 
import java.net.*;
import java.util.Scanner;
import java.io.*; 

public class Server 
{ 
	//initialize socket and input stream 
	private Socket socket		 	= null; 
	private ServerSocket server 	= null; 
	private DataInputStream in	 	= null; 
	private DataOutputStream out 	= null;
	private String incoming 		= "";
	private String outgoing 		= "";
	private String hisName 			= null;
	static private String myName	= null;
	
	public static void main(String args[])
	{ 
		Scanner input = new Scanner(System.in);
		System.out.print("Enter your name: ");
		myName = input.nextLine();
		Server server = new Server(5000); 
	}

	// constructor with port 
	public Server(int port) 
	{
		Scanner input = new Scanner(System.in);
		// starts server and waits for a connection 
		try
		{ 
			server = new ServerSocket(port); 
			System.out.println(myName+" started"); 
			System.out.println("Waiting for a second person..."); 

			socket = server.accept(); 
			 
			in = new DataInputStream( 
				new BufferedInputStream(socket.getInputStream()) 
			);
			out = new DataOutputStream(socket.getOutputStream());
			
			hisName = in.readUTF();
			System.out.println(hisName+" Connected\n");
			out.writeUTF(myName);

			// reads/write message from/ client until "Over" is sent 
			while (!incoming.equals("Over")) 
			{ 
				try{ 
					incoming = in.readUTF(); 
					System.out.println(hisName+": "+incoming);
					//System.out.print("You: ");
					System.out.print(myName+": ");
					outgoing = input.nextLine();
					out.writeUTF(outgoing);
				}
				catch(IOException i) 
				{ 
					System.out.println(i);
				}
			} 
			System.out.println("Closing connection"); 

			// close connection 
			out.close();
			socket.close(); 
			in.close(); 
		} 
		catch(IOException i) 
		{ 
			System.out.println(i); 
		} 
	}

	public Server() {
	} 
}