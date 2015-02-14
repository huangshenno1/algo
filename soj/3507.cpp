import java.util.*;
import java.io.*;
import java.math.*;

class Main
{
    static int[] cnt = new int[5000];
    static BigInteger[] f = new BigInteger[5000];
    public static void main (String[] args)
    {
        cnt[1] = cnt[2] = 0; cnt[3] = 1; cnt[4] = 2;
        for (int i=5;i<5000;i++) cnt[i] = cnt[i-1] + isprime(i);
        f[1] = f[2] = BigInteger.ONE;
        for (int i=3;i<5000;i++) f[i] = f[i-1].add(f[i-2]);
        Scanner input = new Scanner(System.in);
        int T, n;
        T = input.nextInt();
        while (T-- > 0)
        {
            n = input.nextInt();
            while (n-- > 0)
            {
                BigInteger x = input.nextBigInteger();
                int ans = 0;
                for (int i=1;i<5000;i++)
                    if (f[i].compareTo(x) == 0) {ans = cnt[i]; break;} 
                System.out.println(ans);
            }
        }
    }
    
    static int isprime(int x)
    {
        int xx = (int)Math.sqrt(x);
        for (int i=2;i<=xx;i++)
            if (x % i == 0) return 0;
        return 1;
    }
}