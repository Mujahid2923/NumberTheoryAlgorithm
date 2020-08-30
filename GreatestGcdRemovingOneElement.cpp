const int MAXN = 1e6 + 69;

int n , arr[MAXN] , L[MAXN] , R[MAXN] ;
int main()
{
    CIN;
    cin >> n ;

    for ( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr[i] ;
    }
    for ( int i = 1 ; i <= n ; i ++ )
    {
        L[i] = gcd(L[i - 1], arr[i]) ;
    }

    for ( int i = n ; i >= 1 ; i -- )
    {
        R[i] = gcd(R[i + 1], arr[i]) ;
    }
    int ans = 1 ;

    for ( int i = 1 ; i <= n ; i ++ )
    {
        ans = max(ans, gcd(L[i - 1], R[i + 1])) ;
    }

    cout << ans << endl ;
}

problem link:
https://atcoder.jp/contests/abc125/tasks/abc125_c
