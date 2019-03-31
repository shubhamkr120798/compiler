#include<bits/stdc++.h>
using namespace std;
char p[10][100];
int n;
string l;
void first(char c)
{
	for(int i=0;i<n;i++)
	{
		if(p[i][0]==c)
		{
			if(p[i][2]>='A'&&p[i][2]<='Z')
			{
				first(p[i][2]);   
			}
			else if(p[i][2]=='$')
			{
				l+=p[i][2];   //return;
			}
			else
			{
				l+=p[i][2];   //return;
			}
		}
		//cout<<p[i][0]<<" "<<l<<endl;
	}
}
int main()
{
	int i,j;
	cout<<"Enter the number of grammer"<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
    for(int j=0;j<n;j++)
{
	char s;    cout<<"Enter the non-terminal you want to find first for???"<<endl;
      
	cin>>s;
	first(s);
	cout<<"First of "<<s<<" is"<<endl;   cout<<"{";
	for(i=0;i<l.size();i++)
	{
		cout<<l[i]<<" ";
	}
	cout<<"}";
	//cout<<l<<endl;
   l.clear();
}
	return 0;
}
