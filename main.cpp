#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;

template <typename T>

//Search class includes all search methods and constructor
//Constructor generates vector with 100,000 whole numbers between 0 and 1000
class Search
{
    public:
    vector<T> elements,sortedEle;
    int toFind;
    

    Search(int n)
    {
        toFind = n;
        for(int i = 0; i<100000; i++)
            elements.push_back(rand()%1001);
        sortedEle = elements;
        sort(sortedEle.begin(),sortedEle.end());
    }

//Used for Testing Purposes
/*
    T getElement(int a)
    {
        return elements[a];
    }

    T getElementSorted(int a)
    {
        return sortedEle[a];
    }
*/

//First search method
//Finds element in unordered array using linear sequence search
    T seqSearch()
    {
        for(int i = 0; i<elements.size();i++)
        {
            if(elements[i]==toFind)
                return i;
        }
        return -1;
    }


//Second search method
//Finds element in ordered array using linear sequence search
//Stops process if vector value is larger than objective
    T orderedSeq1()
    {
        for(int i = 0; i<sortedEle.size();i++)
        {
            if(sortedEle[i]==toFind)
                return i;
            if(sortedEle[i]>toFind)
                break;
        }
        return -1;
    }


//Third search method
//Finds element in ordered array using sequence search with steps
//Checks vector value p-steps forward and back
//If larger and smaller than objective, lowers p to 1 and searches one at a time
    T orderedSeq2()
    {
        int p = sortedEle.size()/10;
        
        for(int i = 0; i<sortedEle.size();i+=p)
        {
            if(sortedEle[i]==toFind)
                return i;
            if((sortedEle[i-p]<toFind)&&(sortedEle[i]>toFind))
            {
                p = 1;
                continue;
            }
            if((sortedEle[i]<toFind)&&(sortedEle[i+p]>toFind))
            {
                p = 1;
                continue;
            }
        }
        

        return -1;
    }


//Final search method
//Finds elements in ordered array using binary search through recursion
//Checks first and last indexes of vector
//If halfway index is less than objective, begin method with halfway point as first extreme
//If halfway index is more than objective, begin method with halfway point as last extreme 
    T binSearch(int f, int l)
    {
        int h = (f+l)/2;
        if(sortedEle[h]==toFind)
            return h;
        if(sortedEle[h]>toFind)
            return binSearch(f,h-1);
        if(sortedEle[h]<toFind)
            return binSearch(h+1,l);
        return -1;
    }

};

//Basic main method to generate five search classes for each number to find
//For loops utilized to run each method 10 times for testing purposes
//Chrono utilized to measure the runtime of each method's execution
int main()
{
    int num1,num2,num3,num4,num5;

    cout<<"Choose the first number (between 0 and 1000) to find: "<<endl;
    cin>>num1;
    cout<<"Choose the second number (between 0 and 1000) to find: "<<endl;
    cin>>num2;
    cout<<"Choose the third number (between 0 and 1000) to find: "<<endl;
    cin>>num3;
    cout<<"Choose the fourth number (between 0 and 1000) to find: "<<endl;
    cin>>num4;
    cout<<"Choose the final number (between 0 and 1000) to find: "<<endl;
    cin>>num5;

    Search<int> first = Search<int>(num1);
    Search<int> second = Search<int>(num2);
    Search<int> third = Search<int>(num3);
    Search<int> fourth = Search<int>(num4);
    Search<int> fifth = Search<int>(num5);

//Chrono lacks the resolution to give accurate measurements on Windows so an alternate method using the Windows.h library is utilized
//To avoid clutter, time measuring code is commented out but was used for each method to measure results
    for(int i = 0; i<10; i++)
    {
        /*LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        LARGE_INTEGER start;
        QueryPerformanceCounter(&start);
        //SEARCH METHOD GOES HERE
        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
        double interval = (static_cast<double>(end.QuadPart- start.QuadPart)/frequency.QuadPart)*1000; //Execution time in Milliseconds
        cout<<interval<<endl;*/


        first.seqSearch();
        first.orderedSeq1();
        first.orderedSeq2();
        first.binSearch(0,100000);
    }

    for(int i = 0; i<10; i++)
    {
        /*LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        LARGE_INTEGER start;
        QueryPerformanceCounter(&start);
        //SEARCH METHOD GOES HERE
        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
        double interval = (static_cast<double>(end.QuadPart- start.QuadPart)/frequency.QuadPart)*1000; //Execution time in Milliseconds
        cout<<interval<<endl;*/

        
        second.seqSearch();
        second.orderedSeq1();
        second.orderedSeq2();
        second.binSearch(0,100000);
    }

    for(int i = 0; i<10; i++)
    {
        /*LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        LARGE_INTEGER start;
        QueryPerformanceCounter(&start);
        //SEARCH METHOD GOES HERE
        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
        double interval = (static_cast<double>(end.QuadPart- start.QuadPart)/frequency.QuadPart)*1000; //Execution time in Milliseconds
        cout<<interval<<endl;*/

        
        third.seqSearch();
        third.orderedSeq1();
        third.orderedSeq2();
        third.binSearch(0,100000);
    }

    for(int i = 0; i<10; i++)
    {
        /*LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        LARGE_INTEGER start;
        QueryPerformanceCounter(&start);
        //SEARCH METHOD GOES HERE
        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
        double interval = (static_cast<double>(end.QuadPart- start.QuadPart)/frequency.QuadPart)*1000; //Execution time in Milliseconds
        cout<<interval<<endl;*/

        
        fourth.seqSearch();
        fourth.orderedSeq1();
        fourth.orderedSeq2();
        fourth.binSearch(0,100000);
    }

    for(int i = 0; i<10; i++)
    {
        /*LARGE_INTEGER frequency;
        QueryPerformanceFrequency(&frequency);
        LARGE_INTEGER start;
        QueryPerformanceCounter(&start);
        //SEARCH METHOD GOES HERE
        LARGE_INTEGER end;
        QueryPerformanceCounter(&end);
        double interval = (static_cast<double>(end.QuadPart- start.QuadPart)/frequency.QuadPart)*1000; //Execution time in Milliseconds
        cout<<interval<<endl;*/
        
        
        fifth.seqSearch();
        fifth.orderedSeq1();
        fifth.orderedSeq2();
        fifth.binSearch(0,100000);
    }

    return 0;
}