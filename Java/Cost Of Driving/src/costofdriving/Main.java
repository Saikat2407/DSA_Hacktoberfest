package costofdriving;
import java.util.Scanner;
// Cost of driving
//Jan 20, 2021
//All Copyright © goes to Hamim Reza Shammo (https://github.com/hrshammo/)
public class Main {
    public static void main(String[] args) {
        double distance, km_per_liter, per_liter_cost,cost;
        Scanner input = new Scanner(System.in);
        System.out.println("Enter the driving distance :");
        distance= input.nextDouble();
        System.out.println("Enter KM per liter :");
        km_per_liter= input.nextDouble();
        System.out.println("Enter per liter cost :");
        per_liter_cost= input.nextDouble();
        cost=((distance/km_per_liter)*per_liter_cost);
        System.out.println("The cost of Driving will "+cost+ " taka ");
    }
}
