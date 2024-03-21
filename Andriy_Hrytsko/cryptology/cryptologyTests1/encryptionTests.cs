using Microsoft.VisualStudio.TestTools.UnitTesting;
using cryptology;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;


namespace cryptology.Tests
{
    [TestClass()]
    public class encryptionTests
    {
        [TestMethod]
        public async Task EncryptAsync_ValidInput_ReturnsEncryptedText()
        {
           
            var encryptionInstance = new railfance();
            string inputText = "cryptology";
            int key = 3;
            string expectedEncryptedText = "ylrpooyctg";

            
            string encryptedText = encryptionInstance.EncryptAsync(inputText, key);

            Assert.AreEqual(expectedEncryptedText, encryptedText);
        }


        [TestMethod]
        public async Task EncryptAsync_KeyOne_ReturnsOriginalText()
        {
            
            var encryptionInstance = new railfance();
            string inputText = "Hello World!";
            int key = 1;

            string encryptedText = encryptionInstance.EncryptAsync(inputText, key);

            Assert.AreEqual(inputText, encryptedText);
        }

        [TestMethod]
        public async Task EncryptAsync_EmptyInput_ReturnsEmptyString()
        {
      
            var encryptionInstance = new railfance();
            string inputText = "";
            int key = 3;

           
            string encryptedText = encryptionInstance.EncryptAsync(inputText, key);

            Assert.AreEqual(inputText, encryptedText);
        }

    }
}