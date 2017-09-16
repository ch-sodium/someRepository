import java.io.*;
import java.util.*;
class trailingZeros
{
	public static void main(String[]args) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int ctr = 0;
		for(int i = 5; (num/i)>=1;i = i * 5)
		{
			ctr = ctr + (num/i);
		}
		System.out.println("Trailing zeroes = " + ctr);
	}
}

