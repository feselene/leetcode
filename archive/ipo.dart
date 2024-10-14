import 'dart:collection';

class Solution {
  int findMaximizedCapital(int k, int w, List<int> profits, List<int> capital) {
    // Pair projects with capital requirements and profits, then sort by capital
    List<List<int>> projects = List.generate(profits.length, (i) => [capital[i], profits[i]]);
    projects.sort((a, b) => a[0].compareTo(b[0])); // Sort by capital

    // Use a max heap for profits (using a List and maintaining order manually)
    List<int> maxProfitHeap = [];
    int i = 0;

    // Process up to k projects
    while (k > 0) {
      // Add all feasible projects to the maxProfitHeap
      while (i < projects.length && projects[i][0] <= w) {
        _addToHeap(maxProfitHeap, projects[i][1]);
        i++;
      }

      // If no feasible projects available, break
      if (maxProfitHeap.isEmpty) break;

      // Extract the project with the maximum profit
      w += _removeMaxFromHeap(maxProfitHeap);
      k--;
    }

    return w;
  }

  // Helper function to add to max heap
  void _addToHeap(List<int> heap, int value) {
    heap.add(value);
    int current = heap.length - 1;
    while (current > 0) {
      int parent = (current - 1) ~/ 2;
      if (heap[current] <= heap[parent]) break;
      _swap(heap, current, parent);
      current = parent;
    }
  }

  // Helper function to remove max from heap
  int _removeMaxFromHeap(List<int> heap) {
    if (heap.isEmpty) return 0;
    int maxVal = heap[0];
    heap[0] = heap.removeLast();
    int current = 0;
    while (current < heap.length) {
      int left = 2 * current + 1;
      int right = 2 * current + 2;
      int maxIndex = current;

      if (left < heap.length && heap[left] > heap[maxIndex]) maxIndex = left;
      if (right < heap.length && heap[right] > heap[maxIndex]) maxIndex = right;

      if (maxIndex == current) break;

      _swap(heap, current, maxIndex);
      current = maxIndex;
    }
    return maxVal;
  }

  // Swap function
  void _swap(List<int> heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
  }
}
