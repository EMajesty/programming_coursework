package fi.lab.drawing;

public class Point {
    private int x;
    private int y;

    public Point(){
        this(0,0);
    }

    public Point(int x, int y){
        setX(x);
        setY(y);
    }

    @Override
    public String toString() {
        return String.format("(%d, %d)", getX(), getY()); // "(x,y)"
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}