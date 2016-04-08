#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main()
{
	map< char, list <string> > expansion;
	char c, start_state;
	string input_string;

	while(true)
	{
		cin>>c;
		if(c=='$')
			break;

		list<string> list_prod;

		while(true)
		{
			cin>>input_string;
			if(input_string == "$")
				break;
			list_prod.push_back(input_string);			
		}

		expansion[c] = list_prod;		
	}

	cout<<"Enter start symbol"<<endl;
	cin>>start_state;

	//list<string> t = expansion['S'];

	map< char, list <string> > :: iterator it;
	list<string>::iterator li;

	/*list<string> t = expansion[start_state];
	cout << "key= " << start_state;
	cout<< " -> ";
	for(li = (it->second).begin(); li!= (it->second).end(); li++)
	{
		cout<<*li;
	}*/

	for(it = expansion.begin(); it!=expansion.end(); it++)
	{
		cout << "key= " << it->first;
		cout<< " -> ";
		for(li = (it->second).begin(); li!= (it->second).end(); li++)
		{
			cout<<*li;
		}
		cout<<endl;
	}

}