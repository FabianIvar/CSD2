add_subdirectory(WaveTypes)
target_sources(${PROJECT_NAME}
    PRIVATE
    oscillator.cpp
    synth.cpp
    additive.cpp
    )
