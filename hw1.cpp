#include <string>
#include <cstring>
//#include "hw1header.h"
#include <iostream>
#include <cctype>
#include <vector>

std::string Slice(const std::string &str, ssize_t start, ssize_t end=0)   
{
    int strend;
    if (end == 0)
    strend = str.length();  //slice until the end of the string
    else
    strend = end;    //slice until the specified bit - 1


/*     if (end != 0 && end < start)
    {
        std::cout << "start index out of bounds\n";
        return str;
    } */
    if (start < 0)
    {
        start = str.length() + start;
    }

    if (strend < 0)
    {
        strend = str.length() + strend;
    }
    //std::cout << "the length of the string is: " << strend << std::endl;


    if (start > strend)
    {
        return "";
    }

    std::string newstring = str.substr(start, strend-start);
    return newstring;
} 


std::string Capitalize(const std::string &str)
{
    char first = str.at(0);
    char capt = toupper(first);
    std::string tempstr = Slice(str, 1);  //remove first letter
    std::string newstring = capt + tempstr;
    return newstring;
}

std::string Upper(const std::string &str)
{
    std::string newstring = str;
    for (int i = 0; i < str.length(); i++)
    {
        newstring[i] = toupper(str[i]);
    }

    return newstring;
}

std::string Lower(const std::string &str) 
{
    std::string newstring = str;
    for (int i = 0; i < str.length(); i++)
    {
        newstring[i] = tolower(str[i]);
    }

    return newstring;
}

std::string LStrip(const std::string &str)
{
    std::string newstring = str;
    
    int i = 0;
    int count = 0;
    while (isspace(newstring[i]))
    {
        count++;
        i = i+1;
    }

    newstring = Slice(newstring, count);
    return newstring;
}

std::string RStrip(const std::string &str)
{
    std::string newstring = str;

    int index_toend = newstring.find_last_not_of(" \t\f\v\n\r");
    //std::cout<< "the last non-whitespace char is at index: " << index_toend << std::endl;

    newstring = newstring.substr(0, index_toend+1);

    return newstring;
}

std::string Strip(const std::string &str)
{
    std::string newstring = str;
    std::string newstring1 = LStrip(newstring);
    std::string newstring2 = RStrip(newstring1);

    return newstring2;

}

// Returns the center/left/right justified strings 
std::string Center(const std::string &str, int width, char fill = ' ')  //FIX hard code and spacing
{
    std::string newstring = str;

    std::string spaces = "";
    int i = 0;
    while (i < width)
    {
        spaces = spaces + fill;
        i += 1;
    }
    newstring = spaces + newstring + spaces;

    return newstring;

    //NEGATIVE WIDTH ????
    
}

std::string LJust(const std::string &str, int width, char fill = ' ')   //fix hard code
{
    std::string newstring = str;

    std::string spaces = "";
    int i = 0;
    while (i < width)
    {
        spaces = spaces + fill;
        i += 1;
    }
    newstring = spaces + newstring;

    return newstring;
} 

std::string RJust(const std::string &str, int width, char fill = ' ')   //fix hard code
{
    std::string newstring = str;

    std::string spaces = "";
    int i = 0;
    while (i < width)
    {
        spaces = spaces + fill;
        i += 1;
    }
    newstring = newstring + spaces;

    return newstring;
}
 

std::string Replace(const std::string &str, const std::string &old, const std::string &rep)
{
    // Returns the string str with all instances of old replaced with rep
    //iterate through string to find substring, mark the index of each occurance, str.replace() at their index

    std::string newstring = str;
    std::vector< int > founds;        //https://stackoverflow.com/questions/755835/how-to-add-element-to-c-array
    int found;
    int index = str.find(old);

    while (index != std::string::npos)  //while there are matches
    { 
    //index = str.find(old);
   /*  if (std::count(founds.begin(), founds.end(), index))  //if index list already contains index
        break; */
    //std::cout << "found old string at index: " << index << std::endl;
    //if (index != std::string::npos)   //if there is a match
        founds.push_back(index);
        

   /*  if (std::count(founds.begin(), founds.end(), str.find(old, index+1)))  //if index list already contains index
        break;
    else
    { */
    index = str.find(old, index+1);   
    //std::cout << "next old string found at index: " << index << std::endl;
    //founds.push_back(index);
    //}
    
    /* if (found == std::string::npos) //if no matches 
        break;
    else
        std::cout << "next old string found at index: " << found << std::endl;
        founds.push_back(found); */
    }
    
   /*  std::cout << "the indices of substring to be replaced are: ";  
    
    for (int i = 0; i < founds.size(); i++)
    {
        std::cout << founds[i] << " ";
    }
    std::cout << std::endl;
    return str; */


    //NOW REPLACE OLD W REP AT EACH INDEX IN FOUNDS
    
    if (!founds.empty() && old.length() == rep.length())  //if there are any matches
    {
        for (int i = 0; i < founds.size(); i++)
        {
            newstring.replace(founds[i], rep.length(), rep);   //doesn't work when rep and old are not the same length. find another way. slice the string at each index, append rep, and then append the rest of the string??
        }
    }

    else if (!founds.empty() && old.length() != rep.length())
    {
        int iterno = 0;
        for (int i = 0; i < founds.size(); i++)
        {
            int index =  founds[i] + (iterno * (rep.length()) - (iterno* old.length())); //founds[i] + (rep.length() * iterno);
            std::string strfirst = newstring;
            strfirst.resize(index); // index doesn't match the next old's index after replacement
            std::string reststr = newstring.substr(index + old.length());  //from i to end
            //std::cout << "first part of the string: " << strfirst << "\n";
            //std::cout << "2nd part of the string: " << reststr << "\n";
            newstring = strfirst + rep + reststr;
            //std::cout << "new string: " << newstring << "\n";
            //index = founds[i] + rep.length();
            iterno += 1;
        }
    }

    return newstring;
}

