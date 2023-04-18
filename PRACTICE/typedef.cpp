//typedef is used to use shortcut for struct.

#include <bits/stdc++.h>

using namespace std;

typedef struct employee{int id_no; char division; string nick_name;}ep;

int main()
{
  ep Harry;
  Harry.id_no = 1;
  Harry.division = 'A';
  Harry.nick_name = "jojo" ;
  cout<<Harry.nick_name;

}

//union is used when we only  one data of the array is accesed at a time -->same as struct(syntax)
//helps to reduce time and memory