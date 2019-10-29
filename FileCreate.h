/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FileCreat.h
 * Author: alex
 *
 * Created on October 29, 2019, 12:10 AM
 */

#ifndef FILECREAT_H
#define FILECREAT_H

#include<iostream>
#include<vector>
#include <fstream>
#include <sys/stat.h>
#include <string>
#include <unistd.h>
#include <map>


std::string SplitFilename (const std::string& str)
{
  std::cout << "Splitting: " << str << '\n';
  auto found = str.find_last_of("/\\");
 // std::cout << " path: " << str.substr(0,found) << '\n';
 // std::cout << " file: " << str.substr(found+1) << '\n';
  return str.substr(found+1);
}





void DoIt(const std::vector<std::map<std::string,std::string>>List,const std::string Dest){
    
  const int dir_err = Dest.length()>0 ? mkdir((Dest +'/'+ "Your_Files").c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) : -1;
  if (-1 == dir_err){
    printf("Error creating directory!n");
    exit(1);
}
  
    if(!Dest.empty()){ 
    for(int it=0;it<List.size();it++){
      std::string name = SplitFilename(List[it].begin()->first);
      std::ofstream ofs = std::ofstream(Dest+ '/' +"Your_Files"+ '/' + name);
      ofs<<std::noskipws<<List[it].begin()->second<<std::endl;
      ofs.close();
      }
      
    }
    
}






#endif /* FILECREAT_H */