// Splits the string up into a vector of strings based on splt parameter, if 
// splt parameter is empty string, then split on white space
std::vector< std::string > Split(const std::string &str, const std::string &splt = "")   //FIGURE OUT INDEX = 0 EDGE CASE
{
    std::vector<std::string> strs;     //https://cplusplus.com/forum/general/63211/
    std::string tempstr = str;
    std::string newstring = str;
    std::vector< int > founds;    //list of split indexes    
    int index; //= str.find(splt);


    if (splt.empty() || splt == " ") 
    {
        while (index)
       {
            int index = newstring.find(" ");
            if (index == -1)
                break;
            //std::cout << "whitespace found at: " << index << std::endl;
            newstring = Slice(newstring, 0, index);
            //std::cout << "pushed to vector: " << newstring << std::endl;
            if (index != 0)
                strs.push_back(newstring);
            newstring = Slice(tempstr, index+1);
            //std::cout << "rest of string to work on:" << newstring << std::endl;
            tempstr = newstring;
        }

        if (!newstring.empty())
        strs.push_back(newstring);  //push the last elem

    }

    //NOW IMPLEMENT FOR SINGLE CHAR (SAME AS ABOVE) AND SUBSTRING

    if (splt.length() == 1) 
    {
        while (index)
       {
            int index = newstring.find(splt);
            if (index == -1)
                break;
            //std::cout << "whitespace found at: " << index << std::endl;
            newstring = Slice(newstring, 0, index);
            //std::cout << "pushed to vector: " << newstring << std::endl;
            if (index != 0)
                strs.push_back(newstring);
            newstring = Slice(tempstr, index+1);
            //std::cout << "rest of string to work on:" << newstring << std::endl;
            tempstr = newstring;
        }

        if (!newstring.empty())
        strs.push_back(newstring);  //push the last elem

    }


    if (splt.length() > 1)   //substrs
    {
        //slice the length of splt

        while (index)
       {
            int index = newstring.find(splt);
            if (index == -1)
                break;
            //std::cout << "whitespace found at: " << index << std::endl;
            newstring = Slice(newstring, 0, index);
            //std::cout << "pushed to vector: " << newstring << std::endl;
            if (index != 0)
                strs.push_back(newstring);
            newstring = Slice(tempstr, (index+splt.length()));
            //std::cout << "rest of string to work on:" << newstring << std::endl;
            tempstr = newstring;
        }

        if (!newstring.empty())
        strs.push_back(newstring);  //push the last elem
    }


    
/* 
    while (index != std::string::npos)  //while there are matches
    { 
   
        founds.push_back(index);
        
    index = str.find(splt, index+1);   
    }

    for (int i = 0; i < founds.size(); i++)
    {
        newstring.resize(founds[i]);
        strs.push_back(newstring);
        newstring = tempstr;
    }

    int lastelem = founds.size();
    std::cout << "index: " << lastelem << "element: " << founds[lastelem] << std::endl;
    std::cout << "sliced here: " << founds[lastelem] << std::endl;
    newstring = Slice(newstring, founds[lastelem]);   //WILL BE CHANGED???
    strs.push_back(newstring); */

    return strs;


}
 
// Joins a vector of strings into a single string 
std::string Join(const std::string &str, const std::vector< std::string > 
&vect); 

// Replaces tabs with spaces aligning at the tabstops 
std::string ExpandTabs(const std::string &str, int tabsize = 4)
{
    std::string rep = "";
    for (int i = 0; i < tabsize; i++)
    {
        rep = rep + " ";
    } 

    std::string newstring = str;
    newstring = Replace(newstring, "    ", rep);
    return newstring;
}

