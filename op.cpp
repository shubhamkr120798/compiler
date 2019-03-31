#include<bits/stdc++.h>
using namespace std;
void reduce(string& st,string& s,string&  temp,int i)
{
    while(true){
      char a = '#',b='#',c='#';
    if(!temp.empty()) { a = temp.back(); temp.pop_back();}  if(!temp.empty()) { b= temp.back(); temp.pop_back();}  if(!temp.empty()) { c = temp.back(); temp.pop_back();}
    if(a=='i')
    {
        if(c!='#')
      temp.push_back(c); if(b!='#') temp.push_back(b);
      temp.push_back('E');
cout<< st << "             " << s.substr(i,s.size()) << "              " << "pop & reduce" <<  "       " << temp << "\n";
}
else if(a=='E' && (b=='+' || b=='*') && a =='E')
   {
      temp.push_back('E');
cout<< st << "             " << s.substr(i,s.size()) << "              " << "pop & reduce" <<  "       " << temp << "\n";
}
else
{
if(c!='#')
      temp.push_back(c); if(b!='#') temp.push_back(b);
       if(a!='#')
      temp.push_back(a);
   break;
}
}
}     
int main()
{
    cout<< "operator preceedence parser" << "\n";
   cout<< "Given grammar" << "\n"; 
   cout<< "E->E+E"  << "\n";
   cout<< "E->E*E" << "\n";
   cout<< "E->i" << "\n";
   map<char,int> p,m;
   p[1] =1;
   p[2]=2;
   p[3]=3;
   p[4]=0; m['+'] =1;
   m['*']=2;
   m['i']=3;
   m['$']=0;
  char part[5][5];
    part[0][1]='+'; part[0][2] ='*'; part[0][3]='i'; part[0][4]='$';
    part[1][0]='+'; part[2][0]='*'; part[3][0]='i' ; part[4][0]='$';
   part[0][0]=' ';
   for(int i=1;i<5;i++)
{
    for(int j=1;j<5;j++)
{
     if(p[i]>p[j])
{
     part[i][j] = '>';
   }
else if(p[i]<p[j])
     part[i][j] = '<';
   else if(p[i]==p[j])
    part[i][j]= '=';
}}
cout<< "operator preceedence table" << "\n";
for(int i=0;i<5;i++)
 {
 for(int j=0;j<5;j++)
   cout<< part[i][j] << " ";
  cout<< "\n";
}
cout<< "Enter string to parse" <<  "\n";
  string s,temp=""; cin>>s;
  string st = ""; st.push_back('$');
  s= s+'$';
cout<< "stack" << "            " << "input" << "              " <<  "Action" <<   "           " << "temp" << "\n";
int i=0;
 stack<char> stk;
 while(i<s.size()-1)
{
      if(m[st.back()]< m[s[i]])
      {
       st.push_back(s[i]);
     
   cout<< st << "             " << s.substr(i+1,s.size()) << "              " << "shift" <<  "         "   << temp << "\n";
      }
     else 
{
      while(m[st.back()]>=m[s[i]])
{
       stk.push(st.back());
       st.pop_back();
     
 
}
   while(!stk.empty())
    {
     temp.push_back(stk.top()); stk.pop();}
 reduce(st,s,temp,i);
 st.push_back(s[i]);
   
cout<< st << "             " << s.substr(i+1,s.size()) << "              " << "shift" << "         " << temp <<"\n";
}
i++;
}
cout<< st << "\n";
int cnto =0, cnti =0;
if(st.back()!='$')
{
    
    for(int i=0;i<st.size();i++)
     {
     if(st[i]=='*' || st[i]=='+') cnto++;
     else if(st[i]=='i') cnti++;
     }
    for(int i=0;i<temp.size();i++)
{
      if(temp[i]=='*' || temp[i]=='+') cnto++;
     else if(temp[i]=='E') cnti++;
}
}
if(temp=="E" || (cnti==cnto+1))
cout<< "string is accepted" << "\n";
else 
cout<< "string not accepted" << "\n";
return 0;
}

 
