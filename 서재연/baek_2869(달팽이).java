import java.util.Scanner;

public class Main{
	/*
	 * �� ���� �����̰� �ִ�. �� �����̴� ���̰� V������ ���� ���븦 �ö� ���̴�.
	     �����̴� ���� A���� �ö� �� �ִ�. ������, �㿡 ���� �ڴ� ���� B���� �̲�������. ��, ���� �ö� �Ŀ��� �̲������� �ʴ´�.
	�����̰� ���� ���븦 ��� �ö󰡷���, ��ĥ�� �ɸ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan=new Scanner(System.in);
		int A=scan.nextInt(); int B=scan.nextInt(); int V=scan.nextInt();
		
		int i=0;//���� ��ġ
		int day=1;
		while(true) {
			i=i+A; //���� �ö�
			if(i>=V)
				break;
			i=i-B;//�㿡 ������
			day=day+1;//�Ϸ� ����
		}
		
		System.out.println(day);
		
	}

}
