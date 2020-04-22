import FWCore.ParameterSet.Config as cms

rpcNtupleMaker = cms.EDAnalyzer("RPCNtupleMaker",
        storeRpcDigis = cms.untracked.bool(True),
        rpcDigiLabel = cms.untracked.InputTag("muonRPCDigis"),
        storeRpcRecHits = cms.untracked.bool(True),
        rpcRecHitLabel = cms.untracked.InputTag("rpcRecHits"),
        )