int main()
{
/*     std::string sample = "Hello World";
    std::string subsample1 = Slice(sample, 0);  //Hello World
    std::cout << subsample1 << std::endl;

    std::string subsample2 = Slice(sample, 1);  //ello World
    std::cout << subsample2 << std::endl;

    std::string subsample3 = Slice(sample, -2);  //ld
    std::cout << subsample3 << std::endl;

    std::string subsample4 = Slice(sample, -11);  //Hello World
    std::cout << subsample4 << std::endl;

        std::string subsample5 = Slice(sample, 12);  //WHAT TO RETURN WHEN OUT OF BOUNDS????
    std::cout << subsample5 << std::endl; */

/*     std::string ex = "Hello hey";
    std::string test1 = Capitalize(ex);
    std::cout << test1 << std::endl; */


/*     std::string ex = "hello wassup wasgood?";
    std::string test = Upper(ex);
    std::cout << test << std::endl;

        std::string ex1 = "heLLo wassup wasgood?";
    std::string test1 = Upper(ex);
    std::cout << test1 << std::endl; */

/*      std::string ex = "hello wassup wasgood?";
    std::string test = Lower(ex);
    std::cout << test << std::endl;

        std::string ex1 = "heLLo wassup WASGood?";
    std::string test1 = Lower(ex1);
    std::cout << test1 << std::endl;  */
/* 
    std::string ex = "     hi there ";
    std::string test = LStrip(ex);
    std::cout << test << std::endl;

        std::string ex1 = "     what is up   ";
    std::string test1 = LStrip(ex1);
    std::cout << test1 << std::endl;


        std::string ex2 = "what is good   ";
    std::string test2 = LStrip(ex2);
    std::cout << test2 << std::endl; */


/*     std::string ex = "    what is upp     ";
    std::string test = RStrip(ex);
    std::cout << "length of new string: " << test.length() << " " << test << std::endl;

    std::string ex1 = " hello hey    ";
    std::string test1 = RStrip(ex1);
    std::cout << "length of new string: " << test1.length() << " " << test1 << std::endl;

std::string ex2 = "what is going on!!   ";
    std::string test2 = RStrip(ex2);
    std::cout << "length of new string: " << test2.length() << " " << test2 << std::endl; */


/*     std::string ex = "    what is upp     ";
    std::string test = Strip(ex);
    std::cout << "length of new string: " << test.length() << " " << test << std::endl;

    std::string ex1 = " hello hey    ";
    std::string test1 = Strip(ex1);
    std::cout << "length of new string: " << test1.length() << " " << test1 << std::endl;

std::string ex2 = "what is going on!!   ";
    std::string test2 = Strip(ex2);
    std::cout << "length of new string: " << test2.length() << " " << test2 << std::endl; */



/* std::string ex = "what is upp";
std::string test = Center(ex, 1);
std::cout << "length of new string: " << test.length() << " " << test << std::endl; */

/* std::string ex = "what is upp";
std::string test = LJust(ex, 1);
std::cout << "length of new string: " << test.length() << " " << test << std::endl;
 */

/* std::string ex = "what is upp";
std::string test = RJust(ex, 1);
std::cout << "length of new string: " << test.length() << " " << test << std::endl;
 */

/* std::string ex = "is what is going on in is going it going is";   // old > rep
std::string old = "going";
std::string rep = "dl";
std::string test = Replace(ex, old, rep);
std::cout << "old string: " << ex << "\n" << "new string: ";
std::cout << test << std::endl;

std::cout << "\n";

std::string ex1 = "is what is going on in is going it going is";   //old < rep
std::string old1 = "is";
std::string rep1 = "grrah";
std::string test1 = Replace(ex1, old1, rep1);
std::cout << "old string: " << ex1 << "\n" << "new string: ";
std::cout << test1 << std::endl; 

std::cout << "\n";

std::string ex2 = "is what is going on in is going it going is";  //old = rep
std::string old2 = "is";
std::string rep2 = "as";
std::string test2 = Replace(ex2, old2, rep2);  //what if rep has a substring equal to old???
std::cout << "old string: " << ex2 << "\n" << "new string: ";
std::cout << test2 << std::endl;

std::cout << "\n";

std::string ex3 = "is what is going on in is going it going is";  //rep = 1 char
std::string old3 = "is";
std::string rep3 = "t";
std::string test3 = Replace(ex3, old3, rep3);  //what if rep has a substring equal to old???
std::cout << "old string: " << ex3 << "\n" << "new string: ";
std::cout << test3 << std::endl; */

/* std::string ex = "this has tabs";
std::cout << ex << std::endl;
ex = ExpandTabs(ex, 4);
std::cout << ex << std::endl; */


std::string ex = "two needlers in a haystack of needles full of needle is hard to find";

std::vector<std::string> strs = Split(ex, "two");
for (int i = 0; i < strs.size(); i++)
{
    std::cout << strs[i] << std::endl;
}  


}