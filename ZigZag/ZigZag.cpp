// ZigZag.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using charMatrix = std::vector< std::string >;

class Solution
{
public:
	Solution(std::string s, int numRows) : m_s(s), m_numRows(numRows), m_currRow(0), m_currCol(0), m_count(0)
	{
		m_numCols = s.length();
		
		matrix.resize(m_numRows);
		for (int i = 0; i < m_numRows; i++)
		{
			matrix[i].resize(m_numCols);
			matrix[i].insert(0, m_numCols, ' ');
		}
	}

	Solution(Solution& other) = delete;
	Solution& operator=(Solution const&) = delete;

	void insertByRow()
	{
		while (m_count < m_numCols && m_currRow < m_numRows)
		{
			matrix[m_currRow][m_currCol] = m_s.at(m_count);
			m_count++;
			m_currRow++;
		}
		m_currCol++;
		m_currRow--;
	}

	void insertByColumn()
	{
		m_currRow--;
		while (m_count < m_numCols && m_currRow >= 1)
		{
			matrix[m_currRow][m_currCol] = m_s.at(m_count);
			m_count++;
			m_currRow--;
			m_currCol++;
		}
	}

	std::string convert()
	{
		if (1 == m_numRows || m_numRows < 0 || m_numRows >= m_numCols) return m_s;
		std::string out;

		while (m_count < m_s.length())
		{
			insertByRow();
			insertByColumn();
		}

		for (int i = 0; i < m_numRows; i++)
		{
			for (int j = 0; j < m_numCols; j++)
			{
				if (matrix[i][j] != ' ') out += matrix[i][j];
			}
		}

		return out;
	}

private:
	std::string m_s;
	int m_numRows;
	int m_numCols;
	int m_currRow;
	int m_currCol;
	int m_count;
	charMatrix matrix;
};


std::string convert(std::string s, int numRows)
{
	Solution z(s, numRows);
	return z.convert();
}

void testZZConvert()
{
	//std::string s = convert("PAYPALISHIRING", 15);
	//_ASSERT(s == "PAYPALISHIRING");

	//std::string s = convert("PAYPALISHIRING", 3);
	//_ASSERT(s == "PAHNAPLSIIGYIR");

	//std::string s = convert("singasong", 4);
	//_ASSERT(s == "soisnnagg");

	std::string s = convert("iknowthatloveofmine", 5);
	_ASSERT(s == "itikalmnnhofeotvowe");

}

int main()
{
	testZZConvert();
}

