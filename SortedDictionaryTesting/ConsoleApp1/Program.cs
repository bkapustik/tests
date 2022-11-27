using Library;

public class Employees : IEmployees
{
    public int CurrentKey { get; set; }
    public Dictionary<int, string> Names { get; set; }
    public Dictionary<int, int> Salaries { get; set; }
    public HashSet<int> IDs { get; set; }

    public Employees()
    {
        Names = new Dictionary<int, string>();
        Salaries = new Dictionary<int, int>();
        IDs = new HashSet<int>();
        CurrentKey = 0;
    }
    public int add(String name, int salary)
    {
        CurrentKey++;
        IDs.Add(CurrentKey);
        Names.Add(CurrentKey, name);
        Salaries.Add(CurrentKey, salary);
        return CurrentKey;
    }

    public HashSet<int> getAll()
    {
        return IDs;
    }

    public String getName(int id)
    {
        return Names[id];
    }

    public int getSalary(int id)
    {
        return Salaries[id];
    }

    public void changeSalary(int id, int newSalary)
    {
        Salaries[id] = newSalary;
    }
}

public class Program
{
    static void Main()
    {
        Employees Employees;
        Statistics Statistics;
        void Populate()
        {
            Employees = new Employees();

            Employees.add("boris", 999999);
            Employees.add("boris2", 888888);

            Statistics = new Statistics(Employees);
        }
        Populate();
        Statistics.printSalariesByName();

    }
}