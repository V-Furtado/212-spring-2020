# Lab 2: Function Templates 

Welcome to the second Data Structures lab of Spring 2020! The goal of this lab is to help expand your understanding of function templates and display how they can cut down on some repetitive coding. 

1. Introduction to template functions
    - Syntax
    - Usage
2. Dataset Explanation 
3. Building templated functions

## **Important Disclaimers**
Be sure to read and follow all instructions unless otherwise specified. Record your answers to the questions in a text document named lab-02.txt. 

You will be required to work with a group for this lab. Don't forget there's no i in group! (But there is one in programming assignments :-) )


# Part 1 Introduction to template functions 
## Part 1.1 Syntax
Function templates are incredibly useful when coding as it will prevent the need for re-writing the same functions in order to deal with different datatypes. Below you will find a quick example of inserstion sort

**Example Template Sorting Function**
```c++
#include <vector> 

template <class T>
void insertionSort(vector<T> &vec){
    
    for(int i = 1; i < vec.size(); i++){
        for(int j = i; j > 0; j--){
            if(vec[j] < vec[j - 1]){
                swap(vec.at(j), vec.at(j - 1));
            }
            else {
                break;
            }
        }
    }
}
```

To ensure that very important grounding is established, two lines will be explained in detail.

**Reference 1**
```c++
template <class T>
```

**Reference 2**
```c++
void insertionSort(vector<T> &vec)
```
**Reference 3**
```c++
vector<int> vec;
insertionSort<int>(vec);
//or
insertionSort(vec);
```


**Reference 1** This line is communicating to the compiler that no datatype has yet to be be defined for a variable within the function so T will be working as a place holder for that datatype.

**Reference 2** This function definition must follow after calling a function template. It is communicating to the compiler that a vector will be passed into this function but the specific typing of that vector has yet to be defined. When someone finally calls this function with a vector of ints, the compiler will replace every instance of T within that function with the datatype int. It's possible that if we wanted to return an element from this templated function using T, we could just change the return type to be T instead of void. 

**Reference 3** This would be how you would call a templated function.

**Note** 
```c++
template <typename T1, typename T2, typename T3>

void foo(T1 x, T2 y, T3 z);
```
It is also possible to have numerous template classes within its declaration. It is also possible to use typename instead of class. They are interchangeable at this level of usage, however there are certain cases where there are differences between the two. If you're curious towards what the differences are [this will satisfy your curiosity.](https://stackoverflow.com/questions/2023977/difference-of-keywords-typename-and-class-in-templates) 

:white_check_mark: Question 1: Explain whether or not it would be fair to describe a function template as a variable for the compiler?

:white_check_mark: Question 2: Can you use the same datatype for T1, T2 and T3?

:white_check_mark: Question 3: Is it possible to call a templated function without defining all of the datatype placeholders? (i.e. only defining T1 and T2 and not T3).

## Part 1.2 Usage of Templated Functions

Using only the example templated sorting function, the code below contains a main function that calls the example template sorting function in order to sort a vector of ints, floats and strings!
```c++
int main (int argc, char *argv[]){
    //Initialize a vector
    vector<int> Lab_Example_int;
    vector<float> Lab_Example_float;
    const char* Vector_Words[] = {"function","templates","make","life","easy"};

    vector<string> Lab_Example_str(Vector_Words,end(Vector_Words));

    cout<<"Original vectors: " <<endl;
    //Fill in that vector
    cout<<"Original integer vector: ";
    for(int i = 10; i > 0; i-=1){
        Lab_Example_int.push_back(i);
        cout<< i << " ";
        
    }
    cout<<endl;
    cout<<"Original float vector: ";
    for(float i = 10; i > 0; i-=1.3){
        Lab_Example_float.push_back(i);
        cout<< i << " ";
    }
    cout<<endl;
    cout<<"Original string vector: ";
    for(int i = 0; i < Lab_Example_str.size(); i++){
        cout<< Lab_Example_str.at(i) << " ";
    }
    cout<<"-----------------"<<endl;

    //sort that vector using our templated sort.
    insertionSort<int>(Lab_Example_int);
    insertionSort<float>(Lab_Example_float);
    insertionSort<string>(Lab_Example_str);
    
    cout<<"Now printing out sorted versions: "<<endl;;
    //Printing out sorted int vector
    cout<<"Sorted integer vector: ";
    for (int i = 0; i < Lab_Example_float.size(); i++){
        cout<< Lab_Example_int.at(i) <<" ";
    }
    cout<<endl;
    
    //Printing Sorted float vector
    cout<<"Sorted float vector: ";
    for (int i = 0; i < Lab_Example_float.size(); i++){
        cout<< Lab_Example_float.at(i) <<" ";
    }
    cout<<endl;
    
    cout<<"Sorted string vector: ";
    for (int i = 0; i < Lab_Example_str.size(); i++){
        cout<< Lab_Example_str.at(i) <<" ";
    }
    cout<<endl;

    return 0;
}


```  
:white_check_mark: Question 4: Now that you've seen a function template in use, is there any similarity to how the insertion sort function is being called and the declaration of the vectors?

