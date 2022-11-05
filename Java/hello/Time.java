package fi.lab.hello;

public class Time {
    private int hh;
    private int mm;

    public Time(){
        this(0,0);  // midnight
    }

    public Time(int hh, int mm){
        if (isValidHours(hh) && isValidMinutes(mm)){
            setHh(hh);
            setMm(mm);
        } else {    // if hh or mm is invalid --> let's init the object to midnight
            setHh(0);
            setMm(0);
        }
    }

    @Override
    public String toString() {
        return String.format("%02d:%02d", getHh(), getMm());
    }

    private boolean isValidHours(int hh){
        if (hh>=0 && hh<=23) return true;
        return false;
    }

    private boolean isValidMinutes(int mm){
        if (mm>=0 && mm<=59) return true;
        return false;
    }

    public int getHh() {
        return hh;
    }

    public void setHh(int hh) {
        if (isValidHours(hh))
            this.hh = hh;
    }

    public int getMm() {
        return mm;
    }

    public void setMm(int mm) {
        if (isValidMinutes(mm))
            this.mm = mm;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;   // if compared to object itself
        if (obj == null || getClass() != obj.getClass()) return false; 
        Time d = (Time)obj;
        if (this.getHh() == d.getHh() && this.getMm() == d.getMm()) return true;
        return false;
    }

    @Override
    public int hashCode() {
        return getHh()*100+getMm();
    }
}