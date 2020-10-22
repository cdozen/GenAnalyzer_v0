from CRABClient.UserUtilities import config
from CRABClient.UserUtilities import getUsername
username = getUsername()
config = config()
config.section_('General')
config.General.requestName = 'crabOutput2018_DPSMCJJ_withgenfilter'
config.General.workArea = 'crabOutput2018_DPSMCJJ_withgenfilter'
config.General.transferOutputs = True
config.General.transferLogs = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'GenAnalyzer_cfg.py'
config.JobType.allowUndistributedCMSSW = True
#config.Data.inputDataset ='/DPSTo4mu_13TeV_pythia8/zhenhu-BPHSkim-v3-RunIIAutumn18MiniAOD-d2e730fa23c2d26c2f10ec533461faef/USER'
#config.Data.inputDataset ='/SPSTo4mu_13TeV_pythia8_hwen/zhenhu-BPHSkim-v4-RunIIAutumn18MiniAOD-d2e730fa23c2d26c2f10ec533461faef/USER'
#config.Data.inputDataset ='/JHU_JJto4mu_0p_6dot9/hwen-MC2018_skim_RECO_6900_cernbox_v1-548e5de234667f215bbd0c305e6f05af/USER'
#gen level sample without gen filter
#config.Data.inputDataset ='/DPSToJJ_13TeV_pythia8/zhenhu-crab_RunIIAutumn18MiniAOD-102X_upgrade2018_realistic_v15-GENSIM-DPSTo4mu-noGenCut-v2-391455752ee5283724f21c0b29d91758/USER'
#gen level sample with gen filter
config.Data.inputDataset ='/DPSTo4mu_13TeV_pythia8/zhenhu-BPHSkim-v3-RunIIAutumn18MiniAOD-d2e730fa23c2d26c2f10ec533461faef/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'#'LumiBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = '/store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples/GenFilter/'
#/eos/uscms/store/user/cdozen/FourMuon_Analysis/DPS_MC_Ntuples
config.Data.publication = False
config.Data.outputDatasetTag = None
config.Data.ignoreLocality = True

#config.Site.whitelist = ["T2_CH*"]
#config.Site.storageSite = 'T2_CH_CERNBOX'
config.Site.whitelist = ["T2_US*"]
config.Site.storageSite = 'T3_US_FNALLPC'
