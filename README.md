# Document-Handling-System
A Document Handling System that supports misspelled word detection and word suggestion, automatic competition of a given prefix, and efficient document retrieval.
Provided with a text file that contains a large number of English words and a set of files to be used for document retrieval part. 
# Features
The Document Handling System has following features:
- Spell Check and Word Suggestion: reading a text file,pinpoint all the misspelled words in the file. A word is considered to be misspelled if it is not found in the dictionary.The dictionary.txt file is used for this purpose. Once that a word is misspelled,it suggest up to 10 words as spelling suggestion for the misspelled word.
- Auto-complete:  Returns a set of words that all start with a given prefix.Using the same data as in feature 1 and this time achieves a fast retrieval of the words that have that prefix.
- Document Retrieval: Given a set of files and key words, the system will print the names of the files that contain the given keywords in an efficient manner. The system will also detect any possible misspellings and continue the retrieval process after automatically replacing the misspelled key word with the first one amongst the system’s suggestions from the feature one.
# Implementation
- Spell Check and Word Suggestion: Trie is used to implement this feature.The trie is created and inserted with all dictionary words into it from the dictionary file. 
- Auto-complete: The node that represent the given prefix and done a depth first search traversal for the subtree rooted from that node. These are the actual words that start with that prefix.
# Usages
Download the clone or zip file. Once downloaded open in Code Block Plus or Visual Studio or any other IDE that supports C++. 
