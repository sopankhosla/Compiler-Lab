#include <iostream>
#include <string>

using namespace std;

int i;
string input;

bool E();
bool F();
bool EPrime();
bool T();
bool TPrime();
bool F();

bool E()
{
	int isave = i;
	
	if(T())
	{
		if(EPrime())
		{
			return true;
		}
	}
	
	return false;
}

bool EPrime()
{
	int isave = i;
	if(input[i] == '|')
	{
		i++;
		if(T())
		{
			if(EPrime())
			{
				return true;
			}
		}
	}
	i = isave;
}

bool T()
{
	int isave = i;
	if(F())
	{
		if(TPrime())
		{
			return true;
		}
	}
	else return false;
}

bool TPrime()
{
	int isave = i;
	if(input[i] == '&')
	{
		i++;
		if(F())
		{
			if(TPrime())
			{
				return true;
			}
		}
	}
	i = isave;
}

bool F()
{
	int isave = i;
	if(input[i] == '$')
	{
		i++;
		if(F())
		{
			return true;
		}
	}

	i = isave;
	if(input[i] == '(')
	{
		i++;
		if(E())
		{
			if(input[i] == ')')
			{
				i++;
				return true;
			}
		}
	}

	i = isave;
	if(input[i] == '0')
	{
		i++;
		return true;
	}
	if(input[i] == '1')
	{
		i++;
		return true;
	}
	return false; 	
}

int main()
{
	i = 0;

	cout<<"Enter an arithmetic expression"<<endl;
	cin>>input;

	bool result = E();

	if(input.size()==i && result)
	{
		cout<<"Accepted"<<endl;
	}
	else cout<<"Rejected"<<endl;
	
}