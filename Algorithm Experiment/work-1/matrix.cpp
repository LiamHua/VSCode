#include<iostream>
#include<iomanip>
using namespace std;

void matrix(int n)
{
	int num = 2;
	int r=0;                      //row
	int c=0;                      //column
	//creat a dynamic array
	int** array = new int*[n];
	for(int i=0;i<n;i++)
		array[i] = new int[n];
	
	array[r][c] = 1;
	while(true)
	{
		if(r==n-1&&c==n-1)
			break;
		if(r==0&&c!=n-1)
		{
			c = c + 1;
			array[r][c] = num;
			num = num + 1;
			while(c!=0)
			{
				r = r + 1;
				c = c - 1;
				array[r][c] = num;
				num = num + 1;
			}	
		}
		if(c==0&&r!=n-1)
		{
			r = r + 1;
			array[r][c] = num;
			num = num + 1;
			while(r!=0)
			{
				c = c + 1;
				r = r - 1;
				array[r][c] = num;
				num = num + 1;
			}	
		}
		if(c==n-1)
		{
		    r = r + 1;
		    array[r][c] = num;
		    num = num + 1;
		    while(r!=n-1)
		    {
		        r = r + 1;
		        c = c - 1;
		        array[r][c] = num;
		        num = num + 1;
		    }
		}
		if(r==n-1)
		{
		    c = c + 1;
		    array[r][c] = num;
		    num = num + 1;
		    while(c!=n-1)
		    {
		        r = r - 1;
		        c = c + 1;
		        array[r][c] = num;
		        num = num + 1;
		    }
		}
	}
	//show
	for(int g=0;g<n;g++)
	    for(int h=0;h<n;h++)
	    {
	        cout<<std::left<<setw(4)<<array[g][h];
	        if(h==n-1)
	            cout<<endl;
	    }
	//Free memory	
	for (int i = 0; i < n; i++)
		delete []array[i];
	delete []array;
}

int main()
{
	int n;
	cout<<"Please enter a number:";
	cin>>n;
	matrix(n);
}