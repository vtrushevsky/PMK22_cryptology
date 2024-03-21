using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace cryptology
{
    public partial class mainMenu : Form
    {
        public mainMenu()
        {
            InitializeComponent();
        }

        private void Railfance_Click(object sender, EventArgs e)
        {
            this.Hide();
            railfance ra = new railfance();
            ra.ShowDialog();
            this.Close();
        }

        private void CesarB_Click(object sender, EventArgs e)
        {
            this.Hide();
            cesar ce = new cesar();
            ce.ShowDialog();
            this.Close();
        }
    }
}
