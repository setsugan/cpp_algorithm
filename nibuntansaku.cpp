#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    //入力
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &ai:numbers) cin>>ai;

    std::sort(numbers.begin(), numbers.end());

    for(auto &number : numbers)
    {
        cout << number << " ";
    }
    cout << endl;

    //二分探索
    int target;
    cin >> target;

    int min = 0; 
    int max = n - 1;

    int now_looking_num;

    bool isSearching = true;

    while(isSearching)
    {
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
                if(max < min)
                {
                    cout << "not found" << endl;

                    isSearching = false;
                }
            }
            else if(now_looking_num > target)
            {
                max = ((max + min) /2) - 1; // 今見てるやつ以上は見なくていい  
                if(max < min)
                {
                    cout << "not found" << endl;

                    isSearching = false;
                }
            }
            cout << "max: "<< to_string(max) << endl;
            cout << "min: "<< to_string(min) << endl;
        }
    }
}

// 参考

// https://qiita.com/square1001/items/6d414167ca95c97bd8b2

// https://zenn.dev/iharuoru/articles/4751e8977ccd0d
// https://dexall.co.jp/articles/?p=1740