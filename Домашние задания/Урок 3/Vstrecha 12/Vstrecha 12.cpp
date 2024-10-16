#include <iostream>

template <class T>
class Matrix
{
public:

	Matrix() : Matrix(0, 0) {}

	Matrix(size_t u_rows_size, size_t u_cols_size)
	{
		CreateMatrix(u_rows_size, u_cols_size);
	}

	~Matrix()
	{
		if (matrix != nullptr)
		{
			for (size_t i = 0; i != rows_size; i++)
			{
				delete[] matrix[i];
			}
			delete[] matrix;
			matrix = nullptr;
		}
	}

	void InitMatrix()
	{
		for (size_t i = 0; i != rows_size; i++)
		{
			for (size_t j = 0; j != cols_size; j++)
			{
				std::cout << "Введите элемент [" << i << "][" << j << "]: ";
				std::cin >> matrix[i][j];
			}
		}
	}

	void RandInitMatrix(int max = 100, int min = 0)
	{
		for (size_t i = 0; i != rows_size; i++)
		{
			for (size_t j = 0; j != cols_size; j++)
			{
				matrix[i][j] = (T)(min + rand() % (max - min + 1));
			}
		}
	}
	
	friend Matrix<T>& operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix<T> result(matrix1.rows_size, matrix1.cols_size);
		if (matrix1.rows_size == matrix2.rows_size && matrix1.cols_size == matrix2.cols_size)
		{
			for (size_t i = 0; i != result.rows_size; i++)
			{
				for (size_t j = 0; j != result.cols_size; j++)
				{
					result.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
				}
			}
		}
		else
		{
			std::cout << "Размеры матриц должны быть одинаковы." << std::endl;
			result.matrix = nullptr;
		}
		return result;
	}

	friend Matrix<T>& operator-(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix result(matrix1.rows_size, matrix1.cols_size);
		if (matrix1.rows_size == matrix2.rows_size && matrix1.cols_size == matrix2.cols_size)
		{
			for (size_t i = 0; i != result.rows_size; i++)
			{
				for (size_t j = 0; j != result.cols_size; j++)
				{
					result.matrix[i][j] = matrix1.matrix[i][j] - matrix2.matrix[i][j];
				}
			}
		}
		else
		{
			std::cout << "Размеры матриц должны быть одинаковы." << std::endl;
			result.matrix = nullptr;
		}
		return result;
	}

	friend Matrix<T>& operator*(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix result(matrix1.rows_size, matrix1.cols_size);
		if (rows_size == matrix2.rows_size && cols_size == matrix2.cols_size)
		{
			for (size_t i = 0; i != result.rows_size; i++)
			{
				for (size_t j = 0; j != result.cols_size; j++)
				{
					result.matrix[i][j] = matrix1.matrix[i][j] * matrix2.matrix[i][j];
				}
			}
		}
		else
		{
			std::cout << "Размеры матриц должны быть одинаковы." << std::endl;
			result.matrix = nullptr;
		}
		return result;
	}

	friend Matrix<T>& operator/(const Matrix<T>& matrix1, const Matrix<T>& matrix2)
	{
		Matrix result(matrix1.rows_size, matrix1.cols_size);
		if (rows_size == matrix2.rows_size && cols_size == matrix2.cols_size)
		{
			for (size_t i = 0; i != result.rows_size; i++)
			{
				for (size_t j = 0; j != result.cols_size; j++)
				{
					if (matrix2.matrix[i][j] == 0)
					{
						std::cout << "Деление на ноль невозможно." << std::endl;
						result.matrix = nullptr;
						return result;
					}
					result.matrix[i][j] = matrix1.matrix[i][j] / matrix2.matrix[i][j];
				}
			}
		}
		else
		{
			std::cout << "Размеры матриц должны быть одинаковы." << std::endl;
			result.matrix = nullptr;
		}
		return result;
	}

	friend std::ostream& operator<<(std::ostream& output,
		const Matrix& o_matrix)
	{
		if (o_matrix.matrix == nullptr)
		{
			output << "Пустая матрица." << std::endl;
		}
		else
		{
			for (size_t i = 0; i != o_matrix.rows_size; i++)
			{
				for (size_t j = 0; j != o_matrix.cols_size; j++)
				{
					output << o_matrix.matrix[i][j] << " ";
				}
				output << std::endl;
			}
		}

		return output;
	}
private:
	
	size_t rows_size;
	size_t cols_size;
	T** matrix;

	void CreateMatrix(size_t u_rows_size, size_t u_cols_size)
	{
		if (u_rows_size <= 0 && u_cols_size <= 0)
		{
			matrix = nullptr;
		}

		else
		{
			rows_size = u_rows_size;
			cols_size = u_cols_size;
			matrix = new T * [rows_size];
			for (size_t i = 0; i < rows_size; i++)
			{
				matrix[i] = new T[cols_size];
				for (size_t j = 0; j < cols_size; j++)
				{
					matrix[i][j] = T();
				}
			}
		}
	}
};

int main()
{
	setlocale(LC_ALL, "rus");

	Matrix<int> matrix1(5, 5);
	Matrix<int> matrix2(5, 5);
	Matrix <int> matrix3(5, 5);
	Matrix <double> matrix4(5, 5);

	matrix1.RandInitMatrix();
	matrix2.RandInitMatrix();
	//matrix3.RandInitMatrix();
	//matrix4.RandInitMatrix();

	std::cout << matrix1 << "\n" << matrix2;

	std::cout << matrix1 + matrix2;
	//matrix3.ShowMatrix();
	//matrix4.ShowMatrix();

	

	return 0;
}