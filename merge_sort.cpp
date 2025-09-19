#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> merge_sort(vector<int> &numbers, int first,  int end)
{
    if(first == end)//１つで構成されるか
    {
        vector<int> ret(1);
        ret[0] = numbers[first];
        return ret;
    }
    else
    {
        vector<int> left = merge_sort(numbers, first, (first + end)/2);//左
        vector<int> right = merge_sort(numbers, (first + end)/2 + 1, end);//右

        queue<int> left_q;
        queue<int> right_q;

        for(auto &left_i : left) left_q.push(left_i);
        for(auto &right_i : right) right_q.push(right_i);
        
        vector<int> ret(left_q.size() + right_q.size());

        for(int i = 0; i < left.size() + right.size(); i++)
        {
            if(left_q.empty() || right_q.empty())
            {
                if(left_q.empty())
                {
                    int right_q_size = right_q.size();
                    for(int i = 0; i < right_q_size; i++)
                    {
                        ret[i] = right_q.front();
                        right_q.pop();
                    }
                }
                else if(right_q.empty())
                {
                    int left_q_size = left_q.size();
                    for(int i = 0; i < left_q_size; i++)
                    {
                        ret[i] = left_q.front();
                        left_q.pop();
                    }
                }
            }
            else
            {
                if(left_q.front() > right_q.front())
                {
                    ret[i] = left_q.front();
                    left_q.pop();
                }
                else if(right_q.front() > left_q.front())
                {
                    ret[i] = right_q.front();
                    right_q.pop();
                }
                else
                {
                    //どっちでもいいからポップ
                    ret[i] = right_q.front();
                    right_q.pop();
                }
            }
        }
        return ret;
    }


}

int main(void)
{
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(auto &number_i:numbers) cin >> number_i;

    for(auto num_i:merge_sort(numbers, 0, n-1)) cout << num_i << " ";
    cout << endl;
}