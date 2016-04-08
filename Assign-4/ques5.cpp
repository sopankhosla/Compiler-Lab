#include <iostream>
#include <string>

using namespace std;

int i;
string input;

bool execute(int i, int j, char c)
{
	if(c == 'a')
	{
		return (i==j) && (input[i] == c);
	}
	else
	{
		if(i >= j) 
			return false;
		return (execute(i,i,'a') && execute(j,j,'a') && ((i<j-1)?execute(i+1, j-1, 's'):true));
	}
}

int main()
{
	i = 0;

	cout<<"Enter an arithmetic expression"<<endl;
	cin>>input;

	if(execute(0, input.length()-1, 'S'))
	{
		cout<<"Accepted"<<endl;
	}
	else cout<<"Rejected"<<endl;
	
}