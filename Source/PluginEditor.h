/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Sank_stem_splitterAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    Sank_stem_splitterAudioProcessorEditor (Sank_stem_splitterAudioProcessor&);
    ~Sank_stem_splitterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Sank_stem_splitterAudioProcessor& audioProcessor;

    juce::TextButton openButton{ "Open.." };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Sank_stem_splitterAudioProcessorEditor)
};
