//
//  Header.h
//  Project 5
//
//  Created by Felix Minh Thong Vu on 11/16/20.
//
#pragma once
#include <string>

//Section A
class Url {
public:
    Url(std::string url);
    
    std::string getUrl() const;
    std::string getScheme() const;
    std::string getAuthority() const;
    std::string getPath() const;

private:
    std::string _url;
    std::string _scheme;
    std::string _authority;
    std::string _path;
};

//Addition of non-member function printing URL info from Part 1
std::ostream& operator<<(std::ostream& out, const Url url);

void parseUrlInformation(const Url url);

//################################################
//Section B
class Image {
public:
    Image(std::string fileName, std::string imageType, long date, double size, std::string authorName, long width, long height, int apertureSize, std::string exposureTime, int isoValue, bool flash);
        
    std::string getFileName() const;
    std::string getImageType() const;
    long getDate() const;
    double getSize() const;
    std::string getAuthorName() const;
    long getWidth() const;
    long getHeight() const;
    int getApertureSize() const;
    std::string getExposureTime() const;
    int getIsoValue() const;
    bool getFlash() const;
    
    void setFileName(std::string file);
    void setImageType(std::string type);
    void setDate(long date);
    void setSize(double size);
    void setAuthorName(std::string author);
    void setWidth(long width);
    void setHeight(long height);
    void setAperureSize(int aperture);
    void setExposureTime(int numerator, int denominator);
    void setIsoValue(int iso);
    void setFlash(bool flash);
    
private:
    std::string _fileName;
    std::string _imageType;
    long _date;
    double _size;
    std::string _authorName;
    long _width;
    long _height;
    int _apertureSize;
    std::string _exposureTime;
    int _isoValue;
    bool _flash;
};

//Addtion of non-member function printing image metadata from Part 1
std::ostream& operator<<(std::ostream& out, const Image image);

void printImageInformation(const Image image);

//################################################
//Section C
class Item {
public:
    Item(std::string name, long id, double price, int quantity);
    
    std::string getName() const;
    long getId() const;
    double getPrice() const;
    int getQuantity() const;
    void updateItem(int number);

    
private:
    std::string _name;
    long _id;
    double _price;
    int _quantity;
};

//Addtion of non-member function printing item from Part 1
std::ostream& operator<<(std::ostream& out, const Item item);

class Order {
public:
    Order();
    
    void addItem(std::string name);
    void updateBooks(int number);
    int getTotalPrice() const;
    
    int getBooks() const;
    int getPencils() const;
    int getPapers() const;
    int getCrayons() const;
    int getMarkers() const;
    int getStaples() const;

    
private:
    Item _books;
    Item _coloredPencils;
    Item _coloringPaper;
    Item _markers;
    Item _crayons;
    Item _staples;
};

class Store {
public:
    Store();
    
    int getTotal() const;
    int getBooks() const;
    int getPencils() const;
    int getPapers() const;
    int getMarkers() const;
    int getCrayons() const;
    int getStaples() const;
    bool processOrder (const Order& order);
    
private:
    Item _books;
    Item _coloredPencils;
    Item _coloringPaper;
    Item _markers;
    Item _crayons;
    Item _staples;
};

//Addtion of non-member function printing store from Part 1
std::ostream& operator<<(std::ostream& out, const Store store);




