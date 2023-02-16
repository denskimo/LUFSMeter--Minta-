#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class SimpleLUFSMeterAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    SimpleLUFSMeterAudioProcessorEditor (SimpleLUFSMeterAudioProcessor&);
    ~SimpleLUFSMeterAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SimpleLUFSMeterAudioProcessor& audioProcessor;
    juce::Label lufsLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleLUFSMeterAudioProcessorEditor)
};

