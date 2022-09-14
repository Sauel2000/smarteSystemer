class Button {
public:
    Button(int pin);
    bool isPressed();
private:
    const int debounceDelay = 50;
    int pin;
};
