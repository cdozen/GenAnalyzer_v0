// -*- C++ -*-
//
// Package:    GenAnalyzer/GenAnalyzer
// Class:      GenAnalyzer
//
/**\class GenAnalyzer GenAnalyzer.cc GenAnalyzer/GenAnalyzer/plugins/GenAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Candan Dozen
//         Created:  Sat, 11 Jul 2020 11:06:05 GMT
//
//


// system include files
#include <memory>

// user include files
#include <vector>
#include <iostream>
#include <string>

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <DataFormats/HepMCCandidate/interface/GenParticle.h>
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/HepMCCandidate/interface/GenStatusFlags.h"
#include "DataFormats/Candidate/interface/CompositeRefCandidateT.h"
#include "DataFormats/EgammaCandidates/interface/Conversion.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"


#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include <FWCore/Framework/interface/ESHandle.h>


#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"




//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<>
// This will improve performance in multithreaded jobs.
#include <TString.h>
#include <stdio.h>
#include <TCanvas.h>
#include <TROOT.h>
// ************* NTuple ***************************************************
#include <TNtuple.h>
#include <TTree.h>
// // ************************************************************************

// ROOT
#include "TTree.h"
//#include "TLorentzVector.h"
#include "TClonesArray.h"
#include "TParticle.h"
#include "TVector3.h"
#include "TH1F.h"
#include "TH2F.h"
// 


//#include <TFile.h>
#include <vector>
using namespace std;
using namespace edm;
using namespace reco;



//using reco::TrackCollection;

class GenAnalyzer : public edm::EDAnalyzer  {
   public:
      explicit GenAnalyzer(const edm::ParameterSet&);
      ~GenAnalyzer();

      static void fillDescriptions(edm::ConfigurationDescriptions & descriptions);
      void FillTruth(const edm::Event&, const edm::EventSetup&);  

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

int GENfinalState;
                bool passedFiducialSelection;
                bool verbose=false;
                //std::vector<double> GENmu_pt; std::vector<double> GENmu_eta; std::vector<double> GENmu_phi; std::vector<double> GENmu_mass; 

std::vector<int>   GEN_Nmother;
std::vector<int>   GEN_Ndaughter;
std::vector<int>   GEN_pdgID;
std::vector< std::vector<int> >   GEN_Daughter_pdgID;
std::vector< std::vector<int> >   GEN_Mother_pdgID;
std::vector<double>GEN_pt;
std::vector<double>GEN_eta;
std::vector<double>GEN_phi;
std::vector<double>GEN_rapidity;
std::vector<double>GEN_mass;
std::vector<int>   GEN_status;

/*std::vector<int>GEN_Mom_barcode;
std::vector<int>GEN_Mom_ID;
std::vector<double>GEN_Mom_pt;
std::vector<double>GEN_Mom_eta;
std::vector<double>GEN_Mom_phi;
std::vector<double>GEN_Mom_rapidity;
std::vector<double>GEN_Mom_mass;
std::vector<int>GEN_Mom_status;

std::vector<int>GEN_Dau_barcode;
std::vector<int>GEN_Dau_ID;
std::vector<double>GEN_Dau_pt;
std::vector<double>GEN_Dau_eta;
std::vector<double>GEN_Dau_phi;
std::vector<double>GEN_Dau_rapidity;
std::vector<double>GEN_Dau_mass;
std::vector<int>GEN_Dau_status;
*/
TTree * _mytree;
TTree * _MMGtree;



// cocuktan alinan
// -------------------------
// GEN level information
// -------------------------
// Event variables
//int GENfinalState;
//bool passedFiducialSelection;
std::vector<double> GENmu_pt; 
std::vector<double> GENmu_eta; 
std::vector<double> GENmu_phi; 
std::vector<double> GENmu_mass; 
std::vector<int>    GENmu_id; 
std::vector<int>    GENmu_status; 
std::vector<int>    GENmu_MomId; 
std::vector<int>    GENmu_MomMomId;

