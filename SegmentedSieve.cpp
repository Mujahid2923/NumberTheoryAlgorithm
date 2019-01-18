#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll>prime;

void findPrime()
{
    ll n=100000;
    ll i,j;
    bool mark[n+1];

    memset(mark,false,sizeof mark);

    for( i=4; i<=n; i=i+2)
    {
        mark[i]=true;
    }

    mark[1]=true;

    for( i=3; i<=n; i=i+2)
    {
        if(mark[i]==false)
        {
            for( j=2; i*j<=n; j++)
            {
                mark[i*j]=true;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        if(mark[i]==false)
        {
            prime.push_back(i);
        }
    }
}

ll segmentedSieve(ll a,ll b)
{
    ll i,p,j;
    bool arr[b-a+1];
    memset(arr,false,sizeof arr);

    if(a==1)
    {
        a++;
    }
    ll sqrtb=sqrt(b);

    for( i=0; i<prime.size() && prime[i]<=sqrtb; i++)
    {
        p=prime[i];
        j=p*p;
        if(j<a)
        {
            j=((a+p-1)/p)*p;
        }
        for(; j<=b; j=j+p)
        {
            arr[j-a]=true;
        }
    }

    for(i=a; i<=b; i++)
    {
        if(arr[i-a]==false)
        {
            printf("%lld \n",i);
        }
    }
    printf("\n");
}

int main()
{
    ll a,b,t;
    cin>>t;
    findPrime();
    for(ll i=0; i<t; i++)
    {
        cin>>a>>b;
        segmentedSieve(a,b);
    }
    return 0;
}
