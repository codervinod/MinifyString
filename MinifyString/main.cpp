//
//  main.cpp
//  MinifyString
//
//  Created by Vinod Gupta on 2/25/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>


void minifyStrUtil(char *str)
{
    int i=0,j=0;
    while(str[i] !=' ' && str[i] != '\0')
        ++i;
    
    if(str[i] == '\0')
        return;
    
    j=i+1;
    while(str[j] == ' ' && str[j] != '\0')
        ++j;
    
    if(str[j] == '\0')
    {
        str[i+1] = '\0';
        return;
    }
    
    int tmp=i+1;
    while(str[j] != ' ' && str[j] !='\0')
    {
        str[i+1] = str[j];
        str[j] = ' ';
        ++i;
        ++j;
    }
    
    minifyStrUtil(str+tmp);
}


void minifyStr(const char*str)
{
    char *mystr = (char*)str;
    int i=0;
    //REMOVE PREFIX SPACE IF ANY
    while(mystr[i] == ' ' && mystr[i+1] != '\0')
    {
        mystr[i]=mystr[i+1];
        mystr[i+1] = ' ';
        ++i;
    }
    minifyStrUtil((char*)mystr);
}

int main(int argc, const char * argv[]) {
    char str[]=" I     love     my     India. ";
    std::cout << "Original string:"<<str<<"\n";
    minifyStr(str);
    std::cout << "Minified string:"<<str<<"\n";
    return 0;
}
