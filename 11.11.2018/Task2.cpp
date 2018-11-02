#include <iostream> 
using namespace std; 
int main() 
{ 
int n; 
int a = 1; 
cout << "please enter n="; 
cin >> n; 
if (n % 2 != 0) { 
while (n != 0) { 
if (n % 10 % 2 != 0) { 
a *= n % 10; 
} 
else { 
a *= 1; 
} 
n /= 10; 
} 
} 
if (n % 2 == 0) { 
while(n!=0) 
{ 
if (n % 10 % 2 == 0) { 
a *= n % 10; 
} 
else { 
a *= 1; 
} 
n /= 10; 

} 
} 

cout << "mult=" << a << endl; 
return 0; 
}
