package fi.lab.drawing;

public class Shape{
    private Point position;
    private String name;

    public Shape() {
        this(new Point(), "AShape");
    }

    public Shape(Point position, String name) {
        setPosition(position);
        setName(name);
    }

    @Override
    public String toString() {
        return "Name: "+getName()+" Pos: "+getPosition();
    }

    float area() {
        return 0.0f;
    }

    public Point getPosition() {
        return position;
    }

    public void setPosition(Point position) {
        this.position = position;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    
}