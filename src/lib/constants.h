#include <cstdint>
#include <string>
#include <unordered_map>

class Mapping {
 private:
  std::unordered_map<std::uint8_t,
                     std::unordered_map<std::uint8_t, std::string>>
      map;

 // TODO(unknown): Add functions
};