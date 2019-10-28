
/* 
 * File:   FileMan.h
 * Author: alex
 *
 */

#ifndef FILEMAN_H
#define FILEMAN_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>




std::vector<std::map<std::string,std::string>> FileManip(std::vector<std::string>FileName){
    
    std::vector<std::map<std::string,std::string>>ret;
    
    
//    std::vector<std::string>Names;
//    std::string n;
//    FileName += " ";
//    for(int i=0;i<FileName.size();i++){
//        if((int)FileName.at(i)!=32){
//            n += FileName.at(i);
//            if(i+1<FileName.size() && (int)FileName.at(i+1)==32){
//                Names.push_back(n);
//                n="";
//            }
//        }
//    }
    
    
    std::cout<<"File(s) : "<<std::endl;
    std::copy(FileName.begin(),FileName.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
    
    
    char N;
    std::string code="";
    for(int j=0;j<FileName.size();j++){
        std::ifstream ifs = std::ifstream(FileName.at(j));
        if(ifs.is_open()){
            while(!ifs.eof()){
            ifs.get(N);
            if((int)N==10){code += "";}
            else{
              code += N;
                //it will change values of string!!
            if(((int)N>33 && (int)N<46) || (int)N==47 || ((int)N>57 && (int)N<65) || ((int)N>90 && (int)N<97) || ((int)N>122 && (int)N<=126)) {
                
            //left    
            if((int)(code[code.length()-2])==32){
                int a=code.length()-1;
                while((int)code[a-1]==32){
                    code[a-1]='\0';
                    a--;
                }    
            }   
            }
            }
            
        } 
             std::cout<<code<<std::endl;
//            ifs.close();
//            bool check;
//             for(int k=0;k<code.length();k++){
//                 
//             if((int)code.at(k)==33 || ((int)code.at(k)>34 && (int)code.at(k)<46) || (int)code.at(k)==47 || ((int)code.at(k)>57 && (int)code.at(k)<65) || ((int)code.at(k)>90 && (int)code.at(k)<97) || ((int)code.at(k)>122 && (int)code.at(k)<=126)) {
//                 check=1;
//             }
//             if((int)code.at(k)==32 && check){
//                 while((int)code.at(k)==32 && k < code.length()){
//                    
//                 code.at(k) = '\0'; 
//                 k++;
//                 }
//                 
//                 check = 0;
//             }
//        }
          //   std::cout<<code<<std::endl;
            code.erase(std::remove(code.begin(), code.end(), '\0'), code.end());  
          //   std::cout<<code<<std::endl;
            std::map<std::string,std::string>M{{FileName.at(j),code}};
             ret.push_back(M); 
        
        }else{
            std::cout<<"Can't open file with name : "<<FileName.at(j)<<std::endl;
        }
    }
    
    std::cout<<"Done!"<<std::endl;
    
    
    
    return ret;
    
}




 



#endif /* FILEMAN_H */

