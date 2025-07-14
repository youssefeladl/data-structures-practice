#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* top = NULL;
void push(int val)// alhya function insertbegan()
{
	node* new_node = new node;//3ml pointer yeshawer 3la node gdeeda
	new_node->data = val;//dakhlt alkeema
	new_node->next = top;//khletha teshawer 3la node alb3deaha 3n taree2 an lhead already betshawer 3leha ;
	top = new_node;
}
int pop()//deletegebagen()
{
	int value;
	if (top == NULL)
	{
		cout << "stack is empty" << endl;
	}
	else {
		node* first_node = top;
		top = first_node->next;
		value = first_node->data;
		free(first_node);
		return value;
	}
}
void display()
{
	node* current_node;
	if (top == NULL)
	{
		cout << "stack empty" << endl;
	}
	else {
		current_node = top;
		while (current_node != NULL)
		{
			cout << current_node->data << endl;
			current_node = current_node->next;
		}

	}
}
int peak()
{
	if (top == NULL)
	{
		cout << "stack empty" << endl;
	}
	else {
		return top->data;
	}
}
int main()
{
	push(5);
	push(10);
	push(15);
	push(20);
	push(25);
	display();//25 20 15 10 5
	cout << endl;
	pop();//hasheel 25
	cout << endl;
	display(); //20 15 10 5
	cout << endl;
	cout<<"peak element is :"<<peak();//20
	return 0;
}