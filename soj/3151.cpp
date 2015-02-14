import java.util.*;
import java.math.*;

public class Main
{
    public static void main (String args[])
    {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        while (t-- > 0)
        {
            BigInteger n = input.nextBigInteger();
            BigInteger m = input.nextBigInteger();
            BigInteger r = n.mod(m);
            System.out.println(r.toString());
        }
    }
}

