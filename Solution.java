
import java.util.Arrays;

public class Solution {

    private record Flower(int plantPeriod, int growPeriod) {}
    private int numberOfFlowers;

    public int earliestFullBloom(int[] plantTime, int[] growTime) {
        numberOfFlowers = plantTime.length;
        Flower[] flowers = new Flower[numberOfFlowers];
        initializeArrayFlowers(flowers, plantTime, growTime);
        Arrays.sort(flowers, (first, second) -> second.growPeriod - first.growPeriod);

        int minTime = flowers[0].plantPeriod + flowers[0].growPeriod;
        int sumAllPreviousPlantPeriods = 0;

        for (Flower flower : flowers) {
            minTime = Math.max(minTime, flower.plantPeriod + flower.growPeriod + sumAllPreviousPlantPeriods);
            sumAllPreviousPlantPeriods += flower.plantPeriod;
        }
        return minTime;
    }

    private void initializeArrayFlowers(Flower[] flowers, int[] plantTime, int[] growTime) {
        for (int i = 0; i < numberOfFlowers; ++i) {
            flowers[i] = new Flower(plantTime[i], growTime[i]);
        }
    }
}
