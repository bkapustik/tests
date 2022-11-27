#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Cell {

};

class CellInt : public Cell{
    public: 
        int Value;

        CellInt(const int value)
        {
            Value = value;
        }
};

class CellString : public Cell{
    public: 
        string Value;

        CellString(const string value)
        {
            Value = value;
        }
};

class CellDouble : public Cell{
    public:
        double Value;

        CellDouble(const double value)
        {
            Value = value;
        }
};

enum TypeOfCell { t_int, t_double, t_string };

enum GroupOperation { MIN, MAX, SUM, gid };

class GroupFunction {
    private: 
        void getColumnNumber(string col, const vector<string>  head)
        {
            for (int i = 0 ; i < head.size(); i++)
            {   
                if (head[i] == col)
                {
                    ColumnNumber = i;
                }
            }
        }
    public: 
        GroupOperation operation;
        int ColumnNumber;

        GroupFunction(string selected, const vector<string> *head)
        {
            if (selected.size() > 5)
            {
                if (selected.substr(0,3) == "SUM")
                {
                    operation = SUM;
                }
                else if (selected.substr(0,3) == "MIN")
                {
                    operation = MIN;
                }
                else if (selected.substr(0,3) == "MAX")
                {
                    operation = MAX;
                }
                else 
                {
                    operation = gid;
                }
            }
            else 
            {
                operation = gid;
            }

            if (operation == gid)
            {
                getColumnNumber(selected, *head);
            }
            else 
            {
                getColumnNumber(selected.substr(4,selected.size() - 5), *head);
            }
        }
};

class Table
{
     public: 
        void getStringLine(const string &str, vector<string> &output)
        {
            string cell;
            stringstream ss(str);

            while (getline(ss, cell, ';'))
            {
                output.push_back(cell);
            }
        }

    
        vector<string> Head, stringTypes;
        vector<TypeOfCell> Types;
        int RowLength, ColumnLength, GroupByColumn;
        vector<vector<Cell>> Rows;
        vector<GroupFunction> OutputColumns;

        vector<vector<Cell>> GroupedRows;
        map<const Cell &, const int &> keyIndexesInGroupedRows;

        Table()
        {
            Head = vector<string>();
            stringTypes = vector<string>();
            Types = vector<TypeOfCell>();
            Rows = vector<vector<Cell>>();
            OutputColumns = vector<GroupFunction>();
        }

        void getHead(const string &head)
        {
            getStringLine(head, Head);
            RowLength = Head.size();
        }

        void getTypes(const string &types)
        {
            getStringLine(types, stringTypes);
            for (int i = 0; i < RowLength; i++)
            {   
                if (stringTypes[i] == "int") 
                {
                    Types.push_back(t_int);
                }
                else if (stringTypes[i] == "double")
                {
                    Types.push_back(t_double);
                }
                else 
                {
                    Types.push_back(t_string);
                }
            }
        }

        void getTableRow(const string *line)
        {
            vector<Cell> row = vector<Cell>();
            string cell;
            stringstream ss(*line);
        
            for (int i = 0; i < RowLength; i++)
            {
                getline(ss, cell, ';');
                switch(Types[i])
                {
                    case t_double : row.push_back(CellDouble(stod(cell))); break;
                    case t_int : row.push_back(CellInt(stoi(cell))); break;
                    case t_string : row.push_back(CellString(cell)); break;
                }
            }
            Rows.push_back(row);
        }

        void getNumberOfColumns(int num)
        {
            ColumnLength = num;
        }

        void getFunctionColumns(const string &groupLine)
        {
            string cell;
            stringstream ss(groupLine);
            
            getline(ss, cell, ' ');

            while (getline(ss, cell, ' '))
            {
                if (cell == "GROUP_BY")
                {
                    break;
                }
                if (cell[cell.size() - 1] == ',')
                {
                    OutputColumns.push_back(GroupFunction(cell.substr(0, cell.size() - 1), &Head));
                }
                else
                {
                    OutputColumns.push_back(GroupFunction(cell.substr(0, cell.size()), &Head));
                }
            }

            getline(ss, cell);

            for (int i = 0 ; i < Head.size(); i++)
            {   
                if (Head[i] == cell)
                {
                    GroupByColumn = i;
                }
            }
        }

        void GroupBy()
        {
            for (int i = 0; i < Rows.size(); i++)
            {
                if (keyIndexesInGroupedRows.find(Rows[i][GroupByColumn]) == keyIndexesInGroupedRows.end())
                {
                    
                }
            }
        }
};

int main()
{
    string line;
    string second;
    getline(cin, line);
    getline(cin, second);
    Table table = Table();

    table.getHead(line);
    table.getFunctionColumns(second);

    for (int i = 0; i < table.OutputColumns.size(); i++)
    {
        cout << " column number " << table.OutputColumns[i].ColumnNumber << " operation " << table.OutputColumns[i].operation << "\n";
    }
    cout << table.GroupByColumn;

    return 0;
}