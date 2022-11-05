package fi.lab.hello;

public class Person implements Comparable<Person>{
    private String fname;
    private String lname;
    private boolean female;
    private Timestamp birth;

    public Person(){
        //setFname("Keijo");
        //setLname("Kuuppa");
        this("Keijo", "Kuuppa", false);
    }

    public Person(String fname, String lname) {
        //setFname(fname);
        //setLname(lname);
        this(fname, lname, false);
    }

    public Person(String fname, String lname, boolean female){
        this(fname, lname, female, new Timestamp());
    }

    public Person(String fname, String lname, boolean female, Timestamp birth){
        setFname(fname);
        setLname(lname);
        setFemale(female);
        setBirth(birth);
    }

    // Here we override the Object.toString() method
    @Override
    public String toString() {
        return getFname() + " " + getLname()+" is"+(isFemale()?" ":" not ")+"female"
        + " birth: " + getBirth();
    }

    public String getFname() {
        return fname;
    }

    public void setFname(String fname) {
        this.fname = fname;
    }

    public String getLname() {
        return lname;
    }

    public void setLname(String lname) {
        this.lname = lname;
    }

    public boolean isFemale() {
        return female;
    }

    public void setFemale(boolean female) {
        this.female = female;
    }

    public Timestamp getBirth() {
        return birth;
    }

    public void setBirth(Timestamp birth) {
        this.birth = birth;
    }

    @Override	
    public int compareTo(Person o) {	
        String s1 = this.getLname()+" "+this.getFname();	
        String s2 = o.getLname()+" "+o.getFname();	
        return s1.compareToIgnoreCase(s2);	
    }
}