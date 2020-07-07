#include <bits/c++config.h>
#include <boost/filesystem.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <cstdint>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

namespace po = boost::program_options;
namespace fs = boost::filesystem;

void raise_error(const char* message) {
  std::cerr << message << std::endl;
  exit(EXIT_FAILURE);
}

void decoder(const std::string& file_path) {
  std::ifstream input_fd(file_path, std::ios::in | std::ios::binary);
  // Check if the file was read correctly
  if (input_fd.fail()) {
    raise_error("There was an error opening the file");
  }
  // Get the length of the file in bytes
  std::uintmax_t length = fs::file_size(file_path);
  std::vector<char> bytes(length);
  // Read bytes and store in a vector
  input_fd.read(bytes.data(), length);
  // TODO(call_library_decoder): Call the decoder by passing the vector of bytes
}

void encoder(const std::string& file_path) {

}

auto main(int argc, char* argv[]) -> int {
  // Variables to store the flags and the input and output paths
  bool encode = false;
  bool decode = false;
  std::string file_path;
  std::string output_path;
  bool nwa = false;

  // Describe the schema
  po::options_description desc("Allowed options");
  desc.add_options()("help", "produce help message")(
      "encode,e", po::bool_switch(&encode)->default_value(false), "Encode")(
      "decode,d", po::bool_switch(&decode)->default_value(false), "Decode")(
      "file,f", po::value<std::string>(&file_path)->required(), "File path or - for STDIN")(
      "output,o", po::value<std::string>(&output_path)->required(), "Output directory")(
      "no-write-attachments,nwa", po::bool_switch(&nwa)->default_value(false),
      "Don't write attachments to directory")
      ;
  // Describe the variable mapper and call it on the input arguments      
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  po::notify(vm);

  // Exclusive OR to restrict the program to either encoding or decoding
  if (!(encode ^ decode)) {
    raise_error("Either encode or decode option to be given");
  }

  // Check if the input file exists and is indeed a file
  if (fs::exists(file_path) && !fs::is_regular_file(file_path)) {
      raise_error("Given input is not a file");
  }
  if (!fs::exists(file_path)) {
    raise_error("Given input file doesn't exist");
  }

  // Check if the output directory exists and is indeed a directory
  if (fs::exists(output_path) && !fs::is_directory(output_path)) {
    raise_error("Given output is not a directory");
  }
  if (!fs::exists(output_path)) {
    raise_error("Given output directory doesn't exist");
  }

  if (encode) {
    // TODO(unknown): Change the argument later since we have to decide the input
    encoder(file_path);
  } else {
    // Call the decoder
    decoder(file_path);
  }

  return EXIT_SUCCESS;
}