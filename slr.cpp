#include<bits/stdc++.h>
using namespace std;
int main()
{
   cout<< "slr parser" << "\n";
   cout<< "Given grammar" << "\n";
   cout<< "s->AA" << "\n";
   cout<< "A->aA" << "\n";
   cout<< "A->b" << "\n";
   string tab[8][6];
   tab[0][1]= "a" ; tab[0][2] = "b" ; tab[0][3]= "$"; tab[0][4]= "A"; tab[0][5]="S";
   for(int i=1;i<8;i++)
    tab[i][0]= to_string(i-1);
tab[0][0]= " " ;
  for(int i=1;i<8;i++)
{
   for(int j=1;j<6;j++)
{
    tab[i][j] = " ";
}}
tab[0][0] = "s3"; tab[0][1] = "s5"; tab[0][3] = "2"; tab[0][4] = "1"; 
tab[1][2] = "accept";
tab[2][0] = "s3"; tab[2][1] = "s4"; tab[2][3] ="5";
tab[3][0] = "s3"; tab[3][1] = "s4"; tab[3][3]="6";
tab[4][0] = "r3"; tab[4][1] = "r3"; tab[4][2] = "r3";
tab[5][2] = "r1";
tab[6][0] = "r2"; tab[6][1] = "r2"; tab[6][2] = "r2";
cout<< "slr parsing table" << endl;
cout<< "   " << "a" << " " << "b" << " " << "$" << " " << "A" << " " << "$" << "\n";

for(int i=0;i<7;i++)
{
   cout<< i << " ";
   for(int j=0;j<5;j++)
{
    
   cout<< tab[i][j] << " ";
  }
cout<< "\n";
}


cout<< "Enter the inp string" << "\n";
string s; cin>>s;
s+='$';
string st="";
int i=0; st.push_back('0');
map<char,int> m; m['a']= 0; m['b']=1; m['$'] = 2; m['A'] = 3; m['S'] = 4;

cout<< "stack" << "      " << "input" << "      " << "Action" << "\n";
while(i<s.size())
{
   string val = tab[st.back()-'0'][m[s[i]]];
  //cout<< val << " ";
   if(val[0]=='s')
  {   st.push_back(s[i]); st.push_back(val[1]);
      i++; 
     cout<< st << "       " << s.substr(i,s.size()) << "        " << "shift" << "\n";
 }
 else if( val[0]=='r')
{
       int ind = val[1]-'0';
     if(ind ==1)
     {
       for(int j=0;j<4;j++)
        st.pop_back();
     int v = st.back()-'0';
      st.push_back('S');
     if(tab[v][m['S']] =="accept")
     {
      cout<< "accepted" << "\n";
       return 0;
} 
    st+=(tab[v][m['S']]);
cout<< st << "       " << s.substr(i,s.size()) << "        " << "reduce:S->AA" << "\n";
    }
  else if(ind==2)
{
      for(int j=0;j<4;j++)
        st.pop_back();
     int v = st.back()-'0';
    //cout<< v << " ";
     //if(v==0) v=1;
      st.push_back('A');
 if(tab[v][m['A']] =="accept")
     {
      cout<< "accepted" << "\n";
       return 0;
} 
    st+=(tab[v][m['A']]);
cout<< st << "       " << s.substr(i,s.size()) << "        " << "reduce:A->aA" << "\n";
}
else if(ind ==3)
{
    for(int j=0;j<2;j++)
        st.pop_back();
     int v = st.back()-'0';
      st.push_back('A');
 if(tab[v][m['A']] =="accept")
     {
      cout<< "accepted" << "\n";
       return 0;
} 
    st+=(tab[v][m['A']]);
cout<< st << "       " << s.substr(i,s.size()) << "        " << "reduce:A->b" << "\n";
}
}
else
break;
}
if(st.back()=='1' && s.back()=='$')
cout<< "Accepted"<< "\n";
else
cout<< "not accepted" << "\n";
return 0;
}


