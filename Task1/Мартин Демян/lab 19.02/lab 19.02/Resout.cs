using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace lab_19._02
{
    public partial class Resout : Form
    {
        public string TXT
        {
            get { return richTextBox1.Text; }
            set { richTextBox1.Text = value; }
        }
        public string Time
        {
            get { return richTextBox2.Text; }
            set { richTextBox2.Text = value; }
        }
        public Resout()
        {
            InitializeComponent();
        }

        
        private void button1_Click(object sender, EventArgs e)
        {
            Form1 form = new Form1();
            this.Hide();
            form.Show();
        }

        private void richTextBox1_TextChanged_1(object sender, EventArgs e)
        {
            
        }
    }
}
