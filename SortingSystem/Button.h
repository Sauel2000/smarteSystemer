class Button {
public:
    /**
     * @brief Construct a new Button object
     * 
     * @param pin The pin the button is connected to.
     */
    Button(int pin);

    /**
     * @brief Check if the button is pressed.
     * 
     * @return bool 
     */
    bool isPressed();
private:
    const int debounceDelay = 100; // Amount of time in ms to wait for debouncing.
    int pin; // The pin the button is connected to.
};
