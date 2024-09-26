namespace cryptology
{
    partial class cardano
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
            this.cardanoMenu = new System.Windows.Forms.Button();
            this.cardanoEncrWord = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.wordCardanoFast = new System.Windows.Forms.TextBox();
            this.keyCardano = new System.Windows.Forms.TextBox();
            this.cardanoEncrFB = new System.Windows.Forms.Button();
            this.showMatrix = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // cardanoMenu
            // 
            this.cardanoMenu.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cardanoMenu.Location = new System.Drawing.Point(297, 333);
            this.cardanoMenu.Name = "cardanoMenu";
            this.cardanoMenu.Size = new System.Drawing.Size(173, 34);
            this.cardanoMenu.TabIndex = 4;
            this.cardanoMenu.Text = "Menu";
            this.cardanoMenu.UseVisualStyleBackColor = true;
            this.cardanoMenu.Click += new System.EventHandler(this.cardanoMenu_Click);
            // 
            // cardanoEncrWord
            // 
            this.cardanoEncrWord.AutoSize = true;
            this.cardanoEncrWord.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.cardanoEncrWord.Location = new System.Drawing.Point(324, 274);
            this.cardanoEncrWord.Name = "cardanoEncrWord";
            this.cardanoEncrWord.Size = new System.Drawing.Size(82, 24);
            this.cardanoEncrWord.TabIndex = 18;
            this.cardanoEncrWord.Text = "Cardano";
            this.cardanoEncrWord.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.cardanoEncrWord.Click += new System.EventHandler(this.cardanoEncrWord_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(497, 139);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(42, 24);
            this.label3.TabIndex = 17;
            this.label3.Text = "Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(178, 139);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(56, 24);
            this.label2.TabIndex = 16;
            this.label2.Text = "Word";
            // 
            // wordCardanoFast
            // 
            this.wordCardanoFast.Location = new System.Drawing.Point(155, 166);
            this.wordCardanoFast.Name = "wordCardanoFast";
            this.wordCardanoFast.Size = new System.Drawing.Size(110, 20);
            this.wordCardanoFast.TabIndex = 15;
            this.wordCardanoFast.TextChanged += new System.EventHandler(this.wordCardanoFast_TextChanged);
            // 
            // keyCardano
            // 
            this.keyCardano.Location = new System.Drawing.Point(471, 166);
            this.keyCardano.Name = "keyCardano";
            this.keyCardano.Size = new System.Drawing.Size(100, 20);
            this.keyCardano.TabIndex = 14;
            this.keyCardano.TextChanged += new System.EventHandler(this.keyCardano_TextChanged);
            // 
            // cardanoEncrFB
            // 
            this.cardanoEncrFB.Location = new System.Drawing.Point(319, 226);
            this.cardanoEncrFB.Name = "cardanoEncrFB";
            this.cardanoEncrFB.Size = new System.Drawing.Size(75, 23);
            this.cardanoEncrFB.TabIndex = 13;
            this.cardanoEncrFB.Text = "Encrypt";
            this.cardanoEncrFB.UseVisualStyleBackColor = true;
            this.cardanoEncrFB.Click += new System.EventHandler(this.cardanoEncrFB_Click);
            // 
            // showMatrix
            // 
            this.showMatrix.Location = new System.Drawing.Point(482, 226);
            this.showMatrix.Name = "showMatrix";
            this.showMatrix.Size = new System.Drawing.Size(75, 23);
            this.showMatrix.TabIndex = 19;
            this.showMatrix.Text = "Show matrix";
            this.showMatrix.UseVisualStyleBackColor = true;
            this.showMatrix.Click += new System.EventHandler(this.showMatrix_Click);
            // 
            // cardano
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1223, 450);
            this.Controls.Add(this.showMatrix);
            this.Controls.Add(this.cardanoEncrWord);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.wordCardanoFast);
            this.Controls.Add(this.keyCardano);
            this.Controls.Add(this.cardanoEncrFB);
            this.Controls.Add(this.cardanoMenu);
            this.Name = "cardano";
            this.Text = "cardano";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button cardanoMenu;
        private System.Windows.Forms.Label cardanoEncrWord;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox wordCardanoFast;
        private System.Windows.Forms.TextBox keyCardano;
        private System.Windows.Forms.Button cardanoEncrFB;
        private System.Windows.Forms.Button showMatrix;
    }
}