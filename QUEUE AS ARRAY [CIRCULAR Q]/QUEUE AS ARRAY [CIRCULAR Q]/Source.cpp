#include<iostream>
using namespace std;
#define size 5
int cqueue[size];
int front = -1, rear = -1;
bool isempty() //func 3shan yet2kd an queue faady khales mfesh feh ay values
{
	if (front == -1 && rear == -1)//da shart alwaheed an queue mafesh feh ay values
	{
		return true;//rag3ly an faady
	}
	else
	{
		return false;//yb2 rag3ly an feeh kaym
	}
}
bool isfull()//func 3shan yet2kd an queue mlyaaan homa sharteen
{
	if (front == 0 && rear == size - 1)// first case
	{
		return true;
	}
	else if (front == rear + 1)//second case
	{
		return true;
	}
	else
		return false;// yb2 m3na keda an feeh kaym bsmesh mlyaan
}
void enque(int val)
{
	if (isfull())//hyroh func isfull lw shart mn sharteen athh2 hytb3 over flow
	{
		cout << "			queue is overflow			"	 << endl;
	}
	else// 3 cases ala2dr astd5dmhom 3shan a3ml enqueue
	{
		if (isempty())//lw front =rear =-1 de first case wm3naha an keda al queue fady tmamn
		{
			front = 0, rear = 0;
			cqueue[rear] = val;
		}
		else if(rear == size - 1)//hena m3naha an rear wesl lel akherbs lesa feh amakn fadya fel queue
		{
			rear = 0;
			cqueue[rear] = val;
		}
		else
		{
			rear++;// da lw sharten tanyen mth22osh fbkml hena altabee3y 3ady
			cqueue[rear] = val;
		}
	}
}
void dequeue()
{
	if (isempty())// bta2kd an queuefady wla la
	{
		cout << "queue is under flow" << endl;// keda m3naha ano fady
	}
	else// 3 cases
	{
		if (front == rear)//m3naha an alo3nsr alna hmsho hwa al3onsr alakheer fm3naha an b3d mamshoo an queue hyb2 fady khalesf keda rg3t front wrear =-1 keda queue is empty
		{
			front = rear = -1;
		}
		else if (front == size - 1)//keda front wesl le akher indx fmsh hynf3 azwd btree2h takdleya fbrg3o lindx 0
		{
			front = 0;
		}
		else
		{
			front++;// de alhala tabe3ya keda 3mlt dequeue 3ady
		}
	}
}
int peak()// btrg3 keemt front
{
	return cqueue[front];
}
void display()//show
{
	if (isempty())//bt2kd an feeh 3nasr 3shan a2dr a3ml display 
	{
		cout << "queue is empty" << endl;
	}
	else {
		if (front <= rear)// alhala altabee3ya
		{
			for (int i = front; i <= rear; i++)
			{
				cout  << cqueue[i] << "	";
			}
		}
		else {// fe halt an front > rear fb3ml atneen for loop doll
			for (int i = front; i <size; i++)// mn awl mfront wa2fa lhd akhr indx
			{
				cout  << cqueue[i] << "	";
			}
			for (int i = 0; i <= rear; i++)//mn awl indx khaals lhd mal rear wa2fa
			{
				cout  << cqueue[i] << "	";
			}
		}
	}
}
int main()
{
	enque(5);
	enque(10);
	enque(15);
	enque(20);
	enque(25);
	cout << "queue element is :"; display();//5 10 15 20 25 
	cout << endl;
	enque(30);//queue is full
	dequeue();//5
	cout << "queue element after dequeu :"; display();//10 15 20 25
	cout << endl;
enque(6);//6 10 15 20 25
cout << "queue element after new enqueue: "; display();//10 15 20 25 6
cout << endl;
	cout << "peak element is : " << peak() << endl;//10
	return 0;
}