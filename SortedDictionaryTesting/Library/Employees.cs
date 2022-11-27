using System.Collections.Generic;

namespace Library;
public interface IEmployees
{
    public int add(String name, int salary); // returns ID
    public HashSet<int> getAll(); // returns a set of IDs
    public String getName(int id);
    public int getSalary(int id);
    public void changeSalary(int id, int newSalary);
}
