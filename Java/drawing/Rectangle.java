package fi.lab.drawing;

public class Rectangle extends Shape{
    private int height;
    private int width;

    public Rectangle() {
        this(100,200);
    }

    public Rectangle(int height, int width) {
        if(height>0 && width>0) {
            setHeight(height);
            setWidth(width);
        }
        else
        {
            setHeight(10);
            setWidth(20);
        }
    }

    @Override
    public String toString() {
        return "Rect: "+super.toString()+" H: "+getHeight()+" W: "+getWidth();
    }

    @Override
    public float area(){
        return getHeight()*getWidth();
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        if(height>0)
            this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        if(width>0)
            this.width = width;
    }
}