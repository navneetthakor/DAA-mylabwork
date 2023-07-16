#include <bits/stdc++.h>
using namespace std;

// ---------------------- funcitons -----------------------
// buboole sort algorithm
void bsort(vector<int> &v)
{
    int temp, flag = 1;
    // loop to short them
    for (int i = 0; i < v.size(); i++)
    {
        if (flag == 1)
        {
            flag = 0;
            for (int j = 0; j < v.size() - 1 - i; j++)
            {
                if (v[j] > v[j + 1])
                {
                    temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                    flag = 1;
                }
            }
        }
        else
        {
            break;
        }
    }
}

// insertion sort algorithm
void isort(vector<int> &v)
{
    int temp;

    for (int i = 1; i < v.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (v[j] < v[j - 1])
            {
                temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
            }
            else
            {
                break;
            }
        }
    }
}

// selection sort algorithm
void ssort(vector<int> &v)
{
    int min, temp;

    // outer loop
    for (int i = 0; i < v.size() - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[min] > v[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = v[min];
            v[min] = v[i];
            v[i] = temp;
        }
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
    vector<vector<double>> bv, iv, sv;
    // vectors to use as unsorted array
    vector<int> v1, v2, v3;
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
            v3 = v1;

            // calling bubble sort
            start = clock();
            bsort(v1);
            end = clock();
            double time_taken1 = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
            testv.push_back(size);
            cout<<time_taken1<<endl;
            testv.push_back(time_taken1);
            bv.push_back(testv);
            testv.clear();

            // calling insertion sort
            start = clock();
            isort(v2);
            end = clock();
            double time_taken2 = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
            cout<<time_taken2<<endl;
            testv.push_back(size);
            testv.push_back(time_taken2);
            iv.push_back(testv);
            testv.clear();

            // calling selection sort
            start = clock();
            ssort(v3);
            end = clock();
            double time_taken3 = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000;
            testv.push_back(size);
            testv.push_back(time_taken3);
            cout<<time_taken3<<endl;
            sv.push_back(testv);
            testv.clear();

            i++;
            v1.clear();
            v2.clear();
            v3.clear();
            size = size + 2000;
            cout << i << "th round completed.." << endl << endl;
        }

        // writing data in file + terminal

        cout << endl << "time taken  by bubble sort : " << endl;
        fout << endl << "time taken  by bubble sort : " << endl;
        for (int z = 0; z < bv.size(); z++)
        {
            cout << bv[z][0] << " : " << bv[z][1] << endl;
            fout << bv[z][0] << " : " << bv[z][1] << endl;
        }
        cout << endl<< endl;
        fout << endl<< endl;

        cout << endl<< "time taken  by insertion sort : " << endl;
        fout << endl<< "time taken  by insertion sort : " << endl;
        for (int z = 0; z < iv.size(); z++)
        {
            cout << iv[z][0] << " : " << iv[z][1] << endl;
            fout << iv[z][0] << " : " << iv[z][1] << endl;
        }
        cout << endl << endl;
        fout << endl << endl;

        cout << endl << "time taken  by selection sort : " << endl;
        fout << endl << "time taken  by selection sort : " << endl;
        for (int z = 0; z < sv.size(); z++)
        {
            cout << sv[z][0] << " : " << sv[z][1] << endl;
            fout << sv[z][0] << " : " << sv[z][1] << endl;
        }

        bv.clear();
        iv.clear();
        sv.clear();
    }
    return 0;
}