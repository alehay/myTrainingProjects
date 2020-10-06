cyclic shift of an array



#include <bits/stdc++.h>

std::vector<int> circularArrayRotation(std::vector<int> a, int k) {
	// 1234567
    std::reverse (std::begin (a), std::begin(a)+k);
	// 3214567
    std::reverse (std::begin(a) + k , std::end(a));
        //3217654
    std::reverse (std::begin(a), std::end(a));
	//4567123        
    return a;
}

//сдвиг в обратную сторону.
std::vector<int> circularArrayRotationRIGHT(std::vector<int> a, int k) {
    circularArrayRotation(a, a.size() - k);
}

int main () {
   
    std::vector<int> num  {1, 2, 3, 4, 5, 6 , 7 };
    
    std::vector<int> my_vector = circularArrayRotation (num, 3);

    for (int i =  0 ; i < my_vector.size() ; i++) {
        std::cout << my_vector.at(i) << " ";
    }
      for (int i =  0 ; i <10 ; i++) {
        std::cout << "+++++++++++++++++" ;
    }



    return 0;
}
/*




*/
