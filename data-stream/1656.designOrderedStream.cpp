#include "../utils.hpp"
#include <map>

using std::string; using std::map;

class OrderedStream {
public:
    vector<string> out;
    OrderedStream(int n) {
        vector<string> input(n);
        this->out = input;
    }
    
    vector<string> insert(int idKey, string value) {
        this->out[idKey] = value;
        bool null = true;
        for (int i=0; i < idKey; ++i) {
            if (this->out[i] == "") null = false;
        }
        
        vector<string> output(this->out.cbegin(), this->out.cbegin() + idKey + 1); 
        vector<string> empty;
        return (null) ? output : empty;
    }
};

/**
 * MAIN ENTRY.
 */
int main(int argc, char *argv[]) {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  myPrint(nums); // before
  /*
   * Add solution function(s) here.
   */
  myPrint(nums); // after
  return 0;
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
