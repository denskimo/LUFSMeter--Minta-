#include "SimpleLUFSMeterAudioProcessor.h"
#include "SimpleLUFSMeterAudioProcessorEditor.h"

//==============================================================================
SimpleLUFSMeterAudioProcessorEditor::SimpleLUFSMeterAudioProcessorEditor (SimpleLUFSMeterAudioProcessor& processor)
    : juce::AudioProcessorEditor (processor), audioProcessor_(processor)
{
    setSize (200, 200);

    // Create the loudness label
    addAndMakeVisible (loudnessLabel_);
    loudnessLabel_.setFont (15.0f);
    loudnessLabel_.setJustificationType (juce::Justification::centred);
    loudnessLabel_.setText (juce::String(), juce::dontSendNotification);

    startTimerHz (50);
}

void SimpleLUFSMeterAudioProcessorEditor::timerCallback()
{
    double integratedLoudnessDb = audioProcessor_.getIntegratedLoudness();
    loudnessLabel_.setText (juce::String (integratedLoudnessDb) + " LUFS",
                            juce::dontSendNotification);
}

SimpleLUFSMeterAudioProcessorEditor::~SimpleLUFSMeterAudioProcessorEditor()
{
}

//==============================================================================
void SimpleLUFSMeterAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText (loudnessLabel_.getText(), getLocalBounds(), juce::Justification::centred, 1);
}

void SimpleLUFSMeterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
