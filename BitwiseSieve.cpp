#include<bits/stdc++.h>
using namespace std;

vector< ll > v ;
const int MAXN = 1e7 ;
bitset< MAXN > status ;

void findPrime()
{
    int rt = sqrt( MAXN ) + 1 ;

    for( int i = 3 ; i < rt ; i += 2 )
    {
        if( !status[ i ] )
        {
            for( int j = i * i ; j < MAXN ; j += ( i << 1 ) )
            {
                 status[j] = true;
            }
        }
    }

    v.push_back( 2 ) ;

    for( int i = 3; i < MAXN; i += 2 )
    {
        if( !status[ i ] )
        {
            v.push_back( i ) ;
        }
    }
}

int main()
{
    sieve();
    for(auto x : v)
        cout<<x<<" ";
}

/*
vector<int>v;
const int MAXN = 1e3;
bitset<MAXN>status;

void sieve()
{
    int rt = sqrt(MAXN);

    for(int i = 3; i < rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXN; j+=(i<<1))
                status[j] = true;

    v.push_back(2);

    for(int i = 3; i < MAXN; i+=2)
        if(!status[i])
        {
            v.push_back(i);
        }
}*/

