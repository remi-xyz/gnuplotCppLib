#include "plot.h"

using namespace std;

plot::plot(string plot_file,string data_file){
  m_plot_file = plot_file;
  m_data_file = data_file;
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

void plot::addTitle(string title){ //change title of graph
  m_title=title;
}

string plot::showTitle() const{
  return m_title;
}

void plot::addXlabel(string xlabel){ //change label of x axis
  m_xlabel=xlabel;
}

void plot::addYlabel(string ylabel){ //change lable of y axis
  m_ylabel=ylabel;
}

string plot::showXlabel() const{
  return m_xlabel;
}

string plot::showYlabel() const{
  return m_ylabel;
}

void plot::addpoint(double x, double y) const{ //add a point in data file
  //initialisation of stream with data file
  ofstream dataStream(m_data_file, ios::app);
  //add the coordinates of the point with gnuplot syntax
  dataStream << x << " " << y << endl;
}

void plot::plotGraph() const{ //run gnuplot and plot the graph
  //initialisation of stream with the command file
  ofstream cmdStream("cmd.plt");
  //the command file is read by gnuplot, his contain all parameter of graph and the command to run the plot

  //define the type of output file in .svg
  cmdStream << "set terminal svg" << endl;
  //define the name of output file
  cmdStream << "set output \"" << m_plot_file <<"\"" << endl;
  
  //check if a title, x and y label are define by the user and add them on command file
  if (m_title!=""){
    cmdStream << "set title \"" << m_title << "\"" << endl;
  }
  if (m_xlabel!=""){
    cmdStream << "set xlabel \"" << m_title << "\"" << endl;
  }
  if (m_ylabel!=""){
    cmdStream << "set ylabel \"" << m_ylabel << "\"" << endl;
  }

  /*it's the command to plot the graph
  for the moment the graph is ploted in line style (gnuplot use interpolation to create the point between the data)
  use "pointlines" or nothing to change the plot style*/
  cmdStream << "plot \"" << m_data_file << "\" with lines" << endl; 

  // Run gnuplot with wanted parameters
  popen("gnuplot cmd.plt", "r");
}
