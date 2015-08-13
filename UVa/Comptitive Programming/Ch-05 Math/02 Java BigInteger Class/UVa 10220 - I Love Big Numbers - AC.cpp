import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger[] fact=new BigInteger[1001];

        fact[0]=BigInteger.ONE;
        for(int i=1 ; i<1001 ; i++){
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        }

        while(sc.hasNextInt()){
            int n = sc.nextInt();
            long ans=0; String Fact = fact[n].toString();
            for(int i=0 ; i<Fact.length() ; i++){
                ans += (int)(Fact.charAt(i)-'0');
            }
            System.out.println(ans);
        }
    }
}
