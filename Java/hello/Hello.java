/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// usually the package naming convention is the company domain in reverse order,
// then package hierarchy

package fi.lab.hello;

import java.util.Collections;	
import java.util.Comparator;	
import java.util.List;

/*
*   - File name should be exactly the same as the class name
*     e.g: class Hello --> Hello.java
*   - Just one class per file!
*   - Any class can contain main() method
*     --> you should always either start the app with:
*           java fi.lab.hello.Hello
*       or (if you have a jar file):
*           java -jar Hello.jar
*       where the jar file (zip format) should contain manifest file where
*       the main class has been specified
*/

/**
 *
 * @author Lassi
 */
public class Hello {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // System.out is the standard out which directs to console
        System.out.println("Hello world from java oof");
        System.out.print("This is print() without trailing endline\n");
        Person p = new Person();
        System.out.println(p);
        p.setFname("Rami");
        p.setLname("Viskilä");
        System.out.println(p);
        p = new Person("Aino","Kaino",true);
        System.out.println(p);
        Date d = new Date(28,2,2020);
        System.out.println(d);
        Time t = new Time(23,59);
        System.out.println(t);
        Timestamp ts = new Timestamp();
        System.out.println(ts);
        ts = new Timestamp(d, t);
        System.out.println(ts);
        p = new Employee("Rami", "Laiska", false, 
                    new Timestamp(new Date(6,7,1981), new Time(13,12)), 234, 4000);
        System.out.println(p);
        Employee e = new Employee("Olli", "Ahkera", false, 
                     new Timestamp(new Date(5,6,1980), new Time(12,50)), 123, 4500);
        System.out.println(e);

        Persons perse = new Persons();
        perse.add(new Person());
        perse.add(e);
        perse.add(new Person());
        perse.add(p);
        perse.add(new Employee());
        perse.add(new Employee());
        perse.print();

        System.out.println("---------- map contents in Person lastname order ---");
        List<Person> lp = perse.getPersons();
        Collections.sort(lp);   // sort() in natural order 
        // (Person implements Comparable)
        //        for(Person pp : lp){
        //            System.out.println(pp);
        //        }
        lp.forEach((pp) -> System.out.println(pp));
        System.out.println("--- end of map contents in Person lastname order ---");

        System.out.println("---------- map contents in Person firstname order ---");

        // When we have used the Comparable interface already and if we need another
        // ways to compare data we can create classes who implements Comparator
        //Collections.sort(lp, new PersonFnameComparator());
        // Or, if we need the comparison class just once, it is quite common
        // to create an anonymous class who implemnets the necessary methods

        Collections.sort(lp, new Comparator<Person>() {
            @Override
            public int compare(Person o1, Person o2) {
                String s1 = o1.getFname() + " " + o1.getLname();
                String s2 = o2.getFname() + " " + o2.getLname();
                return s1.compareToIgnoreCase(s2);
            }
        }
        );
        lp.forEach((pp) -> System.out.println(pp));
        System.out.println("--- end of map contents in Person firstname order ---");

    }
    
}
