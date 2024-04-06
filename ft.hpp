/*!**************************************************************************************************************************************************************************************************************************************************************
\file       ft.hpp
\par        Author:          Najih
\par        Email:           n.hajasheikallaudin
\par        Course:          RSE1202
\par        Section:         RSE
\par        Tutorial:        Lab 6
\par        File created on: 01/03/2024
\brief      Template based functions
\par        File information:
      This file is contains 13 function definition to called by main in vector-driver.
      function:
      template <typename source, typename destination > destination   copy      (source begin, source end, destination copy                 ); // copying elements from one array to another
      template <typename vector, typename element     >     int       count     (vector begin, vector end, const element &value             ); // count the occurences of a specified element found in the array
      template <typename vector                       >     void     display    (vector begin, vector end                                   ); // function to display elements in a specified array
      template <typename vector, typename vector2     >     bool      equal     (vector begin, vector end, vector2 compare                  ); // checking if the two array exactly the same
      template <typename vector, typename element     >     void      fill      (vector begin, vector end, const element &elm               ); // fill the array with the specified element
      template <typename vector, typename element     >    vector     find      (vector begin, vector end, const element &value             ); // finding the first occurrence of a specified element in the array and returing it's location 
      template <typename vector                       >    vector  max_element  (vector begin, vector end                                   ); // finding the largest element in the array
      template <typename vector                       >    vector  min_element  (vector begin, vector end                                   ); // finding the smallest element in the array
      template <typename vector,   typename element   >    vector    remove     (vector begin, vector end, const element &value             ); // function to remove a element if found in the array
      template <typename vector,   typename element   >     void     replace    (vector begin, vector end, element current, element replace ); // replacing all the occurrences of a specific element in the array with another element when found
      template <typename vector                       >    vector      sum      (vector const *begin, vector const *end                     ); //adding all of the elements in the array
      template <typename element                      >     void       swap     (element &lhs, element &rhs                                 ); // function to swap two elements
      template <typename vector_1, typename vector_2  >     void   swap_ranges  (vector_1 element1, vector_1 last, vector_2 element2        ); // function to swap elements between two arrays
*******************************************************************************************************************************************************************************************************************************************************************************************/
#ifndef FT_H
#define FT_H
#include <iostream>

