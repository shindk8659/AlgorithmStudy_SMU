import java.util.Scanner;


public class Main {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		int a = scanner.nextInt(); //���� A���� �ö�
		int b = scanner.nextInt(); //�㿡 B���� ������
		int v = scanner.nextInt(); //�� V����
		
		int here = 0; //����ġ
		int day = 0; 
		
		while (true) {
			day++;
			
			if(here + a >= v) break;
			else here = here + ( a - b );
		}
		
		System.out.println(day);
		
	}
}