#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;



int main(int count, char *file[]){

        if (count !=3){
                cout << "mysort accepts 2 paramenters only!" << endl;
                cout << "P1: input file" << endl;
                cout << "P2: output file" << endl;
                return 1;
        }

        // Input file
        ifstream fileIn;
        fileIn.open(file[1]);

        // Output file
        ofstream fileOut;
        fileOut.open(file[2], ios::out | ios::trunc);

        int size = 0;
        int num;
        // get the size
        while(fileIn >> num){
                size++;
        }
        // reset fileIn
        fileIn.close();
        fileIn.open(file[1]);

         int * r_numbers= new int[size];

        for(int i = 0; i < size; i++) {
                fileIn >> r_numbers[i];
        }
        // bubble sort
        for(int i = 0; i < size; i++){
                for(int j = i + 1; j < size; j++) {
                        if(r_numbers[j] < r_numbers[i]){
                                int temp = r_numbers[i];
                                r_numbers[i] = r_numbers[j];
                                r_numbers[j] = temp;
                        }
                }
        }

        for(int i = 0; i < size; i++) {
                fileOut << r_numbers[i] << endl;
        }

        delete []r_numbers;
        fileIn.close();
        fileOut.close();
        return 0;
}
                                             
