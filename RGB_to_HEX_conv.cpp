/*
The rgb() method is incomplete. Complete the method so that passing in RGB decimal values will result in a hexadecimal representation being returned. The valid decimal values for RGB are 0 - 255. Any (r,g,b) argument values that fall out of that range should be rounded to the closest valid value.

The following are examples of expected output values:

rgb(255, 255, 255) # returns FFFFFF
rgb(255, 255, 300) # returns FFFFFF
rgb(0,0,0) # returns 000000
rgb(148, 0, 211) # returns 9400D3
*/

#include <iomanip>

class RGBToHex
{
  public:
  static std::string rgb(int r, int g, int b) {
    
    std::stringstream stream;
    stream.flags(std::ios::hex | std::ios::uppercase);
    stream.fill('0');
    std::string result;
    
    stream << std::setw(2) 
           << (r > 255 ? 255 : (r < 0 ? 0 : r))
           << std::setw(2) 
           << (g > 255 ? 255 : (g < 0 ? 0 : g))
           << std::setw(2) 
           << (b > 255 ? 255 : (b < 0 ? 0 : b));
   
    return stream.str();
  }
};