import java.util.Scanner;


public class Main {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		int x = scanner.nextInt(); // ��ɾ��� ������ �Է¹޴´�.
		
		for(int i=0;i<x;i++) {
			stack s = new stack(); // s��� ��ü�� �����Ѵ�.
			String st = scanner.next(); // ���ڿ��� �޴´�
			
			
				for(int j=0; j<st.length(); j++) { // ���ڿ��� ���̸�ŭ for���� ������.
					if(s.isempty()== true)
						s.push(st.charAt(j));
					else if(s.pretop() =='(' && st.charAt(j)==')') { // ���� ������ ���� ')'�̰� ���� '('�� ���� pop�Ѵ�.
						s.pop();
					}					
					
					else
						s.push(st.charAt(j)); //������ ����ְ�
					
				}
				
				s.top();	
		}
	}
}



class stack{ // main �Լ����� ��ü�� ����� Ŭ������ �����.
	
	
	char arr[]; // ���ڿ� �迭 ����
	int top = 0; // �迭�� ���� ä���� ��ġ�� ���� ��ġ�� ����Ŵ
	
	
	public stack() {
		this.arr= new char[50]; // �迭�� ũ��� 50���� ���Ѵ�.
	}
	
	void push(char a) {
			arr[top]=a; // �Ķ���ͷ� ���� ���� top�� ��ġ�� �ְ�
			top++; // top�� ���� ���� �� ��ġ�� �����Ѵ�.

	}
	
	char pretop () {
		return arr[top-1];
	}
	
	void pop() {
		
		top=top-1;
		
	}
	
	boolean isempty() {
		if(top==0)
			return true;
		else
			return false;
	}
	
	void top() {
		if(top == 0) //top�� 0�̶�� �ùٸ� ��ȣ ���ڿ��̱� ������ yes�� ����Ѵ�
			System.out.println("YES");
		else //top�� 0�� �ƴ϶�� �ùٸ� ��ȣ ���ڿ��� �ƴ϶�� no�� ����Ѵ�
			System.out.println("NO");
	}

}