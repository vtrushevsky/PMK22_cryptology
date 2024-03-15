using WinFormsApp1;

namespace Cryptology
{
    public partial class MainMenu : Form
    {
        public MainMenu()
        {
            InitializeComponent();
        }

        private void railfence_button_Click(object sender, EventArgs e)
        {
            this.Hide();
            RailFence r = new RailFence();
            r.ShowDialog();
            this.Close();
        }

        private void Caesar_Click(object sender, EventArgs e)
        {
            this.Hide();
            Caesar r = new Caesar();
            r.ShowDialog();
            this.Close();
        }
    }
}