namespace hlp2 {
//##########################################################################################################################################################################################################################################################################################
//==========================================================================================================================================================================================================================================================================================
//|                                                                             FUNCTION DECLARACTION SECTION                                                                                                                                                                              |
//==========================================================================================================================================================================================================================================================================================
  template <typename source, typename destination > destination   copy      (source begin, source end, destination copy                 ); // copying elements from one array to another
  template <typename vector, typename element     >     int       count     (vector begin, vector end, const element &value             ); // count the occurences of a specified element found in the array
  template <typename vector                       >     void     display    (vector begin, vector end                                   ); // function to display elements in a specified array
  template <typename vector, typename vector2     >     bool      equal     (vector begin, vector end, vector2 compare                  ); // checking if the two array exactly the same
  template <typename vector, typename element     >     void      fill      (vector begin, vector end, const element &elm               ); // fill the array with the specified element
  template <typename vector, typename element     >    vector     find      (vector begin, vector end, const element &value             ); // finding the first occurrence of a specified element in the array and returing it's location 
  template <typename vector                       >    vector  max_element  (vector begin, vector end                                   ); // finding the largest element in the array
  template <typename vector                       >    vector  min_element  (vector begin, vector end                                   ); // finding the smallest element in the array
  template <typename vector,   typename element   >    vector    remove     (vector begin, vector end, const element &value             ); // function to remove a element if found in the array
  template <typename vector,   typename element   >     void     replace    (vector begin, vector end, element current, element replace ); // replacing all the occurrences of a specific element in the array with another element when found
  template <typename vector                       >    vector      sum      (vector const *begin, vector const *end                     ); //adding all of the elements in the array
  template <typename element                      >     void       swap     (element &lhs, element &rhs                                 ); // function to swap two elements
  template <typename vector_1, typename vector_2  >     void   swap_ranges  (vector_1 element1, vector_1 last, vector_2 element2        ); // function to swap elements between two arrays
//==========================================================================================================================================================================================================================================================================================
//|                                                                              FUNCTION DEFINITION SECTION                                                                                                                                                                               |
//==========================================================================================================================================================================================================================================================================================
  template <typename vector>
  void display(vector begin, vector end) {                                                                                                  // function to display elements in a specified array
    for (auto ch = begin; ch != end; ++ch) {                                                                                                // iterating through the array
        std::cout << *ch;
        if(ch!= end-1){std::cout<< ", ";}                                                                                                   // if ch is the last element in the array don't print ", "
    }std::cout << std::endl;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename element>
  void swap(element &lhs, element &rhs) {                                                                                                   // function to swap two elements
      element temp = lhs;                                                                                                                   // temporarily storing value to be swaped 
      lhs = rhs;
      rhs = temp;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector_1, typename vector_2>
  void swap_ranges(vector_1 element1, vector_1 end, vector_2 element2) {                                                                    // function to swap elements between two arrays
    while (element1 != end) { std::swap(*element1++, *element2++); }                                                                        // contiue to swap the elements in the arrays till reaching the last element in the largest array
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
 template <typename vector, typename element>
  vector remove(vector begin, vector end, const element&value) {                                                                            // function to remove a element if found in the array
      vector result = begin;                                                                                                                // iterator to track the result array
      while (begin != end) {                                                                                                                // iterateing through the input array
        if (!(*begin == value)) {                                                                                                           // checking if the current element is not equal to the value and copying it to the result array
          *result++ = std::move(*begin);
        } ++begin;
      }
      return result;                                                                                                                        // Return the iterator pointing to the end of the result array
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector, typename element>
  int count(vector begin, vector end, const element&value) {                                                                                // count the occurences of a specified element found in the array
    int count = 0;
    while (begin != end) {                                                                                                                  // iterateing through the input array and incrementing count of element is found in thr array
      if(*begin == value){ count++; } 
      ++begin;
    }
    return count;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector, typename element>
  vector find(vector begin, vector end, const element&value) {                                                                              // finding the first occurrence of a specified element in the array and returing it's location 
    while (begin != end) {
      if (*begin == value) {
        return begin;                                                                                                                       // returning begin iterator on the first occurrence of when the element is found
      } ++begin;
    }
    return end;                                                                                                                             // returning end iterator if element is not found
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename source , typename destination>
  destination copy(source begin, source end, destination copy) {                                                                            // copying elements from one array to another
    while (begin != end) {                                                                                                                  // iterateing through the input array
      *copy = *begin;
      ++begin; ++copy;
    }
    return copy;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector, typename element> void fill(vector begin, vector end, const element &elm) { std::fill(begin, end, elm); }      // fill the array with the specified element
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector, typename element>
  void replace(vector begin, vector end, element current, element replace) {                                                                // replacing all the occurrences of a specific element in the array with another element when found
    while (begin != end) {                                                                                                                  // iterateing through the input array
      if(*begin == current){*begin = replace;}                                                                                              // when the specified element is found the element is replaced
        ++begin;
    }
  } 
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector> 
  vector min_element(vector begin, vector end) {                                                                                            // finding the smallest element in the array
    vector min = begin++;
      while (begin != end) {                                                                                                                // iterateing through the input array
        if (*begin < *min) { min = begin; }                                                                                                 // when a smaller element is found store the smaller element into min
        ++begin;
      }
    return min;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector>  
  vector max_element(vector begin, vector end) {                                                                                            // finding the largest element in the array
      vector max = begin++;
      while (begin != end) {                                                                                                                // iterateing through the input array
        if (*max < *begin) { max = begin; }                                                                                                 // when a larger element is found store the larger element into max
        ++begin;
      }
    return max;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector, typename vector2>
  bool equal(vector begin, vector end, vector2 compare) {                                                                                   // checking if the two array exactly the same
    while (begin != end) {                                                                                                                  // iterateing through the input array
      if (!(*begin == *compare)) { return false; }                                                                                          // returning false on the occurence of a mismatching array
        ++begin; ++compare;
    }
    return true;
  }
//******************************************************************************************************************************************************************************************************************************************************************************************
  template <typename vector>
  vector sum(vector const *begin, vector const *end) {                                                                                      //adding all of the elements in the array
    vector total{*begin++};
    while (begin != end) { total += *begin++; }                                                                                            // iterateing through the input array and adding all the element in the array together
    return total;
  }
//##########################################################################################################################################################################################################################################################################################
} // namespace hlp2
#endif
