#include <bits/c++config.h>
#include <boost/filesystem/operations.hpp>
#include <boost/program_options.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/filesystem.hpp>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace po = boost::program_options;
namespace fl = boost::filesystem;

void throw_error(const std::string& message) {
  std::cerr << message << std::endl;
  exit(EXIT_FAILURE);
}

void decoder(const std::string& file_path) {
  std::ifstream input_fd;
  std::vector<unsigned char> bytes;
  // Open the file
  input_fd.open(file_path, std::ios::in | std::ios::binary);
  // Check if the file was read correctly
  if (input_fd.fail()) {
    throw_error("There was an error opening the file");
  }
  // Read bytes and store in a vector
  while (!input_fd.eof()) {
    unsigned char byte;
    input_fd >> byte;
    bytes.push_back(byte);
  }
  // TODO(call_library_decoder): Call the decoder by passing the vector of bytes
}

void encoder(const std::string& file_path) {

}

auto main(int argc, char* argv[]) -> int {
  // Variables to store the flags and the input and output paths
  bool encode;
  bool decode;
  std::string file_path;
  std::string output_path;
  bool nwa;

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
    throw_error("Either encode or decode option to be given");
  }

  // Check if the input file exists and is indeed a file
  if (fl::exists(file_path)) {
    if (!fl::is_regular_file(file_path)) {
      throw_error("Given input is not a file");
    }
  } else  {
    throw_error("Given input file doesn't exist");
  }

  // Check if the output directory exists and is indeed a directory
  if (fl::exists(output_path)) {
    if (!fl::is_directory(output_path)) {
      throw_error("Given output is not a directory");
    }
  } else {
    throw_error("Given output directory doesn't exist");
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