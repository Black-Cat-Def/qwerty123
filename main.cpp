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
    std::vector<gpu> gpus;
    std::ifstream gpu_file(file_name);
    if (!gpu_file.is_open()){
        std::cout << "Не удалось открыть файл" << std::endl;
        return gpus;
    }

    gpu in_gpu;
    while (!gpu_file.eof()){
        gpu_file >> in_gpu.name;
        gpu_file >> in_gpu.technical_process;
        gpu_file >> in_gpu.frequency_base;
        gpu_file >> in_gpu.video_memory;
        gpus.push_back(in_gpu);
    }

    gpu_file.close();
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
