// PluginSoftcut.cpp
// Mads Kjeldgaard (madskjeldgaardnielsen@gmail.com)

#include "Softcut.hpp"
#include "SC_PlugIn.hpp"

static InterfaceTable *ft;

namespace SoftcutSC {

Softcut::Softcut() {
  const auto sampleRate = this->mRate->mSampleRate;
  mSoftCut.setSampleRate(sampleRate);

  // Initial rate
  const auto rate = 1.0f;
  mSoftCut.setRate(0, rate);

  // Loop start
  const auto loopStartSeconds = 0.0f;
  mSoftCut.setLoopStart(0, 0.0f);

  // Initial loop end
  const auto loopEndSeconds = 1.0f; // TODO: Should be based on buffer size
  mSoftCut.setLoopEnd(0, loopEndSeconds);

  // Loop flag
  const auto loopFlag = true;
  mSoftCut.setLoopFlag(0, loopFlag);

  // Fade time
  const auto fadeTimeSeconds = 0.1f;
  mSoftCut.setFadeTime(0, fadeTimeSeconds);

  // Rec level
  const auto recLevel = 1.0f;
  mSoftCut.setRecLevel(0, recLevel);

  // Pre level
  const auto preLevel = 1.0f;
  mSoftCut.setPreLevel(0, preLevel);

  // Rec flag
  const auto recFlag = true;
  mSoftCut.setRecFlag(0, recFlag);

  // Play flag
  const auto playFlag = true;
  mSoftCut.setPlayFlag(0, playFlag);

  // set voice buffer
  // FIXME: TODO
  // mSoftCut.setVoiceBuffer(0, buffer, bufferFrames);

  // Set the calc function
  mCalcFunc = make_calc_function<Softcut, &Softcut::next>();

  next(1);
}

void Softcut::next(int nSamples) {

  // Audio rate input
  const float *input = in(0);

  // Control rate parameter: gain.
  const float gain = in0(1);

  // Output buffer
  float *outbuf = out(0);

  mSoftCut.processBlock(0, input, outbuf, nSamples);
}

} // namespace SoftcutSC

PluginLoad(SoftcutUGens) {
  // Plugin magic
  ft = inTable;
  registerUnit<SoftcutSC::Softcut>(ft, "Softcut", false);
}
