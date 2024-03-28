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
    public class cesarTests
    {
        
        
        [TestMethod()]
        public void EncipherTest()
        {
            var encryptionInstanceCesar = new cesar();
            string word = "Tree";
            int key = 3;
            string expectedEncryptedText = "Wuhh";

            string encryptedText = encryptionInstanceCesar.Encipher(word, key);

            Assert.AreEqual(expectedEncryptedText, encryptedText);
        }

        [TestMethod()]
        public void DecipherTest()
        {
            var encryptionInstance = new cesar();
            string inputText = "Wuhh";
            string correctText = "tree";
            int key = 3;

            string decryptedText = encryptionInstance.Decipher(inputText, key);

            Assert.AreEqual(correctText, decryptedText);
        }

        [TestMethod()]
        public void FrequencyAnalysisTest()
        {
            var encryptionInstance = new cesar();
            string inputText = "Wuhh";
            string correctTextF = "tree";

            string decryptedTextF = encryptionInstance.FrequencyAnalysis(inputText);

            Assert.AreEqual(correctTextF, decryptedTextF);
        }
        
    }
}