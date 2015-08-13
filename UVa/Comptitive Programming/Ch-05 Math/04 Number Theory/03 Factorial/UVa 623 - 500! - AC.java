import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        while(sc.hasNext()){
            int n = sc.nextInt();
            if(n==0){
                System.out.println(n+"!\n"+(n+1));
                continue;
            }
            BigInteger a=BigInteger.ONE;
            for(int i=2 ; i<=n ; i++){
                a = a.multiply(BigInteger.valueOf(i));
            }
            System.out.println(n+"!\n"+a);
        }
    }
}
