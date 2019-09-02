#include <map>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
       map<int, string> mp;
       mp[1]= "student_one";
       mp[2]= "student_two";
       mp[3]= "student_three";
       map<int, string>::iterator  iter;
       for(auto iter = mp.begin(); iter!= mp.end();iter++)
       {
          cout<<iter->first<<"   "<<iter->second<<endl;
       }
}
