/* Below Stack implementation program is written in C++ language */
# include<iostream>
using namespace std;
const int n=10;
int top;
int Stack[n]; //Maximum size of Stack

void printStack();

void printStack()
{
	if (top<0) cout << "Stack Underflow \n";
	else
		for (int i=0; i<=top; i++)
			cout<<"stack["<<i<<"]="<<Stack[i]<<endl;
}
// main function
int main() 
{
	int c,m;
	top=-1;
	do
	{
		cout<<"Enter 1 to insert new element "<<endl;
		cout<<"Enter 2 to delete top element "<<endl;
		cout<<"Enter 3 to print stack elements "<<endl;
		cout<<"Enter 4 to Exit "<<endl;
		cout<<"Enter your choice  :";
		cin>>c;
		switch (c)
		{
		case 1 : if (top>=n-1) 
					cout<<" Stack is full"<<endl;
				else 
				{
				 cout<<"Enter new elements : ";
				 cin>>m;
				 top = top + 1;
				 Stack[top] = m;
				}
				 break;
		case 2 : if (top<0) 
					cout<<" Stack is Empty"<<endl;
				else 
				{
				 m = Stack[top];
				 top = top -1;
				 cout<<"deleting element "<<m<<endl;
				}
				 break;
		case 3 : printStack();break;
		case 4 : exit;break;
		default : cout<<" Error choice !!"<<endl;
		}
	} while (c != 4);
}
