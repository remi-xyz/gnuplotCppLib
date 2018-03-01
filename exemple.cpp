/* We test our library in this main function */

#include "plot.h"

using namespace std;

int main(int argc, char const *argv[]) {
  string plot_file="exemple.svg", data_file="exemple.dat";
  plot2D exemple(plot_file, data_file);
  for (double x=0; x<=100; x+=0.1){
    double y=cos(x);
    exemple.addpoint(x,y);
  }
  exemple.plotGraph();
  return 0;
}
