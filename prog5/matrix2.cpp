#include <string>
#include <thread> // include the thread library
#include <iostream>
using namespace std;
// this is the function that is called by each thread
void print_message(string quote, int threadNum) {

    cout << "thread:" << threadNum<< " "<< quote<<endl;
}
int main() {

 // Create 4 threads. Threads launch a process upon creation.
 // Pass the function name and all parameters. 
 // In this case, a function name and string.

    string quote1 = "I";
    string quote2 = "know";
    string quote3 = "Kung";
    string quote4 = "Fu";

    // when thread1 is createad, we pass in print_message, and its paramaters. 
    // it seems like what i'll have to do is pass in the function bubblesort, a section of the array, the size of each section 

    thread thread1(print_message, quote1, 1); 
    thread thread2(print_message, quote2, 2); 
    thread thread3(print_message, quote3, 3); 
    thread thread4(print_message, quote4, 4);

    // force the threads to join back to the main program
    thread1.join(); 
    thread2.join();
    thread3.join();
    thread4.join();
    return 0;
}
