struct Coord {
  int x;
  int y;
};

class LinearRailSystem {
  public:
    // The current position of the linear rail system.
    Coord coord_at;

    LinearRailSystem(Coord coord_initial) {
      this.coord_at = new Coord(0, 0);
    };

    // Move to another position.
    MoveTo(Coord coord_move_to) {
      // Enable motors to move to position.
      this.coord_at.x = coord_move_to -> x;
      this.coord_at.y = coord_move_to -> y; 
    };
  private:
    
};

void setup() {
  // put your setup code here, to run once:
  LinearRailSystem linearRailSystem = new LinearRailSystem(new Coord(0, 0));
};

void loop() {
  // put your main code here, to run repeatedly:

};
