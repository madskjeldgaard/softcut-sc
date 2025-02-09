// PluginSoftcut.cpp
// Mads Kjeldgaard (madskjeldgaardnielsen@gmail.com)

#include "Softcut.hpp"
#include "SC_PlugIn.hpp"

static InterfaceTable *ft;

namespace SoftcutSC {

Softcut::Softcut() {

  mSoftCut = std::make_unique<softcut::Softcut<numVoices>>();

  const auto sampleRate = this->mRate->mSampleRate;
  mSoftCut->setSampleRate(sampleRate);

  const auto voiceNum = 0;

  // Initial rate
  const auto rate = 1.0f;
  mSoftCut->setRate(voiceNum, rate);

  // Loop start
  const auto loopStartSeconds = 0.0f;
  mSoftCut->setLoopStart(voiceNum, loopStartSeconds);

  // Initial loop end (1 second, will be updated based on buffer size)
  const auto loopEndSeconds = 1.0f;
  mSoftCut->setLoopEnd(voiceNum, loopEndSeconds);

  // Loop flag
  const auto loopFlag = true;
  mSoftCut->setLoopFlag(voiceNum, loopFlag);

  // Fade time
  const auto fadeTimeSeconds = 0.1f;
  mSoftCut->setFadeTime(voiceNum, fadeTimeSeconds);

  // Rec level
  const auto recLevel = 1.0f;
  mSoftCut->setRecLevel(voiceNum, recLevel);

  // Pre level
  const auto preLevel = 1.0f;
  mSoftCut->setPreLevel(voiceNum, preLevel);

  // Rec flag
  const auto recFlag = true;
  mSoftCut->setRecFlag(voiceNum, recFlag);

  // Play flag
  const auto playFlag = true;
  mSoftCut->setPlayFlag(voiceNum, playFlag);

  // Set the calc function
  mCalcFunc = make_calc_function<Softcut, &Softcut::next>();

  // Initialize buffer
  const int bufferFrames =
      44100 * 10; // Default buffer size (1 second at 44.1kHz)

  mBuffer = (float *)RTAlloc(this->mWorld, bufferFrames * sizeof(float));
  memset(mBuffer, bufferFrames, 0.f);
  mSoftCut->setVoiceBuffer(voiceNum, mBuffer, bufferFrames);

  // next(1);
}

Softcut::~Softcut() { RTFree(this->mWorld, mBuffer); }

void Softcut::next(int nSamples) {
  // Audio rate input
  const float *input = in(0);

  // Control rate parameters
  const float rate = in0(1);
  const float loopStart = in0(2);
  const float loopEnd = in0(3);
  const float fadeTime = in0(4);
  const float recLevel = in0(5);
  const float preLevel = in0(6);
  const float recFlag = in0(7);
  const float playFlag = in0(8);

  const auto voiceNum = 0;

  // Update Softcut parameters
  mSoftCut->setRate(voiceNum, rate);
  mSoftCut->setLoopStart(voiceNum, loopStart);
  mSoftCut->setLoopEnd(voiceNum, loopEnd);
  mSoftCut->setFadeTime(voiceNum, fadeTime);
  mSoftCut->setRecLevel(voiceNum, recLevel);
  mSoftCut->setPreLevel(voiceNum, preLevel);
  mSoftCut->setRecFlag(voiceNum, recFlag > 0.5f);
  mSoftCut->setPlayFlag(voiceNum, playFlag > 0.5f);

  // Output buffer
  float *outbuf = out(0);

  // Process the audio block
  mSoftCut->processBlock(voiceNum, input, outbuf, nSamples);
}

} // namespace SoftcutSC

PluginLoad(SoftcutUGens) {
  // Plugin magic
  ft = inTable;
  registerUnit<SoftcutSC::Softcut>(ft, "Softcut", false);
}
