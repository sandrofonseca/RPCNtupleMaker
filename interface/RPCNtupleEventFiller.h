#ifndef RPCNtupleEventFiller_h
#define RPCNtupleEventFiller_h

#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleBaseFiller.h"

#include "FWCore/Framework/interface/ConsumesCollector.h"

class RPCNtupleEventFiller : public RPCNtupleBaseFiller
{

 public:

  /// Constructor
  RPCNtupleEventFiller(edm::ConsumesCollector && collector,
              const std::shared_ptr<RPCNtupleConfig> config, 
              std::shared_ptr<TTree> tree, const std::string & label);

  ///Destructor
  virtual ~RPCNtupleEventFiller();
 
  /// Intialize function : setup tree branches etc ... 
  virtual void initialize() final;
  
  /// Clear branches before event filling 
  virtual void clear() final;

  /// Fill tree branches for a given events
  virtual void fill(const edm::Event & ev) final;    

 private :

  int m_runNumber;
  int  m_lumiBlock;
  int64_t m_eventNumber;

  uint64_t m_timeStamp;
  
  int  m_bunchCrossing;
  int64_t m_orbitNumber;
  
};
  
#endif
