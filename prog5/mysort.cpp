// Connor McKenna
// (CECS 325-01)
// Program 5 - Sorting Contest using Threads
// Due Date (11/1/2023)
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.


#include <iostream>
#include <fstream>
#include <thread>

using std::cout;
using std::endl;
using std::thread;
using std::ifstream;
using std::ofstream;
using std::ios;

void bubbleSort(int *r_numbers, int size ){
        for(int i = 0; i < size; i++){
                for(int j = i + 1; j < size; j++) {
                        if(r_numbers[j] < r_numbers[i]){
                                int temp = r_numbers[i];
                                r_numbers[i] = r_numbers[j];
                                r_numbers[j] = temp;
                        }
                }
        }
}

void merge(int *s1, int size1, int *s2, int size2) {
    int totalsize = size1+size2;
    int *merged = new int[totalsize];
    int i = 0, j = 0, k = 0; 

    while (i < size1 && j < size2) {
        if (s1[i] < s2[j]) {
            merged[k++] = s1[i++];
        } else {
            merged[k++] = s2[j++];
        }
    }
    while (i < size1) {
        merged[k++] = s1[i++];
    }
    while (j < size2) {
        merged[k++] = s2[j++];
    }
    
    // copy merged in secion[0]
    for (int m = 0; m < totalsize; m++) {
       s1[m] = merged[m];
    }
    delete [] merged; 
}

int main (int count, char *file[]) {
     // Input file
    ifstream fileIn;
    fileIn.open(file[1]);
    // Output file
    ofstream fileOut;
    fileOut.open(file[2], ios::out | ios::trunc);

    int array_size = 0;
    int num;

    // get the size
    while(fileIn >> num){
            array_size++;
    }
    // reset fileIn
    fileIn.close();
    fileIn.open(file[1]);

    int * r_numbers= new int[array_size];

    for(int i = 0; i < array_size; i++) {
            fileIn >> r_numbers[i];
    }

    int section_size = array_size/8;
    int *section[8];
    thread threads[8];

    for (int i = 0; i < 8; i++) {
        section[i] = &r_numbers[i * section_size];
        threads[i] = thread(bubbleSort, section[i], section_size);
    }

    for(int i = 0; i < 8; i++){
        threads[i].join();
    }
    // first round
    merge(section[0], section_size, section[1], section_size);
    merge(section[2], section_size, section[3], section_size);
    merge(section[4], section_size, section[5], section_size);
    merge(section[6], section_size, section[7], section_size);

    // Merge the four merged arrays.
    merge(section[0], section_size * 2, section[2], section_size * 2);
    merge(section[4], section_size * 2, section[6], section_size * 2);

    // Merge the two merged arrays.
    merge(section[0], section_size * 4, section[4], section_size * 4);
    
     for (int i = 0; i < array_size; i++) {
       fileOut << r_numbers[i] << "\n";
    }

    delete []r_numbers;
    fileIn.close();
    fileOut.close();
    return 0;
}