import java.util.Scanner;
import java.math.*;

public class Main {
    public  static void main(String[] args) {
        final int Max = 100 + 10;
        final int Inf = (int)(1e9);
        Scanner sc = new Scanner(System.in);
        BigInteger[] num = new BigInteger[Max];
        while(sc.hasNext()) {
            int n;
            for(n=0 ; true ; n++){
                num[n] = sc.nextBigInteger();
                if(num[n].equals(BigInteger.valueOf(-999999))==true)
                    break;
            }

            BigInteger ans = BigInteger.valueOf(-Inf);
            for(int i=0 ; i<n ; i++) {
                BigInteger Mul = num[i]; ans = ans.max(Mul);
                for(int j=i+1 ; j<n ; j++) {
                   Mul = Mul.multiply(num[j]); ans = ans.max(Mul);
                }
            }

            System.out.println(ans);
        }
    }
}
