package beakjoon_4963;

import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub		
		Scanner scan=new Scanner(System.in);
		int w, h;
		
		while(true) {
		w= scan.nextInt();//너비
		h=scan.nextInt();//높이
		
		if(w==0 && h==0) return;
		
		Area[][] matrix=new Area[h][w];
		
		
		Queue<Area> areaData=new LinkedList<>();
		
		
		for(int i=0; i<h; i++)
			for(int j=0; j<w;j++)
			{
				int n=scan.nextInt();
				matrix[i][j]=new Area();
				if(n==1) {					
					matrix[i][j].isMoveable=true;
					areaData.add(matrix[i][j]);//queue에다 일단 다 때려 넣기 
					
				}else {
					matrix[i][j].isMoveable=false;
				}
				matrix[i][j].x=i;
				matrix[i][j].y=j;
			}
		

		int count=0;//섬의 개수를 세는 변수 
	
		Queue<Area> queue=new LinkedList<>();
		queue.add(areaData.poll());//첫 번째 land 위치 queue에 삽입 
		
		while(queue.peek()!=null) {//방문할 land가 남아있다면 
			int x= queue.peek().x;
			int y=queue.peek().y;
			if(queue.peek().checked==false) {
				//위쪽으로 방문 가능한지
				if(x-1 >=0 && matrix[x-1][y].isMoveable==true && matrix[x-1][y].checked==true)
				{
				}
				//위 왼쪽 대각선으로 방문 가능한지
				else if(x-1 >=0 && y-1 >=0 && matrix[x-1][y-1].isMoveable==true && matrix[x-1][y-1].checked==true)
				{
				}
				//위 오른쪽 대각선으로 방문 가능한지
				else if(x-1 >=0 && y+1 < w && matrix[x-1][y+1].isMoveable==true && matrix[x-1][y+1].checked==true)
				{
				}
				//왼쪽으로도 방문 가능한지
				else if(y-1 >= 0 && matrix[x][y-1].isMoveable==true && matrix[x][y-1].checked==true ) {
					
				}
				//오른쪽으로 방문 가능한지
				else if(y+1<w && matrix[x][y+1].isMoveable==true && matrix[x][y+1].checked==true) {
				}
				//왼쪽 아래 대각선으로 방문 가능한지
				else if(y-1>=0 && x+1<h && matrix[x+1][y-1].isMoveable==true && matrix[x+1][y-1].checked==true) {
				}
				//아래쪽으로 방문 가능한지
				else if(x+1<h && matrix[x+1][y].isMoveable==true && matrix[x+1][y].checked==true) {
				}
				//오른쪽 아래 대각선으로 방문 가능한지 
				else if(y+1 < w && x+1 <h && matrix[x+1][y+1].isMoveable==true && matrix[x+1][y+1].checked==true) {

				}
				else
					count++;//섬의 개수 카운트
				queue.peek().checked=true; //방문 표시하고 
			}
				//위쪽으로 방문 가능한지
				if(x-1 >=0 && matrix[x-1][y].isMoveable==true && matrix[x-1][y].checked==false)
				{
					matrix[x-1][y].checked=true;
					queue.add(matrix[x-1][y]);
				}
				else if(y-1 >= 0 && matrix[x][y-1].isMoveable==true && matrix[x][y-1].checked==false ) {
					matrix[x][y-1].checked=true;
					queue.add(matrix[x][y-1]);
				}
				//위 왼쪽 대각선으로 방문 가능한지
				if(x-1 >=0 && y-1 >=0 && matrix[x-1][y-1].isMoveable==true && matrix[x-1][y-1].checked==false)
				{
					matrix[x-1][y-1].checked=true;
					queue.add(matrix[x-1][y-1]);
				}
				//위 오른쪽 대각선으로 방문 가능한지
				if(x-1 >=0 && y+1 < w && matrix[x-1][y+1].isMoveable==true && matrix[x-1][y+1].checked==false)
				{
					matrix[x-1][y+1].checked=true;
					queue.add(matrix[x-1][y+1]);
				}
				//오른쪽으로 방문 가능한지
				if(y+1<w && matrix[x][y+1].isMoveable==true && matrix[x][y+1].checked==false) {
					matrix[x][y+1].checked=true;//방문 표시 
					queue.add(matrix[x][y+1]);
				}
				//왼쪽 아래 대각선으로 방문 가능한지
				if(y-1>=0 && x+1<h && matrix[x+1][y-1].isMoveable==true && matrix[x+1][y-1].checked==false) {
					matrix[x+1][y-1].checked=true;
					queue.add(matrix[x+1][y-1]);
				}
				//아래쪽으로 방문 가능한지
				if(x+1<h && matrix[x+1][y].isMoveable==true && matrix[x+1][y].checked==false) {
					matrix[x+1][y].checked=true;
					queue.add(matrix[x+1][y]);
				}
				//오른쪽 아래 대각선으로 방문 가능한지 
				if(y+1 < w && x+1 <h && matrix[x+1][y+1].isMoveable==true && matrix[x+1][y+1].checked==false) {
					matrix[x+1][y+1].checked=true;
					queue.add(matrix[x+1][y+1]);
				}
			
			
			//모든 처리 마치고 해당 area 제거
				queue.poll();
				if(queue.peek()==null) {
					queue.add(areaData.poll());
				}
		}
		
		System.out.println(count);
		}

	}

}

class Area{
	int x,y;
	boolean isMoveable;
	boolean checked=false;
}