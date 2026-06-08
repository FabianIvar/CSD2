project(DelayFeedback VERSION 0.0.1)
juce_add_console_app(DelayFeedback PRODUCT_NAME "DelayFeedback")

add_subdirectory(effects)
add_subdirectory(oscillators)
add_subdirectory(utils)

target_sources(DelayFeedback
        PRIVATE
        main.cpp
        envelope.cpp)

target_compile_definitions(DelayFeedback PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(DelayFeedback
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(DelayFeedback PRIVATE cxx_std_20)
