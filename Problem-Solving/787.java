import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main {
    public static void main (String[] args) throws java.lang.Exception {
         BigInteger maxNow, val, pprev;
         ArrayList<BigInteger> vprod;
         Scanner sc = new Scanner(System.in);

         int tcase=1;

         try {
             while(sc.hasNextInt()) {
                maxNow=BigInteger.valueOf(-10000000);
                pprev=BigInteger.ONE;
                vprod = new ArrayList<BigInteger>();

                val=BigInteger.valueOf(sc.nextInt());

                while(val.compareTo(BigInteger.valueOf(-999999))!=0) {
                    vprod.add(pprev.multiply(val));

                    if(val.compareTo(BigInteger.ZERO)==0) pprev=BigInteger.ONE;
                    else pprev=pprev.multiply(val);

                    val=BigInteger.valueOf(sc.nextInt());
                }

                for(int i=0; i<vprod.size(); i++) {
                    if(i==0 || vprod.get(i-1).compareTo(BigInteger.ZERO)==0)
                    pprev=BigInteger.ONE;
                    else pprev=vprod.get(i-1);

                    maxNow=maxNow.max(vprod.get(i));
                    for(int j=i; j<vprod.size(); j++) {
                        if(vprod.get(j).compareTo(BigInteger.ZERO)==0) break;
                        maxNow=maxNow.max(vprod.get(j).divide(pprev));
                    }
                }

                System.out.println(maxNow);
            }
        } catch(Exception ex) {}
    }
}
