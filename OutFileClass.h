class OutFileClass {
private :
  TFile* file_;
  std::map<std::string, TTree*> tree_;
  std::map<std::string, TH1*> th1_;
  std::map<std::string, TH2*> th2_;
public :
  OutFileClass(TFile* file) {
    SetFile(file);
  }
  JetTree data;
  void SetFile(TFile* file) { file_ = file; }
  TFile* GetFile() { return file_;}
  void AddTH1(TH1* h1) { th1_.insert( pair<std::string, TH1*>(std::string(h1->GetName()), h1)) ; }
  void AddTH1(std::string str, TH1* h1) { th1_.insert( pair<std::string, TH1*>(str, h1)) ; }
  void AddTree(TTree* tree) { AddTree(tree->GetName(), tree); }
  void AddTree(std::string str, TTree* tree) { tree_.insert( pair<std::string, TTree*>(str, tree)) ; }
  TH1* GetTH1(std::string str) {
    auto value = th1_.find(str);
    if ( value != th1_.end() ) return value->second;
    else return nullptr;
  }
  TTree* GetTree(std::string str) {
    auto value = tree_.find(str);
    if ( value != tree_.end() ) return value->second;
    else return nullptr;
  }
  void Write() {
    AllHistWrite();
    AllTreeWrite();
  }
  void AllHistWrite() { 
    for( auto i = th1_.begin() ; i != th1_.end(); ++i) {
      i->second->Write();
    } 
    for( auto i = th2_.begin() ; i != th2_.end(); ++i) {
      i->second->Write();
    }
  } 
  void AllTreeWrite() {
    for( auto i = tree_.begin() ; i != tree_.end(); ++i) {
      i->second->Write();
    } 
  }
};
