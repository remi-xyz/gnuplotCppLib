#include "plot.h"

using namespace std;

// Definition of first contructor
plot::plot(string plot_file,string data_file){
  // We has here the wanted name for final plot graph
  m_plot_file = plot_file;

  // And the name of data file 
  m_data_file = data_file;

  // Initialization of title and labels 
  m_title="";
  m_xlabel="";
  m_ylabel="";
}

// Definition of second constructor 
plot::plot(string plot_file, string data_file, string title, string xlabel, string ylabel){
  // He has here the wanted name for final plot graph
  m_plot_file=plot_file;

  // And the name of data file 
  m_data_file=data_file;

  // And the title and labels of axis 
  m_title=title;
  m_xlabel=xlabel;
  m_ylabel=ylabel;
}

// Definition of addTitle function
void plot::addTitle(string title){
  // We enter in this function the wanted name for graph
  m_title=title;
}

// Definition of shwTitle function
string plot::showTitle() const{
  return m_title;
}

// Definition of add labels
void plot::addXlabel(string xlabel){
  // We enter in this function the wanted name for xlabel
  m_xlabel=xlabel;
}

void plot::addYlabel(string ylabel){
  // We enter in this function the wanted name for ylabel
  m_ylabel=ylabel;
}

// Definition of show label functions
string plot::showXlabel() const{
  return m_xlabel;
}

string plot::showYlabel() const{
  return m_ylabel;
}

// Definition of addpoint function
void plot::addpoint(double x, double y) const{
  // Need com !
  ofstream dataStream(m_data_file, ios::app);

  // Need com !
  dataStream << x << " " << y << endl;
}

// Definition of plotGraph function
void plot::plotGraph() const{
  // Need com !
  ofstream cmdStream("cmd.plt");

  // Need com !
  cmdStream << "set terminal svg" << endl;

  // Need com !
  cmdStream << "set output \"" << m_plot_file <<"\"" << endl;

  // Need com !
  if (m_title!=""){
    // Need com !
    cmdStream << "set title \"" << m_title << "\"" << endl;
  }

  // Need com !
  if (m_xlabel!=""){
    // Need com !
    cmdStream << "set xlabel \"" << m_title << "\"" << endl;
  }

  // Need com !
  if (m_ylabel!=""){
    // Need com !
    cmdStream << "set ylabel \"" << m_ylabel << "\"" << endl;
  }

  // Need com !
  cmdStream << "plot \"" << m_data_file << "\" with lines" << endl;

  // Run gnuplot with wanted parameters
  popen("gnuplot cmd.plt", "r");
}
