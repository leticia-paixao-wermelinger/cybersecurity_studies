#include <iostream>

int	access_url(const std::string &url)
{
	// Implement the logic to access the URL and return the response
	(void)url;
	return 0;
}

// int extract_images(const std::string &html_content)
// {
// 	// Implement the logic to extract image URLs from the HTML content
// 	return 0;
// }

// int download_images(const std::vector<std::string> &image_urls, const std::string &save_path)
// {
// 	// Implement the logic to download images from the provided URLs and save them to the specified path
// 	return 0;
// }

int spider(const std::string &url, const std::string &save_path)
{
	// Implement the logic for the spider functionality
	// This function should handle accessing the URL, extracting images, downloading them

	// acessar a url
	// extrair imagens encontradas na página
	// baixar imagens para o diretório especificado ou para ./data/ como default
	(void)url;
	(void)save_path;
	return 0;
}

bool validateUrl(const std::string &url)
{
	// Implement the logic to validate the URL format
	if (url.empty()) {
		std::cout << "Error: URL is empty." << std::endl;
		return false;
	}
	if (url.find("http://") != 0 && url.find("https://") != 0) {
		std::cout << "Error: Invalid URL format. URL must start with 'http://' or 'https://'." << std::endl;
		return false;
	}
	return true;
}

bool check_path(const std::string &path)
{
	if (std::string(path).find("-") != std::string::npos) {
		std::cerr << "Error: Invalid path after -p flag." << std::endl;
		return false;
	}
	else if (std::string(path).empty()) {
		std::cerr << "Error: Empty path after -p flag." << std::endl;
		return false;
	}
	else if (atoi(path.c_str()) != 0) {
		return false;
	}
	return true;
}

const std::string persoalized_path(char *argv[])
{
	// Implement the logic to parse command-line arguments and determine the save path
	for (int i = 1; argv[i] != nullptr; ++i)
	{
		if (argv[i][0] == '-')
		{
			if (std::string(argv[i]).find("p") != std::string::npos) {
				if (argv[i + 1] == nullptr) {
					std::cerr << "Error: Missing path after -p flag." << std::endl;
					break ;
				}
				if (check_path(argv[i + 1]) == true) {
					
					return std::string(argv[i + 1]);
				}
				else {
					if (argv[i + 2] == nullptr) {
						std::cerr << "Error: Missing path after -p flag." << std::endl;
						break ;
					}
					if (check_path(argv[i + 2]) == true) {
						return std::string(argv[i + 2]);
					}
				}
			}
		}
	}
	return "./data/";
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " [optional flags -rlp] URL" << std::endl;
		return 1;
	}
	const std::string url = argv[argc - 1];
	if (validateUrl(url) != true) {
		// std::cerr << "Error: Invalid URL." << std::endl;
		return 1;
	}

	const std::string save_path = persoalized_path(argv);

	spider(url, save_path);
	// flag -r: recursive to other urls listed in the page
	// flag -l: limit depth for the recursive search
	// flag -p: path to save the downloaded files
	
	return 0;
}