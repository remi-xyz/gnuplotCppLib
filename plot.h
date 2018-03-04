#ifndef DEF_PLOT
#define DEF_PLOT

#include "Includes.h"

using namespace std;

// Class of graphs with 2 axis
class plot2D{
    public:
        // Constructors
        plot2D(string plot_file, string data_file);
        plot2D(string plot_file, string data_file, string title, string xlabel,string ylabel);

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

        // Function to print the name of plot file
        string showPlotFile();

        // Function to print the name of data file
        string showDataFile();

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

// Class for graphs with 3 axis
class plot3D
{
    public:
        // Constructors
        plot3D(string plot_file, string data_file);
        plot3D(string plot_file, string data_file, string title, string xlabel,string ylabel);

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

        // Give a label for z axis
        void addZlabel(string zlabel);

        // Print the z axis label
        string showZlabel();

        // Function to add points on curve
        void addpoint(double x, double y, double z) const;

        // Function to run datas on Gnuplot
        void plotGraph() const;

    private:



};

// Function to open easly a picture
void OpenPicture(string name);

// Function to create a plot with cubic splines interpolation based on another graph
plot2D CubicSplines(plot2D Init_Plot, double e);



#endif
