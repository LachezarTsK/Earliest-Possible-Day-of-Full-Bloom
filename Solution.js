
/**
 * @param {number[]} plantTime
 * @param {number[]} growTime
 * @return {number}
 */
var earliestFullBloom = function (plantTime, growTime) {
    this.numberOfFlowers = plantTime.length;
    const flowers = new Array(numberOfFlowers).fill(new Flower());
    initializeArrayFlowers(flowers, plantTime, growTime);
    flowers.sort((first, second) => second.growPeriod - first.growPeriod);

    let minTime = flowers[0].plantPeriod + flowers[0].growPeriod;
    let sumAllPreviousPlantPeriods = 0;

    for (let flower of flowers) {
        minTime = Math.max(minTime, flower.plantPeriod + flower.growPeriod + sumAllPreviousPlantPeriods);
        sumAllPreviousPlantPeriods += flower.plantPeriod;
    }
    return minTime;
};

/**
 * @param {number} plantPeriod
 * @param {number} growPeriod
 */
function Flower(plantPeriod, growPeriod) {
    this.plantPeriod = plantPeriod;
    this.growPeriod = growPeriod;
}

/**
 * @param {Flower[]} flowers
 * @param {number[]} plantTime
 * @param {number[]} growTime
 * @return {void}
 */
function initializeArrayFlowers(flowers, plantTime, growTime) {
    for (let i = 0; i < this.numberOfFlowers; ++i) {
        flowers[i] = new Flower(plantTime[i], growTime[i]);
    }
}
