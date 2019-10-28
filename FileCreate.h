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

void DoIt(std::vector<std::map<std::string,std::string>>List,std::string Dest){
    
    
  const int dir_err = Dest.length()>0 ? mkdir((Dest +'/'+ "Your_Files").c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) : -1;
  if (-1 == dir_err){
    printf("Error creating directory!n");
    exit(1);
}
  
    if(!Dest.empty()){ 
    for(int it=0;it<List.size();it++){
      std::string name = List[it].begin()->first; 
      std::ofstream ofs = std::ofstream(Dest+ '/' +"Your_Files"+ '/' + name);
      ofs<<std::noskipws<<List[it].begin()->second<<std::endl;
      ofs.close();
      }
      
    }
    
}



#endif /* FILECREAT_H */

