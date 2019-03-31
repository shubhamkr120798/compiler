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
void follow(char c)
{
	if(p[0][0]==c)
	{
		l+='$';
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;p[i][j]!='\0';j++)
		{
			if(p[i][j]==c)
			{
				if(p[i][j+1]=='\0')
				{
					follow(p[i][0]);
				}
				else
				{
					first(p[i][j+1]);
				}
			}
		}
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
     for(int j=0;j<n;j++){
	char s;    cout<<"Enter the non-terminal you want to find follow for???"<<endl;
	cin>>s;
	follow(s);
	cout<<"Follow of "<<s<<" is"<<endl;   cout<<"{";
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
