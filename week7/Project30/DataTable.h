//DOYEON KIM/139766166
//DataTable.h
//2019/03/21

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <math.h>

extern int FW;
extern int ND;

namespace sict
{
	template <class T>
	class DataTable	{
		
		std::deque<T> x_num;
		std::deque<T> y_num;

		int NumOfRecords{ 0 };

		double x_accu{ 0.0f };
		double y_accu{ 0.0f };
		double x_mean{ 0.0f };
		double y_mean{ 0.0f };
		double x_sigma{ 0.0f };
		double y_sigma{ 0.0f };
		double correlation{ 0.0f };
		double slope{ 0.0f };
		double intercept{ 0.0f };

		

	public:

		DataTable(std::ifstream &file)
		{

			

			x_num.clear();
			
			y_num.clear();
			
			std::string the_strings;

			
			double first_str{ 0.0f };
			double second_str{ 0 };
			
			
			if (file.is_open())
			{
				while (!file.eof() && file.good())
				{
					std::getline(file, the_strings, '\n');

					int space = the_strings.find_first_of(' ');

					first_str = std::stof(the_strings.substr(0, space));
					second_str = std::stof(the_strings.substr(space, the_strings.length()));

					x_num.push_back(first_str);
					y_num.push_back(second_str);

					the_strings.clear();
					
					first_str = 0.0f;
					second_str = 0;
					
					NumOfRecords++;
				}
			}

			x_accu = std::accumulate(x_num.begin(), x_num.end(), 0.0);
			y_accu = std::accumulate(y_num.begin(), y_num.end(), 0.0);

			x_mean = x_accu / x_num.size();
			y_mean = y_accu / y_num.size();

			{
				double temp{ 0.0f };
				for (size_t i = 0; i < x_num.size(); i++)
				{
					temp += pow((x_num.at(i) - x_mean), 2);
				}
				x_sigma = std::sqrt(temp / (x_num.size() - 1));
			}

			{
				double temp{ 0.0f };
				for (size_t i = 0; i < y_num.size(); i++)
				{
					temp += pow((y_num.at(i) - y_mean), 2);
				}
				y_sigma = std::sqrt(temp / (y_num.size() - 1));
			}

			{
				double temp{ 0.0f };
				for (size_t i = 0; i < x_num.size(); i++)
				{
					temp += (x_num.at(i) - x_mean) * (y_num.at(i) - y_mean);
				}
				double temp2 = temp / (x_sigma * y_sigma);
				double temp3 = temp2 / (x_num.size() - 1);
				correlation = temp3;
			}

			slope = correlation * (y_sigma / x_sigma);

			intercept = y_mean - (slope * x_mean);
		}

		
		void displayData(std::ostream& os) const
		{

			if (NumOfRecords == 0)
			{
				throw("ERROR: container is empty!");
			}
			else
			{
				os << "Data Values" << "\n------------" << std::endl;

				os << std::right << std::fixed << std::setw(FW) << "x" << std::setw(FW) << " y" << std::endl;

				for (int i = 0; i < NumOfRecords; i++)
				{
					os << std::right << std::fixed << std::setw(FW) << std::setprecision(ND) << x_num.at(i) << std::setw(FW) << std::setprecision(ND) << y_num.at(i) << std::endl;
				}
			}
		}



		
		void displayStatistics(std::ostream& os) const
		{

			T median;
			{
				std::deque<T> temp;
				
				temp = y_num;
				
				std::sort(temp.begin(), temp.end());
				
				if ((temp.size() % 2) != 0)
					median = temp.at(temp.size() / 2);
				else
					median = (temp.at((temp.size() / 2) - 1) + temp.at((temp.size() / 2) + 1)) / 2;
			}

			os << "\nStatistics" << "\n----------" << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y mean    = " << std::setw(FW) << y_mean << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y sigma   = " << std::setw(FW) << y_sigma << std::endl;
			os << std::fixed << std::setprecision(ND) << "  y median  = " << std::setw(FW) << median << std::endl;
			os << std::fixed << std::setprecision(ND) << "  slope     = " << std::setw(FW) << slope << std::endl;
			os << std::fixed << std::setprecision(ND) << "  intercept = " << std::setw(FW) <<  intercept << std::endl;

		
		}
	};
}	
#endif //SICT_DATA_TABLE_H