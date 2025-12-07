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
    std::ofstream file("gpus.bin", std::ios::binary);
    if (!file.is_open()){
        std::cout<< "Ошибка открытия файла для записи" << std::endl;
        return;
    }
    std::stringstream ss;
    int64_t cnt = 0;
    for (const auto& gpu : gpus){
        cnt++;
        ss << "Видеокарта №" << cnt << "\n";
        ss << "Название: " << gpu.name << "\n";
        ss << "Техпроцесс: " << gpu.technical_process << "\n";
        ss << "Базовая частота: " << gpu.frequency_base << "\n";
        ss << "Количество видеопамяти: " << gpu.video_memory << "\n";
    }
    std::string minfo = ss.str();
    file.write(minfo.c_str(), minfo.size());
    file.close();
    return;
}
int main(){
    std::vector<gpu> gpus = Read_Gpus_From_File("gpus.txt");
    Gpu_Table(gpus);
    Write_In_File(gpus);
    return 0;
}
