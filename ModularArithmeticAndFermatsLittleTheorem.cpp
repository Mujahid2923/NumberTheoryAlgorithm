
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

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())

///sort( all( v ) ) ;

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
    ///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
///#include <ext/pb_ds/assoc_container.hpp>
///#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
///using namespace __gnu_pbds;
///template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ull                    unsigned long long int
#define          db                     double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     3.141592653589793238462643
#define          rep( i , a , b )       for( i=a ; i<b ; i++)
#define          rev( i , a , b )       for( i=a ; i>=b ; i--)
#define          repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define          RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          get_pos(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          CASEL(t)               printf("Case %d:\n",t)
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------
///sort( all( v ) ) ;


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
