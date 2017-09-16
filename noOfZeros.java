import java.io.*;
import java.util.*;
import java.math.BigInteger;
class Solution
{
	public static void main(String[]args)throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int ctr=0;
		BigInteger fact = new BigInteger("1");
		for(int i = 1;i <= num;i++)
		{
			fact = fact.multiply(BigInteger.valueOf(i));
		}
		System.out.println("Factorial =" + fact);
		while(fact!=(BigInteger.ZERO))
		{
			BigInteger t = fact.remainder(BigInteger.TEN);
			if(t==(BigInteger.ZERO))
			{
				ctr++;
			}
			fact = fact.divide(BigInteger.TEN);
		}
		System.out.println("Number of zeroes = " + ctr);
	}
}
