#ifndef SEQUENCE_CONTAINER
#define SEQUENCE_CONTAINER

#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <bitset>
#include <valarray>
#include <stack>
#include <queue>

template <typename T, typename V>  //T will need to support <
class sequence_container
{
  enum CONTAINER_TYPE
  {
    VECTOR = 0,
    STRING,
    DEQUE,
    LIST,
    SLIST,
    ARRAY,
    BITSET,
    VALARRAY,
    STACK,
    QUEUE,
    PRIORITY_QUEUE
  };
  CONTAINER_TYPE type;

  V internal_data;

  template<T, V>
  class data_structure
  {

  };

  bool stl;
  bool standard;
  sequence_container(); //Default will use vector
  sequence_container(CONTAINER_TYPE type);
  ~sequence_container();
  void add(T data);
  void add(int position, T data);
};

template <typename T>  //T will need to support <
class sequence_container<T, std::vector<T> >
{
  std::vector<T> internal_data;

  template<T, std::vector<T> >
  class data_structure
  {

  };
};

template <>
class sequence_container<char, std::string>
{
  std::string<char> internal_data;

  template<char, std::string<char> >
  class data_structure
  {

  };
};

template <typename T>  //T will need to support <
class sequence_container<T, std::deque<T> >
{
  std::deque<T> internal_data;

  template<T, std::deque<T> >
  class data_structure
  {

  };
};

template <typename T>  //T will need to support <
class sequence_container<T, std::list<T> >
{
  std::list<T> internal_data;

  template<T, std::list<T> >
  class data_structure
  {

  };
};

template <typename T>  //T will need to support <
class sequence_container<T, std::forward_list<T> >
{
  std::forward_list<T> internal_data;

  template<T, std::forward_list<T> >
  class data_structure
  {

  };
};


  //Want to generalize the sequence containers so a few options
  //1. Just provide a wrapper to each method if the datastructure is
  //   supported. Otherwise return null, -1 or throw an exception but
  //   don't do it quietly. Going to do this for now.
  //2. Decide what if the operation has meaning for the data structure
  //   and if so implement. This should not be the default though so
  //   when I do this I'll make sure to use a define.
  //append  string

  //assign  vector, string, deque, list, forward_list
  //at      vector, string, deque
  //back    vector, string, deque, list
  //before_begin  forward_list
  //begin   vector, string, deque, list, forward_list
  //capacity  vector, string
  //cbefore_begin forward_list
  //cbegin    vector, string, deque, list, forward_list
  //cend      vector, string, deque, list, forward_list
  //clear     vector, string, deque, list, forward_list
  //compare   string
  //copy      string
  //crbegin   vector, string, deque, list
  //crend     vector, string, deque, list
  //c_str     string
  //data      vector, string
  //emplace   vector, deque, list
  //emplace_after   forward_list
  //emplace_back    vector, deque, list
  //emplace_front   deque, list, forward_list
  //empty           vector, string, deque, list, forward_list
  //end             vector, string, deque, list, forward_list
  //erase     vector, string, deque, list
  //erase_after   forward_list
  //find      string
  //find_first_not_of   string
  //find_first_of       string
  //find_last_not_of    string
  //find_last_of        string
  //front     vector, string, deque, list, forward_list
  //get_allocator   vector, string, deque, list, forward_list
  //insert   vector, string, deque, list
  //insert_after  forward_list
  //length   string
  //max_size   vector, string, deque, list, forward_list
  //merge       forward_list
  //operator+=  string
  //operater=   vector, string, deque, list, forward_list
  //operator[]   vector, string, deque
  //pop_back   vector, string, deque, list
  //pop_front   deque, list, forward_list
  //push_back   vector, string, deque, list
  //push_front  deque, list, forward_list
  //rbegin   vector, string, deque, list
  //remove   list, forward_list
  //remove_if list, forward_list
  //rend   vector, string, deque, list
  //reserve   vector, string
  //resize   vector, string, deque, list, forward_list
  //reverse  list, forward_list
  //shrink_to_fit   vector, string, deque
  //size   vector, string, deque, list
  //sort  list, forward_list
  //splice  list
  //splice_after  forward_list
  //substr  string
  //swap   vector, string, deque, list, forward_list
  //unique  list, forward_list


//Standard STL sequence containers:
//  vector
//  string
//  deque
//  list
//Nonstandard STL sequence containers:
//  slist
//  rope
//These can use T

//Standard non-STL containers:
//  arrays
//  bitset
//  valarray
//  stack
//  queue
//  priority_queue
//  These will actually need to use T -> void *

#endif
