
#include <iostream>
using namespace std;

int steps = 0;

int fibonacci(int n){
    steps++;
    if(n<=1)
        return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Fibonacci series : ";
    for (int i = 1; i <= n; i++)
    {
       cout<< fibonacci(i)<<" ";
    }
    
    cout<<"\nStep Count: "<<steps;
}