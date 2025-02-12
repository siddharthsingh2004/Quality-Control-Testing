#include <iostream>
#include <cassert>
#include <string>
#include <cctype>
using namespace std;


bool isValidQC(string results) {
    
    // check if string is empty
    if (results.empty()) { 
        return false;
    }

    // check for empty characters
    for (char c : results) {
        if (isspace(c)){
            return false;
        }
    }

    // declare an index to loop through string
    size_t numInd = 0; 

    // loop to traverse through string
    while (numInd < results.size()) { 

        // check if first letter is Q
        if (results[numInd] != 'Q') { 
            return false;
        }

        // Move past 'Q'
        numInd++; 

        // index of start of first number
        size_t firstNumId = numInd; 

        // loop to extract total number
        while (numInd < results.size() && isdigit(results[numInd])) {
            numInd++;
        }

        // No digits found
        if (firstNumId == numInd) { 
            return false;
        }

        // convert number string to int
        int totalNum = stoi(results.substr(firstNumId, numInd - firstNumId)); 

        
        // check for leading zeroes
        if (results.substr(firstNumId, numInd - firstNumId) != to_string(totalNum)) { 
            return false;
        }

        // check if totalNum is 0
        if (totalNum == 0) {
            return false;
        }

        // declare prelim. variables
        int passNum = -1, defectNum = -1;
        bool hasP = false, hasD = false;

        // Process 'p' and 'd' values
        while (numInd < results.size() && (results[numInd] == 'p' || results[numInd] == 'd')) {
            
            // 'p' or 'd'
            char type = results[numInd]; 
            numInd++;

            // index for pass or defect number
            size_t secondNumId = numInd;

            // loop to get pass or defect number
            while (numInd < results.size() && isdigit(results[numInd])) {
                numInd++;
            }

            // No digits found after 'p' or 'd'
            if (secondNumId == numInd) { 
                return false;
            }

            // convert pass or defect number string to int
            int count = stoi(results.substr(secondNumId, numInd - secondNumId));

            // check for leading zeroes
            if (results.substr(secondNumId, numInd - secondNumId) != to_string(count)) {
                return false;
            }


            if (type == 'p') {
                // Duplicate 'p'
                if (hasP) { 
                    return false;
                }
                // count is number of passes 
                passNum = count;
                hasP = true;
            }
            else if (type == 'd') {
                // Duplicate 'd'
                if (hasD) { 
                    return false;
                }
                // count is number of defects
                defectNum = count;
                hasD = true;
            }
        }

        // Ensure both 'p' and 'd' are present
        if (!hasP || !hasD) {
            return false;
        }

        // Validate sum
        if ((passNum + defectNum) != totalNum) {
            return false;
        }
    } 
    // if all errors cleared return true
    return true;
}

int passQC(string results) {

    // check if valid
    if (!isValidQC(results)) {
        return -1;
    }
    // variable to store pass numbers
    int count = 0;
    
    // loop through string
    for (int i = 0; i < results.size(); i++) {

        
        if (results[i] == 'p') {

            // move past 'p' to get to numbers
            int index = i + 1;

            // loop to get numbers as a string
            while (index < results.size() && isdigit(results[index])) {
                index++;
            }

            // convert that string to int
            count += stoi(results.substr(i + 1, index - (i + 1)));
        }

    }
    return count;
}

int defectQC(string results) {
    
    // check if valid
    if (!isValidQC(results)) {
        return -1;
    }
    // variable to store defect numbers 
    int count = 0;

    // loop through string
    for (int i = 0; i < results.size(); i++) {

        if (results[i] == 'd') {
            
            // move past 'd' to get to numbers
            int index = i + 1;

            // loop to get numbers as a string
            while (index < results.size() && isdigit(results[index])) {
                index++;
            }
            
            // convert string to int
            count += stoi(results.substr(i + 1, index - (i + 1)));
        }

    }
    return count;
}


