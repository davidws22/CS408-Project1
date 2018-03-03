import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Version1 
{
	public void version1(Scanner sc)
	{
		int input = 0;
		List<Integer> set1 = new ArrayList<Integer>();
		List<Integer> set2 = new ArrayList<Integer>();
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
					if(set1.size() > 0)
						set1.clear();
					if(set2.size() > 0)
						set2.clear();
				}
				createSet(set1, set2);
				//System.out.println("this is after creating set: ");
				//System.out.println("set1 size = " + set1.size());
				//System.out.println("Set 2 size = " + set2.size());
				target = false;
				break;
			case 2:
				if(target)
				{
					System.out.print("Please enter set information first...\n");
					break;
				}
				Union(set1, set2);
				break;
			case 3:
				if(target)
				{
					System.out.print("Please enter set information first...\n");
					break;
				}
				Difference(set1, set2);
				break;
			case 4:
				if(target)
				{
					System.out.print("Please enter set information first...\n");
					break;
				}
				Intersection(set1, set2);
				break;
			case 5:
				System.out.print("Exiting version 1...\n");
				flag = false;
				if(set1.size() > 0)
					set1.clear();
				if(set2.size() > 0)
					set2.clear();
				return;
			default:
				System.out.print("Invalid selection. Please try again...\n");
			}//end switch
		}//end while
	}//end version 1

	private void Intersection(List<Integer> set1, List<Integer> set2) 
	{
		List<Integer> temp = new ArrayList<Integer>();
		boolean flag = true;

		if(set1.size() > 0 && set2.size() > 0)
		{
			for(int i = 0; i < set1.size(); i++)
			{
				if(set2.contains(set1.get(i)))
					flag = true;
			}
			for(int i = 0; i < set2.size(); i++)
			{
				if(set1.contains(set2.get(i)))
					flag = true;
			}
			if(flag)
			{
				for(int j = 0; j < set1.size(); j++)
				{
					for(int k = 0; k < set2.size(); k++)
					{
						if(set1.get(j) == set2.get(k))
						{
							if(temp.isEmpty())
								temp.add(set1.get(j));
							else
							{
								if(!temp.contains(set1.get(j)))
									temp.add(set1.get(j));
							}
						}
					}
				}
				if(temp.size() == 0)
					System.out.print("The intersection of set 1 and set 2 is { }\n");
				else
				{
					System.out.print("The intersection of set 1 and set 2 is {");
					for(int x = 0; x < temp.size(); x++)
					{
						System.out.print(temp.get(x));
						if((x+1) == temp.size())
							System.out.print("}\n");
						else
							System.out.print(", ");
					}
				}
			} //end if

			else
			{
				System.out.print("The intersection of set 1 and set 2 is : { }\n");
			}
		}
		else 
		{
			System.out.print("The intersection of set 1 and set 2 is : { }\n");
		}
	}

	private void Difference(List<Integer> set1, List<Integer> set2) 
	{
		if(set1.size() == 0)
		{
			System.out.print("The Difference between set 1 and set 2 is: {");
			for(int i = 0; i < set2.size(); i++)
			{
				System.out.print(set2.get(i));
				if(i+1 == set1.size())
					System.out.print("}");
				else
					System.out.print(", ");
			}
			System.out.println();
		}
		else if(set2.size() == 0)
		{
			System.out.print("The Difference between set 1 and set 2 is: {");
			for(int i = 0; i < set1.size(); i++)
			{
				System.out.print(set1.get(i));
				if(i+1 == set1.size())
					System.out.print("}");
				else
					System.out.print(", ");
			}
			System.out.println();
		}
		else if(set1.size() == 0 && set2.size() == 0)
			System.out.print("The Difference between set 1 and set 2 is : { }");
		else
		{
			int size = set1.size();
			List<Integer> DF = new ArrayList<Integer>();
			boolean flag = false;

			if(size > 0)
			{
				for(int j = 0; j < set1.size(); j++)
				{
					for(int k = 0; k < set2.size(); k++)
					{
						if(set1.get(j) == set2.get(k))
							flag = true;
					}
					if(flag == false)
						DF.add(set1.get(j));

					flag = false;
				}

				System.out.print("The set difference of set 1 and set 2 is: {"); 
				for(int i = 0; i < DF.size(); i++)
				{
					System.out.print(DF.get(i));
					if(i+1 == DF.size())
						System.out.print("}");
					else
						System.out.print(", ");
				}
				System.out.println();
			}
			else
			{
				System.out.print("The set difference of set 1 and set 2 is: { }\n");
			}
		}//end if-else block

	}

	private void Union(List<Integer> set1, List<Integer> set2)
	{
		if(set1.size()+set2.size() == 0)
		{
			System.out.print("The Union of set 1 and set 2 is { }\n");
			return;
		}
		else if(set1.size() == 0)
		{
			System.out.print("The Union of set 1 and set 2 is {");
			for(int i = 0; i < set2.size(); i++)
			{
				System.out.print(set2.get(i) + ", ");
			}
			System.out.print("}\n");
			return;
		}
		else if(set2.size() == 0)
		{
			System.out.print("The Union of set 1 and set 2 is {");
			for(int i = 0; i < set1.size(); i++)
			{
				System.out.print(set1.get(i) + ", ");
			}
			System.out.print("}\n");
		}
		else
		{
			int index = 0;
			List<Integer> UN = new ArrayList<Integer>();
			for(; index < set1.size(); index++)
				UN.add(set1.get(index));

			for( int i = 0; i < set2.size(); i++)
			{
				if(UN.contains(set2.get(i)));
				else
					UN.add(set2.get(i));
			}

			System.out.print("The Union of set 1 and set 2 is: {");
			for(int i = 0; i < UN.size(); i++)
			{
				System.out.print(UN.get(i));
				if(i+1 == UN.size())
					System.out.print("}");
				else
					System.out.print(", ");
			}
			System.out.println();
		}

	}

	private void createSet(List<Integer> set1, List<Integer> set2)
	{
		Scanner sc = new Scanner(System.in);
		boolean flag = true;
		int counter = 1;
		List<Integer> s1 = new ArrayList<Integer>();
		List<Integer> s2 = new ArrayList<Integer>();

		//counting number of integers are given for both set 1 and set 2 and assigning
		// them to m and n respectively
		while(flag)
		{
			System.out.print("Please enter integers for set " + counter + " separated by spaces: ");
			if(counter == 1)
			{
				String [] tokens = sc.nextLine().split("\\s");
				for(int i = 0; i < tokens.length; i++)
					s1.add(Integer.parseInt(tokens[i]));

			}
			if(counter == 2)
			{
				String [] tokens = sc.nextLine().split("\\s");
				for(int i = 0; i <tokens.length; i++)
					s2.add(Integer.parseInt(tokens[i]));
			}
			++counter;
			if(counter == 3)
				flag = false;
		}//end while
		
		//populating set 1
		if(s1.size() > 0)
		{
			for(int j = 0; j < s1.size(); j++)
			{
				if(set1.isEmpty())
				{
					set1.add(s1.get(j));
				}
				else
				{
					if(!set1.contains(s1.get(j)))
						set1.add(s1.get(j));
				}

			}
		}
		//populating set 2
		if(s2.size() > 0)
		{
			for(int j = 0; j < s2.size(); j++)
			{
				if(set2.isEmpty())
				{
					set2.add(s2.get(j));
				}
				else
				{
					if(!set2.contains(s2.get(j)))
						set2.add(s2.get(j));
				}

			}
		}
		//display sets
		System.out.print("Set 1 contains: {");
		for(int i = 0; i < set1.size(); i++)
		{
			System.out.print(set1.get(i));
			if(i + 1 == set1.size());
			else
				System.out.print(", ");
		}
		System.out.print("}\n");
		System.out.print("Set 2 contains: {");
		for(int i = 0; i < set2.size(); i++)
		{
			System.out.print(set2.get(i));
			if(i + 1 == set2.size());
			else
				System.out.print(", ");
		}
		System.out.print("}\n");
	}

}//end class version1
