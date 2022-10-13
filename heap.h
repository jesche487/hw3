#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapVector;
  int m;
  PComparator c;

};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m(m), c(c) {}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap() {

}

//heap push function, adds element to end of vector and trickles up to fix the heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item) {
  heapVector.push_back(item);
  if(heapVector.size() == 1) return;

  int size = heapVector.size();
  int insert_index = size - 1;
  int parent_index = (insert_index - 1)/m;

  //compares the parent and child elements, if the comparator returns true,
  //parent and child are swapped and their indexes are updated accordingly
  while(insert_index > 0) {
    if(c(heapVector[insert_index], heapVector[parent_index])) {
      std::swap(heapVector[insert_index], heapVector[parent_index]);
      insert_index = parent_index;
      parent_index = (insert_index - 1)/m;
    }
    else break;
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapVector.front();
}


// We will start pop() for you to handle the case of 
// calling pop on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
  
  //edge case where vector has only one element
  if(heapVector.size() == 1) {
    heapVector.pop_back();
    return;
  }

  //swaps the last element and first element to start the trickledown
  std::swap(heapVector[heapVector.size()-1], heapVector[0]);
  heapVector.pop_back();

  int parent_index = 0;
  //if comparator returns true for the parent and any of its chidlren,
  //it will swap them and continue checking with the next set of children,
  //until the comparator no longer returns true
  while(true) {
    int min_index = parent_index;
    for(int i = parent_index*m + 1; i <= std::min(parent_index*m + m, (int)heapVector.size()-1); i++) {
      if(c(heapVector[i], heapVector[min_index])) min_index = i;
    }

    if(parent_index == min_index) {
      break;
    }

    std::swap(heapVector[parent_index], heapVector[min_index]);

    parent_index = min_index;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heapVector.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heapVector.size();
}


#endif

