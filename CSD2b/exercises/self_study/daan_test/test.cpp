int main() {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource (44100);
    JUCEModule juceModule (audioSource);
    juceModule.init(2,2); // argument is hoeveelheid input,output channels


    std::cout << "Press q + Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }


    return 0;
}
