
#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleConfig.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"

//#include "Geometry/Records/interface/GlobalTrackingGeometryRecord.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"


RPCNtupleConfig::RPCNtupleConfig(const edm::ParameterSet & config) 
{ 

  edm::InputTag none = edm::InputTag("none");

  m_inputTags["rpcDigiLabel"] = config.getUntrackedParameter<edm::InputTag>("rpcDigiLabel", none);
  m_storeRpcDigis = config.getUntrackedParameter<bool>("storeRpcDigis");
  m_inputTags["rpcRecHitLabel"] = config.getUntrackedParameter<edm::InputTag>("rpcRecHitLabel", none);
  m_storeRpcRecHits = config.getUntrackedParameter<bool>("storeRpcRecHits");

}

void RPCNtupleConfig::getES(const edm::EventSetup & environment) 
{ 

  environment.get<MuonGeometryRecord>().get(m_rpcGeometry);

}

