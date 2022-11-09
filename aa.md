package program5;
import java.math.BigInteger;
import java.util.*;
public class rsa 
{
	public static void main(String args[])
	{	
		Scanner ip=new Scanner(System.in);
		int p,q,n,e=1,j;
		int d=1,i1;
		int t1,t2;
		int pt[]=new int[10];
		int ct[]=new int[10];
		int rt[]=new int[10];
		int temp[]=new int[10];
		String i=new String();
		
		System.out.println("Enter the two prime numbers ");
		p=ip.nextInt();
		q=ip.nextInt();
		System.out.println("Enter the message to be sent ");
		i=ip.next();
		i1=i.length();
		n=p*q;
		t1=p-1;
		t2=q-1;
		System.out.println("\n -------------------------------");
		System.out.println("Sender side");
		while((t1*t2)%e==0)
		{
			e++;
		}
		System.out.println("Public key(e) = "+e);
		System.out.println("\n ----------------------");
		for(j=0;j<i1;j++)
		{
			pt[j]=(i.charAt(j))-96;
			ct[j]=((int)Math.pow(pt[j], e))%n;
			System.out.println("Cipher text = "+ct[j]);
		}
			System.out.println("\n Transmitted message ");
			for(j=0;j<i1;j++)
			{
				temp[j]=ct[j]+96;
				System.out.print((char)temp[j]);
			}
			System.out.println("\n -------------------");
			System.out.println("Receiver side");
			while((d*e)%(t1*t2)!=1)
			{
				d++;
			}
			System.out.println("Private key(d) = "+d);
			System.out.println("--------------------");
			for(j=0;j<i1;j++)
			{
				BigInteger very_big_no= BigInteger.valueOf(ct[j]);
				very_big_no = very_big_no.pow(d);
				very_big_no=very_big_no.mod(BigInteger.valueOf(n));
				rt[j]=very_big_no.intValue();
				System.out.println("Plane text = "+rt[j]);
			}
			System.out.println("\n --------------------");
			System.out.println("Decrypted message ");
			for(j=0;j<i1;j++)
			{
				rt[j]=rt[j]+96;
				System.out.print((char)rt[j]);
			}
			System.out.println("\n ----------------------- ");
			ip.close();
		}

  }
