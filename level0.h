#ifndef _level0_
#define _level0_

#include "abstractlevel.h"
#include <string>
#include <memory>

class AbstractBlock;

class Level0: public AbstractLevel {
 public:
  Level0(std::string seqFile, int seed);
  void setRandom(bool r) override;
  int getLevel() const override;
  std::shared_ptr<AbstractBlock> createBlock() override;
};

#endif
