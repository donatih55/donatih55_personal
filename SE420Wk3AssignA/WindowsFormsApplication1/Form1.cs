//required system dlls for rendering, text, forms, etc.
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

//namespace of my project
namespace WindowsFormsApplication1
{
    //class of the form being displayed
    public partial class Form1 : Form
    {
        // the method of the form1
        public Form1()
        {
            //initialize the rendering
            InitializeComponent();
        }
        //necessary method for the label, accessed when the label is clicked
        private void label1_Click(object sender, EventArgs e)
        {
               
        }
        // form1_load, accessed when the form is loaded
        private void Form1_Load(object sender, EventArgs e)
        {
            //make a db object to pull the data from
            DBConnect test = new DBConnect();
            //output the data in the label
             this.label1.Text = test.Select();
        }

       
    }
}
