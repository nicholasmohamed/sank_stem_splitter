/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Sank_stem_splitterAudioProcessorEditor::Sank_stem_splitterAudioProcessorEditor (Sank_stem_splitterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

    openButton.setButtonText("Open...");
    openButton.onClick = [&p]{ p.openButtonClicked(); };
}

Sank_stem_splitterAudioProcessorEditor::~Sank_stem_splitterAudioProcessorEditor()
{
}

//==============================================================================
void Sank_stem_splitterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("Hello World!", getLocalBounds(), juce::Justification::centred, 1);

    addAndMakeVisible(openButton);
}

void Sank_stem_splitterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    openButton.setBounds(getWidth() / 2 - 50, getHeight() / 2 - 25, 100, 50);
}
