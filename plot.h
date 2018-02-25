#ifndef DEF_PLOT
#define DEF_PLOT

#include <iostream>
#include <fstream>

using namespace std;

class plot{
public:
  //constructor
  plot(string plot_file, string data_file);
  plot(string plot_file, string data_file, string title, string xlabel,string ylabel);

  //graph presentation
  void addTitle(string title);
  string showTitle() const;
  void addXlabel(string xlabel);
  string showXlabel() const;
  void addYlabel(string ylabel);
  string showYlabel() const;

  //data
  void addpoint(double x, double y) const;

  //plot graph
  void plotGraph() const;
private:
  string m_data_file, m_plot_file, m_title, m_xlabel, m_ylabel;

};

#endif
