#pragma once

#include <JuceHeader.h>
#include "ebur128.h"

class SimpleLUFSMeterAudioProcessor : public juce::AudioProcessor
{
public:
    SimpleLUFSMeterAudioProcessor();
    ~SimpleLUFSMeterAudioProcessor() override;

    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    int getNumPrograms() override;
    int getCurrentProgram() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;

    void setPlayConfigDetails (int numInputChannels, int numOutputChannels, double sampleRate, int blockSize) ;

    bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

    bool hasEditor() const override;
    juce::AudioProcessorEditor* createEditor() override;

    const juce::String getName() const override;

    bool isMidiEffect() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    double sampleRate_;
    int samplesPerBlock_;
    double integratedLoudness_ = -INFINITY;
    double shortTermLoudness_ = -INFINITY;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleLUFSMeterAudioProcessor)
};

