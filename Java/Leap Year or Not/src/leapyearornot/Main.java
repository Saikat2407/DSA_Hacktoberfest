package leapyearornot;
import java.time.Year;
import java.util.Scanner;
// Jan 22, 2022
//All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
public class Main {
    public static void main(String[] args) {
	int year;
    Scanner input=new Scanner (System.in);
    System.out.println("Enter the year : ");
    year = input.nextInt();
        if (year%2==0 && year%400!=0)
        {
            System.out.println( year+" is a Leap Year");
        }
        else
        {
            System.out.println(year+" is Not Leap Year");
        }
    }
}
