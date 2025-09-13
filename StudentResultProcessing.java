import java.util.*;
class Student {
    int[] marks;
    int total;
    double percentage;
    String result;

    Student(int[] marks) {
        this.marks = marks;
    }
}

class TotalThread extends Thread {
    Student s;
    TotalThread(Student s) { this.s = s; }

    public void run() {
        int sum = 0;
        for (int m : s.marks) {
            sum += m;
        }
        s.total = sum;
        System.out.println("Total Marks: " + s.total);
    }
}

class PercentageThread extends Thread {
    Student s;
    PercentageThread(Student s) { this.s = s; }

    public void run() {
        // Wait until total is calculated
        while (s.total == 0); // busy wait (not best but simple for demo)
        s.percentage = (double) s.total / (s.marks.length * 100) * 100;
        System.out.println("Percentage: " + s.percentage + "%");
    }
}

class ResultThread extends Thread {
    Student s;
    ResultThread(Student s) { this.s = s; }

    public void run() {
        // Wait until percentage is calculated
        while (s.percentage == 0.0); 
        s.result = (s.percentage >= 40) ? "Pass" : "Fail";
        System.out.println("Result: " + s.result);
    }
}

public class StudentResultProcessing {
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int[] marks = new int [5]; // Example data
        System.out.println("Enter Marks Of % subjects:");
        for(int i=0;i<5;i++)
        {
            marks[i]=sc.nextInt();
        }
        Student s = new Student(marks);

        Thread t1 = new TotalThread(s);
        Thread t2 = new PercentageThread(s);
        Thread t3 = new ResultThread(s);

        t1.start();
        t2.start();
        t3.start();
    }
}
