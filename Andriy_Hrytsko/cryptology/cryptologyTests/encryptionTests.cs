using Microsoft.VisualStudio.TestTools.UnitTesting;
using cryptology;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cryptology.Tests
{
    [TestClass()]
    public class encryptionTests
    {
        private encryption encryptionForm;

        [TestInitialize]
        public void SetUp()
        {
            encryptionForm = new encryption();
        }

        [TestMethod()]
        public void EncryptTest()
        {
            // Arrange
            string text = "hello world";
            int height = 3;
            int length = 4;
            string expected = "Hlerd lolwo";

            // Act
            string encryptedText = encryptionForm.Encrypt(text, height, length);

            // Assert
            Assert.AreEqual(expected, encryptedText);
        }

        [TestMethod()]
        public void ReadTextFromFileAsyncTest()
        {
            // Arrange
            string filePath = "testfile.txt";
            string expectedText = "Hello, this is a test file.";

            // Create a test file
            File.WriteAllText(filePath, expectedText);

            // Act
            string result = encryptionForm.ReadTextFromFileAsync(filePath).Result;

            // Assert
            Assert.AreEqual(expectedText, result);

            // Clean up
            File.Delete(filePath);
        }

        [TestMethod()]
        public void WriteTextToFileAsyncTest()
        {
            // Arrange
            string filePath = "testfile.txt";
            string text = "This is a test text.";

            // Act
            encryptionForm.WriteTextToFileAsync(filePath, text).Wait();

            // Assert
            Assert.IsTrue(File.Exists(filePath));

            // Clean up
            File.Delete(filePath);
        }
    }
}