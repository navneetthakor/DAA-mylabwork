#include <bits/stdc++.h>
using namespace std;

void myMerge(vector<int> &v, int mybegin, int mid, int myend)
{
    // creating left and right array
    vector<int> leftv, rightv;
    for (int i = mybegin; i <= mid; i++)
    {
        leftv.push_back(v[i]);
    }

    for (int i = mid + 1; i <= myend; i++)
    {
        rightv.push_back(v[i]);
    }

    // creating some required variables
    int leftindex = 0;
    int righindex = 0;
    int mergeindex = mybegin;

    // loop to merge in v[mybegin .. myend]
    while (leftindex < leftv.size() && righindex < rightv.size())
    {
        if (leftv[leftindex] <= rightv[righindex])
        {
            v[mergeindex] = leftv[leftindex];
            leftindex++;
        }
        else
        {
            v[mergeindex] = rightv[righindex];
            righindex++;
            
        }
        mergeindex++;
    }

    // copy remaining elements
    // leftv remaining data
    while (leftindex < leftv.size())
    {
        v[mergeindex] = leftv[leftindex];
        leftindex++;
        mergeindex++;
    }

    // right remaining data
    while (righindex < rightv.size())
    {
        v[mergeindex] = rightv[righindex];
        righindex++;
        mergeindex++;
    }
}

void mymergeSort(vector<int> &v, int mybegin, int myend)
{
    if (mybegin >= myend)
    {
        return;
    }

    int mid = (mybegin + myend) / 2;
    mymergeSort(v, mybegin, mid);
    mymergeSort(v, mid + 1, myend);
    myMerge(v, mybegin, mid, myend);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 45, 6, 9, 0};
    mymergeSort(v, 0, (v.size()-1));
    cout<<"size : "<<v.size()<<endl;
    cout << "After short : " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
