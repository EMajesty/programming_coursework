package fi.lab.hello;
/*
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
*/
import java.util.*;

public class Persons {
    // HashMap holds the key-value-pairs by the key hashcode, not sorted
    //private Map<Timestamp,Person> persons = new HashMap<>();
    private Map<Timestamp,Person> persons = new TreeMap<>();
    
    // Map.put(key.value) adds a new key-value-pair or replaces if already
    // exists according the key..
    public Person add(Person p){
        return persons.put(p.getBirth(), p);
    }
    public Person remove(Timestamp ts){
        return persons.remove(ts);
    }
    public void print(){
        System.out.println("---------- Persons contents ----------");
        // java standard for each -construct which is READ ONLY!
        for(Person p : persons.values()){
            System.out.println(p);
        }
        System.out.println("---------- End of Persons contents ----------");
    }
    public List<Person> getPersons(){
        List<Person> lp = new Vector<>(); // alternative: LinkedList<>();
        for(Person p : persons.values()){
            lp.add(p);
        }
        return lp;
    }
}
