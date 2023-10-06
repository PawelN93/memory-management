#include <iostream>
#include <utility>

template <typename T>
class Ruler{
    private:
        T* object;
    public:
        Ruler(T obj) : object(new T{obj}) {}
        
        Ruler(const Ruler& other){
            object = new T;
            *object = *other.object;
        }
        
        Ruler(Ruler && other){
            object = other.object;
            other.object = nullptr;
           
        }
        
        ~Ruler(){
            delete object;
        }
        
        Ruler& operator=(const Ruler& other){
            if (this != &other)
            {
                *object = *other.object;
            }
            return *this;
        }
        
        Ruler& operator=(Ruler&& other){
            if (this != &other){
                
                delete object; 
                object = other.object;
                other.object = nullptr;
            }
            return *this;
        }
        
        T getter(){
            return *object;
        }
        
        void setter(T value){
            *object = value;
        }
};

int main()
{
    Ruler<int> a{5};
    Ruler<int> b = a;
    
    b.setter(7);
    
    std::cout<<a.getter()<<std::endl;
    std::cout<<b.getter()<<std::endl;
    
    a = b;
    std::cout<<"------------------\n";
    std::cout<<a.getter()<<std::endl;
    std::cout<<b.getter()<<std::endl;
    
    a.setter(11);
    Ruler<int> c {std::move(a)};
    std::cout<<"------------------\n";
    //std::cout<<a.getter()<<std::endl;
    std::cout<<b.getter()<<std::endl;
    std::cout<<c.getter()<<std::endl;
    
    c = std::move(b);
    std::cout<<"------------------\n";
    std::cout<<c.getter()<<std::endl;

    return 0;
}
