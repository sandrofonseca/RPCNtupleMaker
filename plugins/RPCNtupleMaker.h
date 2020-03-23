#ifndef RPCNtupleMaker_h
#define RPCNtupleMaker_h

// author Brieuc Francois

#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleConfig.h"
#include "RPCAnalysis/RPCNtupleMaker/interface/RPCNtupleBaseFiller.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
//#include "FWCore/ParameterSet/interface/ConfigurationDescriptions.h"

class RPCNtupleMaker : public edm::EDAnalyzer {

    public:
        RPCNtupleMaker(const edm::ParameterSet &);
        virtual void analyze(const edm::Event&, const edm::EventSetup&);
        virtual void beginRun(const edm::Run&, const edm::EventSetup&);
        virtual void beginJob();
        virtual void endJob();

    private:
        std::shared_ptr<TTree> m_tree;
        std::shared_ptr<RPCNtupleConfig> m_config;
        std::vector<std::unique_ptr<RPCNtupleBaseFiller>> m_fillers;
        edm::ESHandle<RPCGeometry> m_rpcGeo;

};

#endif
