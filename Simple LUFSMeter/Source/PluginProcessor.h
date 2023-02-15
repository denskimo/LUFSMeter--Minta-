#pragma once

#pragma once

#include <JuceHeader.h>
#include "ebur128.h"

class SimpleLUFSMeterAudioProcessor : public juce::AudioProcessor
{
public:
    SimpleLUFSMeterAudioProcessor();
    ~SimpleLUFSMeterAudioProcessor() override;

    void setCurrentProgram (int index) override;
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    const juce::String getName() const override;

private:
    double sampleRate_;
    double integratedLoudness_ = -INFINITY;
    double shortTermLoudness_ = -INFINITY;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleLUFSMeterAudioProcessor)
};
