import java.util.Arrays;

public class Vector {
    private double[] arr;
    private int size;

    public Vector(int size) {
        arr = new double[size];
        this.size = size;
    }

    public Vector(double[] arr) {
        this.arr = arr;
        this.size = arr.length;
    }

    public Vector add(Vector v) {
        if (v.size() != size) {
            throw new IllegalStateException();
        }
        Vector w = new Vector(size);
        for (int i = 0; i < size; ++i)
            w.set(i, arr[i] + v.get(i));
        return w;
    }

    public Vector sub(Vector v) {
        if (v.size() != size) {
            throw new IllegalStateException();
        }
        return this.add(v.mul(-1));
    }

    public Vector mul(double d) {
        Vector w = new Vector(size);
        for (int i = 0; i < size; ++i)
            w.set(i, d * arr[i]);
        return w;
    }

    public double dot(Vector v) {
        if (v.size() != size) {
            throw new IllegalStateException();
        }
        double ret = 0;
        for (int i = 0; i < size; ++i)
            ret += arr[i] * v.get(i);
        return ret;
    }

    public Vector proj(Vector v) {
        if (v.size() != size) {
            throw new IllegalStateException();
        }
        return v.mul(this.dot(v) / v.dot(v));
    }

    public double angle(Vector v) {
        if (v.size() != size) {
            throw new IllegalStateException();
        }
        return Math.acos(this.dot(v) / (this.length() * v.length()));
    }

    public double get(int i) {
        if (i < 0 || i > size - 1) {
            throw new IndexOutOfBoundsException();
        }
        return arr[i];
    }

    private void set(int i, double val) {
        if (i < 0 || i > size - 1) {
            throw new IndexOutOfBoundsException();
        }
        arr[i] = val;
    }

    public int size() {
        return this.size;
    }

    public double length() {
        return Math.sqrt(this.dot(this));
    }

    public String toString() {
        return Arrays.toString(arr);
    }

    public boolean equals(Object o) {
        if (o instanceof Vector) {
            Vector v = (Vector) o;
            for (int i = 0; i < size; ++i) {
                if (Math.abs(v.get(i) - arr[i]) <= 1e-4)
                    return false;
            }
            return true;
        } else {
            return false;
        }
    }
}