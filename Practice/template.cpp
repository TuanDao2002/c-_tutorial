#include <iostream>
template <class X> 
void increase(X &data) {
    data += 1;
}

// first way to override the template function above (apply to functions with or without data type argument)
template <> void increase<std::string>(std::string &data) {
    data += "_new";
}

//second way to override the template funcion above (only apply when no data type argument is specified when calling the function)
void increase(double &data) {
    data += 100;
}

int main(){
    int x = 1;
    double y = 2.0;
    std::string test = "hello";


    increase<double>(y); // there is data type argument specified so only the main version can be called
    std::cout << "Call increase<double>(y): " << y << std::endl;

    increase(y); // no data argument here so the version to increase 100 will be called
    std::cout << "Call increase(y): " << y << std::endl;

    increase(x); // no data argument also but it is type int so only the main version can be called
    std::cout << "Call increase(x): " << x << std::endl;

    increase<int>(x); // data argument specified so the main version is called
    std::cout << "Call increase<int>(x): " << x << std::endl;

    increase(test); // the variable is string type so the string version will be called
    std::cout << "Call increase(test): " << test << std::endl;

    increase<std::string>(test); // data argument specified but string version is overriden with template <> so the string version is still called here
    std::cout << "Call increase<std::string>(test): " << test << std::endl;
    return 0;
}