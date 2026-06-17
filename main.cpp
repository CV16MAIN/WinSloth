#include <iostream>
#include <string> 
#include <vector>
#include <filesystem>  
#include <sstream>


#define RESET  "\033[0m"
#define RED    "\033[31m"
#define GREEN  "\033[32m"
#define YELLOW "\033[33m"
#define BLUE   "\033[34m"

#define WHITE  "\033[37m"

struct FileInfo
{

	std::wstring filename;  //!use w string casue win has many file name in hind and other language
	std::wstring filepath;
};




int main() {
	std::string targetFolder{};
	std::cout << "User Add The Folder To Scan-";  // -
	std::getline(std::cin, targetFolder);
	std::vector<FileInfo> file{}; //! fileinfo is a vector that contain 2 value name and location
	//! safely report errors 
	std::error_code errorbyfilesystem;
	// how the iterator will work 
	auto option{ std::filesystem::directory_options::skip_permission_denied };
	auto start{ std::filesystem::recursive_directory_iterator(targetFolder , option , errorbyfilesystem) };
	auto end{ std::filesystem::recursive_directory_iterator() }; // ! this is the end point we wan't the start to be like this (mean that all file are pushed)

	while (start != end) {
		// ! if no error find  
		if (!errorbyfilesystem) {

			FileInfo tempFile;
			tempFile.filename = start->path().filename().wstring();
			tempFile.filepath = start->path().wstring();
			file.push_back(tempFile); // 


		}
		start.increment(errorbyfilesystem);


	}
	if (file.size() == 0) {
		std::cerr << "Error(Use Real File Location)";
	}
	else {
		std::cout << "File Size-" << file.size() << "\n";
		for (int i = 0; i <= file.size() - 1; i++) { //  
			std::wcout << GREEN << "FileName- " << file[i].filename << " " << "FilePath -" << file[i].filepath << RESET << '\n';
		}
	}
	// std::getline(std::cin, fileinfo.filename);



	return 0;

}