class JetTree {
public :
  float weight;
  float jet_pt[2]; 
  float jet_eta[2]; 
  float jet_phi[2]; 
  int bjet_charge[2];
  int bjet_partonPdgId[2]; 
  int lep_charge[2];
  int bjet_btag[2];
  JetTree() {
    init();
  }
  void reset() { init(); }
  void init() {
    weight = -1e5;
    for (unsigned int i=0 ; i< 2 ; ++i) {
      jet_pt[i]=0.f;
      jet_eta[i]=-9.f;
      jet_phi[i]=-9.f;
      bjet_charge[i]=-9;
      bjet_partonPdgId[i] = 0 ;
      bjet_btag[i]= 0;
      bjet_charge[i]=-9;
    }
  }
};
