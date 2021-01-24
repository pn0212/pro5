//
//  Source.cpp
//  Project 5
//
//  Created by Felix Minh Thong Vu on 11/16/20.
//

#include <stdio.h>
#include "Header.h"
#include <iostream>
#include <string.h>

Url::Url(std::string url)
    : _url{ url } {
        size_t colon_pos = url.find_first_of(":");
        std::string scheme = url.substr(0,colon_pos);

        std::string s_new = url.substr(colon_pos + 3);

        size_t two_forward_slash_pos = url.find_first_of("//");
        size_t forward_slash_pos = s_new.find_first_of("/");
        std::string authority = url.substr(two_forward_slash_pos + 2,forward_slash_pos);

        std::string path = s_new.substr(forward_slash_pos);

        _scheme = scheme;
        _authority = authority;
        _path = path;
    }

std::string Url::getUrl() const
{
    return _url;
}

std::string Url::getScheme() const
{
    return _scheme;
}

std::string Url::getAuthority() const
{
    return _authority;
}

std::string Url::getPath() const
{
    return _path;
}

//Addition of non-member function from Part 1
std::ostream& operator<<(std::ostream& out, const Url url)
{
    out << "URL: " << url.getUrl() << "\n"
        << "\tSCHEME: " << url.getScheme() << "\n"
        << "\tAUTHORITY: " << url.getAuthority() << "\n"
        << "\tPATH: " << url.getPath() << "\n";
    return out;
}

void parseUrlInformation(const Url url)
{
    std::cout << "URL = " << url.getUrl() << "\n"
        << "scheme = " << url.getScheme() << "\n"
        << "authority = " << url.getAuthority() << "\n"
        << "path = " << url.getPath() << "\n";
}

//################################################
//Section B
Image::Image(std::string fileName,std::string imageType, long date, double size, std::string authorName, long width, long height, int apertureSize, std::string exposureTime, int isoValue, bool flash)
    : _fileName{ fileName }, _imageType{ imageType }, _date{ date }, _size{ size}, _authorName{ authorName }, _width{ width }, _height{ height }, _apertureSize{ apertureSize }, _exposureTime{ exposureTime }, _isoValue{ isoValue }, _flash{ flash } {}

std::string Image::getFileName() const {
    return _fileName;
}

std::string Image::getImageType() const {
    return _imageType;
}

long Image::getDate() const {
    return _date;
}

double Image::getSize() const {
    return _size;
}

std::string Image::getAuthorName()  const{
    return _authorName;
}

long Image::getWidth() const {
    return _width;
}

long Image::getHeight() const {
    return _height;
}

int Image::getApertureSize() const {
    return _apertureSize;
}

std::string Image::getExposureTime() const {
    return _exposureTime;
}

int Image::getIsoValue() const {
    return _isoValue;
}

bool Image::getFlash() const {
    return _flash;
}

void Image::setFileName(std::string file)
{
    _fileName = file;
}

void Image::setImageType(std::string type)
{
    if (type == "PNG" || type == "GIF" || type == "JPEG"){
        _imageType = type;
    }
    else {
        _imageType = "Invalid type";
    }
}

void Image::setDate(long date){
    _date = date;
}

void Image::setSize(double size){
    _size = size;
}

void Image::setAuthorName(std::string author){
    _authorName = author;
}

void Image::setWidth(long width){
    _width = width;
}

void Image::setHeight(long height){
    _height = height;
}

void Image::setAperureSize(int aperture){
    _apertureSize = aperture;
}

std::ostream& operator<<(std::ostream& out, const Image image)
{
    out << "File name = " << image.getFileName() << "\n"
        << "Image type = " << image.getImageType() << "\n"
        << "Date = " << image.getDate() << "\n"
        << "Size = " << image.getSize() << " MB\n"
        << "Author name = " << image.getAuthorName() << "\n"
        << "Dimension = " << image.getWidth() << " width " << image.getHeight() << " height\n"
        << "Aperture size = f/" << image.getApertureSize() << "\n"
        << "Exposure time = " << image.getExposureTime() << "\n"
        << "ISO value = " << image.getIsoValue() << "\n"
        << "Flash enabled = " << image.getFlash() << "\n";
    return out;
}

//################################################
//Section C
Item::Item(std::string name, long id, double price, int quantity):
    _name{ name },
    _id{ id },
    _price{ price },
    _quantity{ quantity }{}

std::string Item::getName() const {
    return _name;
}

long Item::getId() const {
    return _id;
}

double Item::getPrice() const {
    return _price;
}

int Item::getQuantity() const {
    return _quantity;
}

//Addtion of non-member function printing item from Part 1
std::ostream& operator<<(std::ostream& out, const Item item){
    out << "Name: " << item.getName() << "\n"
    << "ID: " << item.getId() << "\n"
    << "Price: " << item.getPrice() << "\n"
    << "Quantity: " << item.getQuantity() << "\n";
    return out;
}

Store::Store(): _books{ "books", 700000, 25, 12},
    _coloredPencils{ "colored pencils", 600000, 15, 15},
    _coloringPaper{"coloring papers", 500000, 20, 20},
    _markers{ "markers", 400000, 2, 50},
    _crayons{ "crayons", 300000, 2, 3},
    _staples{"staples", 200000, 1, 7}{}

