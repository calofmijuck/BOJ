import java.util.Arrays;

public class Matrix {
    private double[][] mat;
    private int row;
    private int col;

    // n x n zero matrix
    public Matrix(int n) {
        this(n, n);
    }

    // row x col zero matrix
    public Matrix(int row, int col) {
        if (row <= 0 || col <= 0)
            throw new IllegalArgumentException();
        mat = new double[row][col];
        this.row = row;
        this.col = col;
    }

    // initialize with 2d double array
    public Matrix(double[][] arr) {
        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException();
        mat = arr;
        row = arr.length;
        col = arr[0].length;
        for (int i = 1; i < row; ++i) {
            if (col != arr[i].length)
                throw new IllegalArgumentException();
        }
    }

    // diagonal matrix
    public Matrix(double[] arr) {
        if (arr == null || arr.length == 0)
            throw new IllegalArgumentException();
        mat = new double[arr.length][arr.length];
        for (int i = 0; i < arr.length; ++i)
            mat[i][i] = arr[i];
        row = arr.length;
        col = arr.length;
    }

    // n x n identity matrix
    public static Matrix identity(int n) {
        if (n <= 0)
            throw new IllegalArgumentException();
        double[] arr = new double[n];
        Arrays.fill(arr, 1);
        return new Matrix(arr);
    }

    // row size
    public int rowSize() {
        return row;
    }

    // column size
    public int colSize() {
        return col;
    }

    // get (i, j)-element
    public double get(int i, int j) {
        if (i < 0 || i >= row || j < 0 || j >= col)
            throw new IndexOutOfBoundsException();
        return mat[i][j];
    }

    // set (i, j)-element
    public void set(int i, int j, int val) {
        if (i < 0 || i >= row || j < 0 || j >= col)
            throw new IndexOutOfBoundsException();
        mat[i][j] = val;
    }

    // get i-th row vector
    public double[] getRow(int i) {
        if (i < 0 || i >= row)
            throw new IndexOutOfBoundsException();
        return mat[i];
    }

    // get i-th column vector
    public double[] getCol(int j) {
        if (j < 0 || j >= col)
            throw new IndexOutOfBoundsException();
        double[] arr = new double[row];
        for (int i = 0; i < row; ++i) {
            arr[i] = mat[i][j];
        }
        return arr;
    }

    // toString
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append('[');
        for (int i = 0; i < row; ++i) {
            sb.append(Arrays.toString(mat[i]));
            if (i != row - 1)
                sb.append(", ");
        }
        sb.append(']');
        return sb.toString();
    }

    // equals
    public boolean equals(Object o) {
        if (o instanceof Matrix) {
            Matrix m = (Matrix) o;
            if (row != m.rowSize() || col != m.colSize())
                return false;
            for (int i = 0; i < row; ++i) {
                if (!Arrays.equals(mat[i], m.getRow(i)))
                    return false;
            }
            return true;
        }
        return false;
    }

    // matrix addition
    public Matrix add(Matrix m) {
        return null;
    }

    // matrix subtraction
    public Matrix sub(Matrix m) {
        return null;
    }

    // matrix constant multiplication
    public Matrix mul(double d) {
        return null;
    }

    // matrix and vector multiplication
    public Vector mul(Vector v) {
        return null;
    }

    // matrix multiplication
    public Matrix matMul(Matrix m) {
        return null;
    }

    // matrix transpose
    public Matrix transpose() {
        double[][] arr = new double[col][row];
        for (int i = 0; i < col; ++i) {
            arr[i] = this.getCol(i);
        }
        return new Matrix(arr);
    }

    // matrix exponentiation
    public Matrix pow(int n) {
        return null;
    }

    // trace of matrix
    public double trace() {
        if (row != col) {
            throw new IllegalStateException();
        }
        double ret = 0;
        for (int i = 0; i < row; ++i)
            ret += mat[i][i];
        return ret;
    }

    // absolute value
    public double abs() {
        return 0.0;
    }

    // (Hard) determinant
    public double det() {
        return 0.0;
    }

    // (Hard) inverse
    public Matrix inv() {
        return null;
    }

    // (Hard) Linear equation solver
    public static Vector solve(Matrix m, Vector b) {
        return null;
    }
}
