#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>


struct Solution {
    double rank , x , y ,z ;
    void fitness () {
        double ans = (6 * x + - y + std::pow(z,200)) - 25;

        rank = (ans == 0) ? 9999 :std :: abs(1/ans);
    }

};



int main() {

    //Create random solution

    std::random_device device;
    std::uniform_real_distribution<double> unif(-100,100);
    std::vector<Solution> solutions;

    const int NUM = 9000000;
    for (int i = 0 ; i < NUM ; i++) {
        solutions.push_back(Solution{0,
        unif(device),
        unif(device),
        unif(device)
        });
    }
    // Running the fitness of our solution
    //
    for (auto &s : solutions) {s.fitness();}

    //sot out solutions
     std::sort(solutions.begin(), solutions.end() ,
     [](const auto& lhs , const auto& rhs) {
         return lhs.rank > rhs.rank;
     });

    //print top solutions
    std::for_each(solutions.begin(), solutions.end()+10 , [](const auto& s) {
       std::cout << std::fixed << "Rank" << static_cast<int>(s.rank)
        << "\n x:" <<s.x << " y:" <<s.y << s.z << std::endl;
    });


    return 0;
}