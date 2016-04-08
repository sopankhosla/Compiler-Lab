#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	//int mat[5][3] = {{2,1,2}, {5,1,3}, {1,5,4}, {3,4,5}, {5,4,3}}, r = 3;
	map<int,map<int,int> > mat;

	int r,c,rand;
	cout<<"enter number of rows"<<endl;
	cin>>r;
	cout<<"enter number of cols"<<endl;
	cin>>c;
	cout<<"enter the input state table"<<endl;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>rand;	
			if(rand!=-1)
				mat[i][j] = rand;
		}
	}
	
	string input;
	cout<<"Enter the input sequence: "<<endl;
	cin>>input;
	int state = 1, l = 0;
	while(l<input.length())
	{
		char c = input[l++];
		if (mat.find(state-1) != mat.end() && mat[state-1].find(c-'0') != mat[state-1].end())
			state = mat[state-1][c-'0'];	
		else break;
		cout<<"State after input "<< c <<" is: " << (char)((state-1)+'A')<< endl;	
	}
	if(state <= r && state >=0 && l == input.length())
		cout<<"The final state is: " << (char)((state-1)+'A')<< endl;
	else
		cout<<"Goes to phi state"<<endl;

	if(state == r)
		cout<<"Input Accepted"<<endl;
	else 	
		cout<<"Input Rejected"<<endl;

	return 0;
}

