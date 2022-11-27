namespace Library;

public class Statistics
{
    public IEmployees Employees { get; set; }
    public Statistics(IEmployees employees)
    {
        this.Employees = employees;
    }

    public int computeAverageSalary()
    {
        int salaryTogether = 0;
        
        var allEmployeeIds = Employees.getAll();

        foreach (var employeeId in allEmployeeIds)
        {
            salaryTogether += Employees.getSalary(employeeId);
        }

        if (allEmployeeIds.Count() == 0)
            return 0;
        return salaryTogether / allEmployeeIds.Count();
    }
    public int getMinSalary()
    {
        int minimumSalary = -1;

        var allEmployeeIds = Employees.getAll();

        foreach (var employeeId in allEmployeeIds)
        {
            var currentSalary = Employees.getSalary(employeeId);

            if (minimumSalary == -1 || currentSalary < minimumSalary)
            {
                minimumSalary = currentSalary;
            }
        }

        if (minimumSalary == -1)
        { 
            return 0;
        }

        return minimumSalary;
    }
    public void printSalariesByName() // prints the list of pairs <name, salary> that is sorted by employee names
    {
        var allEmployeeIds = Employees.getAll();

        foreach (var employeeId in allEmployeeIds)
        {
            var salary = Employees.getSalary(employeeId);
            var name = Employees.getName(employeeId);

            Console.WriteLine(name + " has salary: " + salary);
        }
    }
}
