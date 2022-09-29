#include <string>

// Returns a substring of the string str, allows for negative values as in 
// python 
// end == 0 means to include end of string 
std::string Slice(const std::string &str, ssize_t start, ssize_t end=0); 
 
// Returns the capitalized string as in python 
std::string Capitalize(const std::string &str); 
 
// Returns the upper- or lower-case strings as in python 
std::string Upper(const std::string &str); 
std::string Lower(const std::string &str); 
 
// Returns the left/right/both stripped strings (white space characters are  
// removed from left, right or both)  
std::string LStrip(const std::string &str); 
std::string RStrip(const std::string &str); 
std::string Strip(const std::string &str); 
 
// Returns the center/left/right justified strings 
std::string Center(const std::string &str, int width, char fill = ' '); 
std::string LJust(const std::string &str, int width, char fill = ' '); 
std::string RJust(const std::string &str, int width, char fill = ' '); 
 
// Returns the string str with all instances of old replaced with rep 
std::string Replace(const std::string &str, const std::string &old, const 
std::string &rep); 
 
// Splits the string up into a vector of strings based on splt parameter, if 
// splt parameter is empty string, then split on white space
std::vector< std::string > Split(const std::string &str, const std::string 
&splt = ""); 
 
// Joins a vector of strings into a single string 
std::string Join(const std::string &str, const std::vector< std::string > 
&vect); 
 
// Replaces tabs with spaces aligning at the tabstops 
std::string ExpandTabs(const std::string &str, int tabsize = 4); 
 
// Calculates the Levenshtein distance (edit distance) between the two  
// strings. See https://en.wikipedia.org/wiki/Levenshtein_distance for  
// more information. 
int EditDistance(const std::string &left, const std::string &right, bool 
ignorecase=false); 