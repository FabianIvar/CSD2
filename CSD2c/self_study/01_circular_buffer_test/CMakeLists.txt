project(circBuffer_test VERSION 0.0.1)

juce_add_console_app(circBuffer_test PRODUCT_NAME "circBuffer_test")

target_sources(circBuffer_test PRIVATE
  main.cpp
  circBuffer.cpp
  writeToFile.cpp)

add_subdirectory(oscillators)

target_compile_definitions(circBuffer_test PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0 SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(circBuffer_test PUBLIC juce::juce_recommended_config_flags)

target_compile_features(circBuffer_test PRIVATE cxx_std_20)
