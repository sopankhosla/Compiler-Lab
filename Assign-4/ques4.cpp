#include <iostream>
#include <string>

using namespace std;

int i;
string input;

bool S()
{
	int isave = i;
	if(input[i] == 'a')
	{
		i++;
		if(S())
		{
			if(input[i] == 'a')
			{
				i++; 
				return true;
			}
		}
	}

	i = isave;

	if(input[i] == 'a')
	{
		i++;
		if(input[i] == 'a')
		{
			i++;
			return true;
		}
	}

	return false;
}

int main()
{
	i = 0;

	cout<<"Enter an arithmetic expression"<<endl;
	cin>>input;

	bool result = S();

	if(input.size()==i && result)
	{
		cout<<"Accepted"<<endl;
	}
	else cout<<"Rejected"<<endl;
	
}