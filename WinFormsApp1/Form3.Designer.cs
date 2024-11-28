namespace WinFormsApp1
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            button2 = new Button();
            button1 = new Button();
            textBox5 = new TextBox();
            textBox2 = new TextBox();
            textBox1 = new TextBox();
            textBox3 = new TextBox();
            SuspendLayout();
            // 
            // button2
            // 
            button2.Location = new Point(489, 109);
            button2.Name = "button2";
            button2.Size = new Size(94, 29);
            button2.TabIndex = 9;
            button2.Text = "Decrypt";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.Location = new Point(489, 10);
            button1.Name = "button1";
            button1.Size = new Size(94, 29);
            button1.TabIndex = 10;
            button1.Text = "Encrypt";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // textBox5
            // 
            textBox5.Location = new Point(12, 78);
            textBox5.Name = "textBox5";
            textBox5.PlaceholderText = "keySize";
            textBox5.Size = new Size(90, 27);
            textBox5.TabIndex = 4;
            textBox5.Text = "3";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(12, 45);
            textBox2.Name = "textBox2";
            textBox2.PlaceholderText = "output";
            textBox2.Size = new Size(342, 27);
            textBox2.TabIndex = 5;
            textBox2.Text = "D:\\cryptology\\PMK22_cryptology\\Ceasar\\output.txt";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(12, 12);
            textBox1.Name = "textBox1";
            textBox1.PlaceholderText = "input";
            textBox1.Size = new Size(342, 27);
            textBox1.TabIndex = 8;
            textBox1.Text = "D:\\cryptology\\PMK22_cryptology\\Ceasar\\input.txt";
            // 
            // textBox3
            // 
            textBox3.Location = new Point(264, 78);
            textBox3.Name = "textBox3";
            textBox3.PlaceholderText = "blockSize";
            textBox3.Size = new Size(90, 27);
            textBox3.TabIndex = 4;
            textBox3.Text = "3";
            // 
            // Form3
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(604, 183);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(textBox3);
            Controls.Add(textBox5);
            Controls.Add(textBox2);
            Controls.Add(textBox1);
            Name = "Form3";
            Text = "Form3";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button2;
        private Button button1;
        private TextBox textBox5;
        private TextBox textBox2;
        private TextBox textBox1;
        private TextBox textBox3;
    }
}