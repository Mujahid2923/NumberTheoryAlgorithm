///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#define    ll      long long int
#define    siz     1000005
#define    mod     1000003

using namespace std;

ll arr[siz];

ll fact()
{
    arr[0]=1;
    arr[1]=1;
    for(ll i=2; i<=siz; i++)
    {
        arr[i]=(((i%mod)*(arr[i-1])%mod))%mod;
    }
}

ll power(ll x,ll y,ll m)
{
    if(y==0)
        return 1;
    if(y%2==0)
    {
        ll ret=power(x,y/2,m);
        return ((ret%m)*(ret%m))%m;
    }
    else
        return ((x%m)*(power(x,y-1,m)%m))%m;
}

int main()
{
    ll t,n,r;
    fact();
    cin>>t;
    for(ll i=1; i<=t; i++)
    {
        scanf("%lld %lld",&n,&r);
        ll k=(arr[n-r]*arr[r])%mod;
        ll kinv=power(k,mod-2,mod);///mod Inverse
        ll ans=((arr[n]%mod)*(kinv%mod))%mod;
        printf("Case %lld: %lld\n",i,ans%mod);
    }
    return 0;
}

///Getting nCr
