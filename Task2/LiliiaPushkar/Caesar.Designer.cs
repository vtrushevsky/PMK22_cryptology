namespace Cryptology
{
    partial class Caesar
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
            label3 = new Label();
            label4 = new Label();
            textBox2 = new TextBox();
            textBox3 = new TextBox();
            btn_enc_file = new Button();
            textBox1 = new TextBox();
            button_dec = new Button();
            textBox6 = new TextBox();
            textBox5 = new TextBox();
            textBox4 = new TextBox();
            label5 = new Label();
            Decrypte_word = new Button();
            label2 = new Label();
            textBox10 = new TextBox();
            textBox9 = new TextBox();
            textBox8 = new TextBox();
            textBox7 = new TextBox();
            Encrypte_word = new Button();
            label1 = new Label();
            label10 = new Label();
            textBox14 = new TextBox();
            label11 = new Label();
            button4 = new Button();
            label7 = new Label();
            textBox11 = new TextBox();
            label6 = new Label();
            SuspendLayout();
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Sitka Display", 19.8F, FontStyle.Bold, GraphicsUnit.Point);
            label3.Location = new Point(357, 28);
            label3.Name = "label3";
            label3.Size = new Size(210, 48);
            label3.TabIndex = 31;
            label3.Text = "Caesar cipher";
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label4.Location = new Point(43, 75);
            label4.Name = "label4";
            label4.Size = new Size(160, 33);
            label4.TabIndex = 32;
            label4.Text = "Work with files";
            // 
            // textBox2
            // 
            textBox2.Location = new Point(61, 119);
            textBox2.Name = "textBox2";
            textBox2.Size = new Size(108, 27);
            textBox2.TabIndex = 33;
            textBox2.Text = "Enter key";
            // 
            // textBox3
            // 
            textBox3.Location = new Point(61, 185);
            textBox3.Name = "textBox3";
            textBox3.Size = new Size(326, 27);
            textBox3.TabIndex = 36;
            textBox3.Text = "Enter file path to put encrypted";
            // 
            // btn_enc_file
            // 
            btn_enc_file.BackColor = Color.FromArgb(214, 235, 224);
            btn_enc_file.Location = new Point(70, 234);
            btn_enc_file.Name = "btn_enc_file";
            btn_enc_file.Size = new Size(110, 38);
            btn_enc_file.TabIndex = 35;
            btn_enc_file.Text = "Encrypte file";
            btn_enc_file.UseVisualStyleBackColor = false;
            btn_enc_file.Click += btn_enc_file_Click;
            // 
            // textBox1
            // 
            textBox1.Location = new Point(61, 152);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(326, 27);
            textBox1.TabIndex = 34;
            textBox1.Text = "Enter file path which need to be encrypted";
            // 
            // button_dec
            // 
            button_dec.BackColor = Color.FromArgb(214, 235, 224);
            button_dec.Location = new Point(571, 234);
            button_dec.Name = "button_dec";
            button_dec.Size = new Size(110, 38);
            button_dec.TabIndex = 40;
            button_dec.Text = "Decrypte file";
            button_dec.UseVisualStyleBackColor = false;
            button_dec.Click += button_dec_Click;
            // 
            // textBox6
            // 
            textBox6.Location = new Point(571, 119);
            textBox6.Name = "textBox6";
            textBox6.Size = new Size(108, 27);
            textBox6.TabIndex = 39;
            textBox6.Text = "Enter key";
            // 
            // textBox5
            // 
            textBox5.Location = new Point(571, 152);
            textBox5.Name = "textBox5";
            textBox5.Size = new Size(326, 27);
            textBox5.TabIndex = 38;
            textBox5.Text = "Enter file path to encrypted";
            // 
            // textBox4
            // 
            textBox4.Location = new Point(571, 185);
            textBox4.Name = "textBox4";
            textBox4.Size = new Size(326, 27);
            textBox4.TabIndex = 37;
            textBox4.Text = "Enter file path to put decrypted";
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label5.Location = new Point(43, 320);
            label5.Name = "label5";
            label5.Size = new Size(180, 33);
            label5.TabIndex = 49;
            label5.Text = "Work with words";
            // 
            // Decrypte_word
            // 
            Decrypte_word.BackColor = Color.FromArgb(214, 235, 224);
            Decrypte_word.Location = new Point(357, 480);
            Decrypte_word.Name = "Decrypte_word";
            Decrypte_word.Size = new Size(94, 29);
            Decrypte_word.TabIndex = 48;
            Decrypte_word.Text = "Decrypte";
            Decrypte_word.UseVisualStyleBackColor = false;
            Decrypte_word.Click += Decrypte_word_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label2.Location = new Point(357, 439);
            label2.Name = "label2";
            label2.Size = new Size(146, 29);
            label2.TabIndex = 47;
            label2.Text = "Decrypted word: ";
            // 
            // textBox10
            // 
            textBox10.Location = new Point(357, 405);
            textBox10.Name = "textBox10";
            textBox10.Size = new Size(249, 27);
            textBox10.TabIndex = 46;
            textBox10.Text = "Word";
            // 
            // textBox9
            // 
            textBox9.Location = new Point(357, 372);
            textBox9.Name = "textBox9";
            textBox9.Size = new Size(108, 27);
            textBox9.TabIndex = 45;
            textBox9.Text = "Enter key";
            // 
            // textBox8
            // 
            textBox8.Location = new Point(66, 372);
            textBox8.Name = "textBox8";
            textBox8.Size = new Size(108, 27);
            textBox8.TabIndex = 44;
            textBox8.Text = "Enter key";
            // 
            // textBox7
            // 
            textBox7.Location = new Point(70, 405);
            textBox7.Name = "textBox7";
            textBox7.Size = new Size(251, 27);
            textBox7.TabIndex = 43;
            textBox7.Text = "Word";
            // 
            // Encrypte_word
            // 
            Encrypte_word.BackColor = Color.FromArgb(214, 235, 224);
            Encrypte_word.Location = new Point(80, 480);
            Encrypte_word.Name = "Encrypte_word";
            Encrypte_word.Size = new Size(94, 29);
            Encrypte_word.TabIndex = 42;
            Encrypte_word.Text = "Encrypte";
            Encrypte_word.UseVisualStyleBackColor = false;
            Encrypte_word.Click += Encrypte_word_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label1.Location = new Point(66, 439);
            label1.Name = "label1";
            label1.Size = new Size(147, 29);
            label1.TabIndex = 41;
            label1.Text = "Encrypted word: ";
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label10.Location = new Point(672, 336);
            label10.Name = "label10";
            label10.Size = new Size(170, 33);
            label10.TabIndex = 50;
            label10.Text = "Execution time: ";
            // 
            // textBox14
            // 
            textBox14.Location = new Point(699, 441);
            textBox14.Name = "textBox14";
            textBox14.Size = new Size(249, 27);
            textBox14.TabIndex = 52;
            textBox14.Text = "0";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label11.Location = new Point(699, 405);
            label11.Name = "label11";
            label11.Size = new Size(108, 33);
            label11.TabIndex = 51;
            label11.Text = "Block size";
            // 
            // button4
            // 
            button4.BackColor = Color.FromArgb(214, 235, 224);
            button4.Location = new Point(980, 355);
            button4.Name = "button4";
            button4.Size = new Size(94, 29);
            button4.TabIndex = 56;
            button4.Text = "Decrypte";
            button4.UseVisualStyleBackColor = false;
            button4.Click += button4_Click;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Sitka Banner", 12F, FontStyle.Regular, GraphicsUnit.Point);
            label7.Location = new Point(961, 307);
            label7.Name = "label7";
            label7.Size = new Size(146, 29);
            label7.TabIndex = 55;
            label7.Text = "Decrypted word: ";
            // 
            // textBox11
            // 
            textBox11.Location = new Point(961, 265);
            textBox11.Name = "textBox11";
            textBox11.Size = new Size(249, 27);
            textBox11.TabIndex = 54;
            textBox11.Text = "Word";
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Font = new Font("Sitka Display", 13.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label6.Location = new Point(951, 213);
            label6.Name = "label6";
            label6.Size = new Size(220, 33);
            label6.TabIndex = 53;
            label6.Text = "Decrypte without key";
            // 
            // Caesar
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1273, 583);
            Controls.Add(button4);
            Controls.Add(label7);
            Controls.Add(textBox11);
            Controls.Add(label6);
            Controls.Add(textBox14);
            Controls.Add(label11);
            Controls.Add(label10);
            Controls.Add(label5);
            Controls.Add(Decrypte_word);
            Controls.Add(label2);
            Controls.Add(textBox10);
            Controls.Add(textBox9);
            Controls.Add(textBox8);
            Controls.Add(textBox7);
            Controls.Add(Encrypte_word);
            Controls.Add(label1);
            Controls.Add(button_dec);
            Controls.Add(textBox6);
            Controls.Add(textBox5);
            Controls.Add(textBox4);
            Controls.Add(textBox3);
            Controls.Add(btn_enc_file);
            Controls.Add(textBox1);
            Controls.Add(textBox2);
            Controls.Add(label4);
            Controls.Add(label3);
            Name = "Caesar";
            Text = "Caesar";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Label label3;
        private Label label4;
        private TextBox textBox2;
        private TextBox textBox3;
        private Button btn_enc_file;
        private TextBox textBox1;
        private Button button_dec;
        private TextBox textBox6;
        private TextBox textBox5;
        private TextBox textBox4;
        private Label label5;
        private Button Decrypte_word;
        private Label label2;
        private TextBox textBox10;
        private TextBox textBox9;
        private TextBox textBox8;
        private TextBox textBox7;
        private Button Encrypte_word;
        private Label label1;
        private Label label10;
        private TextBox textBox14;
        private Label label11;
        private Button button4;
        private Label label7;
        private TextBox textBox11;
        private Label label6;
    }
}