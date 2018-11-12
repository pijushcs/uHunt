import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main {
	static BigInteger dP[][];
	static int mvec[];

	static BigInteger findNPos(int n, int m) {
		BigInteger res=BigInteger.ZERO;

		if(m==0 && n>=-1) return BigInteger.ONE;
		if(n<=0 || m<=0) return BigInteger.ZERO;

		if(dP[n][m].compareTo(BigInteger.valueOf(-1))!=0) return dP[n][m];

		res=res.add(findNPos(n-mvec[m]-1, m-1));
		res=res.add(findNPos(n-1, m));

		dP[n][m]=res;
		return res;
	}

	public static void main (String[] args) throws java.lang.Exception {
		int t, n, m, val;
		mvec=new int[201];
		dP=new BigInteger[201][201];

		Scanner sc = new Scanner(System.in);

		t=sc.nextInt();
		while(t>0) {
			n=sc.nextInt(); m=sc.nextInt();

			for(int i=1; i<=m; i++) {
				val=sc.nextInt();
				mvec[i]=val;
			}

			for(int i=0; i<=n; i++)
				for(int j=0; j<=m; j++)
					dP[i][j]=BigInteger.valueOf(-1);

			BigInteger res=findNPos(n, m);
			System.out.println(res); t--;
		}
	}
}
