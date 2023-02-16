#include "PluginEditor.h"

SimpleLUFSMeterAudioProcessorEditor::SimpleLUFSMeterAudioProcessorEditor(SimpleLUFSMeterAudioProcessor& processor)
    : AudioProcessorEditor(processor), processor_(processor)
{
    setSize(200, 200);
    addAndMakeVisible(loudnessLabel_);
    loudnessLabel_.setText(juce::String(processor_.getIntegratedLoudness()) + " LUFS", juce::dontSendNotification);
    startTimerHz(50);
}

SimpleLUFSMeterAudioProcessorEditor::~SimpleLUFSMeterAudioProcessorEditor()
{
}

void SimpleLUFSMeterAudioProcessorEditor::timerCallback()
{
    loudnessLabel_.setText(juce::String(processor_.getIntegratedLoudness()) + " LUFS", juce::dontSendNotification);
}

void SimpleLUFSMeterAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);

    // Set the text of the LUFS label to the current integrated loudness
    double lufs = audioProcessor.getIntegratedLoudness();
    lufsLabel.setText(juce::String(lufs, 2) + " LUFS", juce::NotificationType::dontSendNotification);
}


void SimpleLUFSMeterAudioProcessorEditor::resized()
{
    // Position the LUFS label in the center of the editor
    juce::Rectangle<int> area = getLocalBounds();
    lufsLabel.setBounds(area);
}
