#include<bits/stdc++.h>
using namespace std;
int phi[10000];
void toshient(int n,int x)
{
    int phi[n];
    for(int i=1; i<n; i++)
    {
        phi[i]=i;
    }
    for(int i=2; i<n; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<n; j+=i)
            {
                phi[j]-=phi[j]/i;
            }
        }
    }
    cout<<phi[x]<<endl;
}

int main()
{
    int x;
    cin>>x;
    toshient(100,x);
}

----------------------------------------Sqrt(n) Complexity--------------------------------------
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++) 
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n /= i;
            }
            result -= result / i;
        }
    }
    if(n > 1)
    {
        result -= result / n;
    }
    return result;
}
