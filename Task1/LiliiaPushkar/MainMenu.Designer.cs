namespace Cryptology
{
    partial class MainMenu
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
            railfence_button = new Button();
            label1 = new Label();
            Caesar = new Button();
            SuspendLayout();
            // 
            // railfence_button
            // 
            railfence_button.BackColor = SystemColors.GradientInactiveCaption;
            railfence_button.Font = new Font("Sitka Text Semibold", 12F, FontStyle.Bold, GraphicsUnit.Point);
            railfence_button.Location = new Point(119, 115);
            railfence_button.Name = "railfence_button";
            railfence_button.Size = new Size(222, 46);
            railfence_button.TabIndex = 0;
            railfence_button.Text = "Rail fence";
            railfence_button.UseVisualStyleBackColor = false;
            railfence_button.Click += railfence_button_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.BackColor = Color.MediumPurple;
            label1.FlatStyle = FlatStyle.Flat;
            label1.Font = new Font("Sitka Banner", 25.8F, FontStyle.Bold | FontStyle.Italic, GraphicsUnit.Point);
            label1.Location = new Point(437, 23);
            label1.Name = "label1";
            label1.Size = new Size(285, 62);
            label1.TabIndex = 1;
            label1.Text = "Cryptographer";
            // 
            // Caesar
            // 
            Caesar.BackColor = SystemColors.GradientInactiveCaption;
            Caesar.Font = new Font("Sitka Text Semibold", 12F, FontStyle.Bold, GraphicsUnit.Point);
            Caesar.Location = new Point(119, 193);
            Caesar.Name = "Caesar";
            Caesar.Size = new Size(222, 46);
            Caesar.TabIndex = 2;
            Caesar.Text = " Caesar Cipher";
            Caesar.UseVisualStyleBackColor = false;
            Caesar.Click += Caesar_Click;
            // 
            // MainMenu
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackgroundImage = Properties.Resources.main_menu;
            ClientSize = new Size(1148, 651);
            Controls.Add(Caesar);
            Controls.Add(label1);
            Controls.Add(railfence_button);
            Name = "MainMenu";
            Text = "Main menu";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button railfence_button;
        private Label label1;
        private Button Caesar;
    }
}
