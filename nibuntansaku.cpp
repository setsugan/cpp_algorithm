#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &ai:numbers) cin>>ai;

    std::sort(numbers.begin(), numbers.end());

    int target;
    cin >> target;

    int min = 0; 
    int max = n - 1;

    int now_looking_num; // 探索範囲の中央の値

    bool isSearching = true;

    while(isSearching){
        now_looking_num = numbers[(max + min) / 2];

        if(max == min)
        {
            if(numbers[max] == target)
            {
                cout << "I found the number." << endl;
            }
            else
            {
                cout << "not found" << endl;
            }
            isSearching = false;
        }
        else
        {
            if(now_looking_num == target)
            {
                cout << "I found the number." << endl;
                isSearching = false;
            }
            else if(now_looking_num < target)
            {
                min = ((max + min) /2) + 1; // 今見てるやつ以下は見なくていい
            }
            else if(now_looking_num > target)
            {
                max = ((max + min) /2) - 1; // 今見てるやつ以上は見なくていい
            }
            if(max < min)
            {
                cout << "not found" << endl;
                isSearching = false;
            }
        }
    }
}