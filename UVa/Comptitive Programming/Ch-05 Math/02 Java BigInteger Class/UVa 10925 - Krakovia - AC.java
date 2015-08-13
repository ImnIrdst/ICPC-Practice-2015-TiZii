import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in); int t=1;
        while(true){
            int N=sc.nextInt(), F=sc.nextInt();
            if(N==0 && F==0) break;
            BigInteger ans=new BigInteger("0"), tmp;
            for(int i=0 ; i<N ; i++){
                tmp=sc.nextBigInteger();
                ans=ans.add(tmp);
            }
            System.out.println("Bill #" + (t++) + " costs " + ans + ": each friend should pay " + ans.divide(BigInteger.valueOf(F))+"\n");

        }
    }
}

