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


vector<int> v,vec;
bool prime[ 100000+5 ];

void findPrime( int n )
{
    for( int i = 0 ; i <= n ; i ++ )
    {
        prime[ i ] = false ;
    }

    for( int i = 4 ; i <= n ; i += 2 )
    {
        prime[ i ] = true ;
    }

    prime[1] = true ;

    for( int i = 3 ; i*i <= n ; i+= 2 )
    {
        if(!prime[i])
        {
            for( int j = 2 ; i*j <= n ; j++ )
            {
                prime[ i*j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        if( !prime[i] )
        {
            v.pb( i );
        }
    }
}

ll phi(ll n)
{
    ll result = n;
    for (int i = 0 ; v[i] * v[i] <= n; i++ )
    {
        if(n % v[i] == 0)
        {
            while(n % v[i] == 0)
            {
                n /= v[i];
            }
            result -= result / v[i] ;
        }
    }

    if(n > 1)
    {
        result -= result / n ;
    }
    return result;
}

int main()
{
    findPrime(100000) ;
    ll n ;

    while( cin >> n && n != 0)
    {
        ll ans = phi(n);
        pf( "%d\n" , ans );
    }

    return 0;
}

