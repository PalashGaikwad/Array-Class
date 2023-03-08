#include <iostream>
#include "array.cpp"

void showcase_overloaded_operators() {
     // OVERLOADED [] OPERATOR
     std::cout << "[] OPERATOR BEGINNING\n\n\n";
     Array<int,5> arr {2,4,6,8,10};
     std::cout << "ELEMENT AT INDEX 2 BEFORE CHANGING IT USING [] OPERATOR:  " << arr[2] << "\n";
     arr[2] = arr[2] - 1; // Overloaded [] operator let's you access any element in the array. However, you won't be able to access anything outside of the array unlike a raw array. This is for safety purposes.
     std::cout << "ELEMENT AT INDEX 2 AFTER CHANGING IT USING [] OPERATOR:  " << arr[2] << "\n"; // Will output 5
     ++arr[2];
     std::cout << "\n\n[] OPERATOR END\n\n\n";

     // OVERLOADED INEQUALITY (!=) OPERATOR
     std::cout << "!= OPERATOR BEGINNING \n\n\n";
     Array<int,5> arr_2 {1,3,5,7,9};
     std::cout << std::boolalpha;
     std::cout << "values contained within arr: \n";
     arr.display();
     std::cout << "values contained within arr_2: \n";
     arr_2.display();
     if (arr != arr_2) { // This operator is most likely never going to be used but I have added it for those special cases where one might use it, all it does is check if all the elements are equal, the size is equal, and the length is equal. If all these conditions are true than it returns true. Else false.
        std::cout << "(arr != arr_2): " << (arr!=arr_2) << "\n\n";
     }
     else {
        std::cerr << "INEQUALITY OPERATOR FAILURE\n\n";
     }
     std::cout << "\n!= OPERATOR END\n\n\n";
     // OVERLOADED EQUALITY (==) OPERATOR
     std::cout << "== OPERATOR BEGINNING\n\n\n";
     Array<int,5> arr_3 {arr};
     std::cout << "values contained within arr: \n";
     arr.display();
     std::cout <<"\nvalues contained within arr_3: \n";
     arr_3.display();
     if (arr == arr_3) { // Same as the inequality operator but the return values change.
        std::cout << "(arr == arr_3): " << (arr == arr_3) << "\n\n";
     }
     else {
        std::cerr << "EQUALITY OPERATOR FAILURE\n\n";
     } 
     std::cout << "\n== OPERATOR END\n\n";
}

void showcase_functions() {
     Array<int,5> array {2,4,6,8,10};

     // AT FUNCTION BEGINNING
     // This function should be used to access elements in the array. You pass a index in the parameter of this function and it will return the element at that index.
     
     std::cout << "\nAT FUNCTION BEGINNING\n\n\n";
     std::cout << "This function should be used to access elements in the array. You pass a index in the parameter of this function and it will return the element at that index.\n";
     std::cout << "First index before assignment of 0: " << array.at(0) << "\n"; // Will output 2. at() function is just for those who are used to using vectors and their at() function
     array.at(0) = 0; // Array now becomes 0,4,6,8,10
     std::cout << "First index after assignment of 0: " << array.at(0) << "\n"; // Will output 0.
     array.at(0) = 2; // 2,4,6,8,10
     std::cout << "\nAT FUNCTION END\n\n\n";
     // AT FUNCTION END

     // BACK FUNCTION BEGINNING 
     // This function simply returns the element at the end of the array
     std::cout << "BACK FUNCTION BEGINNING\n\n\n";
     std::cout << "This function simply returns the element at the end of the array\n";
     std::cout << "Array contents: \n";
     array.display();
     std::cout << "ARRAY.BACK() BEFORE CHANGE: " << array.back() << "\n";
     array.back() = 3; 
     std::cout << "ARRAY.BACK() AFTER CHANGE: " << array.back() << "\n";
     array.back() = 10;
     std::cout << "BACK FUNCTION ENDING\n\n\n";
     // BACK FUNCTION END
     
     // CLEAR FUNCTION BEGINNING 
     // This function sets everything to 0. Size is 0, Length is 0 and the array is absolutely empty.
     std::cout << "CLEAR FUNCTION BEGINNING\n";
     std::cout << "This function sets everything to 0. Size is 0, Length is 0 and the array is absolutely empty.\n";
     std::cout << "Array before clear function: \n";
     array.display();
     array.clear();
     std::cout << "Array after clear function: Absolutely Empty.\n";
     array.resize(5);
     array[0] = 2;
     array[1] = 4;
     array[2] = 6;
     array[3] = 8;
     array[4] = 10;
     std::cout << "CLEAR FUNCTION END\n\n\n";
     // CLEAR FUNCTION END

     // COUNT FUNCTION BEGINNING
     // This function takes a variable of type T and checks how many times it occurs in the array.
     std::cout << "COUNT FUNCTION BEGINNING\n\n\n";
     std::cout << "This function takes a variable of type T and checks how many times it occurs in the array.\n";
     std::cout << "For this function, we will use a different array with different elements.\n";
     std::cout << "This is the array: \n";
     Array<int,10> array_duplicate {1,1,2,2,3,3,4,4,4,5};
     array_duplicate.display();
     std::cout << "\nWe will count how many times 4 occurs.\n";
     std::cout << "Result: " << array_duplicate.count(4); 
     std::cout << "\nWhat happens if we try to count a element that's not in the array?\n";
     std::cout << "Result: " << array_duplicate.count(91);
     std::cout << "\n\n\nCOUNT FUNCTION END\n";
     // COUNT FUNCTION END    
}

int main(int argc, char const *argv[])
{
    // CONSTRUCTORS 
    Array<int,5> arr_1 {2,4,6,8,10}; // First template parameter is the datatype of the Array object, The second template parameter refers to the size of the array, which by default is 0 and to initialize the elements you have to put them in through a initializer list.
    Array<int> arr; // Datatype is int, size is 0, array is empty
    Array<std::string,10> arr_2 {"YOU","ARE","GREAT","AT","C++"}; // Datatype is std::string, size is 10, Array is {"YOU","ARE","GREAT","AT","CODING","","","","",""}
    
    std::cout << "BEGINNING OF OVERLOADED OPERATORS\n\n";
    // OVERLOADED OPERATORS 
    showcase_overloaded_operators();
    std::cout << "\nEND OF OVERLOADED OPERATORS\n\n";
    // FUNCTIONS
    std::cout << "BEGINNING OF FUNCTIONS\n\n";
    showcase_functions();
    std::cout << "\nEND OF FUNCTIONS\n\n";

    std::cout << "End of showcase.\n\n";

    return 0; 
}

