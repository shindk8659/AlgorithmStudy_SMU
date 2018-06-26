import java.util.Scanner;
import java.util.Stack;

public class AlgorithmTest4 {
/*
 * �Է� �����ʹ� ǥ�� �Է��� ����Ѵ�. �Է��� T���� �׽�Ʈ �����ͷ� �־�����. 
 * �Է��� ù ��° �ٿ��� �Է� �������� ���� ��Ÿ���� ���� T�� �־�����. 
 * �� �׽�Ʈ �������� ù° �ٿ��� ��ȣ ���ڿ��� �� �ٿ� �־�����. 
 * �ϳ��� ��ȣ ���ڿ��� ���̴� 2 �̻� 50 �����̴�. 
 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan=new Scanner(System.in);
	
		int t=scan.nextInt();//�׽�Ʈ���̽� ��
		scan.nextLine();
		
		for(int i=0; i<t; i++) {
			String input=scan.nextLine();
			Stack stack= new Stack();
			for(int k=0; k<input.length(); k++) {
				if(stack.isEmpty()) {//������ ��������� 
					stack.push(input.charAt(k));
					continue;
				}
				//�ϱ� ���� stack top ��ġ�� ��ȣ�� ��Ī�Ǵ��� Ȯ�� => ���� ��ȣ�� )�̰� top ��ġ�� ��ȣ�� ( ���� ��
				if((char)stack.peek()=='(' && input.charAt(k)==')') {
					//��ȣ ¦�� ���� -> pop
					stack.pop();
				}
				//��Ī�� ���� ������ ���ÿ� �߰�
				else {
					stack.push(input.charAt(k));
				}
			}
			if(stack.empty()) System.out.println("YES"); else System.out.println("NO");;
		}	
	}
}

