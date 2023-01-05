public class RainWater {
    // This class solves the Capturing Rainwater problem using pointers

    public int efficientSolution(int[]heights) {
        int totalWater = 0;
        int leftPointer = 0;
        int rightPointer = heights.length - 1;
        int leftBound = 0;
        int rightBound = 0;
        // Fill in the rest of this method with your solution
        while (leftPointer < rightPointer) {
            if (heights[leftPointer] <= heights[rightPointer]) {
                leftBound = Math.max(leftBound, heights[leftPointer]);
                totalWater += leftBound - heights[leftPointer];
                leftPointer++;
            } else {
                rightBound = Math.max(rightBound, heights[rightPointer]);
                totalWater += rightBound - heights[rightPointer];
                rightPointer--;
            }
        }

        return totalWater;
    }

    public static void main(String[]args) {
        // heights: the array representing the histogram
        int [] heights = new int[]{4, 2, 1, 3, 0, 1, 2};
        RainWater rainWater = new RainWater();
        System.out.println("Amount of water captured: " + rainWater.efficientSolution(heights));
    }
}
