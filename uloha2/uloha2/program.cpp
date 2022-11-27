#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Person
{
    public:
        string Name;
        int Age;
     
        Person(string Name, int Age)
        {
            this->Age = Age;
            this->Name = Name;
        }
};

class Database
{
    vector<Person> People;

    int ageToDelete;
    string nameToDelete;

    static bool compareByAge(Person person1, Person person2)
    {
        return (person1.Age < person2.Age);
    }

    static bool compareByName(Person person1, Person person2)
    {
        return person1.Name.compare(person2.Name);
    }

    public: 
        
        
        Database()
        {
            People = vector<Person>();
        }
        
        void insert(string Name, int Age)
        {
            People.push_back(Person(Name, Age));
        }

        void print()
        {
            for (int i = 0; i < People.size(); i++)
            {
                cout << "{ name: " << People[i].Name << ", age : " << People[i].Age << " }" << "\n";
            }
        }

        void sortByAge()
        {
            sort(People.begin(), People.end(), compareByAge);
        }

        void sortByName()
        {
            sort(People.begin(), People.end(), compareByName);
        }

        void removeByAge(int age)
        {
            vector<int> indexes = vector<int>();
            for (int i = 0; i < People.size(); i++)
            {
                if (People[i].Age == age)
                {
                    indexes.push_back(i);
                }
            }
            for (int i = 0; i < indexes.size(); i++)
            {
                People.erase(People.begin() + indexes[i]);
            }
        }

        void removeByName(string name)
        {
            vector<int> indexes = vector<int>();
            for (int i = 0; i < People.size(); i++)
            {
                if (People[i].Name == name)
                {
                    indexes.push_back(i);
                }
            }
            for (int i = 0; i < indexes.size(); i++)
            {
                People.erase(People.begin() + indexes[i]);
            }
        }
};

class Worker 
{
    string Line;
    vector<string> Commands;
    Database PeopleDatabase;

    public:
        Worker()
        {
            Commands = vector<string>();
            this->PeopleDatabase = Database();
        }

        void readDatabase()
        {
            string input;
            getline(cin, input);
            while (input != "exit")
            {
                Commands.push_back(input);
                getline(cin, input);
            }
        }

        void workDatabase()
        {
            string input;
            bool wasThereInsert = false;
            bool removeName = false;
            bool removeAge = false;
            for (int i = 0; i < Commands.size(); i++)
            {
                input = Commands[i];
                if (input == "insert")
                {
                    wasThereInsert = true;
                }
                else if (wasThereInsert)
                {
                    wasThereInsert = false;
                    vector<string> splitInput = splitByDelimeter(input, ' ');
                    int age;
                    
                    age = stoi(splitInput[1]);
                   
                    
                    PeopleDatabase.insert(splitInput[0], age);
                }
                else if (input == "print")
                {
                    PeopleDatabase.print();
                }
                else if (input == "sort_age")
                {
                    PeopleDatabase.sortByAge();
                }
                else if (input == "sort_name")
                {
                    PeopleDatabase.sortByName();
                }
                else if (input == "remove_name")
                {
                    removeName = true;
                }
                else if (input == "remove_age")
                {
                    removeAge = true;
                }
                else if (removeName)
                {
                    vector<string> splitInput = splitByDelimeter(input,' ');
                    if (splitInput.size() != 1)
                    {
                        cout << "Invalid Input";
                        return;
                    }
                    removeName = false;
                    PeopleDatabase.removeByName(input);
                }
                else if (removeAge)
                {
                    int age;
                    
                    age = stoi(input);
                    
                    PeopleDatabase.removeByAge(age);
                }
            }
        }

        vector<string> splitByDelimeter(string stringToSplit, char delimeter)
        {
            vector<string> Strings = vector<string>();
            string word;
            for (int i = 0; i < stringToSplit.length(); i++)
            {
                if (stringToSplit[i] != delimeter)
                {
                    word += stringToSplit[i];
                }
                else
                {
                    Strings.push_back(word);
                    word = string();
                }
            }
            Strings.push_back(word);
            return Strings;
        }
};

int main()
{
    Worker worker = Worker();
    worker.readDatabase();
    worker.workDatabase();
}
