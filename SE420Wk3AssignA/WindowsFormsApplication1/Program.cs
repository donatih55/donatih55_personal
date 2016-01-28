// required dlls from System
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
// required dll to connect to mysql
using MySql.Data.MySqlClient;

// namespace for my app. From here on, everything is in this namespace
namespace WindowsFormsApplication1
{
    //class DBconnector
    class DBConnect
    {
        // my private connection, will be used to connect to the db
        private MySqlConnection connection;
        // private string containing server name
        private string server;
        // private string containing db name
        private string database;
        //private string containing username /root/
        private string uid;
        //private string with password
        private string password;

        //Constructor that calls initialization
        public DBConnect()
        {
            Initialize();
        }

        //Initialize values based on mydb, The password is hidden for security reasons right now
        private void Initialize()
        {
            //assigning values to all those variables declared above
            server = "localhost";
            database = "connectcsharptomysql";
            uid = "root";
            password = "73635674Donati";
            // making a string connection, with all the previous data, it is kind of repetitive but that's how the tutorial had it
            string connectionString;
            connectionString = "SERVER=" + server + ";" + "DATABASE=" +
            database + ";" + "UID=" + uid + ";" + "PASSWORD=" + password + ";";

            //create connection with the string declared above.
            connection = new MySqlConnection(connectionString);
        }

        //open connection to database, everytime we need something from the db
        private bool OpenConnection()
        {
            //test to see if the db can be oppened
            try
            {
                //open db command
                connection.Open();
                //bool returning the db openened without errors, aka, true
                return true;
            }
            //catches exception
            catch (MySqlException ex)
            {

                //When handling errors, you can your application's response based 
                //on the error number.
                //The two most common error numbers when connecting are as follows:
                //0: Cannot connect to server.
                //1045: Invalid user name and/or password.
                switch (ex.Number)
                {
                    //if the error was code 0, then display "Cannot connect to server.  Contact administrator"
                    case 0:
                        MessageBox.Show("Cannot connect to server.  Contact administrator");
                        break;

                    //if error is code 1045, it means the password or/and username was wrong
                    case 1045:
                        MessageBox.Show("Invalid username/password, please try again");
                        break;
                }
                //return false in case the connection cannot be stablished.
                return false;
            }
        }

        //Close connection, should be called after every transaction after opening
        private bool CloseConnection()
        {
            //test closing connection, since there could be no connection open
            try
            {
                // command to close the connection
                connection.Close();
                //returns true for sucessfully closed connection
                return true;
            }
            //if there was any errors on closing the connection
            catch (MySqlException ex)
            {
                //display a messagebox, aka, pop up, and display message that comes along with the error
                MessageBox.Show(ex.Message);
                //return false for unsucessfully closing connection 
                return false;
            }
        }
        //Insert statement, to add stuff to the db
        public void Insert()
        {
            //thaths the query, in the future make the columns and values as parameters passed with call
            string query = "INSERT INTO tableinfo (name, age) VALUES('John Smith', '33')";

            //open connection using the previous made method
            if (this.OpenConnection() == true)
            {
                //create command and assign the query and connection from the constructor
                MySqlCommand cmd = new MySqlCommand(query, connection);

                //Execute command
                cmd.ExecuteNonQuery();

                //close connection
                this.CloseConnection();
            }
        }

        //Update statement
        public void Update()
        {
            // update query, like the previous method, information should be passed in the future
            string query = "UPDATE tableinfo SET name='Joe', age='22' WHERE name='John Smith'";

            //Open connection
            if (this.OpenConnection() == true)
            {
                //create mysql command
                MySqlCommand cmd = new MySqlCommand();
                //Assign the query using CommandText
                cmd.CommandText = query;
                //Assign the connection using Connection
                cmd.Connection = connection;

                //Execute query
                cmd.ExecuteNonQuery();

                //close connection
                this.CloseConnection();
            }
        }

        //Delete statement
        public void Delete()
        {
            //query to be passed deliting from db
            string query = "DELETE FROM tableinfo WHERE name='John Smith'";
            // if it can open the connection
            if (this.OpenConnection() == true)
            {
                //make a new command with the query above
                MySqlCommand cmd = new MySqlCommand(query, connection);
                //execute the query
                cmd.ExecuteNonQuery();
                //close the connection
                this.CloseConnection();
            }
        }

        //Select statement
        public string Select()
        {
            //query selecting everything from table
            string query = "SELECT * FROM tableinfo";

            //Create a string to store the result
            string list = "";
            
            //Open connection
            if (this.OpenConnection() == true)
            {
                //Create Command
                MySqlCommand cmd = new MySqlCommand(query, connection);
                //Create a data reader and Execute the command
                MySqlDataReader dataReader = cmd.ExecuteReader();

                //Read the data and store them in the string called list
                while (dataReader.Read())
                {
                    //item by item adding the info with a simple space in it.
                    list += dataReader["id"] + " ";
                    list += (dataReader["name"] + " ");
                    list+=(dataReader["age"] + " ");
                    // new line so the second item has some space
                    list += "\n";
                }

                //close Data Reader
                dataReader.Close();

                //close Connection
                this.CloseConnection();

                //return string to be displayed
                return list;
            }
            //if the connection was not stablished
            else
            {
                //retunr empty variable
                return list;
            }
        }

        //Count statement
        public int Count()
        {
            //query that counts how many items are there in the list
            string query = "SELECT Count(*) FROM tableinfo";
            int Count = -1;

            //Open Connection
            if (this.OpenConnection() == true)
            {
                //Create Mysql Command
                MySqlCommand cmd = new MySqlCommand(query, connection);

                //ExecuteScalar will return one value
                Count = int.Parse(cmd.ExecuteScalar() + "");

                //close Connection
                this.CloseConnection();

                //retunr number of items in the table
                return Count;
            }
            //if connection doesn't open
            else
            {
                //return -1;
                return Count;
            }
        }
    }
  
    //actual program, AKA, MAin
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            //enable visual styles so we can display the form
            Application.EnableVisualStyles();
            // use TextRenderer class for output, instead of Graphics class
            Application.SetCompatibleTextRenderingDefault(false);
            //run the code in Form1 to display the message.
            Application.Run(new Form1());
        }
    }
}
