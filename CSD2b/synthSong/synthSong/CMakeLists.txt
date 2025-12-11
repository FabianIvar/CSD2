cmake_minimum_required(VERSION 3.22)
project(synthSong VERSION 0.0.1)

juce_add_console_app(synthSong PRODUCT_NAME "synthSong")
target_sources(synthSong PRIVATE main.cpp)
target_compile_definitions(synthSong PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(synthSong
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(synthSong PRIVATE cxx_std_20)
