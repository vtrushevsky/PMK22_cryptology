namespace WinFormsApp1
{
    partial class RailFence
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            textBox1 = new TextBox();
            button1 = new Button();
            textBox2 = new TextBox();
            textBox3 = new TextBox();
            textBox4 = new TextBox();
            textBox5 = new TextBox();
            textBox6 = new TextBox();
            button_dec = new Button();
            label1 = new Label();
            button2 = new Button();
            textBox7 = new TextBox();
            textBox8 = new TextBox();
            textBox9 = new TextBox();
            textBox10 = new TextBox();
            label2 = new Label();
            button3 = new Button();
            label3 = new Label();
            label4 = new Label();
            label5 = new Label();
            label6 = new Label();
            textBox11 = new TextBox();
            label7 = new Label();
            button4 = new Button();
            label8 = new Label();
            textBox12 = new TextBox();
            textBox13 = new TextBox();
            button5 = new Button();
            label9 = new Label();
            label10 = new Label();
            label11 = new Label();
            textBox14 = new TextBox();
            SuspendLayout();
            // 
            // textBox1
            // 
            textBox1.Location = new Point(98, 157);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(326, 27);
            textBox1.TabIndex = 0;
            textBox1.Text = "Enter file path which need to be encrypted";
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(214, 235, 224);
            button1.Location = new Point(107, 239);
            button1.Name = "button1";
            button1.Size = new Size(110, 38);
            button1.TabIndex = 1;
            button1.Text = "Encrypte file";
            button1.UseVisualStyleBackColor = false;
            button1.Click += ButtonEcrypted;
            // 
            // textBox2
            // 
            textBox2.Location = new Point(98, 124);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(108, 27);
            textBox2.TabIndex = 2;
            textBox2.Text = "Enter key";
            // 
            // textBox3
            // 
            textBox3.Location = new Point(98, 190);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(326, 27);
            textBox3.TabIndex = 3;
            textBox3.Text = "Enter file path to put encrypted";
            // 
            // textBox4
            // 
            textBox4.Location = new Point(541, 190);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(326, 27);
            textBox4.TabIndex = 4;
            textBox4.Text = "Enter file path to put decrypted";
            // 
            // textBox5
            // 
            textBox5.Location = new Point(541, 157);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(326, 27);
            textBox5.TabIndex = 5;
            textBox5.Text = "Enter file path to encrypted";
            // 
            // textBox6
            // 
            textBox6.Location = new Point(541, 124);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(108, 27);
            textBox6.TabIndex = 6;
            textBox6.Text = "Enter key";
            // 
            // button_dec
            // 
            button_dec.BackColor = Color.FromArgb(214, 235, 224);
            button_dec.Location = new Point(541, 239);
            button_dec.Name = "button_dec";
            button_dec.Size = new Size(110, 38);
            button_dec.TabIndex = 7;
            button_dec.Text = "Decrypte file";
            button_dec.UseVisualStyleBackColor = false;
            button_dec.Click += ButtonDecrypted;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(98, 492);
            label1.Name = "label1";
            label1.Size = new Size(147, 29);
            label1.TabIndex = 8;
            label1.Text = "Encrypted word: ";
            // 
            // button2
            // 
            button2.BackColor = Color.FromArgb(214, 235, 224);
            button2.Location = new Point(112, 533);
            button2.Name = "button2";
            button2.Size = new Size(94, 29);
            button2.TabIndex = 9;
            button2.Text = "Encrypte";
            button2.UseVisualStyleBackColor = false;
            button2.Click += ButtonEn;
            // 
            // textBox7
            // 
            textBox7.Location = new Point(98, 451);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(251, 27);
            textBox7.TabIndex = 10;
            textBox7.Text = "Word";
            // 
            // textBox8
            // 
            textBox8.Location = new Point(98, 405);
            textBox8.Name = "textBox8";
            textBox8.Size = new Size(108, 27);
            textBox8.TabIndex = 11;
            textBox8.Text = "Enter key";
            // 
            // textBox9
            // 
            textBox9.Location = new Point(375, 405);
            textBox9.Name = "textBox9";
            textBox9.Size = new Size(108, 27);
            textBox9.TabIndex = 12;
            textBox9.Text = "Enter key";
            // 
            // textBox10
            // 
            textBox10.Location = new Point(375, 451);
            textBox10.Name = "textBox10";
            textBox10.Size = new Size(249, 27);
            textBox10.TabIndex = 13;
            textBox10.Text = "Word";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(375, 492);
            label2.Name = "label2";
            label2.Size = new Size(146, 29);
            label2.TabIndex = 14;
            label2.Text = "Decrypted word: ";
            // 
            // button3
            // 
            button3.BackColor = Color.FromArgb(214, 235, 224);
            button3.Location = new Point(389, 533);
            button3.Name = "button3";
            button3.Size = new Size(94, 29);
            button3.TabIndex = 15;
            button3.Text = "Decrypte";
            button3.UseVisualStyleBackColor = false;
            button3.Click += ButtonDe;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Sitka Display", 19.8F, FontStyle.Bold, GraphicsUnit.Point);
            label3.Location = new Point(375, 24);
            label3.Name = "label3";
            label3.Size = new Size(280, 48);
            label3.TabIndex = 30;
            label3.Text = "Rail fence cipher";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label4.Location = new Point(75, 77);
            label4.Name = "label4";
            label4.Size = new Size(160, 33);
            label4.TabIndex = 31;
            label4.Text = "Work with files";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label5.Location = new Point(75, 353);
            label5.Name = "label5";
            label5.Size = new Size(180, 33);
            label5.TabIndex = 32;
            label5.Text = "Work with words";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label6.Location = new Point(661, 353);
            label6.Name = "label6";
            label6.Size = new Size(220, 33);
            label6.TabIndex = 33;
            label6.Text = "Decrypte without key";
            // 
            // textBox11
            // 
            textBox11.Location = new Point(671, 405);
            textBox11.Name = "textBox11";
            textBox11.Size = new Size(249, 27);
            textBox11.TabIndex = 34;
            textBox11.Text = "Word";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label7.Location = new Point(671, 447);
            label7.Name = "label7";
            label7.Size = new Size(146, 29);
            label7.TabIndex = 35;
            label7.Text = "Decrypted word: ";
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(214, 235, 224);
            button4.Location = new Point(690, 495);
            button4.Name = "button4";
            button4.Size = new Size(94, 29);
            button4.TabIndex = 36;
            button4.Text = "Decrypte";
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label8.Location = new Point(1008, 77);
            label8.Name = "label8";
            label8.Size = new Size(220, 33);
            label8.TabIndex = 37;
            label8.Text = "Decrypte without key";
            // 
            // textBox12
            // 
            textBox12.Location = new Point(1008, 124);
            textBox12.Name = "textBox12";
            textBox12.Size = new Size(326, 27);
            textBox12.TabIndex = 38;
            textBox12.Text = "Enter file path to encrypted";
            // 
            // textBox13
            // 
            textBox13.Location = new Point(1008, 157);
            textBox13.Name = "textBox13";
            textBox13.Size = new Size(326, 27);
            textBox13.TabIndex = 39;
            textBox13.Text = "Enter file path to put decrypted";
            // 
            // button5
            // 
            button5.BackColor = Color.FromArgb(214, 235, 224);
            button5.Location = new Point(1008, 239);
            button5.Name = "button5";
            button5.Size = new Size(110, 38);
            button5.TabIndex = 40;
            button5.Text = "Decrypte file";
            button5.UseVisualStyleBackColor = false;
            button5.Click += button5_Click;
            // 
            // label9
            // 
            label9.AutoSize = true;
            label9.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label9.Location = new Point(1008, 196);
            label9.Name = "label9";
            label9.Size = new Size(71, 29);
            label9.TabIndex = 41;
            label9.Text = "Status: ";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label10.Location = new Point(1041, 425);
            label10.Name = "label10";
            label10.Size = new Size(170, 33);
            label10.TabIndex = 42;
            label10.Text = "Execution time: ";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label11.Location = new Point(1041, 336);
            label11.Name = "label11";
            label11.Size = new Size(108, 33);
            label11.TabIndex = 43;
            label11.Text = "Block size";
            // 
            // textBox14
            // 
            textBox14.Location = new Point(1041, 372);
            textBox14.Name = "textBox14";
            textBox14.Size = new Size(249, 27);
            textBox14.TabIndex = 44;
            textBox14.Text = "0";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = SystemColors.GradientInactiveCaption;
            ClientSize = new Size(1394, 597);
            Controls.Add(textBox14);
            Controls.Add(label11);
            Controls.Add(label10);
            Controls.Add(label9);
            Controls.Add(button5);
            Controls.Add(textBox13);
            Controls.Add(textBox12);
            Controls.Add(label8);
            Controls.Add(button4);
            Controls.Add(label7);
            Controls.Add(textBox11);
            Controls.Add(label6);
            Controls.Add(label5);
            Controls.Add(label4);
            Controls.Add(label3);
            Controls.Add(button3);
            Controls.Add(label2);
            Controls.Add(textBox10);
            Controls.Add(textBox9);
            Controls.Add(textBox8);
            Controls.Add(textBox7);
            Controls.Add(button2);
            Controls.Add(label1);
            Controls.Add(button_dec);
            Controls.Add(textBox6);
            Controls.Add(textBox5);
            Controls.Add(textBox4);
            Controls.Add(textBox3);
            Controls.Add(textBox2);
            Controls.Add(button1);
            Controls.Add(textBox1);
            ForeColor = Color.Black;
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private TextBox textBox1;
        private Button button1;
        private TextBox textBox2;
        private TextBox textBox3;
        private TextBox textBox4;
        private TextBox textBox5;
        private TextBox textBox6;
        private Button button_dec;
        private Label label1;
        private Button button2;
        private TextBox textBox7;
        private TextBox textBox8;
        private TextBox textBox9;
        private TextBox textBox10;
        private Label label2;
        private Button button3;
        private Label label3;
        private Label label4;
        private Label label5;
        private Label label6;
        private TextBox textBox11;
        private Label label7;
        private Button button4;
        private Label label8;
        private TextBox textBox12;
        private TextBox textBox13;
        private Button button5;
        private Label label9;
        private Label label10;
        private Label label11;
        private TextBox textBox14;
    }
}