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
void plot::addpoint(double x, double y) const{ // Add a point in data file
  // Initialisation of stream with data file
  ofstream dataStream(m_data_file, ios::app);

  // Add the coordinates of the point with gnuplot syntax
  dataStream << x << " " << y << endl;
}

// Definition of plotGraph function
void plot::plotGraph() const{ // Run gnuplot and plot the graph
  // Initialisation of stream with the command file
  ofstream cmdStream("cmd.plt");
  // The command file is read by gnuplot, his contain all parameter of graph and the command to run the plot

  // Define the type of output file in .svg
  cmdStream << "set terminal svg" << endl;

  // Define the name of output file
  cmdStream << "set output \"" << m_plot_file <<"\"" << endl;

  // Check if a title, x and y label are define by the user and add them on command file
  if (m_title!=""){
    // Scripting
    cmdStream << "set title \"" << m_title << "\"" << endl;
  }

  if (m_xlabel!=""){
    // Scripting
    cmdStream << "set xlabel \"" << m_title << "\"" << endl;
  }

  if (m_ylabel!=""){
    // Scritpting
    cmdStream << "set ylabel \"" << m_ylabel << "\"" << endl;
  }

  /*it's the command to plot the graph
  for the moment the graph is ploted in line style (gnuplot use interpolation to create the point between the data)
  use "pointlines" or nothing to change the plot style*/
  cmdStream << "plot \"" << m_data_file << "\" with lines" << endl;

  // Run gnuplot with wanted parameters
  popen("gnuplot cmd.plt", "r");
}
