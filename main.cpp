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
    std::cout <<"\n" << std::setw(65) << "ТАБЛИЦА ВИДЕОКАРТ\n";
    std::cout << std::string(80, '-') << std::endl;
    std::cout << std::left
        << std::setw(35) << "Название"
        << std::setw(23) << "Техпроцесс"
        << std::setw(32) << "Базовая частота"
        << "Количество видеопамяти" << std::endl;
    std::cout << std::string(80, '-') << std::endl;
    for (const auto& gpu : gpus) {
        std::cout << std::left
             << std::setw(31) << gpu.name
             << std::setw(15) << gpu.technical_process
             << std::setw(20) << gpu.frequency_base
             << gpu.video_memory
             << std::endl;
             std::cout << std::string(80, '-') << std::endl;
    }
}
void Write_In_File(const auto& gpus){

}
int main(){
    std::vector<gpu> gpus = Read_Gpus_From_File("gpus.txt");
    Gpu_Table(gpus);
    Write_In_File(gpus);
    return 0;
}
