#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>
#include <sstream>
#include <iomanip>


using namespace std;

struct gpu{
    std::string name;
    int64_t technical_process;
    int64_t frequency_base;
    int64_t video_memory;
};

std::vector<gpu> Read_Gpus_From_File(const auto& file_name){
    return gpus;
}
void Gpu_Table(const auto& gpus){

}
void Write_In_File(const auto& gpus){

}
int main(){
    std::vector<gpu> gpus = Read_Gpus_From_File("gpus.txt");
    Gpu_Table(gpus);
    Write_In_File(gpus);
    return 0;
}
