#include "abstractlevel.h"
#include "fstream"

using namespace std;

AbstractLevel::AbstractLevel(bool random, string seqFile, int seed):  seed{seed},  seqFile{seqFile}, random{random}, seqPos{0}{
  ifstream ifs;
  ifs.open(seqFile);
  char block;
  while(ifs >> skipws >> block){
    blockSeq.push_back(block);
  }
}

void AbstractLevel::setSeqFile(string newFile){
  seqFile = newFile;
  ifstream ifs;
  ifs.open(seqFile);
  char block;
  blockSeq.clear();
  while(ifs >> skipws >> block){
    blockSeq.push_back(block);
  }
}

AbstractLevel::~AbstractLevel(){}

bool AbstractLevel::isRandom(){
  (void)seed;
  return random;
}
