namespace cryptology
{
    partial class mainMenu
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
            this.Menu = new System.Windows.Forms.Label();
            this.Railfance = new System.Windows.Forms.Button();
            this.CesarB = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Menu
            // 
            this.Menu.AutoSize = true;
            this.Menu.Font = new System.Drawing.Font("Microsoft Sans Serif", 21.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Menu.Location = new System.Drawing.Point(350, 45);
            this.Menu.Name = "Menu";
            this.Menu.Size = new System.Drawing.Size(87, 33);
            this.Menu.TabIndex = 0;
            this.Menu.Text = "Menu";
            // 
            // Railfance
            // 
            this.Railfance.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Railfance.Location = new System.Drawing.Point(310, 110);
            this.Railfance.Name = "Railfance";
            this.Railfance.Size = new System.Drawing.Size(173, 34);
            this.Railfance.TabIndex = 1;
            this.Railfance.Text = "Railfance";
            this.Railfance.UseVisualStyleBackColor = true;
            this.Railfance.Click += new System.EventHandler(this.Railfance_Click);
            // 
            // CesarB
            // 
            this.CesarB.Font = new System.Drawing.Font("Microsoft Sans Serif", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.CesarB.Location = new System.Drawing.Point(310, 191);
            this.CesarB.Name = "CesarB";
            this.CesarB.Size = new System.Drawing.Size(173, 34);
            this.CesarB.TabIndex = 2;
            this.CesarB.Text = "Cesar";
            this.CesarB.UseVisualStyleBackColor = true;
            this.CesarB.Click += new System.EventHandler(this.CesarB_Click);
            // 
            // mainMenu
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.GradientActiveCaption;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.CesarB);
            this.Controls.Add(this.Railfance);
            this.Controls.Add(this.Menu);
            this.Name = "mainMenu";
            this.Text = "mainMenu";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Menu;
        private System.Windows.Forms.Button Railfance;
        private System.Windows.Forms.Button CesarB;
    }
}