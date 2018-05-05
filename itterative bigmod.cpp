#include<bits/stdc++.h>
#include<limits.h>

#define ll unsigned long long
using namespace std;
ll mmul(ll a, ll b, ll m)
{
    ll result = 0;
    a %= m;
    while (b)
    {
        if (b % 2) result = (result + a) % m;
        a = (a + a) % m;
        b /= 2;
    }
    return result;
}
ll mpow(ll a, ll b, ll m)
{
    ll result = 1;
    a %= m;
    while (b)
    {
        if (b % 2) result = mmul(result, a, m);
        a = mmul(a, a, m);
        b /= 2;
    }
    return result;
}

int main()
{
    int tc,p;
    ll a,b,c;

    while(scanf("%llu %llu %llu",&a,&b,&c)==3)
    {


        printf("%llu\n",(mpow(a,b,c)));
    }

    return 0;
}
