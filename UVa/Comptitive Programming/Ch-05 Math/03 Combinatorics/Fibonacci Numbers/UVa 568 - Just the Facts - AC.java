import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) {
        BigInteger fib[] = new BigInteger[500];
        Scanner sc = new Scanner(System.in);
        fib[0]=BigInteger.ONE; fib[1]=BigInteger.ONE;
        for(int i=2 ; i<500 ; i++){
            fib[i]=fib[i-1].add(fib[i-2]);
            //System.out.println(fib[i].toString().length());
        }

        while(true){
            BigInteger a=sc.nextBigInteger(), b=sc.nextBigInteger();
            if(a.toString()=="0" && b.toString()=="0")
                break;

            int ans=0;
            for(int i=1 ; i<500 ; i++){
                if(fib[i].compareTo(a)>=0 && fib[i].compareTo(b)<=0){
                    ans++;
                }
            }
            System.out.println(ans);
        }
    }
}
