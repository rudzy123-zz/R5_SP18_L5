#include <iostream>
#include <string>
#include <vector>

#include "isPalindrome.h"

int main() {
    
    std::vector<std::string> strVec = { "",
        "a",
        "aba",
        "abba",
        "deleveled",
        "a man a plan a canal panama",
        "ab",
        "abbc" };
    
    for (const std::string& str : strVec) {
        // Initialize a clean string to empty:
        std::string clean("");
        
        // Iterate over the string currStr and remove all space characters:
        for (char ch : str) {
            if (ch != ' ') {
                clean += ch;
            }
        }
        
        // Test and report whether the string in clean is a palindrome:
        if (isPalindrome(clean) ) {
            std::cout << "YES "
            << clean
            << " is a palindrome."
            << std::endl;
        }
        else {
            std::cout << "NO "
            << clean
            << " is not a palindrome."
            << std::endl;
        }
    }
    
    return EXIT_SUCCESS;
}

