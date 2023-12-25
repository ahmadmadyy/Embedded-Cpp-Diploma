/*
Create a class named image has 2D vector of uint8_t
you can set/get an image and copy image into another image
*/
#include "image.h"
#include <iostream>

    Image::Image() : m_vect(0)
    {

    }

    Image::Image(const Image& image_copy) : m_vect(image_copy.m_vect)
    {
        std::cout << "Copy constructor is called\n" ;
    }

    Image::Image(std::vector<std::vector<std::uint8_t>> vect) : m_vect(vect)
    {

    }

    void Image::setImage(std::vector<std::vector<std::uint8_t>> img)
    {
        this->m_vect = img;
    }

    std::vector<std::vector<std::uint8_t>> Image::getImage()
    {
        return this->m_vect;
    }
/*
    std::ostream& operator<<(std::ostream& output, const Image &complex)
    {
        output << "ostream: " << complex.real << " "<< "+ i" << complex.img << std::endl;
        return output; 
    }
*/

    void Image::showImage()
    {
        for (int i = 0; i < m_vect.size(); i++)
        {
            for (int j = 0; j < m_vect.size(); j++)
                {
                    //std::cout << m_vect[i][j] << " ";
                    printf("%d ",m_vect[i][j]);
                }    
            std::cout << std::endl;
        } 
    }