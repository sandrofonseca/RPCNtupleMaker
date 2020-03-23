#ifndef RPCNtupleBaseFiller_h
#define RPCNtupleBaseFiller_h

#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleConfig.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "TTree.h"

#include <memory>
#include <string>

class RPCNtupleBaseFiller
{

 public :

  /// Constructor
  RPCNtupleBaseFiller(const std::shared_ptr<RPCNtupleConfig> config, 
             std::shared_ptr<TTree> tree, const std::string & label);
  
  /// Destructor
  virtual ~RPCNtupleBaseFiller();

  /// Intialize function : setup tree branches etc ...
  virtual void initialize() = 0;

  /// Clear branches before event filling
  virtual void clear() = 0;

  /// Fill tree branches for a given event
  virtual void fill(const edm::Event & ev) = 0;

 protected :

  /// Definition of default values for int variables
  static constexpr int DEFAULT_INT_VAL = -999;

  /// Definition of default values for positive int variables
  static constexpr int DEFAULT_INT_VAL_POS = -1;

  /// Definition of default values for float variables
  static constexpr double DEFAULT_DOUBLE_VAL = -999.;

  /// Definition of default values for positive float variables
  static constexpr double DEFAULT_DOUBLE_VAL_POS = -1.;
 
  /// Ponter to the configuration
  std::shared_ptr<RPCNtupleConfig> m_config;

  /// Pointer to the TTree
  std::shared_ptr<TTree> m_tree;

  /// The label at the beginning of each branch
  std::string m_label;

  /// Conditional getter :
  /// checks whether a token is valid and if
  /// retireving the data collection succeded
  template<typename T> edm::Handle<T> conditionalGet(const edm::Event & ev,
                             const edm::EDGetTokenT<T> & token,
                             const std::string & collectionName)
    {

      edm::Handle<T> collection ;

      if (!token.isUninitialized()) 
    {
      if (!ev.getByToken(token, collection)) 
        edm::LogError("") << "[RPCNtuple]::conditionalGet: "
                  << collectionName << " collection does not exist !!!";
    }
      
      return collection;

    }
};

#endif