:white_check_mark: Question 5: What is the output of the sorted string vector?

:white_check_mark: Question 6: If the string vector changed to just contain the words apple and act, what word would come first? 


**Hint** Look back at how insertion sort is called and compare it to the declaration of the vector. 

# Part 2. Dataset Explanation 
This text file that is attatched to this lab is a slimmed down version of Alice In Wonderland. All words were set to lowercase. All non-english words have been removed in order to avoid any situation where you will need to deal with a charchter that has an accent. (à, ê, ī,į ...ect). The removal of non-english words also encapsulates names of the author, charchters and fictional places. 
All special charchters such as ?, !, @ ...ect were also removed. If any more clarification is needed just open the file and press control + f or command + f in order to search for char's you're concerned about.

# Part 3. Building templated functions

The given code will first declare three vectors, Word_Container, Word_Frequency and Word_Length. Afterwards the program will read in the cleaned text from Alice In Wonderland. When a word is pulled from the text it will store only one instance of this word in the vector called Word_Container. It will then input the length of the word into Word_Length and for every occurence of the word in the text Word_Frequency will increment at a specific index.

**Theoretical Example**

This sentence is to be read in by the program, "I am a student. I want a degree.". The vectors would look something like this

Word_Container = {"I","am","a","student","want",degree"}

Word_Length = {1,2,1,7,4,6}

Word_Frequency = {2.0,1.0,2.0,1.0,1.0,1.0} 

After all the text has been read in, the Word_Frequency vector will be divided by the total number of words in the text. This will give us a vector of floats. In reference to our previous example, it will turn Word_Frequency into 

Word_Frequency = {0.25, 0.125, 0.25, 0.125, 0.125, 0.125} 

**Goal**

Your goal for this lab is to use **ONE** templated sorting function that can sort any of the 3 vector datatypes. That templated function should work by sorting the vector that is passed into the first parameter and when a swap is made, the other two vectors that were entered as parameters should make an adjustment in order for them to maintain the correct indexing. 

**Example**

If you were to use this function on the Word_Length vector, everything would look like the following: 

Word_Length = {1,1,2,4,6,7}

Word_Container = {"I", "a", "am", "want", "degree", "student" }

Word_Frequency = {0.25, 0.25, 0.125, 0.125, 0.125, 0.125} 


:white_check_mark: Question 7: What are last 3 entries for Word_Container and Word_Frequency when you sort by Word_Length?

:white_check_mark: Question 8: What are the last 3 entries for Word_Length and Word_Frequency when you sort by Word_Container?

:white_check_mark: Question 9: What are the last 3 entries for Word_Length and Word_Container when you sort by Word_Frequency?

:white_check_mark: Question 10: What is last entry for Word_Length and Word_Container when you sort by Word_Frequencies that are over 0.0005?

:white_check_mark: Question 11: What is last entry for Word_Frequency and Word_Container when you sort by Word_Lengths that are over 5?

# Starter code

You will need to include fstream, cstring, iostream and vector. 
```c++
int main(int argc, char *argv[]){
    if(argc == 1){
        cout << "Please enter a text file to read in. ./prog <AIWL.txt>" << endl;
        return 0;
        
    }

    vector<string> Words_Container;
    vector<float> Words_Frequency;
    vector<int> Words_Length;
    
    // Name of the textbook
    char* book = argv[1];
    
    // Declare file name that we can read from
    ifstream file;
    
    //Attempt to open file
    file.open (argv[1]);
    
    //If the file is unable to open that means there is
    //no file with the inputted type
    if (!file.is_open()){
        cout << book << " is unable to open. Please enter a different text file. " << endl;
        return 0;
        
    }

    
    int Total_Word_Count = 0;

    string word;
    
    while (file >> word){
        Total_Word_Count+=1;
        
        //boolean switch if word was found
        int found = 0;
        
        //check if word is already in our vector
        for (int i = 0; i < Words_Container.size(); i++){
            if (word == Words_Container.at(i)){
                found = 1;
                
                Words_Frequency.at(i)=Words_Frequency.at(i)+1.0;
                break;
            
            }
        }
        
        if (found == 0) {
            Words_Container.push_back(word);
            Words_Frequency.push_back(1.0);
            Words_Length.push_back(word.size());
            
        }
        
        
    }
    //End while
    
    //Turning into frequencies
    for (int i = 0; i < Words_Container.size(); i++){
        Words_Frequency.at(i) = Words_Frequency.at(i) / Total_Word_Count;


    }
    
    //sorting by Words_Length
    insertionSort(Words_Length,Words_Container,Words_Frequency);
    
    //sorting by Words_Container
    //insertionSort(Words_Container,Words_Length,Words_Frequency);

    //sorting by Words_Frequency
    //insertionSort(Words_Frequency,Words_Container,Words_Length);

    for (int i = 0; i < Words_Container.size(); i++){
            cout << "Word:\t" << Words_Container.at(i) << endl;
            cout << "Word Length:\t"<<Words_Length.at(i) << endl;
            cout << "Word Frequency:\t" << Words_Frequency.at(i) << endl << endl;

    }
    

    return 1;
}
```


