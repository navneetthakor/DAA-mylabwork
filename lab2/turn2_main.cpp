#include <bits/stdc++.h>
using namespace std;

// ---------------------- funcitons -----------------------
// merge sort algorithm
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
            ;
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

// quick short algorithm 
int partition(vector<int> &v, int left, int right){
    // choosing our pivot 
    int pivot = v[right];

    //temperory variable to use for swaping
    int n = left;
    int temp;

    // loop to starting swaping 
    for(int i=left; i<right; i++){
        if(v[i]<pivot){
            temp = v[i];
            v[i] = v[n];
            v[n] = temp;
            n++;
        }
    }

    // putting pivot to it's right position 
   
        temp = v[right];
        v[right] = v[n];
        v[n] = temp;
        return n;
}

void myQuickSort(vector<int> &v, int left, int right){
    if(left<right){
        // first creating partitions
        int p = partition(v,left,right);

        // now sorting each patitions sepratly
        myQuickSort(v,left,p-1);
        myQuickSort(v,p+1, right);
    }
}

// -----------------------------main funciton start's ---------------------------
int main()
{
    int n, temp, flag = 1,i,m,size;
    cout << "how many tests you want to carry out : ";
    cin >> n;
    // vectors to store result of time taken
    vector<double> testv;
    vector<vector<double>> mv, qv;
    // vectors to use as unsorted array
    vector<int> v1, v2;
    // to measeure the time taken 
    clock_t start, end;
    // to write in file 
    fstream fout;
    fout.open("result", ios::out);

    // main loop to run all the things
    for (int p = 0; p < 3; p++)
    {
         i = 0;
         m = n;
         size =1000;

        switch (p)
        {
        case 0:
            fout<<"Best case : "<<endl;
            break;
        case 1:
            fout<<endl<<"Avarage case : "<<endl;
            break;
        case 2:
            fout<<endl<<"worst case : "<<endl;
        }
        
        // executing each cases 
        while (i < m)
        {
            cout << "starting " << i << "th round.." << endl;

            // to initailize array
            if (p == 0)
            {
                for (int j = 0; j < size; j++)
                {
                    v1.push_back(j);
                }
            }
            else if (p == 2)
            {
                for (int j = 0; j < size; j++)
                {
                    temp = size - j;
                    v1.push_back(temp);
                }
            }
            else
            {
                for (int j = 0; j < size; j++)
                {
                    temp = 1 + (rand() % size);
                    v1.push_back(temp);
                }
            }

            // coping arr1 to arr2 and arr3
            v2 = v1;

            // calling merge sort
            start = clock();
            mymergeSort(v1,0,(v1.size()-1));
            end = clock();
            double time_taken1 = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
            testv.push_back(size);
            cout<<time_taken1<<endl;
            testv.push_back(time_taken1);
            mv.push_back(testv);
            testv.clear();

            // calling quick sort
            start = clock();
            myQuickSort(v2,0,(v2.size() -1 ));
            end = clock();
            double time_taken2 = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
            cout<<time_taken2<<endl;
            testv.push_back(size);
            testv.push_back(time_taken2);
            qv.push_back(testv);
            testv.clear();


            i++;
            v1.clear();
            v2.clear();
            size = size + 5000;
        }

        // writing data in file + terminal

        fout << endl << "time taken  by Merge sort : " << endl;
        for (int z = 0; z < mv.size(); z++)
        {
            fout << mv[z][0] << " : " << mv[z][1] << endl;
        }
        fout << endl<< endl;

        fout << endl<< "time taken  by quick sort : " << endl;
        for (int z = 0; z < qv.size(); z++)
        {
            fout << qv[z][0] << " : " << qv[z][1] << endl;
        }
        fout << endl << endl;

        mv.clear();
        qv.clear();
    }
    return 0;
}