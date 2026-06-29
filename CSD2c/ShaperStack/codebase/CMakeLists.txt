project(PluginFocus2 VERSION 0.0.1)
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
juce_add_plugin(PluginFocus2
        # ICON_BIG ...
        # ICON_SMALL ...
        COMPANY_NAME CSD
        # IS_SYNTH TRUE/FALSE
        # NEEDS_MIDI_INPUT TRUE/FALSE
        # NEEDS_MIDI_OUTPUT TRUE/FALSE
        # IS_MIDI_EFFECT TRUE/FALSE
        # EDITOR_WANTS_KEYBOARD_FOCUS TRUE/FALSE
        # COPY_PLUGIN_AFTER_BUILD TRUE/FALSE
        PLUGIN_MANUFACTURER_CODE Csd2
        PLUGIN_CODE Fab2
        FORMATS Standalone VST3 AU
        PRODUCT_NAME "Plugin Focus2")

add_subdirectory(effects)
add_subdirectory(utils)

target_sources(PluginFocus2
        PRIVATE
        PluginEditor.cpp
        PluginProcessor.cpp)

target_compile_definitions(PluginFocus2
        PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)



# hier gaat ie misschien fout |
#                             V

# header only files need INTERFACE
add_library(audio_header INTERFACE)
target_include_directories(audio_header INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/audiocomponent.h)





target_link_libraries(PluginFocus2
        PRIVATE
        juce::juce_audio_utils
        juce::juce_product_unlocking
        juce::juce_data_structures

        PUBLIC
        audio_header
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
#        juce::juce_recommended_warning_flags
)


if(MSVC)
    add_definitions(-DNOMINMAX)
endif()

target_compile_features(PluginFocus2 PRIVATE cxx_std_20)
