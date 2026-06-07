project(Waveshaper VERSION 0.0.1)
juce_add_console_app(Waveshaper PRODUCT_NAME "Waveshaper")

add_subdirectory(oscillators)

target_sources(Waveshaper PRIVATE
        main.cpp
        effect.cpp
        waveshaper.cpp)

target_compile_definitions(Waveshaper PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(Waveshaper
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(Waveshaper PRIVATE cxx_std_20)
