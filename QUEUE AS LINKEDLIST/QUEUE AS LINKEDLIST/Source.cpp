#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* front = NULL;//byeshawer 3la null y3ny lesa mbd3nash linked list de ltarkeeba albastkhdmha
node* rear = NULL;//byeshawer 3la null y3ny lesa mbd3nash linked list de ltarkeeba albastkhdmha
void enqueue(int val)//func 3shan adkhl values
{
	node* new_node = new node;//3rf pointer gdeed w3ml node gdeeda wkhla pointer yeshawer 3leeh
	new_node->data = val;//dakhl value
	new_node->next =NULL;//khla goz2 next alfe node de yeshawer 3la NULL
	if (front== NULL)//fe halt an an node de awl node hadkhlha fe linkedlist 
	{
		front = rear = new_node;//khlet front wrear yeshawro 3la node gdeeda al3mltlha badl null
	}
	else {//fe halt an kan feeh kza node abl ma3ml node gdeeda wadkhlha fe linkedlist
		rear->next = new_node;//hakhly rear alfe node alakhera yeshawer 3la node algdeeda al lesa 3mlha
		rear = new_node;//khleet rear yeshawr 3la node gdeeda
	}
}
void dequeue()//delete value from the start of linkedlist
{
	if (rear == NULL)//bt2kd fadya wla la
	{
		cout << "queue empty";
	}
	else if (front == rear)//fe halet an queue fe 3onsr wahed only
	{
		node* ptr = front;//3mlt pointer yeshawer 3la node lhya m3ndesh 8erha aslun 3shan ahzfha
		front = rear = NULL;//keda mb2aash feh ay nodes frg3t khlet front w rear yeshwro 3la null
		delete(ptr);//masht value
	}
	else// fe haleet an feeeh aktr mn 3onsor
	{
		node* ptr = front;//nfs sequnecekhleet pointer yeshawer 3la awl node 3ndy
		front =front->next;//khleet front yeshawer 3la al3onsor alb3do 3shan khlas hamsh node de
		delete(ptr);//khlas mashtha keda
	}
}
void display()
{
	if (front == NULL)//queue fady
	{
		cout << "queue empty";
	}
	else {
		node* current = front;//3mlt pointer yeshawer 3la awl node (awl 3onser 3ndy)
		while (current != NULL)//tool mhwa maswaash null yb2h keda feh nodes wfee 3naaseer
		{
			cout << current->data << "	 ";//ytb3 keema
			current = current->next;//ykhush 3la node alb3deeha lhd mywsl ano yesawy null fkhlas keda wesl le akher node
		}
	}
}
int peek()
{

	if (front == NULL)
	{
		cout << "queue empty";
		return -1;
	}
	else {
		return front->data;
	}
}
int main()
{
	enqueue(5);
	enqueue(10);
	enqueue(15);
	enqueue(20);
	enqueue(25);
	display();// 5 10 15 20 25
	cout << endl;
	dequeue();//hysheel 5
	display(); // 10 15 20 25
	cout << endl;
	cout<<"	peak element is :"<<peek();//10
	return 0;
}