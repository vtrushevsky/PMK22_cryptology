﻿namespace cryptology
{
    partial class cesar
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
            this.cesarEncLB = new System.Windows.Forms.Button();
            this.keyCesar = new System.Windows.Forms.TextBox();
            this.wordCesarFast = new System.Windows.Forms.TextBox();
            this.cesarPath = new System.Windows.Forms.TextBox();
            this.cesarEncrPath = new System.Windows.Forms.TextBox();
            this.keyLEncr = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.cesarEncrWord = new System.Windows.Forms.Label();
            this.cesarEncrFB = new System.Windows.Forms.Button();
            this.backToMenuCesar = new System.Windows.Forms.Button();
            this.timeNeededC = new System.Windows.Forms.Label();
            this.wordNoKey = new System.Windows.Forms.Label();
            this.boxWordNoKey = new System.Windows.Forms.TextBox();
            this.noKeyEncr = new System.Windows.Forms.Button();
            this.noKeyWord = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.lengthBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // cesarEncLB
            // 
            this.cesarEncLB.Location = new System.Drawing.Point(343, 146);
            this.cesarEncLB.Name = "cesarEncLB";
            this.cesarEncLB.Size = new System.Drawing.Size(75, 23);
            this.cesarEncLB.TabIndex = 1;
            this.cesarEncLB.Text = "Encrypt";
            this.cesarEncLB.UseVisualStyleBackColor = true;
            this.cesarEncLB.Click += new System.EventHandler(this.cesarEncLB_Click);
            // 
            // keyCesar
            // 
            this.keyCesar.Location = new System.Drawing.Point(512, 245);
            this.keyCesar.Name = "keyCesar";
            this.keyCesar.Size = new System.Drawing.Size(100, 20);
            this.keyCesar.TabIndex = 2;
            this.keyCesar.TextChanged += new System.EventHandler(this.keyCesar_TextChanged);
            // 
            // wordCesarFast
            // 
            this.wordCesarFast.Location = new System.Drawing.Point(179, 245);
            this.wordCesarFast.Name = "wordCesarFast";
            this.wordCesarFast.Size = new System.Drawing.Size(110, 20);
            this.wordCesarFast.TabIndex = 3;
            this.wordCesarFast.TextChanged += new System.EventHandler(this.wordCesarFast_TextChanged);
            // 
            // cesarPath
            // 
            this.cesarPath.Location = new System.Drawing.Point(179, 46);
            this.cesarPath.Name = "cesarPath";
            this.cesarPath.Size = new System.Drawing.Size(110, 20);
            this.cesarPath.TabIndex = 4;
            this.cesarPath.TextChanged += new System.EventHandler(this.cesarPath_TextChanged);
            // 
            // cesarEncrPath
            // 
            this.cesarEncrPath.Location = new System.Drawing.Point(512, 46);
            this.cesarEncrPath.Name = "cesarEncrPath";
            this.cesarEncrPath.Size = new System.Drawing.Size(134, 20);
            this.cesarEncrPath.TabIndex = 5;
            this.cesarEncrPath.TextChanged += new System.EventHandler(this.cesarDecrPath_TextChanged);
            // 
            // keyLEncr
            // 
            this.keyLEncr.Location = new System.Drawing.Point(329, 96);
            this.keyLEncr.Name = "keyLEncr";
            this.keyLEncr.Size = new System.Drawing.Size(110, 20);
            this.keyLEncr.TabIndex = 6;
            this.keyLEncr.TextChanged += new System.EventHandler(this.keyLEncr_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(211, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(47, 24);
            this.label1.TabIndex = 7;
            this.label1.Text = "Path";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(202, 218);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 24);
            this.label2.TabIndex = 8;
            this.label2.Text = "Word";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(538, 218);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(42, 24);
            this.label3.TabIndex = 9;
            this.label3.Text = "Key";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(362, 69);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(42, 24);
            this.label4.TabIndex = 10;
            this.label4.Text = "Key";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label5.Location = new System.Drawing.Point(508, 19);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(115, 24);
            this.label5.TabIndex = 11;
            this.label5.Text = "Encrypt path";
            // 
            // cesarEncrWord
            // 
            this.cesarEncrWord.AutoSize = true;
            this.cesarEncrWord.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cesarEncrWord.Location = new System.Drawing.Point(348, 353);
            this.cesarEncrWord.Name = "cesarEncrWord";
            this.cesarEncrWord.Size = new System.Drawing.Size(59, 24);
            this.cesarEncrWord.TabIndex = 12;
            this.cesarEncrWord.Text = "Cesar";
            this.cesarEncrWord.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.cesarEncrWord.Click += new System.EventHandler(this.cesarEncrWord_Click);
            // 
            // cesarEncrFB
            // 
            this.cesarEncrFB.Location = new System.Drawing.Point(343, 305);
            this.cesarEncrFB.Name = "cesarEncrFB";
            this.cesarEncrFB.Size = new System.Drawing.Size(75, 23);
            this.cesarEncrFB.TabIndex = 0;
            this.cesarEncrFB.Text = "Encrypt";
            this.cesarEncrFB.UseVisualStyleBackColor = true;
            this.cesarEncrFB.Click += new System.EventHandler(this.cesarEncrFB_Click);
            // 
            // backToMenuCesar
            // 
            this.backToMenuCesar.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.backToMenuCesar.Location = new System.Drawing.Point(512, 386);
            this.backToMenuCesar.Name = "backToMenuCesar";
            this.backToMenuCesar.Size = new System.Drawing.Size(187, 33);
            this.backToMenuCesar.TabIndex = 13;
            this.backToMenuCesar.Text = "Menu";
            this.backToMenuCesar.UseVisualStyleBackColor = true;
            this.backToMenuCesar.Click += new System.EventHandler(this.backToMenuCesar_Click);
            // 
            // timeNeededC
            // 
            this.timeNeededC.AutoSize = true;
            this.timeNeededC.Font = new System.Drawing.Font("Microsoft YaHei UI", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.timeNeededC.Location = new System.Drawing.Point(562, 305);
            this.timeNeededC.Name = "timeNeededC";
            this.timeNeededC.Size = new System.Drawing.Size(84, 35);
            this.timeNeededC.TabIndex = 14;
            this.timeNeededC.Text = "Time:";
            this.timeNeededC.Click += new System.EventHandler(this.timeNeededC_Click);
            // 
            // wordNoKey
            // 
            this.wordNoKey.AutoSize = true;
            this.wordNoKey.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.wordNoKey.Location = new System.Drawing.Point(775, 130);
            this.wordNoKey.Name = "wordNoKey";
            this.wordNoKey.Size = new System.Drawing.Size(193, 24);
            this.wordNoKey.TabIndex = 17;
            this.wordNoKey.Text = "Decription without key";
            // 
            // boxWordNoKey
            // 
            this.boxWordNoKey.Location = new System.Drawing.Point(816, 157);
            this.boxWordNoKey.Name = "boxWordNoKey";
            this.boxWordNoKey.Size = new System.Drawing.Size(110, 20);
            this.boxWordNoKey.TabIndex = 16;
            this.boxWordNoKey.TextChanged += new System.EventHandler(this.boxWordNoKey_TextChanged);
            // 
            // noKeyEncr
            // 
            this.noKeyEncr.Location = new System.Drawing.Point(833, 207);
            this.noKeyEncr.Name = "noKeyEncr";
            this.noKeyEncr.Size = new System.Drawing.Size(75, 23);
            this.noKeyEncr.TabIndex = 15;
            this.noKeyEncr.Text = "Encrypt";
            this.noKeyEncr.UseVisualStyleBackColor = true;
            this.noKeyEncr.Click += new System.EventHandler(this.noKeyEncr_Click);
            // 
            // noKeyWord
            // 
            this.noKeyWord.AutoSize = true;
            this.noKeyWord.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.noKeyWord.Location = new System.Drawing.Point(842, 241);
            this.noKeyWord.Name = "noKeyWord";
            this.noKeyWord.Size = new System.Drawing.Size(59, 24);
            this.noKeyWord.TabIndex = 18;
            this.noKeyWord.Text = "Cesar";
            this.noKeyWord.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.noKeyWord.Click += new System.EventHandler(this.noKeyWord_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label6.Location = new System.Drawing.Point(350, 8);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(68, 24);
            this.label6.TabIndex = 20;
            this.label6.Text = "Length";
            // 
            // lengthBox
            // 
            this.lengthBox.Location = new System.Drawing.Point(329, 35);
            this.lengthBox.Name = "lengthBox";
            this.lengthBox.Size = new System.Drawing.Size(110, 20);
            this.lengthBox.TabIndex = 19;
            this.lengthBox.TextChanged += new System.EventHandler(this.lengthBox_TextChanged);
            // 
            // cesar
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ControlDark;
            this.ClientSize = new System.Drawing.Size(1133, 450);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.lengthBox);
            this.Controls.Add(this.noKeyWord);
            this.Controls.Add(this.wordNoKey);
            this.Controls.Add(this.boxWordNoKey);
            this.Controls.Add(this.noKeyEncr);
            this.Controls.Add(this.timeNeededC);
            this.Controls.Add(this.backToMenuCesar);
            this.Controls.Add(this.cesarEncrWord);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.keyLEncr);
            this.Controls.Add(this.cesarEncrPath);
            this.Controls.Add(this.cesarPath);
            this.Controls.Add(this.wordCesarFast);
            this.Controls.Add(this.keyCesar);
            this.Controls.Add(this.cesarEncLB);
            this.Controls.Add(this.cesarEncrFB);
            this.Name = "cesar";
            this.Text = "cesar";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button cesarEncLB;
        private System.Windows.Forms.TextBox keyCesar;
        private System.Windows.Forms.TextBox wordCesarFast;
        private System.Windows.Forms.TextBox cesarPath;
        private System.Windows.Forms.TextBox cesarEncrPath;
        private System.Windows.Forms.TextBox keyLEncr;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label cesarEncrWord;
        private System.Windows.Forms.Button cesarEncrFB;
        private System.Windows.Forms.Button backToMenuCesar;
        private System.Windows.Forms.Label timeNeededC;
        private System.Windows.Forms.Label wordNoKey;
        private System.Windows.Forms.TextBox boxWordNoKey;
        private System.Windows.Forms.Button noKeyEncr;
        private System.Windows.Forms.Label noKeyWord;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox lengthBox;
    }
}