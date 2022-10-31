
#include <vector>
using namespace std;

class Solution {

    struct Flower {
        int plantPeriod{};
        int growPeriod{};
        Flower(int plantPeriod, int growPeriod): plantPeriod{plantPeriod}, growPeriod{growPeriod}{}
        Flower() = default;
    };
    size_t numberOfFlowers{};

public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        numberOfFlowers = plantTime.size();
        vector <Flower> flowers(numberOfFlowers);
        initializeVectorFlowers(flowers, plantTime, growTime);

        //Alternatively C++20: std::ranges::sort(flowers,...), done the old way for compatibility.
        sort(flowers.begin(), flowers.end(), [](const Flower& first, const Flower& second){return second.growPeriod < first.growPeriod;});

        int minTime = flowers[0].plantPeriod + flowers[0].growPeriod;
        int sumAllPreviousPlantPeriods = 0;

        for (Flower flower : flowers) {
            minTime = max(minTime, flower.plantPeriod + flower.growPeriod + sumAllPreviousPlantPeriods);
            sumAllPreviousPlantPeriods += flower.plantPeriod;
        }
        return minTime;
    }

private:
    void initializeVectorFlowers(vector <Flower>& flowers, const vector<int>& plantTime, const vector<int>& growTime) {
        for (int i = 0; i < numberOfFlowers; ++i) {
            flowers[i] = Flower(plantTime[i], growTime[i]);
        }
    }
};
