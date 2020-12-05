#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <iostream>

using namespace std;

template<typename T>
void merge_sort(T array[], std::size_t size) noexcept
{
    if (size > 1)
    {
        std::size_t const left_size = size / 2;
        std::size_t const right_size = size - left_size;

        merge_sort(&array[0], left_size);
        merge_sort(&array[left_size], right_size);

        std::size_t lidx = 0, ridx = left_size, idx = 0;
        std::unique_ptr<T[]> tmp_array(new T[size]);

        while (lidx < left_size || ridx < size)
        {
            if (array[lidx] < array[ridx])
            {
                tmp_array[idx++] = std::move(array[lidx]);
                lidx++;
            }
            else
            {
                tmp_array[idx++] = std::move(array[ridx]);
                ridx++;
            }

            if (lidx == left_size)
            {
                std::copy(std::make_move_iterator(&array[ridx]),
                          std::make_move_iterator(&array[size]),
                          &tmp_array[idx]);
                break;
            }
            if (ridx == size)
            {
                std::copy(std::make_move_iterator(&array[lidx]),
                          std::make_move_iterator(&array[left_size]),
                          &tmp_array[idx]);
                break;
            }
        }

        std::copy(std::make_move_iterator(&tmp_array[0]),
                  std::make_move_iterator(&tmp_array[size]),
                  array);
    }
}

int main(){
    int elCt=0;
    cout<<"Sortirovka sliyaniem"<<endl;
    cout<<"Vvedite chislo elementov"<<endl;
    cin>>elCt;
    int elArr [elCt+1];
    int OutelArr [elCt+1];
    cout<<"Vvedite elementi"<<endl;
    for(int i=0;i<elCt;i++){
        cin>>elArr[i];
    }
    elArr[elCt+1]==elArr[elCt];
    merge_sort(elArr,elCt+1);
    
    for(int i=1;i<elCt+1;i++){
        elArr[i-1]=elArr[i];
    }
    cout<<"Vivod masiva"<<endl;
    for(int i=0;i<elCt;i++){
        cout<<elArr[i]<<endl;
    }
    system("pause");
   return 0;
}