std::vector<int>    GENups_DaughtersId;
std::vector<double> GENups_Daughter_mupt;
std::vector<double> GENups_Daughter_mueta;
std::vector<double> GENups_Daughter_muphi;
std::vector<double> GENups_Daughter_mumass;
std::vector<double> GENups_Daughter_mustatus;
std::vector<int>    GENups_Daughter_muid;
std::vector<int>    GENups_MomId;
std::vector<double> GENups_pt;
std::vector<double> GENups_eta;
std::vector<double> GENups_y;
std::vector<double> GENups_phi;
std::vector<double> GENups_mass;

//end
  
    const edm::ParameterSet&  conf;
    edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticlesToken_;
    edm::EDGetTokenT<vector<reco::GenParticle> > genParticleToken_;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
GenAnalyzer::GenAnalyzer(const edm::ParameterSet& iConfig):
conf(iConfig)
{

   //now do what ever initialization is needed

genParticleToken_ = mayConsume<vector<reco::GenParticle>>(iConfig.getParameter<edm::InputTag>("genParticlesAOD"));
    
    edm::Service<TFileService> fs ;
    _mytree  = fs->make < TTree >("gen_tree","gen tree");
    _MMGtree  = fs->make < TTree >("gen_tree2","gen tree2");

}


GenAnalyzer::~GenAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void GenAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   FillTruth(iEvent, iSetup);
   //Tree fill
   _mytree->Fill();
   _MMGtree->Fill();
   
   //Clear vectorss
   GEN_Nmother.clear();
   GEN_Ndaughter.clear();
   GEN_pdgID.clear();
   GEN_pt.clear();
   GEN_eta.clear();
   GEN_phi.clear();
   GEN_rapidity.clear();
   GEN_mass.clear();
   GEN_status.clear();
   GEN_Daughter_pdgID.clear();
   GEN_Mother_pdgID.clear();
   /*GEN_Mom_barcode->clear();
   GEN_Mom_ID->clear();
   GEN_Mom_pt->clear();
   GEN_Mom_eta->clear();
   GEN_Mom_phi->clear();
   GEN_Mom_rapidity->clear();
   GEN_Mom_mass->clear();
   GEN_Mom_status->clear();
   GEN_Dau_barcode->clear();
   GEN_Dau_ID->clear();
   GEN_Dau_pt->clear();
   GEN_Dau_eta->clear();
   GEN_Dau_phi->clear();
   GEN_Dau_rapidity->clear();
   GEN_Dau_mass->clear();
   GEN_Dau_status->clear();
*/

GENmu_pt.clear();
GENmu_eta.clear();
GENmu_phi.clear();
GENmu_mass.clear();
GENmu_id.clear();
GENmu_status.clear();
GENmu_MomId.clear();
GENmu_MomMomId.clear();
GENups_DaughtersId.clear();
GENups_Daughter_mupt.clear();
GENups_Daughter_mueta.clear();
GENups_Daughter_muphi.clear();
GENups_Daughter_mumass.clear();
GENups_Daughter_mustatus.clear();
GENups_MomId.clear();
GENups_pt.clear();
GENups_eta.clear();
GENups_y.clear();
GENups_phi.clear();
GENups_mass.clear();

}