int totalQC(string results) {

    // check if valid
    if (!isValidQC(results)) {
        return -1;
    }
    // variable to store total number
    int count = 0;

    // loop through string
    for (int i = 0; i < results.size(); i++) {

        if (results[i] == 'Q') {
            
            // move past 'Q' to get to numbers
            int index = i + 1;

            // loop to get numbers as a string
            while (index < results.size() && isdigit(results[index])) {
                index++;
            }
            
            // convert string to int
            count += stoi(results.substr(i + 1, index - (i + 1)));
        }

    }
    return count;
}

int batches(string results) {
    
    // check if valid 
    if (!isValidQC(results)) {
        return -1;
    }

    // variable to store number of batches
    int count = 0;
    
    // loop through string
    for (int i = 0; i < results.size(); i++) {
        
        // since string is valid, can assume everytime we see 'Q' that means new batch
        if (results[i] == 'Q') {
            count++;
        }
    }
    return count;
}

int main()
{
    // Test cases for isValidQC()
    assert(isValidQC("Q10p7d3") == true);
    assert(isValidQC("Q5p3d2Q8p4d4") == true);
    assert(isValidQC("Q7p3d4Q10p6d4") == true);
    assert(isValidQC("Q3p1d2Q6p3d3Q9p5d4") == true);
    assert(isValidQC("Q2p1d1Q4p2d2Q6p3d3Q8p4d4") == true);

    // Invalid cases
    assert(isValidQC("Q10p7") == false);      // Missing 'd'
    assert(isValidQC("Q5d2") == false);       // Missing 'p'
    assert(isValidQC("Q5p3d3") == false);     // Sum doesn't match
    assert(isValidQC("Q07p5d2") == false);    // Leading zero
    assert(isValidQC("Q0p0d0") == false);     // Zero total

    // Test cases for passQC()
    assert(passQC("Q10p7d3") == 7);
    assert(passQC("Q5p3d2Q8p4d4") == 3 + 4);
    assert(passQC("Q7p3d4Q10p6d4") == 3 + 6);
    assert(passQC("Q3p1d2Q6p3d3Q9p5d4") == 1 + 3 + 5);
    assert(passQC("Q2p1d1Q4p2d2Q6p3d3Q8p4d4") == 1 + 2 + 3 + 4);

    // Invalid cases
    assert(passQC("Q10p7") == -1);
    assert(passQC("Q5d2") == -1);
    
    // Test cases for defectQC()
    assert(defectQC("Q10p7d3") == 3);
    assert(defectQC("Q5p3d2Q8p4d4") == 2 + 4);
    assert(defectQC("Q7p3d4Q10p6d4") == 4 + 4);
    assert(defectQC("Q3p1d2Q6p3d3Q9p5d4") == 2 + 3 + 4);
    assert(defectQC("Q2p1d1Q4p2d2Q6p3d3Q8p4d4") == 1 + 2 + 3 + 4);

    // Invalid cases
    assert(defectQC("Q10p7") == -1);
    assert(defectQC("Q5d2") == -1);
    
    // Test cases for totalQC()
    assert(totalQC("Q10p7d3") == 10);
    assert(totalQC("Q5p3d2Q8p4d4") == 5 + 8);
    assert(totalQC("Q7p3d4Q10p6d4") == 7 + 10);
    assert(totalQC("Q3p1d2Q6p3d3Q9p5d4") == 3 + 6 + 9);
    assert(totalQC("Q2p1d1Q4p2d2Q6p3d3Q8p4d4") == 2 + 4 + 6 + 8);

    // Invalid cases
    assert(totalQC("Q10p7") == -1);
    assert(totalQC("Q5d2") == -1);

    // Test cases for batches()
    assert(batches("Q10p7d3") == 1);
    assert(batches("Q5p3d2Q8p4d4") == 2);
    assert(batches("Q7p3d4Q10p6d4") == 2);
    assert(batches("Q3p1d2Q6p3d3Q9p5d4") == 3);
    assert(batches("Q2p1d1Q4p2d2Q6p3d3Q8p4d4") == 4);

    // Invalid cases
    assert(batches("Q10p7") == -1);
    assert(batches("Q5d2") == -1);

    cout << "All test cases passed!" << endl;
    return 0;

}
