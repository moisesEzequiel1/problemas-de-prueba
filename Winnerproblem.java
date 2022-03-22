import java.io.File;
import java.util.*;
import java.lang.Math;
// Java Program to illustrate Reading from FileReader
// using BufferedReader Class
 
// Importing input output classes
import java.io.*;
 
// Main class
public class Winnerproblem {
 
    static Integer puntosjugador1 = 0;
    static Integer puntosjugador2 = 0;

    static List<Integer> lider1puntuaje = new ArrayList<Integer>(30);
    static List<Integer> lider2puntuaje = new ArrayList<Integer>(30);
    public void solver(int n1 , int n2) {
        puntosjugador1 += n1; 
        puntosjugador2 += n2; 
        int aux = puntosjugador1 - puntosjugador2; 
        if (aux > 0) { 
            lider1puntuaje.add(aux); 
        }else if (aux < 0){
            lider2puntuaje.add(Math.abs(aux)); 
        }
    }
    public void printresult() {
        int ventajajugador1 = Collections.max(lider1puntuaje);
        int ventajajugador2 = Collections.max(lider2puntuaje);
        if (ventajajugador1 > ventajajugador2) { 
            System.out.println("1 " + ventajajugador1);
        }else{ 
            System.out.println("2 " + ventajajugador2);
        }
    }
    public static void main(String[] args) throws Exception
    {
        Winnerproblem scoreboard = new Winnerproblem(); 
        File file = new File( args[0]);
        BufferedReader br = new BufferedReader(new FileReader(file));
        String st;
        int index = 0; 
        while ((st = br.readLine()) != null){ 
            if(index > 0){
                String[] tokens = st.split(" ");
                int n1 = Integer.parseInt(tokens[0]);
                int n2 = Integer.parseInt(tokens[1]);
                scoreboard.solver(n1, n2);
            }
        index += 1; 
        }
        br.close();
        scoreboard.printresult();
    }
}
