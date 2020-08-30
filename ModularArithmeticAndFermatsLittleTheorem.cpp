
ll power( ll x,ll y,ll m )
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x , y/2 , m ) ;
        return ( ( ret % m ) * ( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) *( power( x , y-1 , m ) % m ) ) % m ;
}

ll modInverse( ll a, ll m )
{
    return power( a , m - 2 , m ) ;
}


-----------------------------------------Uva 12619------------------------------------------


vl v, v1, v2 ;
//vector < pll > vec ;
map < ll, ll > Mp ;
set < ll > st ;
deque < ll > dq ;


bool mark[ 1000000 + 5 ];
ll pd[ 1000000 + 5 ];

void findPrime()
{
    for ( ll i = 2; i <= 1000000 ; i+= 2)
    {
        pd[ i ] = 2;
    }

    for ( ll i = 3; i <= 1000000 ; i += 2 )
    {
        if ( !mark[ i ] )
        {
            pd[ i ] = i ;
            for ( ll j = i ; ( j * i ) <= 1000000 ; j += 2 )
            {
                mark[ j * i ] = true ;
                pd[ j * i ] = i ;
            }
        }
    }
}


ll power( ll x,ll y,ll m )
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x , y/2 , m ) ;
        return ( ( ret % m ) * ( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) *( power( x , y-1 , m ) % m ) ) % m ;
}

ll modInverse( ll a, ll m )
{
    return power( a , m - 2 , m ) ;
}

ll val = 0 , ans = 1 ;

ll divisor1( ll n )
{
    while( n != 1 )
    {
        ll cnt = 0 ;
        ll  x = pd[ n ] ;
        while( n % x == 0 )
        {
            n = n / x ;
            cnt ++ ;
        }

        ll y = modInverse( Mp[ x ] + 1 , MOD ) ;/// 12 = 2 ^ 2 * 3 ^ 1 ..so 3 er power( 1 + 1) divide kore .6 theke 2 divide = 3
        ans = ( ans % MOD * y % MOD ) % MOD ; /// 36 = 3 er new power ( 2 + 1 ) = 3  multiply kore we got new divisor .3 * 3 = 9
        Mp[ x ] += cnt ;
        ans = ( ans % MOD * ( Mp[ x ] + 1 ) % MOD ) % MOD ;
    }
    return ans ;
}

ll divisor2( ll n )
{
    while( n != 1 )
    {
        ll cnt = 0 ;
        ll  x = pd[ n ] ;
        while( n % x == 0 )
        {
            n = n / x ;
            cnt ++ ;
        }

        ll y = modInverse( Mp[ x ] + 1 , MOD ) ;
        ans = ( ans % MOD * y % MOD ) % MOD ;
        Mp[ x ] -= cnt ;
        ans = ( ans % MOD * ( Mp[ x ] + 1 ) % MOD ) % MOD ;
    }
    return ans ;
}


int main()
{
    findPrime() ;
    ll t, n, a ;
    scln( t ) ;
    for( int j = 1 ; j <= t ; j ++ )
    {
        scln( n ) ;
        for( int i = 1 ; i <= n ; i ++ )
        {
            scln( a ) ;
            if( a > 0 )
            {
                val = ( val % MOD + divisor1( a ) % MOD ) % MOD ;
            }
            else
            {
                val = ( val % MOD + divisor2( -a ) % MOD ) % MOD ;
            }
        }
        pf("Case %d: %lld\n", j, val ) ;
        val = 0 , ans = 1 ;
        Mp.clear() ;
    }

    return 0 ;
}




------------------------------------- Basic Problem ------------------------------------------


ll power(ll x,ll y,ll m)
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x , y/2 , m ) ;
        return ( ( ret % m ) * ( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) *( power( x , y-1 , m ) % m ) ) % m ;
}

int main()
{
    CIN ;
    ll n ;
    cin >> n ;
    ll x = power( 15 , n , 100 ) ;
    cout << x << endl ;
    return 0;
}


-----------------------------------------******------------------------------------------------
    
 

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

ll power( ll x ,ll y ,ll m )
{
    if( y == 0 )
        return 1 ;
    if( y % 2 == 0 )
    {
        ll ret = power( x , y / 2 , m ) ;
        return ( ( ret % m )*( ret % m ) ) % m ;
    }
    else
        return ( ( x % m ) * ( power( x , y - 1 , m ) % m ) ) % m ;
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
