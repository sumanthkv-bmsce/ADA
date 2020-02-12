import java.util.*;
import java.util.Random;

class Sortme {
        public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        Random rand = new Random();
                int n,i,a[],temp;
                System.out.println("Enter n: ");
                n = scan.nextInt();
                a = new int[n];
	for(i=0;i<n;i++) {
	        a[i] = rand.nextInt(10000);
	}
	long startTime = System.nanoTime();
	a = sort(a,n);
	 
	  long endTime   = System.nanoTime(); 
	  long totalTime = endTime - startTime;
        System.out.println((double)totalTime/1000000000);
           
       }
       
       
       public static int[] sort(int a[],int n) {
	int temp;
	for(int i=0;i<n;i++) {
	        for(int j=i+1;j<n;j++) {
	                if(a[i]>a[j]) {
	                        temp = a[i];
	                        a[i] = a[j];
	                        a[j] = temp;
	                   }
	             }
	        }
	        return a;
	 
        }
}







