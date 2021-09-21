// The Stock program is following the MVC design template and this is our controller object.
// The main functionality for buying and selling the stocks are in this controller object.
// This is the ONLY file you may edit

import java.util.LinkedList;
import java.util.Scanner;

public class Controller {
	
	public Controller() {
		LinkedList<Stock> googList = new LinkedList<Stock>();
		LinkedList<Stock> amazList = new LinkedList<Stock>();
		Scanner input = new Scanner(System.in);
		
		do {
			System.out.print("Enter 1 for Google stock or 2 for Amazon, 3 to quit: ");
			int stockSelect = input.nextInt();
			if(stockSelect == 3)
				break;
			System.out.print("Input 1 to buy, 2 to sell: ");
			int controlNum = input.nextInt();
			System.out.print("How many stocks: ");
			int quantity = input.nextInt();
			
			if(controlNum == 1) {
				System.out.print("At what price: ");
				double price = input.nextDouble();
				if(stockSelect == 1) {
					Controller.buyStock(googList, "Google", quantity, price);
				}
				else
					Controller.buyStock(amazList, "Amazon", quantity, price);
			}
			else {
				System.out.print("Press 1 for LIFO accounting, 2 for FIFO accounting: ");
				controlNum = input.nextInt();
				if(controlNum == 1) {
					if(stockSelect == 1)
						Controller.sellLIFO(googList, quantity);
					else
						Controller.sellLIFO(amazList, quantity);
				}
				else {
					if(stockSelect == 1)
						Controller.sellFIFO(googList, quantity);
					else
						Controller.sellFIFO(amazList, quantity);
				}
			}
			
		} while(true);
		input.close();
	}
			
	public static void buyStock(LinkedList<Stock> list, String name, int quantity, double price) {
		Stock temp = new Stock(name,quantity,price);
		list.push(temp);
		System.out.printf("You bought %d shares of %s stock at $%.2f per share %n", quantity, name, price);
	}
	
	public static void sellLIFO(LinkedList<Stock> list, int numToSell) {
	    // You need to write the code to sell the stock using the LIFO method (Stack)
	    // You also need to calculate the profit/loss on the sale
	    double total = 0; // this variable will store the total after the sale
	    double profit = 0; // the price paid minus the sale price, negative # means a loss
	    int size = list.size();
	    
	    if (list.size() < numToSell)
	    {
	    	System.out.print("You do not have that many stocks.");
	    }
	    else
	    {
	    	for(int i = size; 0 < i; i--)
		    {
          list.get(i).getPrice();
		    }
		    
			System.out.printf("You sold %d shares of %s stock at %.2f per share %n", numToSell, list.element().getName(), total/numToSell);
		    System.out.printf("You made $%.2f on the sale %n", profit);
	    }
	}
	
	public static void sellFIFO(LinkedList<Stock> list, int numToSell) {
	    // You need to write the code to sell the stock using the FIFO method (Queue)
	    // You also need to calculate the profit/loss on the sale
	    double total = 0; // this variable will store the total after the sale
	    double profit = 0; // the price paid minus the sale price, negative # means a loss
		System.out.printf("You sold %d shares of %s stock at %.2f per share %n", numToSell, list.element().getName(), total/numToSell);
	    System.out.printf("You made $%.2f on the sale %n", profit);
	}
	
	
}
