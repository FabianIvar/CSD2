cmake_minimum_required(VERSION 3.10)
project(main)

add_subdirectory(oscillators)

add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 20)

project(main)
juce_add_console_app(main PRODUCT_NAME "main")
target_sources(main PRIVATE main.cpp)
target_compile_definitions(main PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(Filters
        PRIVATE
        csd_lib

        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(Filters PRIVATE cxx_std_20)
