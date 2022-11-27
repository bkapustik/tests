using Library;
using System.Text;

namespace Tests;

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


[TestClass]
public class StatisticsTests
{
    Employees Employees { get; set; }
    Statistics Statistics { get; set; }
    void PopulateWithNoEntries()
    {
        Employees = new Employees();
        Statistics = new Statistics(Employees);
    }
    void Populate()
    {
        Employees = new Employees();

        Employees.add("aaa", 48000);
        Employees.add("aab", 21000);
        Employees.add("aac", 25000);
        Employees.add("aad", 37000);
        Employees.add("aae", 51000);
        Employees.add("aaf", 121000);
        Employees.add("aag", 37000);
        Employees.add("aah", 44000);
        Employees.add("aai", 56000);
        Employees.add("aaj", 98000);
        Employees.add("aak", 74000);
        Employees.add("aal", 73000);
        Employees.add("aam", 47000);
        Employees.add("aan", 39000);
        Employees.add("aao", 38000);
        Employees.add("aap", 39000);

        Statistics = new Statistics(Employees);
    }

    void PopulateSmaller()
    {
        Employees = new Employees();

        Employees.add("boris", 999999);
        Employees.add("boris2", 888888);

        Statistics = new Statistics(Employees);
    } 
    
    [TestMethod]
    public void ComputeAverageSalary()
    {
        Populate();
        Assert.AreEqual(53000, Statistics.computeAverageSalary());
    }

    [TestMethod]
    public void ComputeAverageSalaryWithNoEntries()
    {
        PopulateWithNoEntries();
        Assert.AreEqual(0, Statistics.computeAverageSalary());
    }

    [TestMethod]
    public void GetMinSalary()
    {
        Populate();
        Assert.AreEqual(21000, Statistics.getMinSalary());
    }

    [TestMethod]
    public void GetMinSalaryWithNoentries()
    {
        PopulateWithNoEntries();
        Assert.AreEqual(0, Statistics.getMinSalary());
    }

    [TestMethod]
    public void PrintSalariesByName()
    {
        StringBuilder ConsoleOutput = new StringBuilder();
        Console.SetOut(new StringWriter(ConsoleOutput));
        ConsoleOutput.Clear();
        PopulateSmaller();
        Statistics.printSalariesByName();
        Assert.AreEqual("boris has salary: 999999\r\n" + "boris2 has salary: 888888\r\n", ConsoleOutput.ToString());
    }

    [TestMethod]
    public void PrintSalariesWithNoEntries()
    {
        StringBuilder ConsoleOutput = new StringBuilder();
        Console.SetOut(new StringWriter(ConsoleOutput));
        ConsoleOutput.Clear();
        PopulateWithNoEntries();
         Statistics.printSalariesByName();
        Assert.AreEqual("", ConsoleOutput.ToString());
    }
}
