class Button {
public:
    Button(int pin);
    bool isPressed();
private:
    const int debounceDelay = 100;
    int pin;
};
