using Microsoft.VisualStudio.TestTools.UnitTesting;
using Reliase;
using System;
using System.IO;
using System.Windows.Forms;

namespace UnitTestProject4
{
    [TestClass]
    public class UnitTest_Reliase
    {


        [TestMethod]
        public void TestButton1_Click_InvalidInputFile_ShowErrorMessage()
        {
            // Arrange
            var form = new Form1();
            form.Input.Text = "nonexistent_file.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.Key.Text = "2";
            form.Block.Text = "4";

            // Act
            form.button1_Click(null, null);

            // Assert
            Assert.AreEqual(System.Windows.Forms.DialogResult.None, form.DialogResult); ;
        }

        [TestMethod]
        public void TestButton1_Click_InvalidKey_ShowErrorMessage()
        {
            // Arrange
            var form = new Form1();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile1.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.Key.Text = "invalid_key";
            form.Block.Text = "4";

            // Act
            form.button1_Click(null, null);

            // Assert
            Assert.AreEqual(System.Windows.Forms.DialogResult.None, form.DialogResult);
        }

        [TestMethod]
        public void TestButton1_Click_InvalidOutputFile_ShowErrorMessage()
        {
            // Arrange
            var form = new Form1();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.output.Text = "nonexistent_file.txt";
            form.Key.Text = "2";
            form.Block.Text = "4";

            // Act
            form.button1_Click(null, null);

            // Assert
            Assert.AreEqual(System.Windows.Forms.DialogResult.None, form.DialogResult); ;
        }
        [TestMethod]
        public void TestButton1_Click_InvalidBlock_ShowErrorMessage()
        {
            // Arrange
            var form = new Form1();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.Key.Text = "2";
            form.Block.Text = "0";

            // Act
            form.button1_Click(null, null);

            // Assert
            Assert.AreEqual(System.Windows.Forms.DialogResult.None, form.DialogResult); ;
        }

        [TestMethod]
        public void TestButton1_Click_InvalidBlock1_ShowErrorMessage()
        {
            // Arrange
            var form = new Form1();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            form.Key.Text = "2";
            form.Block.Text = "0";

            // Act
            form.button1_Click(null, null);

            // Assert
            Assert.AreEqual(System.Windows.Forms.DialogResult.None, form.DialogResult); ;
        }

        [TestMethod]
        public void T1EncryptData1_KeyEquals1_ReturnsOriginalData()
        {
            // Arrange
            var data = "Hello, World!";
            var key = 1;
            var form = new Form1(); ; // Вам слід створити клас, в якому міститься ваша функція

            // Act
            var result = form.EncryptData1(data, key);

            // Assert
            Assert.AreEqual(data, result);
        }

        [TestMethod]
        public void T1EncryptData1_ValidDataAndKey_ReturnsEncryptedData()
        {
            // Arrange
            var data = "kvitka";
            var key = 3;
            var form = new Form1();

            // Act
            var result = form.EncryptData1(data, key);

            // Assert
            Assert.AreEqual("ivtakk", result);
        }
        [TestMethod]
        public void TestButton1_Click_InvalidInputFile_ShowErrorMessage_Caesar()
        {
            // Arrange
            string input = "no_exist.txt";
            string output = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            string key = "3";
            string block = "4";
            ClassCipher Cipp = new ClassCipher();


            // Act
            bool result = Cipp.ValidateInput(input, output, key, block);

            // Assert
            Assert.AreEqual(false, result); ;
        }

        [TestMethod]
        public void TestButton1_Click_InvalidKey_ShowErrorMessage_Caesar()
        {
            // Arrange
            string input = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            string output = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            string key = "invalid_key";
            string block = "4";
            ClassCipher Cipp = new ClassCipher();


            // Act
            bool result = Cipp.ValidateInput(input, output, key, block);

            // Assert
            Assert.AreEqual(false, result);
        }

        [TestMethod]
        public void TestButton1_Click_InvalidOutputFile_ShowErrorMessage_Caesar()
        {
            // Arrange
            string input = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            string output = "no_exist.txt";
            string key = "2";
            string block = "4";
            ClassCipher Cipp = new ClassCipher();


            // Act
            bool result = Cipp.ValidateInput(input, output, key, block);

            // Assert
            Assert.AreEqual(false, result);
        }
        [TestMethod]
        public void TestButton1_Click_InvalidBlock_ShowErrorMessage_Caesar()
        {
            // Arrange
            string input = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            string output = "D:\\MyProgects\\shifer\\shiferrr\\Betta\\TextFile2.txt";
            string key = "2";
            string block = "qweerdsf";
            ClassCipher Cipp = new ClassCipher();


            // Act
            bool result = Cipp.ValidateInput(input, output, key, block);

            // Assert
            Assert.AreEqual(false, result); 
        }
        
        [TestMethod]
        public void EncryptData_ValidDataAndKey_ReturnsEncryptedData()
        {
            // Arrange
            var data = "cryptology";
            var key = 8;
            var form = new Form3();

            // Act
            var result = form.EncryptData(data, key);

            // Assert
            Assert.AreEqual("kzgxbwtwog", result);
        }
        [TestMethod]
        public void EncryptData_ValidDataAndKey_ReturnsEncryptedData1()
        {
            // Arrange
            var data = "hello word";
            var key = 20;
            var form = new Form3();

            // Act
            var result = form.EncryptData(data, key);

            // Assert
            Assert.AreEqual("byffi qilx", result);
        }
        [TestMethod]
        public void Test_Block_Size_0()
        {
            // Arrange
            var form = new Form3();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_block_0.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_block_01.txt";
            form.Key.Text = "5";
            form.Block.Text = "0";

            // Act
            form.button1_Click(null, null);


            // Assert
            string outputFileName = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_block_01.txt";
            string result = File.ReadAllText(outputFileName);
            Assert.AreEqual("hwduytqtld", result); ;
        }
        [TestMethod]
        public void Test_Decrypt()
        {
            // Arrange
            var form = new Form4();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_Decrypt.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_Decrypt1.txt";
            form.Key.Text = "6";
            form.Block.Text = "5";

            // Act
            form.button1_Click(null, null);


            // Assert
            string inputFileName = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_Decrypt1.txt";
            string result = File.ReadAllText(inputFileName);
            Assert.AreEqual("hello word", result); ;
        }
        [TestMethod]
        public void Test_Hack()
        {
            // Arrange
            var form = new Form7();
            form.Input.Text = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_Hack.txt";
            form.output.Text = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_Hack1.txt";
            

            // Act
            form.button1_Click(null, null);


            // Assert
            string inputFileName = "D:\\MyProgects\\shifer\\shiferrr\\UnitTestProject4\\TextFile_Test_Hack1.txt";
            string result = File.ReadAllText(inputFileName);
            Assert.AreEqual("Cryptology is important to us", result); ;
        }





    }
}
