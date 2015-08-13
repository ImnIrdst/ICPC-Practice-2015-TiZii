
import java.util.Scanner;
import java.math.*;

class Main{//Main
	private static BigInteger[] cat = new BigInteger[1000+10];
	
	public static void calcCatalan(){
		cat[0]=BigInteger.ONE;
		for(int i=1 ; i<1000+9 ; i++){
			cat[i]=cat[i-1].multiply(BigInteger.valueOf(2*(2*i-1)));
			cat[i]=cat[i].divide(BigInteger.valueOf(i+1));
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n; calcCatalan();
		while(sc.hasNext()){
			n = sc.nextInt();
			System.out.println(cat[n]);
		}
		sc.close();
	}
}



