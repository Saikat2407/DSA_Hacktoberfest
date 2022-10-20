package areaofacircle;
import java.util.Scanner;
import java.lang.Math;

// Area Of A Circle
public class Main {
    //Jan 20, 2021
    //All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
    public static void main(String[] args) {
            Scanner input = new Scanner(System.in);
            double r,area;
        final double PI=3.1416;
        System.out.println("Enter the radious:");
        r=input.nextDouble();
        if(r>0)
        {
            // The area of a circle is pi times the radius squared (area = π*r²).
            area=PI*(Math.pow(r,2));
            System.out.println("Area will be:"+area);
        }
        else
        {
            System.out.println("Invalid input");
        }

    }
}
