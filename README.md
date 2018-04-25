# Adaptive Huffman Implementation with C++
Adaptive Huffman is a Data Compression technique based on Huffman coding.
It permits building the code as the symbols are being transmitted, having no initial knowledge of source distribution, that allows one-pass encoding and adaptation to changing conditions in data.
The benefit of one-pass procedure is that the source can be encoded in real time, though it becomes more sensitive to transmission errors, since just a single loss ruins the whole code.

### Team Members
* Khaled Mohamed
* Mena Fayez
* Ahmed Mahmoud

### Notes
There are three text files to read input and write results :
1. "input.txt" : it must contain the input text whether it was encoding or decoding process.
2. "set.txt" : it must contain the set of symbols that may appear on the input file. be careful if you typed a space you mean that it is in the set.
3. "output.txt" : the output of the encoding or decoding process will appear on this file.
