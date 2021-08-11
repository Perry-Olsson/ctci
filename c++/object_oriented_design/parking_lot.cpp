//Necessary Object ---- Single ParkingLot, Spot

class Spot {
  bool handicapped;
  bool occupied;
  public:
    Spot(bool h = false, bool o = false): handicapped(h), occupied(o) {}
    void setOccupied() {
      occupied = true;
    }
    
    void setVacant() {
      occupied = false;
    }
};

class ParkingLot {
  int const _size = 100;
  int _openSpots = 100;
  Spot spots[100];
  public:
    int size() {
      return _size;
    }

    int openSpots() {
      return _openSpots;
    }
    ParkingLot() {
      for (int i = 0; i < _size; i++) {
        spots[i] = new Spot();
      }
    }

};

int main()
{
  return 0;
}