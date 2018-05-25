import java.util.Scanner;


public class Main {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		int a = scanner.nextInt(); //낮에 A미터 올라감
		int b = scanner.nextInt(); //밤에 B미터 내려감
		int v = scanner.nextInt(); //총 V미터
		
		int here = 0; //현위치
		int day = 0; 
		
		while (true) {
			day++;
			
			if(here + a >= v) break;
			else here = here + ( a - b );
		}
		
		System.out.println(day);
		
	}
}