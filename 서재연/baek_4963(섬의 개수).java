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
		w= scan.nextInt();//�ʺ�
		h=scan.nextInt();//����
		
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
					areaData.add(matrix[i][j]);//queue���� �ϴ� �� ���� �ֱ� 
					
				}else {
					matrix[i][j].isMoveable=false;
				}
				matrix[i][j].x=i;
				matrix[i][j].y=j;
			}
		

		int count=0;//���� ������ ���� ���� 
	
		Queue<Area> queue=new LinkedList<>();
		queue.add(areaData.poll());//ù ��° land ��ġ queue�� ���� 
		
		while(queue.peek()!=null) {//�湮�� land�� �����ִٸ� 
			int x= queue.peek().x;
			int y=queue.peek().y;
			if(queue.peek().checked==false) {
				//�������� �湮 ��������
				if(x-1 >=0 && matrix[x-1][y].isMoveable==true && matrix[x-1][y].checked==true)
				{
				}
				//�� ���� �밢������ �湮 ��������
				else if(x-1 >=0 && y-1 >=0 && matrix[x-1][y-1].isMoveable==true && matrix[x-1][y-1].checked==true)
				{
				}
				//�� ������ �밢������ �湮 ��������
				else if(x-1 >=0 && y+1 < w && matrix[x-1][y+1].isMoveable==true && matrix[x-1][y+1].checked==true)
				{
				}
				//�������ε� �湮 ��������
				else if(y-1 >= 0 && matrix[x][y-1].isMoveable==true && matrix[x][y-1].checked==true ) {
					
				}
				//���������� �湮 ��������
				else if(y+1<w && matrix[x][y+1].isMoveable==true && matrix[x][y+1].checked==true) {
				}
				//���� �Ʒ� �밢������ �湮 ��������
				else if(y-1>=0 && x+1<h && matrix[x+1][y-1].isMoveable==true && matrix[x+1][y-1].checked==true) {
				}
				//�Ʒ������� �湮 ��������
				else if(x+1<h && matrix[x+1][y].isMoveable==true && matrix[x+1][y].checked==true) {
				}
				//������ �Ʒ� �밢������ �湮 �������� 
				else if(y+1 < w && x+1 <h && matrix[x+1][y+1].isMoveable==true && matrix[x+1][y+1].checked==true) {

				}
				else
					count++;//���� ���� ī��Ʈ
				queue.peek().checked=true; //�湮 ǥ���ϰ� 
			}
				//�������� �湮 ��������
				if(x-1 >=0 && matrix[x-1][y].isMoveable==true && matrix[x-1][y].checked==false)
				{
					matrix[x-1][y].checked=true;
					queue.add(matrix[x-1][y]);
				}
				else if(y-1 >= 0 && matrix[x][y-1].isMoveable==true && matrix[x][y-1].checked==false ) {
					matrix[x][y-1].checked=true;
					queue.add(matrix[x][y-1]);
				}
				//�� ���� �밢������ �湮 ��������
				if(x-1 >=0 && y-1 >=0 && matrix[x-1][y-1].isMoveable==true && matrix[x-1][y-1].checked==false)
				{
					matrix[x-1][y-1].checked=true;
					queue.add(matrix[x-1][y-1]);
				}
				//�� ������ �밢������ �湮 ��������
				if(x-1 >=0 && y+1 < w && matrix[x-1][y+1].isMoveable==true && matrix[x-1][y+1].checked==false)
				{
					matrix[x-1][y+1].checked=true;
					queue.add(matrix[x-1][y+1]);
				}
				//���������� �湮 ��������
				if(y+1<w && matrix[x][y+1].isMoveable==true && matrix[x][y+1].checked==false) {
					matrix[x][y+1].checked=true;//�湮 ǥ�� 
					queue.add(matrix[x][y+1]);
				}
				//���� �Ʒ� �밢������ �湮 ��������
				if(y-1>=0 && x+1<h && matrix[x+1][y-1].isMoveable==true && matrix[x+1][y-1].checked==false) {
					matrix[x+1][y-1].checked=true;
					queue.add(matrix[x+1][y-1]);
				}
				//�Ʒ������� �湮 ��������
				if(x+1<h && matrix[x+1][y].isMoveable==true && matrix[x+1][y].checked==false) {
					matrix[x+1][y].checked=true;
					queue.add(matrix[x+1][y]);
				}
				//������ �Ʒ� �밢������ �湮 �������� 
				if(y+1 < w && x+1 <h && matrix[x+1][y+1].isMoveable==true && matrix[x+1][y+1].checked==false) {
					matrix[x+1][y+1].checked=true;
					queue.add(matrix[x+1][y+1]);
				}
			
			
			//��� ó�� ��ġ�� �ش� area ����
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