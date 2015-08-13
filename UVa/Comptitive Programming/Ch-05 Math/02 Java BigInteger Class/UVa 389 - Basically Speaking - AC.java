import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in); String str; int b1, b2;
                StringBuilder sb;
		while(sc.hasNext()){
            str = sc.next(); b1 = sc.nextInt(); b2 = sc.nextInt();
            Integer n = Integer.parseInt(str,b1);
            str = Integer.toString(n,b2).toUpperCase();

            if(str.length()>7) System.out.println("  ERROR");
            else{
                sb = new StringBuilder("");
                for(int i=str.length() ; i<7 ; i++) sb.append(" ");
                sb.append(str);
                System.out.println(sb.toString());
            }
		}
	}
}