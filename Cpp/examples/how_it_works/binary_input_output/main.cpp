#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>


int main() {
   typedef std::ostream_iterator<double> oi_t;
   typedef std::istream_iterator<double> ii_t;
   std::ofstream ofs("data.bin", std::ios::in);
   //-If file doesn't exist, create a new one now
   if(!ofs) {
      ofs.open("data.bin", std::ios::out|std::ios::binary|std::ios::app);
   }
   else {
      ofs.close();
      ofs.open("data.bin", std::ios::out|std::ios::binary|std::ios::app);
   }

   //-Write a header consisting of length of grid subdomain and its name
   ///*
   const std::string grid = "Header";
   unsigned int olen = grid.size();
   ofs.write(reinterpret_cast<const char*>(&olen), sizeof(olen));
   ofs.write(grid.c_str(), olen);
   //*/

   //-Now write the data
   ///*
   std::vector<double> data_out;
   //std::vector<std::pair<int, int> > cell_ids;
   for(int i=0; i<100; ++i) {
      data_out.push_back(5.0*double(i) + 100.0);
   }
   ofs << std::setprecision(4);
   std::copy(data_out.begin(), data_out.end(), oi_t(ofs, " "));
   //*/
   ofs.close();

   //-Now read the binary file; first header then data
   std::ifstream ifs("data.bin", std::ios::binary);
   ///*
   unsigned int ilen;
   ifs.read(reinterpret_cast<char*>(&ilen), sizeof(ilen));
   std::string header;
   if(ilen > 0) {
      char* buf = new char[ilen];
      ifs.read(buf,ilen);
      header.append(buf,ilen);
      delete[] buf;
   }
   std::cout << "Read header: " << header << "\n";
   //*/

   ///*
   std::vector<double> data_in;
   ii_t ii(ifs);
   std::copy(ii, ii_t(), std::back_inserter(data_in));
   std::cout << "Read data size: " << data_in.size() << "\n";
   //*/
   ifs.close();

   //-Check the result
   ///*
   for(int i=0; i < data_out.size(); ++i) {
      std::cout << "Testing input/output element #" << i << " : "
                << data_out[i] << "  " << data_in[i] << "\n";
   }
   std::cout << "Element sizes: " << data_out.size() << "  " << data_in.size() <<
            "\n";
   //*/
   return 0;
}
