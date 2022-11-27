namespace Tests;

[TestClass]
public class DictionaryTests
{
    SortedDictionary<int, string> Dictionary = new SortedDictionary<int, string>();

    public void Populate()
    {
        Dictionary.Add(1, "hello");
        Dictionary.Add(2, "no");
    }

    [TestMethod]
    public void AddNewKey()
    {
        Assert.IsTrue(!Dictionary.ContainsKey(1));
        Assert.IsTrue(Dictionary.TryAdd(1, "hello"));
        Assert.IsTrue(Dictionary.ContainsKey(1));
        Assert.IsTrue(Dictionary[1] == "hello");
    }

    [TestMethod]
    public void AddAlreadyExistingKey()
    {
        Populate();
        Assert.IsTrue(Dictionary.Count == 2);
        Assert.IsFalse(Dictionary.TryAdd(1, "helloo"));
    }

    [TestMethod]
    public void RemovePresentMapping()
    {
        Populate();
        Assert.IsTrue(Dictionary.Count == 2);
        Assert.IsTrue(Dictionary.ContainsKey(1));
        Dictionary.Remove(1);
        Assert.IsFalse(Dictionary.ContainsKey(1));
    }

    [TestMethod]
    public void RemoveAllMappings()
    {
        Populate();
        Assert.IsTrue(Dictionary.Count == 2);
        Dictionary.Clear();
        Assert.IsTrue(Dictionary.Count == 0);
    }

    [TestMethod]
    public void GetValue()
    {
        Populate();
        Assert.IsTrue(Dictionary.Count == 2);
        Assert.AreEqual(Dictionary[1], "hello");
    }

    [TestMethod]
    public void TryGetNotExistentValue()
    {
        string value;
        Populate();
        Assert.IsTrue(Dictionary.Count == 2);
        Assert.IsFalse(Dictionary.TryGetValue(3,out value));
    }

    [TestMethod]
    public void FailingTest()
    {
        Assert.IsTrue(Dictionary.ContainsKey(1),"The Dictionary does not contain this key");
    }
}