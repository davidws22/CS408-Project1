import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
public class set 
{
	private	List<Integer> s;
	
	set()
	{
		s = new ArrayList<Integer>();
	}
	
	public int getSize()
	{
		return s.size();
	}
	public void delete()
	{
		s.clear();
	}
	public void populate()
	{
		List<Integer> s1 = new ArrayList<Integer>();
		Scanner sc = new Scanner(System.in);
		System.out.print("Please enter integers for this set: ");
		String [] tokens = sc.nextLine().split("\\s");
		for(int i = 0; i < tokens.length; i++)
			s1.add(Integer.parseInt(tokens[i]));
		if(s1.size() > 0)
		{
			for(int j = 0; j < s1.size(); j++)
			{
				if(s.isEmpty())
				{
					s.add(s1.get(j));
				}
				else
				{
					if(!s.contains(s1.get(j)))
						s.add(s1.get(j));
				}

			}
		}

	}
	public void display()
	{
		//display set
		if(s.size() == 0)
			System.out.println("This set contains: { }");

		else
		{
			System.out.print("This set contains: {");
			for(int i = 0; i < s.size(); i++)
			{
				System.out.print(s.get(i));
				if(i + 1 == s.size());
				else
					System.out.print(", ");
			}
			System.out.print("}\n");
		}
	}
	public void union(set store)
	{
		if(s.size()+store.getSize() == 0)
		{
			System.out.print("The Union of set 1 and set 2 is { }\n");
			return;
		}
		else if(s.size() == 0)
		{
			System.out.print("The Union of set 1 and set 2 is {");
			for(int i = 0; i < store.getSize(); i++)
			{
				System.out.print(store.s.get(i) + ", ");
			}
			System.out.print("}\n");
			return;
		}
		else if(store.getSize() == 0)
		{
			System.out.print("The Union of set 1 and set 2 is {");
			for(int i = 0; i < s.size(); i++)
			{
				System.out.print(s.get(i) + ", ");
			}
			System.out.print("}\n");
		}
		else
		{
			int index = 0;
			List<Integer> UN = new ArrayList<Integer>();
			for(; index < s.size(); index++)
				UN.add(s.get(index));

			for( int i = 0; i < store.getSize(); i++)
			{
				if(UN.contains(store.s.get(i)));
				else
					UN.add(store.s.get(i));
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
	public void difference(set store)
	{
		if(s.size() == 0)
		{
			System.out.print("The Difference between set 1 and set 2 is: {");
			for(int i = 0; i < store.getSize(); i++)
			{
				System.out.print(store.s.get(i));
				if(i+1 == s.size())
					System.out.print("}");
				else
					System.out.print(", ");
			}
			System.out.println();
		}
		else if(store.getSize() == 0)
		{
			System.out.print("The Difference between set 1 and set 2 is: {");
			for(int i = 0; i < s.size(); i++)
			{
				System.out.print(s.get(i));
				if(i+1 == s.size())
					System.out.print("}");
				else
					System.out.print(", ");
			}
			System.out.println();
		}
		else if(s.size() == 0 && store.getSize() == 0)
			System.out.print("The Difference between set 1 and set 2 is : { }");
		else
		{
			int size = s.size();
			List<Integer> DF = new ArrayList<Integer>();
			boolean flag = false;

			if(size > 0)
			{
				for(int j = 0; j < s.size(); j++)
				{
					for(int k = 0; k < store.getSize(); k++)
					{
						if(s.get(j) == store.s.get(k))
							flag = true;
					}
					if(flag == false)
						DF.add(s.get(j));

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
	public void intersection(set temp)
	{
		List<Integer> store = new ArrayList<Integer>();
		boolean flag = true;

		if(s.size() > 0 && temp.s.size() > 0)
		{
			for(int i = 0; i < s.size(); i++)
			{
				if(temp.s.contains(s.get(i)))
					flag = true;
			}
			for(int i = 0; i < temp.s.size(); i++)
			{
				if(s.contains(temp.s.get(i)))
					flag = true;
			}
			if(flag)
			{
				for(int j = 0; j < s.size(); j++)
				{
					for(int k = 0; k < temp.s.size(); k++)
					{
						if(s.get(j) == temp.s.get(k))
						{
							if(store.isEmpty())
								store.add(s.get(j));
							else
							{
								if(!store.contains(s.get(j)))
									store.add(s.get(j));
							}
						}
					}
				}
				if(store.size() == 0)
					System.out.print("The intersection of set 1 and set 2 is { }\n");
				else
				{
					System.out.print("The intersection of set 1 and set 2 is {");
					for(int x = 0; x < store.size(); x++)
					{
						System.out.print(store.get(x));
						if((x+1) == store.size())
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
}
