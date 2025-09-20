#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int r = a%b;
    if(r == 0)
    {
        return b;//ans   
    }
    else
    {
        int ans = gcd(b, r);
        return ans;
    }
}

int main(void)
{
    int a, b;
    cin >> a >> b;

    int ans = gcd(a, b);
    cout << ans << endl;
}