// ------------ method called once each job just before starting event loop  ------------
void
GenAnalyzer::beginJob()
{
    
    //Int_t mother_pdgId;
    //Int_t dimuon_pdgId;
    //TLorentzVector gen_dimuon_p4;
    //TLorentzVector gen_mu1_p4;
    //TLorentzVector gen_mu2_p4;
    
_mytree->Branch("GENfinalState",&GENfinalState,"GENfinalState/I");
_mytree->Branch("passedFiducialSelection",&passedFiducialSelection,"passedFiducialSelection/O");

//_mytree->Branch("GEN_barcode",&GEN_barcode);

_mytree->Branch("GEN_Nmother",&GEN_Nmother);
_mytree->Branch("GEN_Ndaughter",&GEN_Ndaughter);
_mytree->Branch("GEN_pdgID",&GEN_pdgID);
_mytree->Branch("GEN_pt",&GEN_pt);
_mytree->Branch("GEN_eta",&GEN_eta);
_mytree->Branch("GEN_phi",&GEN_phi);
_mytree->Branch("GEN_rapidity",&GEN_rapidity);
_mytree->Branch("GEN_mass",&GEN_mass);
_mytree->Branch("GEN_status",&GEN_status);
_mytree->Branch("GEN_Daughter_pdgID",&GEN_Daughter_pdgID);
_mytree->Branch("GEN_Mother_pdgID",&GEN_Mother_pdgID);

/*_mytree->Branch("GEN_Mom_barcode",&GEN_Mom_barcode);
_mytree->Branch("GEN_Mom_ID",&GEN_Mom_ID);
_mytree->Branch("GEN_Mom_pt",&GEN_Mom_pt);
_mytree->Branch("GEN_Mom_eta",&GEN_Mom_eta);
_mytree->Branch("GEN_Mom_phi",&GEN_Mom_phi);
_mytree->Branch("GEN_Mom_rapidity",&GEN_Mom_rapidity);
_mytree->Branch("GEN_Mom_mass",&GEN_Mom_mass);
_mytree->Branch("GEN_Mom_status",&GEN_Mom_status);

_mytree->Branch("GEN_Dau_barcode",&GEN_Dau_barcode);
_mytree->Branch("GEN_Dau_ID",&GEN_Dau_ID);
_mytree->Branch("GEN_Dau_pt",&GEN_Dau_pt);
_mytree->Branch("GEN_Dau_eta",&GEN_Dau_eta);
_mytree->Branch("GEN_Dau_phi",&GEN_Dau_phi);
_mytree->Branch("GEN_Dau_rapidity",&GEN_Dau_rapidity);
_mytree->Branch("GEN_Dau_mass",&GEN_Dau_mass);
_mytree->Branch("GEN_Dau_status",&GEN_Dau_status);
*/

_MMGtree->Branch("GENmu_pt",&GENmu_pt);
_MMGtree->Branch("GENmu_eta",&GENmu_eta);
_MMGtree->Branch("GENmu_phi",&GENmu_phi);
_MMGtree->Branch("GENmu_mass",&GENmu_mass);
_MMGtree->Branch("GENmu_id",&GENmu_id);
_MMGtree->Branch("GENmu_status",&GENmu_status);
_MMGtree->Branch("GENmu_MomId",&GENmu_MomId);
_MMGtree->Branch("GENmu_MomMomId",&GENmu_MomMomId);
_MMGtree->Branch("GENups_DaughtersId",&GENups_DaughtersId);
_MMGtree->Branch("GENups_Daughter_mupt",&GENups_Daughter_mupt);
_MMGtree->Branch("GENups_Daughter_mueta",&GENups_Daughter_mueta);
_MMGtree->Branch("GENups_Daughter_muphi",&GENups_Daughter_muphi);
_MMGtree->Branch("GENups_Daughter_mumass",&GENups_Daughter_mumass);
_MMGtree->Branch("GENups_Daughter_mustatus",&GENups_Daughter_mustatus);
_MMGtree->Branch("GENups_MomId",&GENups_MomId);
_MMGtree->Branch("GENups_pt",&GENups_pt);
_MMGtree->Branch("GENups_eta",&GENups_eta);
_MMGtree->Branch("GENups_y",&GENups_y);
_MMGtree->Branch("GENups_phi",&GENups_phi);
_MMGtree->Branch("GENups_mass",&GENups_mass);

    
    
    return;
}

