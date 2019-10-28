/* 
 * File:   main.cpp
 * Author: alex
 *
 */

#include <iostream>
#include <vector>
#include "FileMan.h"
#include "FileCreate.h"


int main(int argc, char** argv) {
  
   std::vector<std::string>Files;
   for(int i=1;i<argc;i++){
       Files.push_back(argv[i]);
       std::cout<<argv[i];
   }
    std::vector<std::map<std::string,std::string>>c=FileManip(Files);
    
    std::string dest;
    std::cout<<"give me Destination  "<<std::flush;
    std::cin>>dest;
    DoIt(c,dest);
    
    
    return 0;
}

