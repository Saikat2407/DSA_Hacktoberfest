package odd_or_even;

import java.util.Scanner;

// Jan 23, 2022
//All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
public class Main {

    public static void main(String[] args) {
	    int odd,even,n;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the number: ");
        n=input.nextInt();
        if (n%2==0)
        {
            System.out.println("The number "+n+" is even ");
        }
        else
        {
            System.out.println("The number "+n+" is odd ");
        }
    }
}
