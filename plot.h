#ifndef DEF_PLOT
#define DEF_PLOT

#include "Includes.h"

using namespace std;

class plot{
    public:
        // Constructor
        plot(string plot_file, string data_file);
        plot(string plot_file, string data_file, string title, string xlabel,string ylabel);

        // Functions to custom graphs
        // Add a title to graph
        void addTitle(string title);

        // Function to print the graph title
        string showTitle() const;

        // Give a label for x axis
        void addXlabel(string xlabel);

        // Function to print the x axis label
        string showXlabel() const;

        // Give a label for y axis
        void addYlabel(string ylabel);

        // Function to print the y axis label
        string showYlabel() const;

        // Function to add points on curve
        void addpoint(double x, double y) const;

        // Function to run datas on Gnuplot
        void plotGraph() const;

    private:
        // The name of file which contains datas for graph
        string m_data_file;

        // The name of file which will contain plotting graph
        string m_plot_file;

        // Title of graph
        string m_title;

        // Label of x axis
        string m_xlabel;

        // Label of y axis
        string m_ylabel;
};

#endif
