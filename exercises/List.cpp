#include <iostream>
#include <memory>

using namespace std;

class EmptyListError : public std::runtime_error{
    public:
    EmptyListError(const std::string &msg) : std::runtime_error(msg) {}
};

class Node
{
public:
    Node(const int v) :
        next(nullptr),
        value(v)
    {}
    // ~Node(){
    //     delete next;
    // }

    std::shared_ptr<Node> next;
    int value;
};

class List
{
public:
    List();
    // ~List();
    void add(std::shared_ptr<Node> node);
    std::shared_ptr<Node> get(const int value);
    // void delete_list();

private:
    std::shared_ptr<Node> first;
};

List::List() :
    first(nullptr)
{}

// List::~List(){
//     delete first;
// }

void List::add(std::shared_ptr<Node> node)
{
    if(!first)
    {
        first = node;
    }
    else
    {
        std::shared_ptr<Node> current = first;
        while(current->next)
        {
            current = current->next;
        }

        if (node->next != nullptr || current == node)
        {
            current->next = std::make_shared<Node>(node->value);
        }
        else
        {
            current->next = node;
        }
        
    }
}

std::shared_ptr<Node> List::get(const int value)
{
    if(!first)
    {
        throw EmptyListError{"Pusta lista!"};
    }
    else
    {
        std::shared_ptr<Node> current = first;
        do
        {
            if(current->value == value)
            {
                cout << "Found value " << current->value << endl;
                return current;
            }
            else
            {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while(current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

// void List::delete_list(){
    
//     Node *current = first;

//     while (current){
//         Node *temp = current->next;
//         delete current;
//         current = temp;
//     }
// }

int main()
{
    List lista;
    std::shared_ptr<Node> node4 = std::make_shared<Node>(Node(4));
    std::shared_ptr<Node> node7 = std::make_shared<Node>(Node(7));

    // lista.add(node4);
    // lista.add(std::make_shared<Node>(Node(2)));
    // lista.add(node7);
    // lista.add(node7);
    // lista.add(node4);
    // lista.add(node7);
    // lista.add(node4);
    // lista.add(std::make_shared<Node>(Node(9)));

    try{
        auto node = lista.get(1);

        if(node){
        cout << node->value << '\n';
        }
    }
    catch(EmptyListError const &e){
        std::cout << e.what() << std::endl;
    }

    // lista.delete_list();
    return 0;
}

