#include <vector>
#include <iostream> 
#include <algorithm> 
#include <functional> 

class Graphics
{
    public:
        virtual void draw() const = 0; 
        virtual void add(Graphics* graphics) {}
        virtual void remove(Graphics* graphics) {}
        virtual ~Graphics() {}
};

class Line : public Graphics
{
    public:
        void draw() const override
        {
            std::cout << "Draw Line " << std::endl;
        }
};

class Rectangle : public Graphics
{
    public:
        void draw() const override
        {
            std::cout << "Draw Rectangle " << std::endl;
        }
};

class Text : public Graphics
{
    public:
        void draw() const override
        {
            std::cout << "Draw Text " << std::endl;
        }
};

class Picture : public Graphics
{
    public:
        void draw() const override
        {
           std::for_each(gList.begin(),gList.end(),std::mem_fn(&Graphics::draw));
        }

        void add(Graphics* aGraphic)
        {
            gList.push_back(aGraphic);
        }

        void remove(Graphics* aGraphic)
        {
            gList.erase(std::remove(gList.begin(),gList.end(),aGraphic));
        }

    private:
        std::vector<Graphics*> gList; //composition as Picture class fully 
                            // controls the lifecycle of the Graphics objects it contains.

};

int main()
{
    Line line;
    Rectangle rectangle;
    Text text;
    Picture pic;

    pic.add(&line);
    pic.add(&rectangle);
    pic.add(&text);
    pic.add(&rectangle);
    pic.draw();
    printf("\n");
    pic.remove(&rectangle);
    pic.draw();

}