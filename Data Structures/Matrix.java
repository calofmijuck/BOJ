public class Matrix {
    private double[][] arr;
    // private int row;
    // private int col;

    // n x n zero matrix
    public Matrix(int n) {

    }

    // row x col zero matrix
    public Matrix(int row, int col) {

    }

    // diagonal matrix
    public Matrix(double[] arr) {

    }

    // n x n identity matrix
    public static Matrix identity(int n) {
        return null;
    }

    // row size
    public int rowSize() {
        return 0;
    }

    // column size
    public int colSize() {
        return 0;
    }

    // get (i, j)-element
    public double get(int i, int j) {
        return 0;
    }

    // set (i, j)-element
    public void set(int i, int j, int val) {

    }

    // get i-th row vector
    public Vector getRow(int i) {
        return null;
    }

    // get i-th column vector
    public Vector getCol(int j) {
        return null;
    }

    // toString
    public String toString() {
        return null;
    }

    // equals
    public boolean equals(Object o) {
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