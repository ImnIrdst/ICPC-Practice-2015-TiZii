import java.math.BigInteger;
import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
    
        while(true){
            int n = sc.nextInt(); if(n==0) break;
            BigInteger a=BigInteger.ONE;
            for(int i=2 ; i<=n ; i++){
                a = a.multiply(BigInteger.valueOf(i));
            }
            int[] ans = new int[]{0,0,0,0,0,0,0,0,0,0,0};
            String str = a.toString();
            for(int i=0 ; i<str.length() ; i++){
                ans[str.charAt(i)-'0']++;
            }
            System.out.println(n+"! --");
            for(int i=0 ; i<10 ; i++){
                System.out.printf("   (%d) %4d", i, ans[i]);
                if(i==4) System.out.println();
            }
            System.out.println();
        }
    }
}
