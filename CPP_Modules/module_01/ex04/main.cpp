#include <iostream>
#include <fstream>
#include <string>

int	main( int argc, char **argv ) {

	if (argc != 4) {
	
		std::clog << "Insert 3 arguments" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string	s2 = argv[3];
	std::string	buffer;

	std::ifstream infile(filename.c_str());
	if (!infile) {
		std::cout << "Opening file failed." << std::endl;
		return 1;
	}
	std::string out_filename = filename + ".replace";
	std::ifstream check_outfile(out_filename.c_str());
	if (check_outfile) {
		std::clog << out_filename << " already exists." << std::endl;
		return 1;
	}
	std::ofstream outfile(out_filename.c_str());
	if (!outfile) {
		std::clog << "Opening file failed." << std::endl;
		return 1;
	}

	while (std::getline(infile, buffer)) {
		
		size_t pos = 0;
		// std::clog << buffer << std::endl;
		while (1) {
			size_t start = buffer.find(s1, pos);
			if (start == std::string::npos)
				break ;
			buffer.erase(start, s1.length());
			// std::clog << buffer << std::endl;
			buffer.insert(start, s2);
			// std::clog << buffer << std::endl;
			pos += s2.length();
		}
		outfile << buffer << std::endl;
	}

	if (infile.eof())
		std::clog << "EOF reached." << std::endl;
	else if (infile.fail())
		std::clog << "Reading failed." << std::endl;
	else if (infile.bad())
		std::clog << "I/O error." << std::endl;
}