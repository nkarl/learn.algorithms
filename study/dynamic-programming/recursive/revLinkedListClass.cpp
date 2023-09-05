#include <vector>
#include <iostream>

//use shared pointers for auto memory stuff
template<typename T>
struct node{
    T value;
    node<T> * next;
    node<T> * previous;
    node(T const value, node<T>* const previous=nullptr,  node<T> * const next=nullptr)
     : value(value), next(next), previous(previous)
    {}
};


template<typename T>
class doubly_linked_list{
    public:
        node<T> * head = nullptr;
        node<T> * tail = nullptr;
        
        //can overload for lhs argument
        doubly_linked_list(std::vector<T> const&& list){
            if(list.size() == 0){
                return;
            }
            
            head = new node<T>(list[0]);
            node<T>* currentNode = head;
            for(std::size_t i =1; i < list.size(); ++i){
                currentNode->next = new node<T>(list[i], currentNode);
                currentNode = currentNode->next;
            }
        }
        
        ~doubly_linked_list(){
            node<T>* currentNode = head;
            while(currentNode){
                node<T>* nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }
        }
        
        void add_new_head(T const value){
            head->previous = new node<T>(value, nullptr, head);
            head = head->previous;
        }
        
};

int main(){
    using dlink_t = int;
    auto dlinkedList = doubly_linked_list<dlink_t>(std::vector<dlink_t>({1,2,3}));
    dlinkedList.add_new_head(0);
    std::cout << dlinkedList.head->value;
}
