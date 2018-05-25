import java.util.Scanner;


public class Main {

	public static void main(String args[]) {
		
		Scanner scanner = new Scanner(System.in);
		
		int x = scanner.nextInt(); // 명령어의 개수를 입력받는다.
		
		for(int i=0;i<x;i++) {
			stack s = new stack(); // s라는 객체를 생성한다.
			String st = scanner.next(); // 문자열을 받는다
			
			
				for(int j=0; j<st.length(); j++) { // 문자열의 길이만큼 for문을 돌린다.
					if(s.isempty()== true)
						s.push(st.charAt(j));
					else if(s.pretop() =='(' && st.charAt(j)==')') { // 지금 들어오는 값이 ')'이고 앞이 '('일 때만 pop한다.
						s.pop();
					}					
					
					else
						s.push(st.charAt(j)); //무조건 집어넣고
					
				}
				
				s.top();	
		}
	}
}



class stack{ // main 함수에서 객체로 사용할 클래스를 만든다.
	
	
	char arr[]; // 문자열 배열 생성
	int top = 0; // 배열의 값이 채워진 위치의 다음 위치를 가리킴
	
	
	public stack() {
		this.arr= new char[50]; // 배열의 크기는 50으로 정한다.
	}
	
	void push(char a) {
			arr[top]=a; // 파라미터로 들어온 값을 top의 위치에 넣고
			top++; // top을 다음 값이 들어갈 위치로 지정한다.

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
		if(top == 0) //top이 0이라면 올바른 괄호 문자열이기 떄문에 yes를 출력한다
			System.out.println("YES");
		else //top이 0이 아니라면 올바른 괄호 문자열이 아니라면 no를 출력한다
			System.out.println("NO");
	}

}