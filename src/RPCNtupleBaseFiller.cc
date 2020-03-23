#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleBaseFiller.h" 

RPCNtupleBaseFiller::RPCNtupleBaseFiller(const std::shared_ptr<RPCNtupleConfig> config, 
                       std::shared_ptr<TTree> tree, const std::string & label) : 
  m_config(config), m_tree(tree), m_label(label) 
{ 
  
}

RPCNtupleBaseFiller::~RPCNtupleBaseFiller()
{ 

}

