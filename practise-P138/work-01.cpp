#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int>> ps;
void Insert(vector<int> s,int i,vector<vector<int>> &ps1)
{	
    vector<int> s1;
	vector<int>::iterator it;
	for (int j=0;j<i;j++)						
	{	
        s1=s;
		it=s1.begin()+j;						
		s1.insert(it,i);						
		ps1.push_back(s1);						
	}
}
void Perm(int n)								
{	
    vector<vector<int>> ps1;					
	vector<vector<int>>::iterator it;			
	vector<int> s,s1;
	s.push_back(1);
	ps.push_back(s);							 
	for (int i=2;i<=n;i++)						
	{	
        ps1.clear();							
		for (it = ps.begin();it != ps.end();++it)
			Insert(*it,i,ps1);					
		ps = ps1;
	}
}
void dispps()									
{	
    vector<vector<int>>::reverse_iterator it;	
	vector<int>::iterator sit;					
	for (it = ps.rbegin();it != ps.rend();++it)
	{	
        for (sit = (*it).begin();sit != (*it).end();++sit)
			printf("%d",*sit);
		printf("  ");
	}
	printf("\n");
}
int main()
{	
    int n = 3;
	printf("1～%d的全排序如下:\n",n);
	Perm(n);
	dispps();
}