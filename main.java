import java.io.File;
import java.util.*;
import java.lang.Math;
// Java Program to illustrate Reading from FileReader
// using BufferedReader Class
 
// Importing input output classes
import java.io.*;
 
// Main class
public class main {
 
    static Integer p1 = 0;
    static Integer p2 = 0;

    static List<Integer> list1 = new ArrayList<Integer>(30);
    static List<Integer> list2 = new ArrayList<Integer>(30);

    public void solver(int n1 , int n2) {
        int aux = n1 - n2; 
        if (aux > 0) { 
            p1 +=aux;
            list1.add(aux); 
        }else if (aux < 0){
            p2+=Math.abs(aux);
            list2.add(Math.abs(aux)); 
        }
    }
    public void printresult(int r1,int r2) {
        if (r1 > r2) { 
            int highestNumber = Collections.max(list1);
            System.out.println("1: " + highestNumber);
        }else if (r1 < r2){ 
            int highestNumber = Collections.max(list2);
            System.out.println("2: " + highestNumber);
        }
    }
    // main driver method
    public static void main(String[] args) throws Exception
    {
        main main = new main(); 
        File file = new File( args[0]);
        BufferedReader br = new BufferedReader(new FileReader(file));
 
        // Declaring a string variable
        String st;
        // Condition holds true till
        // there is character in a string
        int index = 0; 
        while ((st = br.readLine()) != null){ 
            if(index > 0){
                String[] tokens = st.split(" ");
                int n1 = Integer.parseInt(tokens[0]);
                int n2 = Integer.parseInt(tokens[1]);
                main.solver(n1, n2);
            }
        index = index + 1; 
        }
        main.printresult(p1,p2);
    }
}
