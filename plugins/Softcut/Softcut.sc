Softcut : UGen {
    *ar { |input, rate=1, loopStart=0, loopEnd=1, fadeTime=0.1, recLevel=1, preLevel=1, recFlag=1, playFlag=1|
        // Ensure all inputs are audio rate or control rate
        // input = input.asAudioRateInput;
        // rate = rate.asAudioRateInput;
        // loopStart = loopStart.asAudioRateInput;
        // loopEnd = loopEnd.asAudioRateInput;
        // fadeTime = fadeTime.asAudioRateInput;
        // recLevel = recLevel.asAudioRateInput;
        // preLevel = preLevel.asAudioRateInput;
        // recFlag = recFlag.asAudioRateInput;
        // playFlag = playFlag.asAudioRateInput;

        // Call the multiNew method to create the UGen instance
        ^this.multiNew('audio', input, rate, loopStart, loopEnd, fadeTime, recLevel, preLevel, recFlag, playFlag);
    }

    checkInputs {
        // // Ensure all inputs are valid
        // if (inputs.at(0).rate != 'audio') {
        //     ^("Input must be audio rate: " + inputs.at(0) + " is not audio rate.");
        // };
        // if (inputs.at(1).rate != 'audio' && inputs.at(1).rate != 'control') {
        //     ^("Rate must be audio or control rate: " + inputs.at(1) + " is not valid.");
        // };
        // if (inputs.at(2).rate != 'audio' && inputs.at(2).rate != 'control') {
        //     ^("Loop start must be audio or control rate: " + inputs.at(2) + " is not valid.");
        // };
        // if (inputs.at(3).rate != 'audio' && inputs.at(3).rate != 'control') {
        //     ^("Loop end must be audio or control rate: " + inputs.at(3) + " is not valid.");
        // };
        // if (inputs.at(4).rate != 'audio' && inputs.at(4).rate != 'control') {
        //     ^("Fade time must be audio or control rate: " + inputs.at(4) + " is not valid.");
        // };
        // if (inputs.at(5).rate != 'audio' && inputs.at(5).rate != 'control') {
        //     ^("Rec level must be audio or control rate: " + inputs.at(5) + " is not valid.");
        // };
        // if (inputs.at(6).rate != 'audio' && inputs.at(6).rate != 'control') {
        //     ^("Pre level must be audio or control rate: " + inputs.at(6) + " is not valid.");
        // };
        // if (inputs.at(7).rate != 'audio' && inputs.at(7).rate != 'control') {
        //     ^("Rec flag must be audio or control rate: " + inputs.at(7) + " is not valid.");
        // };
        // if (inputs.at(8).rate != 'audio' && inputs.at(8).rate != 'control') {
        //     ^("Play flag must be audio or control rate: " + inputs.at(8) + " is not valid.");
        // };

        ^this.checkValidInputs;
    }
}
