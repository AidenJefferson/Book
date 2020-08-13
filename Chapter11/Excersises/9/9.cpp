// Split the binary I/O program from §11.3.2 into two: one program that converts an ordinary text file into binary and one
// program that reads binary and converts it to text. Test these programs by comparing a text file with what you get by
// converting it to binary and back.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <class T>
char* as_bytes(T& x) {
    return &reinterpret_cast<char&>(x);
    // or:
    // return reinterpret_cast<char*>(std::addressof(x));
}

void text_to_binary(std::string& t_file_name, std::string& b_file_name){
    std::ifstream ifs{t_file_name};
    if(!ifs) throw std::runtime_error("cannot open input file.");
    std::ofstream ofs{b_file_name, std::ios_base::binary};
    if(!ofs) throw std::runtime_error("cannot open output file.");

    for(char x; ifs >> x;){
        ofs.write(as_bytes(x), sizeof(char));
    }
} 

void binary_to_text(std::string& b_file_name, std::string t_file_name){
    std::ifstream ifs{b_file_name, std::ios_base::binary};
    if(!ifs) throw std::runtime_error("cannot open input file.");
    std::ofstream ofs{t_file_name};
    if(!ofs) throw std::runtime_error("cannot open output file.");

    for(char x; ifs.read(as_bytes(x), sizeof(char));){
        ofs << x;
    }
}
int main(){
    std::string ifile, bfile, tfile;
    std::cout << "Please enter input file name\n";
    std::cin >> ifile;
    std::cout << "Please enter output (binary) file name:" << std::endl;
    std::cin >> bfile;
    std::cout << "Please enter output (text) file name:" << std::endl;
    std::cin >> tfile;

    text_to_binary(ifile, bfile);
    binary_to_text(bfile, tfile);

    return 0;
}
