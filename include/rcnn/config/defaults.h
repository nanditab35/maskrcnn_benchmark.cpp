#pragma once
#include <string>
#include <algorithm>
#include "yaml-cpp/yaml.h"

namespace rcnn{
namespace config{

namespace{
  YAML::Node* cfg = nullptr;
};

void SetCFGFromFile(const std::string file_path);

template<typename T>
void SetNode(YAML::Node parent, T value){
  if(parent.Type() == YAML::NodeType::Undefined){
    parent = value;
  }
}

class CFGS{
  private:
    std::string name_;
    char* name_c_;

  public:
    CFGS(std::string name);
    CFGS(const CFGS& other);
    CFGS(CFGS&& other);
    CFGS& operator=(const CFGS& other);
    CFGS& operator=(CFGS&& other);
    ~CFGS();
    char* get();
};
//TODO
//std::string argument occurs undefined reference error
//so seperate get cfg char

//get code related bug
//https://github.com/pytorch/pytorch/issues/19353
//implementation in header occurs link error
template<typename T>
T GetCFG(std::initializer_list<const char*> node);

}//configs
}//mrcn