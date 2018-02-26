#include "plot.h"

using namespace std;

plot::plot(string plot_file,string data_file){
  m_plot_file=plot_file;
  m_data_file=data_file;
  m_title="";
  m_xlabel="";
  m_ylabel="";
}

plot::plot(string plot_file, string data_file, string title, string xlabel, string ylabel){
  m_plot_file=plot_file;
  m_data_file=data_file;
  m_title=title;
  m_xlabel=xlabel;
  m_ylabel=ylabel;
}

void plot::addTitle(string title){
  m_title=title;
}

string plot::showTitle() const{
  return m_title;
}

void plot::addXlabel(string xlabel){
  m_xlabel=xlabel;
}

string plot::showXlabel() const{
  return m_xlabel;
}

void plot::addYlabel(string ylabel){
  m_ylabel=ylabel;
}

string plot::showYlabel() const{
  return m_ylabel;
}

void plot::addpoint(double x, double y) const{
  ofstream dataStream(m_data_file, ios::app);
  dataStream << x << " " << y << endl;
}

void plot::plotGraph() const{
  ofstream cmdStream("cmd.plt");
  cmdStream << "set terminal svg" << endl;
  cmdStream << "set output \"" << m_plot_file <<"\"" << endl;
  if (m_title!=""){
    cmdStream << "set title \"" << m_title << "\"" << endl;
  }
  if (m_xlabel!=""){
    cmdStream << "set xlabel \"" << m_title << "\"" << endl;
  }
  if (m_ylabel!=""){
    cmdStream << "set ylabel \"" << m_ylabel << "\"" << endl;
  }
  cmdStream << "plot \"" << m_data_file << "\" with lines" << endl;

  popen("gnuplot cmd.plt", "r");
}
