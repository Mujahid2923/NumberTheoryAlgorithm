----------------------Total trailing zeros-------------------------------
 ll two(ll n)
{
    ll k = 0;
    while( n )
    {
        k += n / 2 ;
        n = n/2 ;
    }
    return k;
}

ll five(ll n)
{
    ll k = 0;

    while( n )
    {
        k += n / 5 ;
        n = n/5 ;
    }
    return k;
}

ll x = two( a ) ;
ll y = five( b ) ;
ll z = min( x, y ) ;
------------------Here z is number of trailing zeros---------------



#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------


----------------LOJ 1028------------------
vector<ll>v;
bool prime[1000005];

void findPrime()
{
    ll n=1000000;
    memset(prime,false,sizeof prime);

    for(int i=4; i<=n; i+=2)
    {
        prime[i]=true;
    }

    prime[1]=true;

    for(ll i=3; i*i<=n; i+=2)
    {
        if(prime[i]==false)
        {
            for(ll j=2; i*j<=n; j++)
            {
                prime[i*j]=true;
            }
        }
    }

    for(ll i=1; i<=n; i++)
    {
        if(prime[i]==false)
        {
            v.push_back(i);
        }
    }
}

ll div(ll n)
{
    ll sum=1;
    for(int i=0; v[i]*v[i]<=n; i++)
    {
        ll k=0;
        while(n%v[i]==0)
        {
            n=n/v[i];
            k++;
        }
        sum=sum*(k+1);
    }
    if(n>1)
    {
        sum=sum*2;
    }
    return sum-1;
}

int main()
{
    //freopen("in.txt","w",stdout);
    findPrime();
    ll t,n;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        ll ans=div(n);
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}

----------------LOJ 1090------------------
#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

ll two(ll n)
{
    ll k=0;
    while(n%2==0)
    {
        k++;
        n=n/2;
    }
    return k;
}

ll five(ll n)
{
    ll k=0;

    while(n%5==0)
    {
        k++;
        n=n/5;
    }
    return k;
}

ll two2(ll n)
{
    ll k=0;
    while(n)
    {
        k+=n/2;
        n=n/2;
    }
    return k;
}


ll five5(ll n)
{
    ll k=0;

    while(n)
    {
        k+=n/5;
        n=n/5;
    }
    return k;
}



int main()
{
    ll t,n,r,p,q;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        ll x2=two2(n);
        ll y2=two2(n-r);
        ll z2=two2(r);
        ll x5=five5(n);
        ll y5=five5(n-r);
        ll z5=five5(r);

        ll xtwo=x2-(y2+z2);
        ll xfive=x5-(y5+z5);

        ll u2=two(p)*q;
        ll u5=five(p)*q;

        ll v2=xtwo+u2;
        ll v5=xfive+u5;
        ll ans=min(v2,v5);

        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}

------------------LOJ 1138 ---------------------------

#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

ll Find(ll n)
{
    ll cnt=0;
    while(n)
    {
        cnt+=n/5;
        n=n/5;
    }
    return cnt;
}

ll calculate(ll n)
{
    ll low=1;
    ll high=10000000000;
    ll index=-1;
    while(low<=high)
    {
        ll mid=(low+high)/2;
        ll ck=Find(mid);
        if(ck==n)
        {
            index=mid;
            high=mid-1;
        }
        else if(ck>n)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return index;
}

int main()
{
    ll t,n;
    cin>>t;
    for(ll i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        ll x=calculate(n);
        if(x==-1)
        {
            printf("Case %lld: impossible\n",i);
        }
        else
        {
            printf("Case %lld: %lld\n",i,x);
        }
    }
    return 0;
}
