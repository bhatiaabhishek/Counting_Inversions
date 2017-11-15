//
//  main.cpp
//  Counting_Inversions
//
//  Created by Abhishek Bhatia on 11/11/17.
//  Copyright © 2017 Abhishek Bhatia. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;


long int merge_and_count(vector<int>&arr_A, vector<int>&arr_B, vector<int>&arr_comb) {
    long int inv_count=0;
    int i=0, j=0, k=0; //i for arr A, j for arr B, k for arr_comb
    
    while (i<arr_A.size() && j<arr_B.size()) {
        
        if (arr_A[i]<arr_B[j]) {
            arr_comb[k++] = arr_A[i++];
        }
        else {
            arr_comb[k++] = arr_B[j++];
            inv_count = inv_count + arr_A.size() - i; // all remaining elements count as inversions
        }
    }
        //Copy remaining elements to the combined array
        while(i<arr_A.size()){
            arr_comb[k++] = arr_A[i++];
        }
        while(j<arr_B.size()){
            arr_comb[k++] = arr_B[j++];
        }
    
    return inv_count;
    
}

long int sort_and_count(vector<int>& arr) {
    
    int mid, left, right;
    vector<int> arrA, arrB;
    long int inv_count = 0;
    if (arr.size() <= 1){
        return 0; // no inversions for a single element vector
    }
    left = 0;
    right = arr.size()-1;
    mid = (left+right)/2;
    arrA = vector<int>(arr.begin(), arr.begin()+mid+1);
    arrB = vector<int>(arr.begin()+mid+1, arr.end());
    inv_count  = sort_and_count(arrA);
    inv_count += sort_and_count(arrB);
    // merge the two parts to count split inversions
    inv_count += merge_and_count(arrA, arrB, arr);
    
    
    
    
    return inv_count;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string line;
   
    vector<int> sample_arr;
   
    ifstream File;
    long int inv_count;
    //File.open("/Users/abhatia/Documents/Algorithms/Counting_inversions/Counting_Inversions/mytest");
    File.open("input1.txt");
    if (File.is_open()) {
        while(!File.eof())
        {
            getline(File,line);
            //cout << line << endl;
            if (!line.empty()) {
                //file_arr[file_line++] =  stoi(line);
                sample_arr.push_back(stoi(line));
            }
            
            
        }
        File.close();
    }
        else {
            cout << "file not found" << endl;
        }
    
    
    //cout << sizeof(file_arr) << "\n";
    //cout << file_arr[0] << "\n";
    inv_count = sort_and_count(sample_arr);
    for (int i1=0; i1<sample_arr.size();) {
        cout << sample_arr[i1] << endl;
        i1++;
    }
    cout << "Inversion count = " << inv_count << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
