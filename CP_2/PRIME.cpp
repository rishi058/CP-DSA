#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()
#define F(a,b,i) for (int i = a; i < b; i++)
#define RISHI ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long double ld;
typedef vector<int> vi;

//------------------------------------------------------

bool isPrime(int n)
{

    if (n == 1)

        return false;

    if (n == 2 || n == 3)

        return true;

    if (n % 2 == 0 || n % 3 == 0)

        return false;

    for (int i = 5; i <= sqrt(n); i += 6)

    {

        if (n % i == 0 || n % (i + 2) == 0)

            return false;

    }

    return true;
}



int nearestPrime(int n)

{

    int prime1, prime2;



    if (n == 1)

        return 2;



    for (int i = n; i > 1; i--)

    {

        if (isPrime(i))

        {

            prime1 = i;

            break;

        }

    }



    for (int i = n; i < n * n; i++)

    {

        if (isPrime(i))

        {

            prime2 = i;

            break;

        }

    }

    if (abs(n - prime1) > abs(n - prime2))

    {

        return prime2;

    }

    else if (abs(n - prime1) < abs(n - prime2))

    {

        return prime1;

    }

    else

    {

        if (prime1 > prime2)

            return prime2;

        else

            return prime1;

    }

}

int32_t main()
{
    RISHI
    cout<<"000";

}