

void countPrimitiveRoot( ll p )
{
    ll cnt = 0 ;
    for( ll i = 1 ; i <= p ; i ++ )
    {
        if( gcd( i , p ) == 1 )
            cnt ++ ;
    }
    cout << cnt << endl ;
}

int main()
{
    CIN ;
    ll p ;
    cin >> p ;
    countPrimitiveRoot( p - 1 ) ;
    return 0 ;
}

