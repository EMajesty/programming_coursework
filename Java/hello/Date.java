package fi.lab.hello;

public class Date {
    private int day;
    private int month;
    private int year;

    public Date(){
        this(1,1,2020);
    }

    public Date(int day, int month, int year){
        if (!setValues(day, month, year))
            setValues(1,1,2020);
    }

    @Override
    public String toString() {
        return String.format("%02d.%02d.%04d", getDay(), getMonth(), getYear());
    }

    public boolean setValues(int day, int month, int year){
        if (year<1900) return false;
        if (month<1 || month>12) return false;
        if (day<1) return false;
        int maxDays[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear(year)) maxDays[2]=29;
        if (day>maxDays[month]) return false;
        setDay(day);
        setMonth(month);
        setYear(year);
        return true;
    }

    private boolean isLeapYear(int year){
        if (year%400==0) return true;    // eg. 2000 was a leap year
        if (year%100==0) return false;   // 1900 was not
        if (year%4==0)   return true;    // 2020 was
        return false;                   // rest are not
    }

    public int getDay() {
        return day;
    }

    private void setDay(int day) {
        this.day = day;
    }

    public int getMonth() {
        return month;
    }

    private void setMonth(int month) {
        this.month = month;
    }

    public int getYear() {
        return year;
    }

    private void setYear(int year) {
        this.year = year;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;   // if compared to object itself
        if (obj == null || getClass() != obj.getClass()) return false; 
        Date d = (Date)obj;
        if (this.getDay() == d.getDay() && this.getMonth() == d.getMonth() 
        && this.getYear() == d.getYear()) return true;
        return false;
    }

    @Override
    public int hashCode() {
        return getYear()*10000+getMonth()*100+getDay();
    }
}