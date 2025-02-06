// PluginSoftcut.hpp
// Mads Kjeldgaard (madskjeldgaardnielsen@gmail.com)

#pragma once

#include "SC_PlugIn.hpp"
#include "softcut/Softcut.h"
#include "softcut/Types.h"

namespace SoftcutSC {

constexpr auto numVoices = 1;

class Softcut : public SCUnit {
public:
  Softcut();

  // Destructor
  // ~Softcut();

private:
  // Calc function
  void next(int nSamples);

  // Member variables
  softcut::Softcut<numVoices> mSoftCut;

  // Buffer
  std::vector<float> mBuffer;
};

} // namespace SoftcutSC