// ------------ method called once each job just after ending the event loop  ------------
void
GenAnalyzer::endJob()
{
    return;
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
GenAnalyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

void GenAnalyzer::FillTruth(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
edm::Handle<vector<reco::GenParticle> > genCandidatesCollection;
iEvent.getByToken(genParticleToken_, genCandidatesCollection);

    
// ----------------------------
//   //      Loop on particles
//     // ----------------------------
for( auto p = genCandidatesCollection->begin();p != genCandidatesCollection->end(); ++ p ) {

if(verbose) {
    cout << "Status pdgid = " << fabs(p->pdgId()) << " status = "<< p->status()  << " Pt = "<< p->pt() << " Eta = " << p->eta() << "Numb of Mother="<< p->numberOfMothers()<< "Numb of Daughters="<< p->numberOfDaughters()<< endl;
}
///particle info
//GEN_barcode->push_back(p->barcode());
GEN_pdgID.push_back(p->pdgId());
GEN_pt.push_back(p->pt());
GEN_eta.push_back(p->eta());
GEN_phi.push_back(p->phi());
GEN_rapidity.push_back(p->rapidity());
GEN_mass.push_back(p->mass());
GEN_status.push_back(p->status());
//
int Nmothers   =p->numberOfMothers();
int Ndaughters =p->numberOfDaughters();
GEN_Nmother.push_back(Nmothers);
GEN_Ndaughter.push_back(Ndaughters);
std::vector<int> Temp_MotherpdgID,Temp_DaughterpdgID;

if(Nmothers>0) {
   for(int i=0;i<Nmothers;i++){
   Temp_MotherpdgID.push_back(p->mother(i)->pdgId());
   }

GEN_Mother_pdgID.push_back(Temp_MotherpdgID);
}
if(Ndaughters>0) {
   for(int i=0;i<Ndaughters;i++){
   Temp_DaughterpdgID.push_back(p->daughter(i)->pdgId());
   }
GEN_Daughter_pdgID.push_back(Temp_DaughterpdgID);
}

Temp_MotherpdgID.clear();
Temp_DaughterpdgID.clear();

//Muhammad Branches
    if(Nmothers>0 && Ndaughters>0){
         const reco::Candidate  *Mom = p->mother(0);
      if(Mom->numberOfMothers()>0){   
         const reco::Candidate  *GrandMom = Mom->mother(0);
        if (abs(p->pdgId())==13) {        //if it is muon 

        //if (!(p->status()==1)) continue; // only allow status 1 gen muons,	particle not decayed or fragmented, represents the final state as given by the generator
        if (!(Mom->pdgId()==553)) continue;  // Upsilon =553
   
         cout<<"found a gen muon: id "<<p->pdgId()<<" pt: "<<p->pt()<<" eta: "<<p->eta()<<endl;
           GENmu_id.push_back(p->pdgId() );
           GENmu_status.push_back(p->status());
           GENmu_pt.push_back(p->pt());
           GENmu_eta.push_back(p->eta());
           GENmu_phi.push_back(p->phi());
           GENmu_mass.push_back(p->mass());
           GENmu_MomId.push_back(Mom->pdgId());
           GENmu_MomMomId.push_back(GrandMom->pdgId()); 
             } // end Gen muons

            if (verbose) cout<<"p id : "<<p->pdgId() << " status: "<<p->status()<<endl;

            if ((p->pdgId()==553)  ) {
            const reco::Candidate *ups_dau0=p->daughter(0);            
            int ups_dauId = fabs(ups_dau0->pdgId());
            if (verbose) cout<<"Ups daughter : "<<ups_dauId<<endl;

            int ndau = p->numberOfDaughters();
            if (verbose) cout<<"Ups daughter size: "<<ndau<<endl;

                for (int d=0; d<ndau; d++) {
                    const reco::Candidate *ups_dau=p->daughter(d);
                    if (fabs(ups_dau->pdgId()) == 13) { //if daughter of ups is muon
                        ups_dauId = fabs(ups_dau->pdgId());
                        if (verbose) cout<<"ups Dau: "<<d<<" id: "<<fabs(ups_dau->pdgId())<<" status: "<<ups_dau->status() <<endl;
                        GENups_DaughtersId.push_back(fabs(ups_dau->pdgId()));
                        GENups_Daughter_mupt.push_back(ups_dau->pt());
                        GENups_Daughter_mueta.push_back(ups_dau->eta());
                        GENups_Daughter_muphi.push_back(ups_dau->rapidity());
                        GENups_Daughter_mumass.push_back(ups_dau->phi());
                        GENups_Daughter_mustatus.push_back(ups_dau->status());
                        GENups_Daughter_muid.push_back(ups_dau->mass());
                    }
                } //daughter loop

            GENups_MomId.push_back(Mom->pdgId());                
            GENups_pt.push_back(p->pt());
            GENups_eta.push_back(p->eta());
            GENups_y.push_back(p->rapidity());
            GENups_phi.push_back(p->phi());
            GENups_mass.push_back(p->mass());
                } // Upsilon ifi
            //end Muhammad branches
            } //if Gndmother>0
        }//if mother/daughter>0

    } // particle loop

}

//define this as a plug-in
DEFINE_FWK_MODULE(GenAnalyzer);
