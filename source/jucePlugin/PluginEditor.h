#pragma once

#include "PluginProcessor.h"

//==============================================================================
class AudioPluginAudioProcessorEditor : public juce::AudioProcessorEditor, private juce::Timer
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
	void timerCallback() override;
	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	AudioPluginAudioProcessor& processorRef;

	juce::GenericAudioProcessorEditor m_tempEditor;

	juce::TextButton m_partSelectors[16];

	juce::TextButton m_btSingleMode;
	juce::TextButton m_btMultiMode;
	
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
