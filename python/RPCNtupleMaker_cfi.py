import FWCore.ParameterSet.Config as cms

rpcNtupleMaker = cms.EDAnalyzer("RPCNtupleMaker",
        rpcDigiLabel = cms.untracked.InputTag("muonRPCDigis"),
        rpcRecHitLabel = cms.untracked.InputTag("rpcRecHits"),
        )
