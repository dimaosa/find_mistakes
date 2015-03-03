#include <iostream>
#include <ctime>
#include <vector>

int swap_counts;

void sorting(std::vector<double>& array, int first, int last){
    
    if (first < 0 || last < 0){
        return;
    }
    
    int i = first, j = last;
    double x = array[(first + last) / 2];
    do
    {
        while (array[i]<x) i++;
        while (array[j]>x) j--;
        
        if (i <= j)
        {
            if (array[i]>array[j])
            {
                double temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                swap_counts++;
            }
            i++;
            j--;
        }
    } while (i <= j);
    
    if (i<last)
        sorting(array, i, last);
    if (first<j)
        sorting(array, first, j);
}

void generate_array(std::vector<double>& arr, int size, double rand_min, double rand_max){
    srand((unsigned int)time(NULL));
    
    for (int i = 0; i < size; ++i){
        arr.push_back(rand_min + ((double)rand() / RAND_MAX) * (rand_max - rand_min));
    }

}
void show_array(const std::vector<double>& arr){
    for(auto elem : arr){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}


int main(int argc, char* argv[]){
    int arr_size;
    std::vector<double> arr;
    std::cout << "Enter array size: ";
    std::cin >> arr_size;
    std::cout << std::endl;
    
    //generate array
    double rand_min = -23.45;
    double rand_max = 45.954;
    generate_array(arr, arr_size, rand_min, rand_max);
    show_array(arr);
    
    //quicksort
    sorting(arr, 0, arr_size);
    
    //result of sorted array
    show_array(arr);
    
    std::cout << std::endl << "Swaps: " << swap_counts << std::endl;
}