#include <iostream>
using namespace std;
int main()
{
int n;
int sum=0;
cout«"please, enter n=";
cin»n;
while(n!=0)
{
if(n%10%2!=0){
sum+=n%10;
}
else{
sum+=0;
}
n/=10;
}
cout«"sum="«sum«endl;
return 0;
}
