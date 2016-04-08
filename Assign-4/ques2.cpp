#include <iostream>
#include <string>

using namespace std;

int i;
string input;

bool S()
{
	int isave = i;
	cout<<"isave: "<<i<<endl;
	
	if(input[i] == 'a')
	{
		i++;
		cout<<"isave: "<<i<<endl;
		if(S())
		{
			if(input[i] == 'b')
			{
				i++;
				cout<<"isave: "<<i<<endl;
				if(S())
				{
					return true;
				}
			}
		}
	}
	
	i = isave;
	cout<<"isave: "<<i<<endl;

	if(input[i] == 'b')
	{
		i++;
		cout<<"isave: "<<i<<endl;
		if(S())
		{
			if(input[i] == 'a')
			{
				i++;
				cout<<"isave: "<<i<<endl;
				if(S())
				{
					return true;
				}
			}
		}
	}

	i = isave;
	cout<<"isave: "<<i<<endl;

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