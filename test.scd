(
s.waitForBoot{
    // Allocate a buffer
    b = Buffer.alloc(s, s.sampleRate * 1.0, 1); // 1 second buffer
    s.sync;

    // Define a SynthDef using the Softcut UGEN
        SynthDef(\softcut, { |out=0, in=0, gate=1, rate=1, loopStart=0, loopEnd=1, fadeTime=0.1, recLevel=1, preLevel=1, recFlag=1, playFlag=1|
            var input = SoundIn.ar(in);
            var softcut = Softcut.ar(input, rate, loopStart, loopEnd, fadeTime, recLevel, preLevel, recFlag, playFlag);
            var env = EnvGen.kr(Env.asr(0.01, 1, 0.1), gate, doneAction: 2);
            Out.ar(out, softcut * env);
        }).add;

    s.sync;

    // Create a Synth instance
    x = Synth(\softcut, [\in, 0, \rate, 1, \loopStart, 0, \loopEnd, 1, \fadeTime, 0.1, \recLevel, 1, \preLevel, 1, \recFlag, 1, \playFlag, 1]);

};
)
// Change parameters dynamically
x.set(\rate, 0.5);
x.set(\loopEnd, 0.5);
x.set(\fadeTime, 0.05);

// Free the Synth
x.free;
