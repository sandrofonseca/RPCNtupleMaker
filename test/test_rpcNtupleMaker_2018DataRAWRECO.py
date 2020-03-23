import FWCore.ParameterSet.Config as cms
process = cms.Process("RPCNtupleMaker")

# import of standard configurations
#process.load('Configuration.StandardSequences.Services_cff')
#process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
#process.load('FWCore.MessageService.MessageLogger_cfi')
#process.load('Configuration.EventContent.EventContent_cff')
#process.load('SimGeneral.MixingModule.mixNoPU_cfi')
##process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
##process.load('Configuration.Geometry.GeometryDB_cff')
##process.load('Configuration.StandardSequences.GeometryExtended_cff')
#process.load('Configuration.Geometry.GeometryExtended2016_cff')
#process.load('Configuration.Geometry.GeometryExtended2016Reco_cff')
#process.load('Configuration.StandardSequences.MagneticField_38T_cff')
#process.load('Configuration.StandardSequences.Generator_cff')
#process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic50ns13TeVCollision_cfi')
#process.load('GeneratorInterface.Core.genFilterSummary_cff')
#process.load('Configuration.StandardSequences.SimIdeal_cff')
#process.load('Configuration.StandardSequences.Digi_cff')
#process.load('Configuration.StandardSequences.EndOfProcess_cff')
#process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.load('Configuration.StandardSequences.Services_cff')
process.load('FWCore.MessageService.MessageLogger_cfi')

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
#process.GlobalTag.globaltag = cms.string("92X_dataRun2_Prompt_v11")
process.GlobalTag.globaltag = cms.string("103X_dataRun2_Prompt_v3")

process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
#process.load("Configuration.StandardSequences.GeometryDB_cff")
process.load("Configuration.StandardSequences.MagneticField_cff")

process.source = cms.Source("PoolSource", fileNames = cms.untracked.vstring(
    'file:/eos/cms/store/data/Run2018D/SingleMuon/RAW-RECO/ZMu-PromptReco-v2/000/321/457/00000/0C03F56B-BEA5-E811-AE45-FA163E96C3EF.root',
    )
    )
process.TFileService = cms.Service('TFileService',
                fileName = cms.string('RPCTree.root')
                )

#process.treeOut = cms.OutputModule("PoolOutputModule",
#                                   fileName = cms.untracked.string('output_edm.root'),
#                                   outputCommands = cms.untracked.vstring('drop *',
#                                                                          "keep *_rpc*_*_*" 
#                                                                          #"keep *"
#                                                                          )
#                                   )

process.load("EventFilter.RPCRawToDigi.rpcUnpacker_cfi")
import EventFilter.RPCRawToDigi.rpcUnpacker_cfi
muonRPCDigis = EventFilter.RPCRawToDigi.rpcUnpacker_cfi.rpcunpacker.clone()
muonRPCDigis.InputLabel = 'rawDataCollector'
process.rpcunpacker.InputLabel = 'rawDataCollector'

#process.load("EventFilter.RPCRawToDigi.rpcUnpackingModule_cfi")
#process.load("EventFilter.RPCRawToDigi.rpcUnpacker_cfi")
#import EventFilter.RPCRawToDigi.rpcUnpacker_cfi
#muonRPCDigis = EventFilter.RPCRawToDigi.rpcUnpacker_cfi.rpcunpacker.clone()
#muonRPCDigis.InputLabel = 'rawDataCollector'
#process.rpcunpacker.InputLabel = 'rawDataCollector'


process.load('RPCAnalysis.RPCNtupleMaker.RPCNtupleMaker_cfi')
process.rpcNtupleMaker.rpcDigiLabel = 'rpcunpacker'

process.p = cms.Path(process.rpcunpacker + process.rpcNtupleMaker)
#process.EndPath = cms.EndPath(process.treeOut)
#process.unpacker = cms.Path(process.rpcUnpackingModule)
#process.nTupleMaker = cms.Path(process.rpcNtupleMaker)

#process.p = cms.Schedule(
#        process.unpacker,
#        process.nTupleMaker)

