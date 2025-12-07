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
        std::cout << "РќРµ СѓРґР°Р»РѕСЃСЊ РѕС‚РєСЂС‹С‚СЊ С„Р°Р№Р»" << std::endl;
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
