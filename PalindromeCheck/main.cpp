//
//  main.cpp
//  PalindromeCheck
//
//  Created by adeeb mohammed on 05/01/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//
//  program to check whether a string is palindrome or not
// aha is a palindrome
// alaa is not a palindrome
#include <iostream>
#include <string>


// solution using recursion
// o(n) time o(n) space
// tail recursaion is used so each recursive function is replaced by the last call o(1)
bool palHelper(std::string str, int i){
    int j = (int)str.length() - 1 - i;
    return (i >= j) ? true: (str[i] == str[j]) && palHelper(str,i+1);
}
bool isPalindromeRecursion(std::string str){
    return palHelper(str,0);
}

// more cleaner code using
bool isPalindrome(std::string str){
    int leftIndex = 0;
    int rightIndex = (int)str.size()-1;
    while(leftIndex < rightIndex){
        if(str.at(leftIndex) != str.at(rightIndex)){
            return false;
        }
        leftIndex++;
        rightIndex--;
    };
    return true;
}

// solution using for loop
bool isPalindromeOrg(std::string str) {
    int szStr = (int)str.size();
    if(str.empty()){
        return false;
    }else if(szStr == 1){
        return true;
    }else {
        for(int i = 0, j = (szStr -1) ; i <= (szStr/2) , j >=(szStr/2) ;j--, i++){
            if(str[i] != str[j]){
                return false;
            }
        }
        return true;
    }
  return false;
}
int main(int argc, const char * argv[]) {
    std::cout << "Program to check palindrome "<< std::endl;
    std::string str = "aha";
    std::cout << "palindrome :" << isPalindromeRecursion(str) << std::endl;
    return 0;
}
