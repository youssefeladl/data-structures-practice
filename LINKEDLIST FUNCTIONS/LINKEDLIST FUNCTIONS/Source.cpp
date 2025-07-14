#include<iostream>
using namespace std;
struct node
{
	int data;
	node* next;//node da data type wl next da asm pointer
};
node *head = NULL;// m3naha an pointer alasmo head da mesh byshawer 3la haga
void insert_item(int val)//insert end
{
	node* new_node,*last;//3ml 2 pointer
	new_node = new node;//5la alpointer alasmo new_node yehgzly node gdeeda wyeshawer 3leha
	new_node->data = val;//rah khazn data fe goz2 ldata fe new_node
	if (head == NULL)//byt2kd an node albdkhlha hya awl node wla la
	{
		head = new_node;//5la lhead yeshawr 3la new node alahna 3mlnaha gdeed
		new_node->next = NULL;//m3naha an mafesh haga b3deha fbtshawer 3la null
	}
	else {//da fe halet an node alhdkhlha yekon ablha kza node
		last = head;//m3naha ano hykhleh yeshawer 3la awl node
		while (last->next != NULL)//lw = null yb2 m3naha an de akher node 3ndy
		{
			last = last->next;//m3naha bkhush 3la node alb3deeha
		}
		last->next = new_node;//keda hayshawer 3la node algdeeda
		new_node->next = NULL;//wkeda alnode lgdeeda htb2 akher node 3ndy
	}
}
void display()
{
	node* current_node;//3rf pointer byshawer 3la node
	if (head == NULL)//m3naha anha fadya
	{
		cout << "linkedlist is empty" << endl;
	}
	else
	{
		current_node = head;//khla pointer yeshawer 3la awl node
		while (current_node != NULL)//m3na an hwa not= null fm3naha ano byshawer 3la node
		{
			cout  << current_node->data <<" ";//hy3rd value
			current_node = current_node->next;//bykhush 3la node alb3deha
		}
	}
}
void deleteitem(int val)
{
	node* current, * previous;//3ml 2 pointer byshawro wahd hyshawr 3la node al3yzen nemshaa wltany hyshawer 3la node alablha 3ltool
	current = head;//hybd2 mn awl nood
	previous = head;//hybd2 mn awl nood
	if (current->data == val)//m3naha an currenet byshawer 3la nafs albyshawer 3leh head
	{//da fe halt an node al3yzen nemsha awl node 3ndy
		head = current->next;//hakhly head yeshawer 3la node alb3dha
		free(current);//3mlha delete
		return;
	}
	while (current->data != val)
	{//fe halt anha mesh awl node
		previous = current;	
		current = current->next;//byshawer 3la node alb3dha
	}//fe halt ano = value
	previous->next = current->next;//fhkhly node alablha teshawer 3la alkant node al3ndy meshawra 3leh 
	free(current);//3mlha delete
}
void insert_began(int val)
{
	node* new_node = new node;//3rf pointer wkhlah yeshawer 3la node gdeeda
	new_node->data = val;	//khazn feh value
	new_node->next = head;//khlah yeshawer 3la alkan byshawer 3leh alhead 3shan awl 3onsr 
	head = new_node;//khla al head teshawer 3la node lgdeda alhya ahna 3mlnaha 3shan ahna 3mlnha awl wahda 
}
void delete_began()
{
	if (head == NULL) {//mfesh3naser
		cout << "linked list empty" << endl;
	}
	else
	{
		node* first_node = head;//3ml node gdeeda wkhlaha teshawer 3la alkan byshawer 3leh al head
		head = first_node->next;//khlena head yeshawer 3la node lb3d node al2oola
		delete(first_node);//3mlnlha delete
	}
}
void delete_last()
{
	if (head == NULL)//m3naha anha fadya
	{
		cout << "linked list is empty" << endl;
	}
	else if (head->next == NULL)//m3naha an mafesh 8er node wahdabs
	{
		delete(head);//keda 3mlnlha delete
		head = NULL;
	}
	else {//m3naha an feeh aktr mn node
		node* ptr = head;//3mlna pointer yeshawer 3la awl node
		while (ptr->next->next  != NULL)//3shan yet2kd an feeh aktr mn node wde m3naha goz2 lnext fel node lb3d lna wa2f 3leha lw bysway null yb2 de akher node 3ndy 
		{
			ptr = ptr->next;//hakhleeh yekhush 3la node alb3deeha 
		}
		delete(ptr->next);//3shan nehzf node alakhera 3shan loop kant btet2kd mn alabl alakheera
		ptr->next = NULL;
	}
}
 
int main()
{
	insert_item(10);
	insert_item(15);
	insert_item(20);
	display();//10 15 20
	insert_began(5);
	cout << endl;
	display();//5 10 15 20
	cout << endl;
	 delete_began();
	 display();//10 15 20
	delete_last();
	cout<< endl;
 display();//10 15
  deleteitem(15);
  cout << endl;
  display();//10

}