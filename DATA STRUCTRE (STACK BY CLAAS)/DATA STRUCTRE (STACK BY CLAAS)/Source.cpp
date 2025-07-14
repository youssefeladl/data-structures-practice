#include<iostream>
using namespace std;
const int maxsize = 5;
class stack
{
private:
	int stac[maxsize];
	int top = -1;
public:
	void push(int val)
	{
		if (top == maxsize - 1)
		{
			cout << "stack overflow" << endl;
		}
		else
		{
			top++;
			stac[top] = val;
		}
	}

	void display()
	{
		if (top == -1)
		{
			cout << "stack underflow"<<endl;
		}
		else
		{
			for (int i = top; i >= 0; i--)
			{
				cout << stac[i]<<" " ;
			}
		}
	}
	int pop()
	{
		if (top == -1)
		{
			cout << "stack under flow";
		}
		else
		{
			return stac[top--];
		}
	}

};
int main()
{
	stack S;
	S.push(10);
	S.push(15);
	S.push(20);
	S.push(25);
	S.push(30);
	S.display();
	cout << "display func before pop" << endl;
	S.pop();
	S.pop();
	S.display();
	cout << "display func after pop" << endl;
	S.push(-1);
	S.push(0);
	S.display();
	cout << "display func after input pop" << endl;

}