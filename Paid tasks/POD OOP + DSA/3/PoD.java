import java.util.*;

public class PoD{
    public static void main( String [] args )
    {
        Scanner in = new Scanner( System.in );

        Queue battingOrder = new Queue();

        final int TEAM_SIZE = in.nextInt();
        in.nextLine();

        for (int i=0; i<TEAM_SIZE; i++) {
            String nextBatter = in.nextLine();
            battingOrder.add(nextBatter);
        }

        for( int outs = 3; outs > 0; ) {
            String batter = battingOrder.remove();
            if( in.next().equals( "out" ) ) {
              System.out.println( batter + " is out!" );
              outs--;
            } else {
              System.out.println( batter + " is on base!" );
            }
            battingOrder.add( batter );
        }

        in.close();
        System.out.print("END OF OUTPUT");
    }
}