int Store::getBooks() const {
    return _books.getQuantity();
}

int Store::getPencils() const {
    return _coloredPencils.getQuantity();
}

int Store::getPapers() const {
    return _coloringPaper.getQuantity();
}

int Store::getCrayons() const {
    return _crayons.getQuantity();
}

int Store::getMarkers() const {
    return _markers.getQuantity();
}

int Store::getStaples() const {
    return _staples.getQuantity();
}

int Store::getTotal() const {
    return _books.getQuantity() + _coloredPencils.getQuantity()
    + _coloringPaper.getQuantity() + _crayons.getQuantity()
    + _markers.getQuantity() + _staples.getQuantity();
}

//Addtion of non-member function printing store from Part 1
std::ostream& operator<<(std::ostream& out, const Store store) {
    out << "Store:\n" << "Books x " << store.getBooks() << "\n"
        << "Colored Pencils x " << store.getPencils() << "\n"
        << "Coloring Paper x " << store.getPapers() << "\n"
        << "Crayons x " << store.getCrayons() << "\n"
        << "Markers x " << store.getMarkers() << "\n"
        << "Staples x " << store.getStaples() << "\n";
    return out;
}

//Return true if order is processed, false if it is otherwise
bool Store::processOrder(const Order& order){
    //Check Quantity, do not update order if quantity is not enough
    int currentBooks = _books.getQuantity() - order.getBooks();
    if (currentBooks < 0){
        std::cout << "Not enough quantity\n";
        return 0;
    }

    int currentPencils = _coloredPencils.getQuantity() - order.getPencils();
    if (currentPencils < 0){
        std::cout << "Not enough quantity\n";
        return 0;
    }

    int currentPapers = _coloringPaper.getQuantity() - order.getPapers();
    if (currentPapers < 0){
        std::cout << "Not enough quantity\n";
        return 0;
    }

    int currentCrayons = _crayons.getQuantity() - order.getCrayons();
    if (currentCrayons < 0){
        std::cout << "Not enough quantity\n";
        return 0;
    }

    int currentMarkers = _markers.getQuantity() - order.getMarkers();
    if (currentMarkers < 0){
        std::cout << "Not enough quantity\n";
        return 0;
    }

    int currentStaples = _staples.getQuantity() - order.getStaples();
    if (currentStaples < 0){
        std::cout << "Not enough quantity\n";
        return 0;
    }

    //Update Order
    _books.updateItem(currentBooks);
    _coloredPencils.updateItem(currentPencils);
    _coloringPaper.updateItem(currentPapers);
    _crayons.updateItem(currentCrayons);
    _markers.updateItem(currentMarkers);
    _staples.updateItem(currentStaples);
    return 1;
}

//Example of Order with 1 for each item
Order::Order(): _books{ "books", 700000, 25, 1},
    _coloredPencils{ "colored pencils", 600000, 15, 1},
    _coloringPaper{"coloring papers", 500000, 20, 1},
    _markers{ "markers", 400000, 2, 1},
    _crayons{ "crayons", 300000, 2, 1},
    _staples{"staples", 200000, 1, 1}{}

int Order::getBooks() const {
    return _books.getQuantity();
}

int Order::getPencils() const {
    return _coloredPencils.getQuantity();
}

int Order::getPapers() const {
    return _coloringPaper.getQuantity();
}

int Order::getCrayons() const {
    return _crayons.getQuantity();
}

int Order::getMarkers() const {
    return _markers.getQuantity();
}

int Order::getStaples() const {
    return _staples.getQuantity();
}

void Order::addItem(std::string name){
    if (name == _books.getName()){
        int totalBooks = _books.getQuantity() + 1;
        _books.updateItem(totalBooks);
    }
    if (name == _coloredPencils.getName()){
        int totalPencils = _coloredPencils.getQuantity() + 1;
        _coloredPencils.updateItem(totalPencils);
    }
    if (name == _coloringPaper.getName()){
        int totalPaper = _coloringPaper.getQuantity() + 1;
        _coloringPaper.updateItem(totalPaper);
    }
    if (name == _crayons.getName()){
        int totalCrayons = _crayons.getQuantity() + 1;
        _crayons.updateItem(totalCrayons);
    }
    if (name == _markers.getName()){
        int totalMarkers = _markers.getQuantity() + 1;
        _markers.updateItem(totalMarkers);
    }
    if (name == _staples.getName()){
        int totalStaples = _staples.getQuantity() + 1;
        _staples.updateItem(totalStaples);
    }
}

void Item::updateItem(int number){
    _quantity = number;
}

int Order::getTotalPrice() const {
    return _books.getPrice() * _books.getQuantity()
    + _coloredPencils.getPrice() * _coloredPencils.getQuantity()
    + _coloringPaper.getPrice() * _coloringPaper.getQuantity()
    + _crayons.getPrice() * _crayons.getQuantity()
    + _markers.getPrice() * _markers.getQuantity()
    + _staples.getPrice() * _staples.getQuantity();
}
