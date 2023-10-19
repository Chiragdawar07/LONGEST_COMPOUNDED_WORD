# LONGEST_COMPOUNDED_WORD
Problem Statement
Write a program that:
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file
o longest compounded word
o second longest compounded word
o time taken to process the input file

Compounded words are the words formed using one or more of the valid words only in the selected file.
Since the files are already sorted alphabetically and only contain one word per line some of the the valid words that compose the compounded words are bound to come before the compounded word itself.

# Steps to execute the program-

Put all the files answer.cpp, Input_01.txt and Input_02.txt in the same folder.
Now run the file by using any cpp compiler

# Approach
While researching for this problem , I observed that trie based approach was the most easily understandable , effecient and widely used one. Trie can implement insert and search operations faster than a binary search tree. Tries are also faster than hash tables as there is no hash functions and collisions in a trie. Trie can be used to order the strings in alphabetical order. With trie , we can insert and find strings in O(l) time where l represent the length of a single word.
