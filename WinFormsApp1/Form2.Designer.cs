namespace WinFormsApp1
{
    partial class Form2
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
            openFileDialog1 = new OpenFileDialog();
            textBox1 = new TextBox();
            button1 = new Button();
            textBox3 = new TextBox();
            textBox5 = new TextBox();
            button2 = new Button();
            textBox2 = new TextBox();
            pBar = new ProgressBar();
            textBox4 = new TextBox();
            SuspendLayout();
            // 
            // openFileDialog1
            // 
            openFileDialog1.FileName = "openFileDialog1";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(23, 42);
            textBox1.Name = "textBox1";
            textBox1.PlaceholderText = "input";
            textBox1.Size = new Size(342, 27);
            textBox1.TabIndex = 0;
            textBox1.Text = "D:\\cryptology\\PMK22_cryptology\\Affine\\input.txt";
            textBox1.MouseClick += textBox1_MouseClick;
            // 
            // button1
            // 
            button1.Location = new Point(500, 40);
            button1.Name = "button1";
            button1.Size = new Size(94, 29);
            button1.TabIndex = 3;
            button1.Text = "Encrypt";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // textBox3
            // 
            textBox3.Location = new Point(23, 108);
            textBox3.Name = "textBox3";
            textBox3.PlaceholderText = "keyMatrix";
            textBox3.Size = new Size(342, 27);
            textBox3.TabIndex = 0;
            textBox3.Text = "D:\\cryptology\\PMK22_cryptology\\Affine\\keym.txt";
            textBox3.MouseClick += textBox1_MouseClick;
            textBox3.TextChanged += textBox3_TextChanged;
            // 
            // textBox5
            // 
            textBox5.Location = new Point(23, 171);
            textBox5.Name = "textBox5";
            textBox5.PlaceholderText = "keySize";
            textBox5.Size = new Size(81, 27);
            textBox5.TabIndex = 0;
            textBox5.Text = "3";
            textBox5.MouseClick += textBox1_MouseClick;
            // 
            // button2
            // 
            button2.Location = new Point(500, 139);
            button2.Name = "button2";
            button2.Size = new Size(94, 29);
            button2.TabIndex = 3;
            button2.Text = "Decrypt";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(23, 75);
            textBox2.Name = "textBox2";
            textBox2.PlaceholderText = "output";
            textBox2.Size = new Size(342, 27);
            textBox2.TabIndex = 0;
            textBox2.Text = "D:\\cryptology\\PMK22_cryptology\\Affine\\output.txt";
            textBox2.MouseClick += textBox1_MouseClick;
            textBox2.TextChanged += textBox2_TextChanged;
            // 
            // pBar
            // 
            pBar.Enabled = false;
            pBar.Location = new Point(-1, 309);
            pBar.Name = "pBar";
            pBar.Size = new Size(681, 29);
            pBar.TabIndex = 4;
            // 
            // textBox4
            // 
            textBox4.Location = new Point(23, 139);
            textBox4.Name = "textBox4";
            textBox4.PlaceholderText = "keyVector";
            textBox4.Size = new Size(342, 27);
            textBox4.TabIndex = 0;
            textBox4.Text = "D:\\cryptology\\PMK22_cryptology\\Affine\\keyv.txt";
            textBox4.MouseClick += textBox1_MouseClick;
            textBox4.TextChanged += textBox3_TextChanged;
            // 
            // Form2
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(681, 339);
            Controls.Add(pBar);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(textBox5);
            Controls.Add(textBox2);
            Controls.Add(textBox4);
            Controls.Add(textBox3);
            Controls.Add(textBox1);
            Name = "Form2";
            Text = "Form2";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private OpenFileDialog openFileDialog1;
        private TextBox textBox1;
        private Button button1;
        private TextBox textBox3;
        private TextBox textBox5;
        private Button button2;
        private TextBox textBox2;
        private ProgressBar pBar;
        private TextBox textBox4;
    }
}