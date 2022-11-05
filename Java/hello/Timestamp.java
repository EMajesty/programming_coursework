package fi.lab.hello;

public class Timestamp implements Comparable<Timestamp>  {
    private Date date;
    private Time time;

    public Timestamp(){
        this(new Date(), new Time());
    }

    public Timestamp(Date date, Time time){
        setDate(date);
        setTime(time);
    }

    @Override
    public String toString() {
        return getDate()+" "+getTime();
    }



    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public Time getTime() {
        return time;
    }

    public void setTime(Time time) {
        this.time = time;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;   // if compared to object itself
        if (obj == null || getClass() != obj.getClass()) return false; 
        Timestamp d = (Timestamp)obj;
        if (this.getDate().equals(d.getDate()) && 
        this.getTime().equals(d.getTime())) return true;
        return false;
    }

    @Override
    public int hashCode() {
        return getDate().hashCode()*100 + getTime().hashCode();
    }

    // returns:
    // negative: this < o
    // zero: this == o
    // positive: this > o
    @Override
    public int compareTo(Timestamp o) {
        // beacuse Date.hashCode() and Time.hashCode() has been implemented
        // "correctly" by our purposes, we can use them as refences
        int t1 = this.hashCode();
        int t2 = o.hashCode();
        // if else if .. not the easiest..
	    // if(t1<t2) return -1;
	    // else if(t1==t2) return 0;
	    // else return 1;
        return t1-t2;
    }
}