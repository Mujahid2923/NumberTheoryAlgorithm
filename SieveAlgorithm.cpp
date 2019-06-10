#include<bits/stdc++.h>
using namespace std;

vector< int > v ;
bool prime[ 200005 ] ;

void findPrime()
{
    int n = 200005 ;
    memset( prime , false , sizeof prime ) ;

    for( int i = 4 ; i <= n ; i += 2 )
    {
        prime[ i ] = true ;
    }

    prime[ 1 ] = true ;

    for( int i = 3 ; i * i <= n ; i += 2 )
    {
        if( !prime[ i ] )
        {
            for( int j = 2 ; i * j <= n ; j ++ )
            {
                prime[ i * j ] = true ;
            }
        }
    }

    for( int i = 1 ; i <= n ; i ++ )
    {
        if( !prime[ i ] )
        {
            v.push_back( i ) ;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    findPrime(n);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
}
