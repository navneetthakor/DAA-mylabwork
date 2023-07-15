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
    int n, size = 1000, temp, flag = 1;
    cout << "how many tests you want to carry out : ";
    cin >> n;
    int i = 0;
    vector<double> testv;
    vector<vector<double>> bv,iv,sv;
    vector<int> v1, v2, v3;

    // main loop to run all the things
    clock_t start, end;
    while (i < n)
    {
        cout<<"starting "<<i<<"th round.."<<endl;
        // to initailize array
        for (int j = 0; j < size; j++)
        {
            temp = 1 + (rand() % size);
            v1.push_back(temp);
        }

        // coping arr1 to arr2 and arr3
        v2 = v1;
        v3 = v1;

        // calling bubble sort 
        start = clock();
        bsort(v1);
        end = clock();
        double time_taken1 = (double(end - start) / double(CLOCKS_PER_SEC))*1000;
        testv.push_back(size);
        testv.push_back(time_taken1);
        bv.push_back(testv);
        testv.clear();


        // calling insertion sort 
        start = clock();
        isort(v2);
        end = clock();
        double time_taken2 = (double(end - start) / double(CLOCKS_PER_SEC))*1000;
        testv.push_back(size);
        testv.push_back(time_taken2);
        iv.push_back(testv);
        testv.clear();

        // calling selection sort 
        start = clock();
        ssort(v3);
        end = clock();
        double time_taken3 = (double(end - start) / double(CLOCKS_PER_SEC))*1000;
        testv.push_back(size);
        testv.push_back(time_taken3);
        sv.push_back(testv);
        testv.clear();

        i++;
        v1.clear();
        v2.clear();
        v3.clear();
        size = size + 2000;
        cout<<i<<"th round completed.."<<endl<<endl;
    }
    

    // writing data in file + terminal 
    fstream fout;
    fout.open("result",ios::out);

    cout<<endl<<"time taken  by bubble sort : "<<endl;
    fout<<endl<<"time taken  by bubble sort : "<<endl;
    for(int i=0; i<bv.size();i++){
        cout<<bv[i][0]<<" : "<<bv[i][1]<<endl;
        fout<<bv[i][0]<<" : "<<bv[i][1]<<endl;
    }
    cout<<endl<<endl;
    fout<<endl<<endl;

    cout<<endl<<"time taken  by insertion sort : "<<endl;
    fout<<endl<<"time taken  by insertion sort : "<<endl;
    for(int i=0; i<iv.size();i++){
        cout<<iv[i][0]<<" : "<<iv[i][1]<<endl;
        fout<<iv[i][0]<<" : "<<iv[i][1]<<endl;
    }
    cout<<endl<<endl;
    fout<<endl<<endl;

    cout<<endl<<"time taken  by selection sort : "<<endl;
    fout<<endl<<"time taken  by selection sort : "<<endl;
    for(int i=0; i<sv.size();i++){
        cout<<sv[i][0]<<" : "<<sv[i][1]<<endl;
        fout<<sv[i][0]<<" : "<<sv[i][1]<<endl;
    }


    return 0;
}


