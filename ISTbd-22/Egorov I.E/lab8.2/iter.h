#pragma once
#include <algorithm>
#include "vector.h"
#include <iterator>

using namespace std;

template<typename T>
class vec_iter:public std::iterator<input_iterator_tag , T>{
 private:
  T* tp;
 public:
  vec_iter(const vec_iter& ths):tp(ths.tp){}
  vec_iter(T* tp):tp(tp){}

  bool operator!=(vec_iter const& otr) const{
    return this->tp != otr.tp;
  }

  bool operator==(vec_iter const& otr) const{
    return this->tp == otr.tp;
  }

  typename vec_iter::reference operator*() const {
        return *this->tp;
    }

  vec_iter& operator++() {
        ++this->tp;
        return *this;
    }
};