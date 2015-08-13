import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); Integer n, a;

		while(sc.hasNextInt()){
			n=sc.nextInt(); a=sc.nextInt();
			BigInteger ans = BigInteger.ZERO;
			BigInteger Ai = new BigInteger(a.toString());
			BigInteger AI = new BigInteger(a.toString());
			BigInteger I = BigInteger.ONE;
			BigInteger tmp; 
			for(int i=1 ; i<=n ; i++){
				tmp = I.multiply(AI);  ans = ans.add(tmp);
                AI = AI.multiply(Ai); I = I.add(BigInteger.ONE);
			}
            System.out.println(ans);
		}

	}
}