#include <iostream>
#include <string>
#include <conio.h>

class Dimensions {
private:
    double _dHeight;
    double _dWidth;
public:
    double GetHeight() { return _dHeight; }
    void SetHeight(double height) { _dHeight = height; }

    double GetWidth() { return _dWidth; }
    void SetWidth(double width) { _dWidth = width; }
};

class Tiles {
private:
    double _dTilePrice = 1.5;
    double _dTileSize = 2;
public:
    double GetTilePrice() { return _dTilePrice; }
    void SetTilePrice(double tilePrice) { _dTilePrice = tilePrice; }

    double GetTileSize() { return _dTileSize; }
    void SetTileSize(double tileSize) { _dTileSize = tileSize; }
};

class Walls {
protected:
    double _dWallHeight = 10;
    double _dWallpaperSize = 2;
    double _dWallpaperCost = 1;
    double _dWallArea;
public:
    double GetWallArea() { return _dWallArea; }
};

class Room : public Dimensions, public Tiles, public Walls {
private:
    double _dArea;
    double _dTilesRequired;
    double _dWallpaperRequired;
    double _dFloorPrice;
    double _dWallPrice;
public:
    Room();
    void CalculateArea();
    void CalculateTilesRequired();
    void CalculateFloorPrice();
    void CalculateWallPrice();

    double GetArea() { return _dArea; }
    double GetTilesRequired() { return _dTilesRequired; }
    double GetFloorPrice() { return _dFloorPrice; }

    double GetWallpaperRequired() { return _dWallpaperRequired; }
    double GetWallPrice() { return _dWallPrice; }
};

int main()
{
    Room objRoom;
    double dHeight, dWidth;

    std::cout << "Enter Height: ";
    std::cin >> dHeight;

    std::cout << "Enter width: ";
    std::cin >> dWidth;

    objRoom.SetHeight(dHeight);
    objRoom.SetWidth(dWidth);

    objRoom.CalculateArea();
    objRoom.CalculateTilesRequired();
    objRoom.CalculateFloorPrice();
    objRoom.CalculateWallPrice();

    std::cout << "\n";

    std::cout << "Floor Area: " << objRoom.GetArea() << "\n";
    std::cout << "Tiles Required: " << objRoom.GetTilesRequired() << "\n";
    std::cout << "Floor Price: " << objRoom.GetFloorPrice() << "\n";

    std::cout << "\n";

    std::cout << "Wall Area: " << objRoom.GetWallArea() << "\n";
    std::cout << "Wallpaper Required: " << objRoom.GetWallpaperRequired() << "\n";
    std::cout << "Wall Price: " << objRoom.GetWallPrice() << "\n";
}

Room::Room() {
    _dArea = 0;
    _dTilesRequired = 0;
    _dFloorPrice = 0;
    _dWallArea = 0;
    _dWallPrice = 0;
    _dWallpaperRequired = 0;
}

void Room::CalculateArea() {
    _dArea = GetWidth() * GetHeight();
}

void Room::CalculateTilesRequired() {
    _dTilesRequired = _dArea / GetTileSize();
}

void Room::CalculateFloorPrice() {
    _dFloorPrice = GetTilePrice() * _dTilesRequired;
}

void Room::CalculateWallPrice() {
    double dWallAreaWidth = _dWallHeight * GetWidth();
    double dWallAreaHeight = _dWallHeight * GetHeight();
    _dWallArea = dWallAreaHeight + dWallAreaWidth;

    _dWallpaperRequired = _dWallArea / _dWallpaperSize;

    _dWallPrice = _dWallpaperRequired * _dWallpaperCost;
}
