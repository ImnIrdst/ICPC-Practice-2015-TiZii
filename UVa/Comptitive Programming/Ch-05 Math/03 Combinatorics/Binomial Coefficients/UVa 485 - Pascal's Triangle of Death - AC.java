
import java.math.BigInteger;


class Main{//Main
	
	private static BigInteger[] prev, cur;
	private static BigInteger p1060 = BigInteger.ONE;
	//private static BigInteger ten = new BigInteger("10")
	
	
	public static void main(String[] args){
		for(int i=0 ; i<60 ; i++) p1060 = p1060.multiply(BigInteger.valueOf(10));
		prev = new BigInteger[100000];
		cur = new BigInteger[100000];
		//System.out.println(p1060);
		int found = 0;
		
		for(int i=0 ; found==0 ; i++){
			cur[0]=BigInteger.ONE; System.out.print(cur[0]);
			for(int j=1 ; j<i ; j++){
				//System.out.print(" "+prev[j-1]+" "+cur[j]);
				cur[j]=prev[j].add(prev[j-1]);
				System.out.print(" "+cur[j]);
				if(cur[j].compareTo(p1060)>=0) found=1;
			}
			if(i!=0){ cur[i]=BigInteger.ONE; System.out.print(" "+cur[i]); }
			//prev[0]=cur[0];
			for(int j=0 ; j<=i ; j++) prev[j]=cur[j];
			System.out.print("\n");
		}
		//System.out.print("\n");
	}
}



