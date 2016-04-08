#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;


int main()
{
	int alph[100], accept[100], size=0, states=0;

	string mat[100][100];
	map<string, map<int, string> > md;
	// accept states as binary string and parse to get the individual states

	cout<<"Enter size of alphabet"<<endl;
	cin>>size;

	cout<<"Enter the alphabet"<<endl;
	char temp; int temp2;
	
	for(int i=0;i<size;i++)
	{
		cin>>temp;
		alph[i] = (int)(temp-'a');
		cout<<endl<<"alphabet "<<alph[i]<<endl;
	}
	cout<<"Enter the state table"<<endl;

	cout<<"Enter number of states"<<endl;
	cin>>states;

	for(int i=0;i<states;i++)
	{
		for(int j=0;j<size;j++)
		{
			cout<<"Enter for "<<i<<" state and "<<alph[j]<<" input"<<endl;
			cin>>mat[i][j];
			cout<<endl<<"mat "<<mat[i][j]<<endl;
		}
	}

	cout<<"Enter accepting states"<<endl;
	cin>>temp2;
	
	int i=0;
	while(temp2!=-1)
	{
		accept[i] = temp2;
		cout<<endl<<"accepted states "<<accept[i]<<endl;
		i++;
		cin>>temp2;
	}
	cout<<"input taken successfully"<<endl;
	// insert qo to the list
	// using the trasition function find the next states
	// insert them to the list
	// do it again while no further states are added to the list
	
	// using binary to represent the numbers

	set<string> storage,temp_store;
	storage.insert("1000");
	temp_store.insert("1000");
	cout<<"created both sets"<<endl;
	while(1)
	{
		int count =0;
		std::set<string>::iterator it;
		cout<<"inside while loop"<<endl;
		for(it = storage.begin(); it !=storage.end(); ++it)
		{
			cout<<"current state "<<*it<<endl; 
			for(int i=0;i<states;i++)
			{	
				if((*it)[i] == '1')
				{		
					cout<<"current state "<<*it<<endl;			
					for(int j=0;j<size;j++)
					{
						if(temp_store.find(mat[i][j]) == temp_store.end())
						{
							cout<<"current state ka mat "<<*it<<endl;
							temp_store.insert(mat[i][j]);
							count++;
						}
						if(mat[i][j] != "0000")
								md[*it][j] = mat[i][j];
							cout<<"the matrix value "<<md[*it][j]<<endl;
					}
				}
			}
		}
		std::copy(temp_store.begin(), temp_store.end(), std::inserter(storage, storage.end()) );
		if(count == 0)
			break;
	}
	md["0000"][0] = "0000";
	md["0000"][1] = "0000";
	md["0110"][1] = "0101";

	map<string, map<int, string> >::iterator it;
	for(it = md.begin(); it != md.end(); it++)
	{
		for(int i=0;i<size;i++)
		{
			cout<<"The state "<<it->first<<" and input "<<i<<" : "<<it->second[0] <<endl;
		}
	}
	cout<<md["0101"][0]<<endl;

	
	




	
	

	
}
