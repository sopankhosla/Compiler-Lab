#include <iostream>
#include <string>
using namespace std;
int main()
{
	int mat[5][3] = {{2,1,2}, {5,1,3}, {1,5,4}, {3,4,5}, {5,4,3}};
	string input;
	cout<<"Enter the input sequence: "<<endl;
	cin>>input;
	int state = 1, l = 0;
	while(l<input.length())
	{
		char c = input[l++];
		switch(state)
		{
			case 1: state = mat[0][c-'0'];
				break;
			case 2: state = mat[1][c-'0'];
				break;
			case 3: state = mat[2][c-'0'];
				break;
			case 4: state = mat[3][c-'0'];
				break;
			case 5: state = mat[4][c-'0'];
				break;
		}
		
	}
	cout<<"The final state is: " << (char)((state-1)+'A')<< endl;
	return 0;
}

