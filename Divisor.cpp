///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
using namespace std;

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
#define          CASEL(t)               printf("Case %d:\n",t)

///priority_queue<int,vector<int>,greater<int> >pq;

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


vector< ll > v, vec;

void divisor( ll n )
{
    for( int i = 1 ; i <= sqrt(n) ; i++ )
    {
        if( ( n % i ) == 0 )
        {
            if((n / i ) == i )
            {
                v.pb( i ) ;
            }
            else
            {
                v.pb( i ) ;
                v.pb( n / i ) ;
            }
        }
    }
}

int main()
{
    CIN ;
    ll t ;
    cin >> t ;
    while( t-- )
    {
        ll a, b, k ;
        cin >> a >> b >> k ;
        ll c = a % k ;
        if( c != 0 )
        {
            ll d = a / k ;
            c = k * ( d + 1) ;
        }
        else
        {
            c = a ;
        }

        for( int i = c ; i <= b ; i += k )
        {
            divisor( i ) ;
            for( auto j : v )
                vec.pb( j ) ;
            v.clear();
        }

        ll sum = 0 ;
        for( auto j : vec )
            sum += j ;
        cout << vec.size() << " " << sum << "\n" ;

        vec.clear() ;
    }

    return 0;
}

///Problem Link
///https://vjudge.net/contest/300539?fbclid=IwAR2t34w4hg0-FvOtvCXNIBvS8kk-IZ9J3Gq3A3CmW-s8ynr3Ed0eCWihTw0#problem/H

-----------------------------------------------Efficient Approach-----------------------------------------------------------
map < int , int > Mp ;
vector < int > vec ;

bool mark[ 50000 + 5];
void findPrime( int n )
{

    memset( mark, false, sizeof mark ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        mark[ i ] = true ;
    }

    mark[ 1 ] = true ;

    for( int i = 3 ; i <= n ; i += 2 )
    {
        if( !mark[i] )
        {
            for( int j = 2 ; i*j <= n ; j++ )
            {
                mark[ i*j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i++ )
    {
        if( !mark[i] )
        {
            prime.pb( i );
        }
    }
}

    
int divisor( int n )
{
    for( int i = 0 ; prime[i]*prime[i] <= n ; i++ )
    {
        while( ( n % prime[i] ) == 0 )
        {
            n = n / prime[i] ;
            vec.pb( prime[i] ) ;
        }
    }

    if( n > 1 )
    {
        vec.pb( n ) ;
    }

    for( auto i : vec )
    {
        Mp[i]++ ;
    }


    sort( all(vec) ) ;

    int ans = 1;
    vec.erase( unique( vec.begin(), vec.end() ), vec.end() ) ;
    for( auto i : vec )
    {
        ans *= ( Mp[i] + 1 ) ;
    }
    Mp.clear() ;
    vec.clear() ;
    return ans ;
}

