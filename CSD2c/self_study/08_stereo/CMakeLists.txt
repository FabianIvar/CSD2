project(circBuff_test2 VERSION 0.0.1)

juce_add_console_app(circBuff_test2 PRODUCT_NAME "circBuff_test2")

target_sources(circBuff_test2 PRIVATE
  main.cpp
  circBuffer.cpp)

add_subdirectory(oscillators)
add_subdirectory(utils)

target_compile_definitions(circBuff_test2 PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(circBuff_test2 PUBLIC juce::juce_recommended_config_flags)

target_compile_features(circBuff_test2 PRIVATE cxx_std_20)
