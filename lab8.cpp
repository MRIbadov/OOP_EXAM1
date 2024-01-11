#include <iostream>
#include <cassert>
#include <stdexcept>
static int count =0;


class Box{
protected:
    double length;
    double width;
    double height;

    std::string content;

public:

class Empty_Eror : public std::logic_error {
public:
    Empty_Eror(): std::logic_error("The box is empty"){};
};
class CapacityEror : public std::logic_error {
public:
  CapacityEror(): std::logic_error("the box is empty"){};
};

Box(double _len, double _wid, double _hei, std::string _cont);
double getCapacity() const;
void setContent(std::string value, double volume);
std::string getContent() const;
bool isEmpty() const;
static int allCount();
 friend std::ostream& operator<<(std::ostream &os,const Box &v1);

~Box() {count--;}
};


Box::Box(double _len, double _wid, double _hei, std::string _cont="") :
length(_len),width(_wid), height(_hei), content(std::move(_cont))  { count++;};

double Box::getCapacity() const {
  return length * width * height;
}
void Box::setContent(std::string value, double volume) {
    if(volume > getCapacity())
        throw Box::CapacityEror();
    content = std::move(value);
}

std::string Box::getContent() const {
    if(content.empty())
        throw Box::Empty_Eror();
    return content;
}
bool Box::isEmpty() const {
    return content == "";
}
 int Box::allCount() {
    return count;
}
std::ostream& operator<<(std::ostream &os,const Box&v1) {
    os<<"Length: "<<v1.length<<" width: " << v1.width << " height: " << v1.height
    <<" Content is: "<<v1.content<<"\n";
    return os;
}
class ColouredBox: public Box{
    std::string color_of_box;

public:

    ColouredBox( std::string color_box, double __length, double width, double _height, std::string _content=""):
    color_of_box(color_box),
    Box(__length,width,_height, _content){};

    std::string getColor() const;
    void setColor(std::string _color);
   friend std::ostream&  operator<<(std::ostream &os, const ColouredBox &v1);
};

std::string ColouredBox::getColor() const {
    return color_of_box;
}
void ColouredBox::setColor(std::string _color) {
    this->color_of_box = std::move(_color);
}

std::ostream& operator<<(std::ostream &os, const ColouredBox &v1){
    os<<"Length: "<<v1.length<<" width: " << v1.width << " height: " << v1.height
      <<" Content is: "<<v1.content<<"\n"<<" color of box " << v1.color_of_box<<"\n";

    return os;
}

int main()
{
    Box v1(12, 21, 31, "okat");
    assert(v1.allCount() == 1);
    assert(v1.isEmpty() == false);
    assert(v1.getContent() == "okat");
    return 0;
}