# word-search-and-count

## Description
This project reads words from a specified file into the program, where each word is made up solely of the letters A-Z and a-z. Any whitespace, punctuation, digits, or other characters separate words. For instance, “this!is A&Word” would be separated into the words: this, is, A, and Word. Each word is converted to lowercase upon reading. After processing the file, the program displays the total count of words. It also determines the number of unique words in the file and outputs that count. Next, the user can enter a word, and the program will report the number of times that word appears in the file. The program continues prompting until the user enters the EOF character. When searching, a ‘?’ character may be included as a wildcard, substituting any character, including no character. For example, “re?d” would match both "red" and "read." The program then lists each word matching the query, keeping them in the order they originally appeared in the file.

## Files
"word_search.cpp" is the main file with all the code. "a.exe" is the compiled version of "word_search.cpp". "sample.txt" is described below, and all other files were test files created for this. 

## Example
Here are the contents of the file “sample.txt”.  
> Cryptography is both the practice and study of the techniques used to communicate and/or store information or data privately and securely, without being intercepted by third parties. This can include processes such as encryption, hashing, and steganography. Until the modern era, cryptography almost exclusively referred to encryption, but now cryptography is a broad field with applications in many critical areas of our lives.

## Sample Output
Here is an example of the program running with "sample.txt" and all output.  
> $ g++ -Wall -std=c++11 word_search.cpp -o a  
> $ ./a sample.txt  
> The number of words found in the file was 64  
> The number of distinct words found in the file was 52  
> Please enter a word: of  
> The word of appears 2 times in the document  
> 
> Please enter a word: is  
> The word is appears 2 times in the document  
> 
> Please enter a word: or  
> The word or appears 2 times in the document  
> 
> Please enter a word: a?d  
> The word and appears 4 times in the document  
> 
> Please enter a word: a??  
> The word and appears 4 times in the document  
> The word as appears 1 times in the document  
> The word a appears 1 times in the document  
> 
> Please enter a word: ^C  
> $ 
