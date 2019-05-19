//Example 3.6
package com.company;
import java.util.Scanner;

public class Ex_3_6 {

    public class Money{
        //The value of money is no more than ¥5.00
        int yuan,jiao,fen,x;
        double value;

        public void setValue(double v){
            value=v;
            x=(int)(500-value*100);
        }

        public int getYuan(){
            int ans=x/500;
            x%=500;
            ans+=x/200;
            x%=200;
            ans+=x/100;
            x%=100;
            return ans;
        }

        public int getJiao(){
            int ans=x/50;
            x%=50;
            ans+=x/20;
            x%=20;
            ans+=x/10;
            x%=10;
            return ans;
        }

        public int getFen(){
            int ans=x/5;
            x%=5;
            ans+=x/2;
            x%=2;
            ans+=x;
            return ans;
        }

        public void exchange(double x){
            setValue(x);
            yuan=getYuan();
            jiao=getJiao();
            fen=getFen();
        }

        public String toString() {
            return (yuan+"元,"+jiao+"角,"+fen+"分.");
        }
    }

    public static void main(String[] args) {
	    Money a;
	    a=new Money();

        Scanner sn = new Scanner(System.in);
        double x=sn.nextDouble();
	    a.exchange(x);
	    System.out.println(a.toString());
    }
}
