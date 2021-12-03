
#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <array>

// Matrix class.
template<class T, std::size_t N, std::size_t M>
class Matrix
{
public:
    std::array<std::array<T, M>, N> m{0};
    static const std::size_t num_rows{N};
    static const std::size_t num_cols{M};
    static constexpr std::array<std::size_t, 2> dim{N, M};

    Matrix()
    {
    }

    void SetMatrix(std::array<std::array<T, M>, N> mtx)
    {
        this->m = mtx;
    }

    void SetIdentityMatrix()
    {
        if(this->GetNumRows() == this->GetNumCols())
        {
            for(std::size_t i = 0; i < this->GetNumRows(); i++)
            {
                this->m[i][i] = 1;
            }
        }
    }

    void SetOnes()
    {
        for(std::size_t i = 0; i < this->GetNumRows(); i++)
        {
            for(std::size_t j = 0; j < this->GetNumCols(); j++)
            {
                this->m[i][j] = 1;
            }
        }
    }


    void SetZeroes()
    {
        for(std::size_t i = 0; i < this->GetNumRows(); i++)
        {
            for(std::size_t j = 0; j < this->GetNumCols(); j++)
            {
                this->m[i][j] = 0;
            }
        }
    }

    std::size_t GetNumRows()
    {
        return this->num_rows;
    }

    std::size_t GetNumCols()
    {
        return this->num_cols;
    }

    std::array<std::size_t, 2> GetDim()
    {
        return this->dim;
    }

    void PrintDim()
    {
        std::cout << this->dim[0] << " x " << this->dim[1] << std::endl;
    }

    void Show()
    {

        for(int i = 0; i < this->num_rows; i++)
        {
            for(int j = 0; j < this->num_cols; j++)
            {
                std::cout << this->m[i][j] << " ";
            }

            std::cout << "" << std::endl;
        }
    }

    friend Matrix<T, N, M> operator+ (Matrix<T, N, M>& a, Matrix<T, N, M>& b)
    {

        Matrix<T, N, M> c;

        std::array<std::size_t, 2> dim_a = a.GetDim();
        std::array<std::size_t, 2> dim_b = b.GetDim();

        if(dim_a[0] != dim_b[0] && dim_a[1] != dim_b[1])
        {
            std::cout << "ERROR: Cannot add two matrices of different dimensions..." << std::endl;
            return c;
        }

        for(std::size_t i = 0; i < a.GetNumRows(); i++)
        {
            for(std::size_t j = 0; j < b.GetNumCols(); j++)
            {
                c.m[i][j] = a.m[i][j] + b.m[i][j];
            }
        }


        return c;
    }

    friend Matrix<T, N, M> operator- (Matrix<T, N, M>& a, Matrix<T, N, M>& b)
    {

        Matrix<T, N, M> c;

        std::array<std::size_t, 2> dim_a = a.GetDim();
        std::array<std::size_t, 2> dim_b = b.GetDim();

        if(dim_a[0] != dim_b[0] && dim_a[1] != dim_b[1])
        {
            std::cout << "ERROR: Cannot subtract two matrices of different dimensions..." << std::endl;
            return c;
        }

        for(std::size_t i = 0; i < a.GetNumRows(); i++)
        {
            for(std::size_t j = 0; j < b.GetNumCols(); j++)
            {
                c.m[i][j] = a.m[i][j] - b.m[i][j];
            }
        }


        return c;
    }
    template<std::size_t K>
    friend Matrix<T, N, M> operator* (Matrix<T, N, K>& a, Matrix<T, K, M>& b)
    {

        Matrix<T, N, M> c;

        if(a.GetNumCols() != b.GetNumRows())
        {
            std::cout << "ERROR: Cannot perform Matrix multiplication on the given matrices..." << std::endl;
        }

        for(int i = 0; i < a.GetNumRows(); i++)
        {
            for(int j = 0; j < b.GetNumCols(); j++)
            {
                for(int k = 0; k < b.GetNumRows(); k++)
                {
                    c.m[i][j] += a.m[i][k] * b.m[k][j];
                }
            }
        }

        return c;
    }

    friend bool operator== (Matrix<T, N, M>& a, Matrix<T, N, M>& b)
    {
        if(N != M)
        {
            return false;
        }

        for(int i = 0; i < a.GetNumRows(); i++)
        {
            for(int j = 0; j < b.GetNumCols(); j++)
            {
                if(a.m[i][j] != b.m[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }

};

#endif
