#include<stdio.h>
#include<vector>
using namespace std;
vector<vector<int>> ps;
void PSet(int n)
{
    vector<vector<int>> ps1;
    vector<vector<int>>::iterator it;
    vector<int> s;
    ps.push_back(s);
    for (int i = 1; i <= n; i++)
    {
        ps1 = ps;
        for(it=ps1.begin();it!=ps1.end();++it)
            (*it).push_back(i);
        for (it = ps1.begin();it!=ps1.end();++it)
            ps.push_back(*it);
    }
    
}
void dispps()
{
    vector<vector<int>>::iterator it;
    vector<int>::iterator sit;
    for(it = ps.begin();it != ps.end();++it)
    {
        printf("{");
        for (sit = (*it).begin();sit != (*it).end();++sit)
            printf("%d",*sit);
		printf("} ");
    }
	printf("\n");
}
int main()
{
	int n = 3;
	PSet(n);
	printf("1~%d的幂集:\n",n);
	dispps();
}