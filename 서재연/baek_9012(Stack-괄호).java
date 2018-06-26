import java.util.Scanner;
import java.util.Stack;

public class AlgorithmTest4 {
/*
 * 입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 
 * 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 
 * 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 
 * 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 
 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan=new Scanner(System.in);
	
		int t=scan.nextInt();//테스트케이스 수
		scan.nextLine();
		
		for(int i=0; i<t; i++) {
			String input=scan.nextLine();
			Stack stack= new Stack();
			for(int k=0; k<input.length(); k++) {
				if(stack.isEmpty()) {//스택이 비어있으면 
					stack.push(input.charAt(k));
					continue;
				}
				//하기 전에 stack top 위치의 괄호와 매칭되는지 확인 => 현재 괄호가 )이고 top 위치의 괄호가 ( 여야 함
				if((char)stack.peek()=='(' && input.charAt(k)==')') {
					//괄호 짝이 맞음 -> pop
					stack.pop();
				}
				//매칭이 되지 않으면 스택에 추가
				else {
					stack.push(input.charAt(k));
				}
			}
			if(stack.empty()) System.out.println("YES"); else System.out.println("NO");;
		}	
	}
}

