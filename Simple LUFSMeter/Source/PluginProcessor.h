#pragma once

#include <JuceHeader.h>
#include "ebur128.h"

class SimpleLUFSMeterAudioProcessor : public juce::AudioProcessor
{
public:
    SimpleLUFSMeterAudioProcessor();
    ~SimpleLUFSMeterAudioProcessor() override;

    void setCurrentProgram (int index) override;
    
    void setPlayConfigDetails (int numInputChannels, int numOutputChannels, double sampleRate, int bufferSize)
    {
        AudioProcessor::setPlayConfigDetails(numInputChannels, numOutputChannels, sampleRate, bufferSize);
    }

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index, const juce::String& newName) override;
    int getCurrentProgram() override;
    
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    const juce::String getName() const override;
    int getNumPrograms() override;

private:
    double sampleRate_;
    int samplesPerBlock_;
    double integratedLoudness_ = -INFINITY;
    double shortTermLoudness_ = -INFINITY;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleLUFSMeterAudioProcessor)
};
