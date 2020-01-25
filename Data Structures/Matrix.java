import java.util.Arrays;

public class Matrix {
    private double[][] mat;
    private int row;
    private int col;

    // n x n zero matrix
    public Matrix(int n) {
        this(0, 0);
    }

    // row x col zero matrix
    public Matrix(int row, int col) {
        mat = new double[row][col];
        this.row = row;
        this.col = col;
    }

    // initialize with 2d double array
    public Matrix(double[][] arr) {
        mat = arr;
        row = arr.length;
        col = arr[0].length;
    }

    // diagonal matrix
    public Matrix(double[] arr) {
        mat = new double[arr.length][arr.length];
        for (int i = 0; i < arr.length; ++i)
            mat[i][i] = arr[i];
        row = arr.length;
        col = arr.length;
    }

    // n x n identity matrix
    public static Matrix identity(int n) {
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
        return mat[i][j];
    }

    // set (i, j)-element
    public void set(int i, int j, int val) {
        mat[i][j] = val;
    }

    // get i-th row vector
    public Vector getRow(int i) {
        return new Vector(mat[i]);
    }

    // get i-th column vector
    public Vector getCol(int j) {
        double[] arr = new double[row];
        for (int i = 0; i < row; ++i) {
            arr[i] = mat[i][j];
        }
        return new Vector(arr);
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
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (mat[i][j] != m.get(i, j))
                        return false;
                }
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
        return null;
    }

    // matrix exponentiation
    public Matrix pow(int n) {
        return null;
    }

    // trace of matrix
    public double trace() {
        return 0;
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
