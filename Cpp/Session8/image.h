#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>

/*
Create a class named image has 2D vector of uint8_t 
you can set/get an image and copy image into another image
*/

class Image
{
    public:
        Image();
        Image(const Image& image_copy);
        Image(std::vector<std::vector<std::uint8_t>> vect);
        void setImage(std::vector<std::vector<std::uint8_t>> img);
        std::vector<std::vector<std::uint8_t>> getImage();
        void showImage();
        //friend std::ostream& operator<<(std::ostream& output, const Image &complex);
    private: 
        std::vector<std::vector<std::uint8_t>> m_vect;
};

#endif