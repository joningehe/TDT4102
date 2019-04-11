#include "std_lib_facilities.h"

int main(){
    /*
    try{
        int x1 = narrow_cast<int>(2.9);
    }
    catch(runtime_error &e){
        error(e.what());
    }
    */
    try{
        int x2 {narrow_cast<int>(2.9)};
    }
    catch(runtime_error){
        std::cout << ":D" << endl;
    }
    catch(...){
        std::cout << "Error" << endl;
    }
    
    return 0;
}
