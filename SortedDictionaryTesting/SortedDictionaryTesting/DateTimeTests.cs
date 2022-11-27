using System;
namespace Tests;

[TestClass]
public class DateTimeTests
{
    [TestMethod]
    [DataRow(2022, 12, 12)]
    [DataRow(2011, 11, 21)]
    [DataRow(2019, 9, 4)]
    public void Constructor(int year, int month, int day)
    {
        DateTime dateTime = new DateTime(year, month, day);
        Assert.AreEqual(dateTime.Year, year);
        Assert.AreEqual(dateTime.Month, month);
        Assert.AreEqual(dateTime.Day, day);
    }

    [TestMethod]
    [DataRow(2022, 12, 12)]
    [DataRow(2011, 11, 21)]
    [DataRow(2019, 9, 4)]
    public void ToString(int year, int month, int day)
    {
        DateTime dateTime = new DateTime(year, month, day);
        Assert.AreEqual($"{day:D2}/{month:D2}/{year} 00:00:00", dateTime.ToString());
    }

    [TestMethod]
    [DataRow("27/11/2000 00:00:00")]
    [DataRow("23/12/2022 00:00:00")]
    [DataRow("03/02/2019 00:00:00")]
    public void DateParseFromString(string date)
    {
        DateTime dateTime = DateTime.Parse(date);
        Assert.AreEqual(date, dateTime.ToString());
    }
    
}
