#include "Fetcher.h"

Fetcher::Fetcher(): motorZ(6, 7, 20) { // Initialising pins for Z in arduino
    
}

const int Fetcher::getStepsToFetch()
{
    return this->stepsToFetch; 
}

void Fetcher::fetch(int direction) {
    motorZ.step(direction * motorZ.getstepsPerRevolutionZ());
}
