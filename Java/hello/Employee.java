package fi.lab.hello;


// java accepts just single inheritance because multiple inheritances (like in c++)
// has some problems. Java has a workaround: a class can implement several interfaces

public class Employee extends Person {
    private int id;
    private float salary;

    public Employee(){
        this("Rami", "Rasvanahka", false, new Timestamp(), 666, 3000.0f);
    }

    public Employee(String fname, String lname, boolean female, Timestamp birth, 
    int id, float salary){
        //setFname(fname);
        //setLname(lname);
        //setFemale(female);
        //setBirth(birth);
        super(fname, lname, female, birth); // super() is a call to parent constructor
        setId(id);
        setSalary(salary);
    }

    @Override
    public String toString() {
        // if we want to refer an overridden method in parent class
        // we have to call super.method()
        return super.toString() + " id: " + getId() + " salary: " + getSalary();
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public float getSalary() {
        return salary;
    }

    public void setSalary(float salary) {
        this.salary = salary;
    }
}