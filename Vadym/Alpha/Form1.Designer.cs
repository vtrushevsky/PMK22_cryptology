namespace Alpha
{
    partial class Form1
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
            button1 = new Button();
            label1 = new Label();
            label2 = new Label();
            Input = new TextBox();
            output = new TextBox();
            label3 = new Label();
            Key = new TextBox();
            label4 = new Label();
            Block = new TextBox();
            label5 = new Label();
            label7 = new Label();
            Times = new Label();
            SuspendLayout();
            // 
            // button1
            // 
            button1.BackColor = Color.FromArgb(6, 128, 17);
            button1.Location = new Point(336, 407);
            button1.Name = "button1";
            button1.Size = new Size(103, 31);
            button1.TabIndex = 0;
            button1.Text = "Encrypt";
            button1.UseVisualStyleBackColor = false;
            button1.Click += button1_Click;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Stencil Std", 36F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.Location = new Point(155, 9);
            label1.Name = "label1";
            label1.Size = new Size(484, 63);
            label1.TabIndex = 1;
            label1.Text = "Palisade cipher";
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Italic, GraphicsUnit.Point, 204);
            label2.Location = new Point(256, 72);
            label2.Name = "label2";
            label2.Size = new Size(288, 25);
            label2.TabIndex = 2;
            label2.Text = "write the path to the input file";
            // 
            // Input
            // 
            Input.Location = new Point(256, 100);
            Input.Name = "Input";
            Input.Size = new Size(268, 23);
            Input.TabIndex = 3;
            // 
            // output
            // 
            output.Location = new Point(256, 164);
            output.Name = "output";
            output.Size = new Size(268, 23);
            output.TabIndex = 5;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Italic, GraphicsUnit.Point, 204);
            label3.Location = new Point(256, 136);
            label3.Name = "label3";
            label3.Size = new Size(301, 25);
            label3.TabIndex = 4;
            label3.Text = "write the path to the output file";
            // 
            // Key
            // 
            Key.Location = new Point(256, 227);
            Key.Name = "Key";
            Key.Size = new Size(268, 23);
            Key.TabIndex = 7;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Italic, GraphicsUnit.Point, 204);
            label4.Location = new Point(256, 199);
            label4.Name = "label4";
            label4.Size = new Size(133, 25);
            label4.TabIndex = 6;
            label4.Text = "write the key";
            // 
            // Block
            // 
            Block.Location = new Point(256, 296);
            Block.Name = "Block";
            Block.Size = new Size(268, 23);
            Block.TabIndex = 9;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Font = new Font("Microsoft Sans Serif", 15.75F, FontStyle.Italic, GraphicsUnit.Point, 204);
            label5.Location = new Point(256, 268);
            label5.Name = "label5";
            label5.Size = new Size(275, 25);
            label5.TabIndex = 8;
            label5.Text = "write the length of the block";
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 204);
            label7.Location = new Point(288, 345);
            label7.Name = "label7";
            label7.Size = new Size(72, 32);
            label7.TabIndex = 11;
            label7.Text = "Time:";
            // 
            // Times
            // 
            Times.AutoSize = true;
            Times.Font = new Font("Segoe UI", 18F, FontStyle.Regular, GraphicsUnit.Point, 204);
            Times.Location = new Point(350, 345);
            Times.Name = "Times";
            Times.Size = new Size(34, 32);
            Times.TabIndex = 12;
            Times.Text = "....";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(64, 201, 76);
            ClientSize = new Size(784, 450);
            Controls.Add(Times);
            Controls.Add(label7);
            Controls.Add(Block);
            Controls.Add(label5);
            Controls.Add(Key);
            Controls.Add(label4);
            Controls.Add(output);
            Controls.Add(label3);
            Controls.Add(Input);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(button1);
            FormBorderStyle = FormBorderStyle.FixedSingle;
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button1;
        private Label label1;
        private Label label2;
        private TextBox Input;
        private TextBox output;
        private Label label3;
        private TextBox Key;
        private Label label4;
        private TextBox Block;
        private Label label5;
        private Label label7;
        private Label Times;
    }
}
