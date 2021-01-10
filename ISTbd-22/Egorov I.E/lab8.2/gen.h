#pragma once
#include <algorithm>

class fib_gen : public std::iterator<std::input_iterator_tag , long>{
 private:
  long* gp;
  long sect;
  long st;
  long mx;
 public:
  fib_gen(long startG , long sectG , long max):st(startG),sect(sectG),mx(max),gp(new long (startG)){};
  ~fib_gen(){ delete gp ;};

  bool operator!=(fib_gen const& otr) const{
    return *gp != *otr;
  }

  bool operator==(fib_gen const& otr) const{
    return *gp == *otr.gp;
  }

  typename fib_gen::reference operator*() const {
        return *gp;
    }

  fib_gen& operator++() {
        long ud = *gp;
        long udd = ud;
        delete gp;
        gp=new long(ud+sect);
        sect=udd;
        return *this;
    }

  typedef fib_gen const_it;

  const_it begin()const{
      return const_it(this->st,this->sect,this->mx);
  }

  const_it end()const{
      return const_it(this->mx,this->sect,this->mx);
  }

};