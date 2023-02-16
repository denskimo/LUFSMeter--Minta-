#include "PluginEditor.h"

SimpleLUFSMeterAudioProcessorEditor::SimpleLUFSMeterAudioProcessorEditor (SimpleLUFSMeterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Add LUFS label to the editor
    lufsLabel.setText("0.00 LUFS", juce::NotificationType::dontSendNotification);
    lufsLabel.setFont(18.0f);
    lufsLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(lufsLabel);

    setSize (300, 100);
}

SimpleLUFSMeterAudioProcessorEditor::~SimpleLUFSMeterAudioProcessorEditor()
{
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
