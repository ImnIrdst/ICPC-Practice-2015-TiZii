import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); BigInteger n , num17 = new BigInteger("17");

		while(true){
			n=sc.nextBigInteger(); if(n.equals(BigInteger.ZERO)) break;
        
            if( n.remainder(num17).equals(BigInteger.ZERO)) System.out.println(1);
            else System.out.println(0);
		}

	}
}