package main;

import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
//import java.util.

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger Base10; String num, ans; Integer base1, base2;
        while(sc.hasNextInt()){
            base1 = sc.nextInt();
            base2 = sc.nextInt(); num = sc.next();
            try{
                Base10 = new BigInteger(num, base1);
            }catch(Exception e){
                System.out.println(num + " is an illegal base " + base1 + " number");
                continue;
            }
            try{
                ans = Base10.toString(base2).toUpperCase();
               
            }catch(Exception e){
                System.out.println(num + " is an illegal base " + base2 + " number");
                continue;
            }
            System.out.println(num + " base " + base1 + " = " + ans + " base " + base2);
        }
    }
}
