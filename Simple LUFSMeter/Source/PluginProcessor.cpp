#include "PluginProcessor.h"
#include "PluginEditor.h"

SimpleLUFSMeterAudioProcessor::SimpleLUFSMeterAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input", juce::AudioChannelSet::stereo(), true)),
      integratedLoudness_(-100.0)
{
}

SimpleLUFSMeterAudioProcessor::~SimpleLUFSMeterAudioProcessor()
{
}

void SimpleLUFSMeterAudioProcessor::setCurrentProgram(int index)
{
}

int SimpleLUFSMeterAudioProcessor::getCurrentProgram()
{
    return 0;
}

const juce::String SimpleLUFSMeterAudioProcessor::getProgramName(int index)
{
    return {};
}

void SimpleLUFSMeterAudioProcessor::changeProgramName(int index, const juce::String& newName)
{
}

void SimpleLUFSMeterAudioProcessor::getStateInformation(juce::MemoryBlock& destData)
{
}

void SimpleLUFSMeterAudioProcessor::setStateInformation(const void* data, int sizeInBytes)
{
}

double SimpleLUFSMeterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

bool SimpleLUFSMeterAudioProcessor::acceptsMidi() const
{
    return false;
}

bool SimpleLUFSMeterAudioProcessor::producesMidi() const
{
    return false;
}

bool SimpleLUFSMeterAudioProcessor::isMidiEffect() const
{
    return false;
}

void SimpleLUFSMeterAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    // Set up the loudness meter using the EBU R128 standard
    ebur128_state* loudnessState = ebur128_init(buffer.getNumChannels(), sampleRate_, EBUR128_MODE_I);

    // Process the audio buffer in windows and calculate loudness for each window
    const int windowSize = 400; // Window size in milliseconds
    const int windowOverlap = 200; // Window overlap in milliseconds
    double integratedLoudness = 0.0;
    double shortTermLoudness = 0.0;
    int numWindows = 0;
    for (int i = 0; i < buffer.getNumSamples(); i += (windowSize - windowOverlap)) {
        const int windowStart = i;
        const int windowLength = juce::jmin(windowSize, buffer.getNumSamples() - windowStart);
        const float* windowBufferPtr = buffer.getReadPointer(0, windowStart);
        const double windowLoudness = ebur128_add_frames_float(loudnessState, windowBufferPtr, windowLength);

        // Add the window loudness to the integrated and short-term loudness
        integratedLoudness += windowLoudness;
        shortTermLoudness = juce::jmin(shortTermLoudness, windowLoudness);

        numWindows++;
    }

    // Calculate the integrated loudness
    integratedLoudness_ = integratedLoudness / numWindows;
    double integratedLoudnessDb;
    ebur128_loudness_global(loudnessState, &integratedLoudnessDb);
    double lufsMultiple = integratedLoudnessDb + 0.691;

    // If the short-term loudness has dropped below a threshold, output a warning to the console
    const double shortTermLoudnessThreshold = -10.0; // Loudness warning threshold (in LUFS)
    if (shortTermLoudness_ != shortTermLoudness && shortTermLoudness < shortTermLoudnessThreshold) {
        shortTermLoudness_ = shortTermLoudness;
        DBG("Short-term loudness warning: " << shortTermLoudness_ << " LUFS");
    }

    // Clean up the loudness meter state
    ebur128_destroy(&loudnessState);
}

juce::AudioProcessorEditor* SimpleLUFSMeterAudioProcessor::createEditor()
{
    return new SimpleLUFSMeterAudioProcessorEditor(*this);
}

void SimpleLUFSMeterAudioProcessor::setPlayConfigDetails (int numInputChannels, int numOutputChannels, double sampleRate, int bufferSize)
{
    AudioProcessor::setPlayConfigDetails(numInputChannels, numOutputChannels, sampleRate, bufferSize);
}

void SimpleLUFSMeterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Add your implementation here
}

void SimpleLUFSMeterAudioProcessor::releaseResources()
{
    // Add your implementation here
}

bool SimpleLUFSMeterAudioProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
{
    // Add your implementation here
    return true;
}

int SimpleLUFSMeterAudioProcessor::getNumPrograms()
{
    return 1;
}

double SimpleLUFSMeterAudioProcessor::getIntegratedLoudness() const
{
    return integratedLoudness_;
}


bool SimpleLUFSMeterAudioProcessor::hasEditor() const
{
    return true;
}

const juce::String SimpleLUFSMeterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

// This creates new instances of the plugin
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SimpleLUFSMeterAudioProcessor();
}
