/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SimpleLUFSMeterAudioProcessor.h"

//==============================================================================
/**
*/
class SimpleLUFSMeterAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                             private juce::Timer

{
public:
    SimpleLUFSMeterAudioProcessorEditor (SimpleLUFSMeterAudioProcessor&);
    ~SimpleLUFSMeterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SimpleLUFSMeterAudioProcessor& audioProcessor_;

    juce::Label loudnessLabel_;

    void timerCallback() override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SimpleLUFSMeterAudioProcessorEditor)
};
