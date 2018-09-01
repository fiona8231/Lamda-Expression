#include <iostream>
#include <vector>

using namespace std;

//generate vector including max and min values that we defined
vector<int> GenerateRandomVector(int numofElement, int min, int max){
    //new a vector
    vector<int> newVec;
    for(int i = 0; i<numofElement; i++){
        int pushNum = min + rand()%((max+1) - min);
        newVec.push_back(pushNum);
    }
    return newVec;
}


int main() {

    vector<int> vector1;
    cout << "Vector before we sort: ";
    vector1 =GenerateRandomVector(8, 50 , 100);

    for(auto i:vector1){
        cout << i << endl;
    }

    //use lambda to sort the vector
    //use std::sort
    //ascending order
    sort(vector1.begin(), vector1.end());
    cout << "Vector we sort in ascending order: ";
    for(auto i:vector1){
        cout << i << endl;
    }

    //descending order
    sort(vector1.begin(), vector1.end(), [](int x, int y){ return x > y ;});
    cout << "Vector we sort in descending order: ";
    for(auto i:vector1){
        cout << i << endl;
    }

    //sort it out the even number vector by using lambda
    vector<int> evenVector;

    copy_if(vector1.begin(), vector1.end(), back_inserter(evenVector), [](int x){ return (x % 2) == 0;});
    cout << "Vector we sort out even number : ";
    for(auto i:evenVector){
        cout << i << endl;
    }

    //use lambda to sum up all the elements in vector
    int sum = 0;
    for_each(vector1.begin(), vector1.end(), [&](int x){ sum += x ; });

    cout <<  "Sum: " << sum <<  endl;

    // You can define what value is checked for divisability
    // by passing the value to check in the capture list
    // which lies between []
    // Send a value entered by the user through the capturelist and create a list based on it
    int divisor;
    cin >> divisor;
    vector<int> divisibleList;
    copy_if(vector1.begin(), vector1.end(), back_inserter(divisibleList), [&](int x){ return (x%divisor)== 0; });

    cout << "List of divisible: " << endl;
    for(auto i : divisibleList){
        cout << i << endl;
    }


    //list of number divided by a number cin

    cout << "List of values divisable by : ";


    vector<int> resultVector;
    for_each(vector1.begin(), vector1.end(), [&](int x){ resultVector.push_back(x/divisor);});


    cout << "List of result by divisor : ";
    for(auto i:resultVector){
        cout << i << endl;
    }


    // ----- PERFORMING OPERATIONS USING MULTIPLE VECTORS -----
    // Add values in separate vectors and save them to another
    vector<int> vec1 = {1,2,3,4,5};
    vector<int> vec2 = {1,2,3,4,5};
    vector<int> vec3(5);

    transform(vec1.begin(), vec1.end(), vec2.begin(), vec3.begin(), [](int x, int y){ return x + y;} );
    cout << "Sum of Two vectors" << endl;
    for(auto i: vec3){ cout << i << endl; }

    // ----- RECURSIVE LAMBDA FUNCTIONS -----
    // Recursive Lambda to calculate Fibonacci Numbers
    // Fib(0) = 0
    // Fib(1) = 1
    // Fib(2) = 1
    // Fib(3) = 2
    // Fib(4) = 3

    function<int(int)> Fib = [&Fib](int x){ return x < 2 ? x : Fib(x-2) + Fib(x-1) ;};

    cout << "Fib 4 : " << Fib(4) << "\n";

    return 0;


}