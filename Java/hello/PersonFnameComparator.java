package fi.lab.hello;

import java.util.Comparator;

public class PersonFnameComparator implements Comparator<Person> {

    @Override
    public int compare(Person o1, Person o2) {
        String s1 = o1.getFname()+" "+o1.getLname();
        String s2 = o2.getFname()+" "+o2.getLname();
        return s1.compareToIgnoreCase(s2);
    }
    
}
