#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"


#include "RPCAnalysis/RPCNtupleMaker/plugins/RPCNtupleMaker.h"
#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleEventFiller.h"
#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleDigiFiller.h"
#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleConfig.h"

RPCNtupleMaker::RPCNtupleMaker(const edm::ParameterSet & config){
    
    edm::Service<TFileService> fileService;
    m_tree = std::shared_ptr<TTree>(fileService->make<TTree>("RPCTree","RPC Tree"));
    m_config = std::make_shared<RPCNtupleConfig>(RPCNtupleConfig(config));

    m_fillers.push_back(std::make_unique<RPCNtupleEventFiller>(consumesCollector(), m_config, m_tree, "event"));
    if (m_config->m_storeRpcDigis){
        m_fillers.push_back(std::make_unique<RPCNtupleDigiFiller>(consumesCollector(), m_config, m_tree, "digi"));
    }
    if (m_config->m_storeRpcRecHits){
        m_fillers.push_back(std::make_unique<RPCNtupleRecHitFiller>(consumesCollector(), m_config, m_tree, "recHit"));
    }
}

void RPCNtupleMaker::beginJob() 
{

    for (const auto & filler : m_fillers){
         filler->initialize();
         filler->clear();
    }

}

void RPCNtupleMaker::beginRun(const edm::Run & run, const edm::EventSetup & environment ){

    environment.get<MuonGeometryRecord>().get(m_rpcGeo);
    m_config->getES(environment);

}

void RPCNtupleMaker::endJob(){

    m_tree->Write();

}

void RPCNtupleMaker::analyze(const edm::Event & ev, const edm::EventSetup & environment ){

    for (const auto & filler : m_fillers){
         filler->fill(ev);
    }

    m_tree->Fill();

}

DEFINE_FWK_MODULE(RPCNtupleMaker);
