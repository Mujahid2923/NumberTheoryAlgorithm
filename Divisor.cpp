
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
///Uva12043

-----------------------------------------------Efficient Approach-----------------------------------------------------------


vl v, v1, v2, prime ;
//vector < pll > vec ;
map < ll, ll > Mp ;
set < ll > st ;
deque < ll > dq ;


bool mark[ 1000000 + 5 ];
void findPrime()
{
    ll n = 1000000 ;
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


void divisor( ll n )
{
    for( int i = 0 ; prime[ i ] * prime[ i ] <= n ; i++ )
    {
        while( ( n % prime[ i ] ) == 0 )
        {
            n = n / prime[ i ] ;
            Mp[ prime[ i ] ] ++ ;
        }
    }

    if( n > 1 )
    {
        Mp[ n ] ++ ;
    }

    int ans = 1;
    for( auto x : Mp )
    {
        ans *= ( x.second + 1 ) ;
    }

    cout << ans << endl ;
    Mp.clear() ;
}


int main()
{
    CIN ;
    findPrime() ;
    ll n ;
    while( cin >> n )
    {
        divisor( n ) ;
    }

    return 0 ;
}



******************************-----------------------------Sum of Divisors--------------------------********************
Imagine you wish to work out the sum of divisors of the number 72. It would not take long to list the divisors, 
and then find their sum: 1 + 2 + 3 + 4 + 6 + 8 + 9 + 12 + 18 + 24 + 36 + 72 = 195.

However, this method would become both tedious and difficult for large numbers like 145600. Fortunately, there is a simple and elegant method at hand.

Let σ(n) be the sum of divisors of the natural number, n.

For any prime, p: σ(p) = p + 1, as the only divisors would be 1 and p.

Consider pa: σ(pa) = 1 + p + p2 + ... + pa (1).

Multiplying by p: pσ(pa) = p + p2 + p3 + ... + pa + 1 (2).

Subtracting (1) from (2): pσ(pa)−σ(pa) = (p−1)σ(pa) = pa+1 − 1.

Hence σ(pa) = (pa+1 − 1)/(p − 1).

For example, σ(34)=(35−1)/(3−1) = 242/2 = 121,
and checking: 1 + 3 + 9 + 27 + 81 = 121.

Although no proof is supplied here, the usefulness of the function, σ(n), is its multiplicativity,
which means that σ(a×b×...)=σ(a)×σ(b)×..., where a, b, ..., are relatively prime.

Returning to example, we use the fact that σ(72) = σ(23×32). As 23 and 32 are relatively prime,
we can separately work out σ(23) = 24 − 1 = 15 and σ(32) = (33 − 1)/2 = 13. Therefore, σ(72) = 15×13 = 195.
