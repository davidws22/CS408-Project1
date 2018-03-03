import java.util.Scanner;

public class main 
{
	public static void main(String[] args)
	{	
		Version1 v1 = new Version1();
		Version2 v2 = new Version2();
		Scanner sc = new Scanner(System.in);
		int input;
		while(true)
		{
			System.out.print("1. Version 1\n");
			System.out.print("2. Version 2\n");
			System.out.print("3. Exit\n");
			System.out.print("Please choose a selection: ");
			input = sc.nextInt();
			
			if(input == 1)
			{
				System.out.println("calling function 1");
				v1.version1(sc);
			}
			else if(input == 2)
			{
				System.out.println("calling function 2");
				v2.version2(sc);
			}
			else if(input == 3)
			{
				System.out.print("Exiting program...\n");
				break;
			}
			else
			{
				System.out.print("Invalid selection. Please try again...\n");
			}

		}//end menu
		sc.close();
	}

}
