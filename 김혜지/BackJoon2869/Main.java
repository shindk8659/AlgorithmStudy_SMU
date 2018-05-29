import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scanner=new Scanner(System.in);
		int A=scanner.nextInt();
		int B=scanner.nextInt();
		int V=scanner.nextInt();
		int i=0;
		int date=0;
		
		if(1<=B&&B<A&&A<=V&&V<=1000000000){
			while(V!=i){
				date=date+1;
				i=i+A;
				if(i>=V){
					break;
				}
				i=i-B;				
			}
			System.out.println(date);
		}
	}
}
