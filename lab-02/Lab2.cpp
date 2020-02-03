#include <fstream> // This is used for reading in the book
#include <cstring> // This is used for treating the string values
#include <iostream> // This is used to help with couting things
#include <vector> // This is used to contain the strings
using namespace std; //This is so we dont need to do std:: for everything



template <typename T1, typename T2, typename T3>
void insertionSort(vector<T1> &vec_1,vector<T2> &vec_2, vector<T3> &vec_3){
    for(int i = 1; i < vec_1.size(); i++){
        for(int j = i; j > 0; j--){
            if(vec_1.at(j) < vec_1.at(j - 1)){
                swap(vec_1.at(j), vec_1.at(j - 1));
                swap(vec_2.at(j), vec_2.at(j - 1));
                swap(vec_3.at(j), vec_3.at(j - 1));
            }
            else {
                break;
            }
        }
    }

}


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
        cout << book << " is unable to open. Please enter something different. " << endl;
        return 0;
        
    }

    
    int Total_Word_Count = 0;

    string word;
    
    while (file >> word){
        Total_Word_Count+=1;
        
        //boolean switch if found or not
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
    //Turn Counts into freqs
    for (int i = 0; i < Words_Container.size(); i++){
        Words_Frequency.at(i) = Words_Frequency.at(i) / Total_Word_Count;


    }
    

    insertionSort(Words_Length,Words_Container,Words_Frequency);
    for (int i = 0; i < Words_Container.size(); i++){
        if (Words_Frequency[i] > 0.0005) {
            cout << "Word:\t" << Words_Container.at(i) << endl;
            cout << "Word Length:\t"<<Words_Length.at(i) << endl;
            cout << "Word Frequency:\t" << Words_Frequency.at(i) << endl << endl;
        }


    }
    

    return 1;
}
