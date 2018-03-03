import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Version2 
{
	void version2(Scanner sc)
	{
		int input = 0;
		set set1 = new set();
		set set2 = new set();
		boolean target = true;
		boolean flag = true;

		while(flag)
		{
			System.out.print("1. Enter sets\n");
			System.out.print("2. Union\n");
			System.out.print("3. Difference\n");
			System.out.print("4. Intersection\n");
			System.out.print("5. Return to main menu\n");
			System.out.print("Please choose a selection: ");
			input = sc.nextInt();

			switch(input)
			{
			case 1:
				if(target == false)
				{
					if(set1.getSize() > 0)
						set1.delete();
					if(set2.getSize() > 0)
						set2.delete();
				}
				set1.populate();
				set2.populate();
				set1.display();
				set2.display();
				target = false;
				break;
			case 2:
				if(target)
				{
					System.out.print("Please enter set information first...\n");
					break;
				}
				set1.union(set2);
				break;
			case 3:
				if(target)
				{
					System.out.print("Please enter set information first...\n");
					break;
				}
				set1.difference(set2);
				break;
			case 4:
				if(target)
				{
					System.out.print("Please enter set information first...\n");
					break;
				}
				set1.intersection(set2);
				break;
			case 5:
				System.out.print("Exiting version 1...\n");
				flag = false;
				if(set1.getSize() > 0)
					set1.delete();
				if(set2.getSize() > 0)
					set2.delete();
				return;
			default:
				System.out.print("Invalid selection. Please try again...\n");
			}//end switch
		}//end while
	}

}
