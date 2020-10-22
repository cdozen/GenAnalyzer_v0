# GenAnalzer
Gen level Ntuple producer for Double Jpsi

cmsrel CMSSW_10_2_5 
cd CMSSW_10_2_5/src
cmsenv
git clone https://github.com/cdozen/GenAnalzer.git

scram b -j24

main code :

plugins/GenAnalyzer.cc 

To run it locally:

Add Gen Level dataset in 

/test/GenAnalyzer_cfg.py 

run : 

cmsRun GenAnalyzer_cfg.py

Submit job to crab: 

for a single dataset : crab submit -c crabconfig_MC_jpsi.py

Add dataset name:

Line# 20
config.Data.inputDataset =' Datasetname....'

Add output files path :

Line #24 

config.Data.outLFNDirBase = '/store/user/username/Folder/Subfolder2/'

for multiple dataset:  multicrab_MC or multicrab_MCJJ

Add output files path :

Line#95

config.Data.outLFNDirBase = '/store/user/username/Folder/Subfolder2/'

Add Dataset name in 

Line #102 

inputDatasets = [Datasetnames....]

Submit jobs:

./multicrab_MC --crabCmd=submit
