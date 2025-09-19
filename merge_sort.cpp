#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &number_i:numbers) cin >> number_i;
}