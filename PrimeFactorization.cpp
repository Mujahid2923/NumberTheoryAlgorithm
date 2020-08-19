
*****************-------------------------------Prime Factorization----------------------------*******************

#include<bits/stdc++.h>
using namespace std;


vector<int> v,vec;

void findPrime()
{
    int n = 1000 ;
    bool prime[ n + 5 ];
    memset( prime , false , sizeof prime ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        prime[ i ] = true ;
    }

    prime[ 1 ] = true ;

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
        if( !prime[ i ] )
        {
            v.pb( i );
        }
    }
}

int main()
{
    findPrime() ;
    int n;

    while( cin>> n )
    {
        vec.pb( 1 ) ;
        for( int i = 0 ; v[i]*v[i] <= n ; i++ )
        {
            while( n % v[i] == 0 )
            {
                n = n / v[i] ;
                vec.pb( v[i] ) ;
            }
        }

        if( n > 1 )
        {
            vec.pb( n ) ;
        }

        for( int i = 0 ; i < vec.size() ; i++ )
        {
             cout << vec[i] << endl ;
        }
        vec.clear() ;
    }
    return 0;
}


**************--------------------Number of prime factorization of numbers---------------------------***************
    
    2 = 2 ( 1 )
    3 = 3 ( 1 )
    4 = 2 * 2 ( 2 )
    12 = 2 * 2 * 3 ( 3 )
    for( ll i = 2 ; i <= 5e6 ; i ++ )
    {
        if( !arr[ i ] )
        {
            for( ll j = i ; j <= 5e6 ; j += i )
            {
                arr[ j ] = arr[ j / i ] + 1 ;
            }
        }
    }


