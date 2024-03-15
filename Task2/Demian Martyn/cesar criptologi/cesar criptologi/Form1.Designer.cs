namespace cesar_criptologi
{
    partial class Form1
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
            this.KeyForChifer = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.LincReadFile = new System.Windows.Forms.TextBox();
            this.LincWrietFile = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.LangvicForChifer = new System.Windows.Forms.DomainUpDown();
            this.label4 = new System.Windows.Forms.Label();
            this.TameDoing = new System.Windows.Forms.Label();
            this.EncriptingButton = new System.Windows.Forms.Button();
            this.DecriptingBatton = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.KeyForChifer)).BeginInit();
            this.SuspendLayout();
            // 
            // KeyForChifer
            // 
            this.KeyForChifer.Location = new System.Drawing.Point(411, 186);
            this.KeyForChifer.Name = "KeyForChifer";
            this.KeyForChifer.Size = new System.Drawing.Size(190, 22);
            this.KeyForChifer.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(129, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(536, 24);
            this.label1.TabIndex = 2;
            this.label1.Text = "Введіть посилання документу над яким буде проводитися операція ";
            // 
            // LincReadFile
            // 
            this.LincReadFile.Location = new System.Drawing.Point(133, 71);
            this.LincReadFile.Name = "LincReadFile";
            this.LincReadFile.Size = new System.Drawing.Size(532, 22);
            this.LincReadFile.TabIndex = 3;
            // 
            // LincWrietFile
            // 
            this.LincWrietFile.Location = new System.Drawing.Point(133, 142);
            this.LincWrietFile.Name = "LincWrietFile";
            this.LincWrietFile.Size = new System.Drawing.Size(567, 22);
            this.LincWrietFile.TabIndex = 5;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(129, 115);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(571, 24);
            this.label2.TabIndex = 4;
            this.label2.Text = "Введіть посилання документу на який буде записано результат операції";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(130, 182);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(223, 24);
            this.label3.TabIndex = 6;
            this.label3.Text = "Виберіть ключ шифрування\r\n";
            // 
            // LangvicForChifer
            // 
            this.LangvicForChifer.Location = new System.Drawing.Point(411, 232);
            this.LangvicForChifer.Name = "LangvicForChifer";
            this.LangvicForChifer.Size = new System.Drawing.Size(190, 22);
            this.LangvicForChifer.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(130, 232);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(120, 24);
            this.label4.TabIndex = 8;
            this.label4.Text = "Виберіть мову\r\n";
            // 
            // TameDoing
            // 
            this.TameDoing.AutoSize = true;
            this.TameDoing.Location = new System.Drawing.Point(134, 288);
            this.TameDoing.Name = "TameDoing";
            this.TameDoing.Size = new System.Drawing.Size(0, 16);
            this.TameDoing.TabIndex = 9;
            // 
            // EncriptingButton
            // 
            this.EncriptingButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.EncriptingButton.Location = new System.Drawing.Point(133, 352);
            this.EncriptingButton.Name = "EncriptingButton";
            this.EncriptingButton.Size = new System.Drawing.Size(227, 46);
            this.EncriptingButton.TabIndex = 10;
            this.EncriptingButton.Text = "Шифрувати ";
            this.EncriptingButton.UseVisualStyleBackColor = true;
            this.EncriptingButton.Click += new System.EventHandler(this.EncriptingButton_Click);
            // 
            // DecriptingBatton
            // 
            this.DecriptingBatton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.DecriptingBatton.Location = new System.Drawing.Point(430, 352);
            this.DecriptingBatton.Name = "DecriptingBatton";
            this.DecriptingBatton.Size = new System.Drawing.Size(235, 46);
            this.DecriptingBatton.TabIndex = 11;
            this.DecriptingBatton.Text = "Дешифрувати ";
            this.DecriptingBatton.UseVisualStyleBackColor = true;
            this.DecriptingBatton.Click += new System.EventHandler(this.DecriptingBatton_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.DecriptingBatton);
            this.Controls.Add(this.EncriptingButton);
            this.Controls.Add(this.TameDoing);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.LangvicForChifer);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.LincWrietFile);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.LincReadFile);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.KeyForChifer);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.KeyForChifer)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.NumericUpDown KeyForChifer;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox LincReadFile;
        private System.Windows.Forms.TextBox LincWrietFile;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DomainUpDown LangvicForChifer;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label TameDoing;
        private System.Windows.Forms.Button EncriptingButton;
        private System.Windows.Forms.Button DecriptingBatton;
    }
}

