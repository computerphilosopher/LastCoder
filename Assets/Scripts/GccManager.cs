using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Data;
using Mono.Data.SqliteClient;

using System.Diagnostics;

using UnityEngine;
using UnityEngine.UI;
using System.Threading;

class GccManager : MonoBehaviour
{
    private Process compileProcess;
    private Process excuteProcess;
    private string relativePath;
    public int problemNumber;
 
    private Button submitButton;

    private Text errorMsg;
    private Text stdOut;

    private string outputText;
    private InputField codingField;

    DBParser parser;

    void Start()
    {


        relativePath = Application.dataPath + "/../bin";

        errorMsg = GameObject.Find("ErrorMSG").GetComponentInChildren<Text>();
        errorMsg.text = "initial text";

        stdOut = GameObject.Find("Output").GetComponentInChildren<Text>();
        stdOut.text = "initial text";
 
        parser = new DBParser(problemNumber, relativePath+"/");

        codingField = GameObject.Find("InputField").GetComponent<InputField>();
        codingField.text= ReadDefaultText();

        submitButton = GetSubmitButton();
        submitButton.onClick.AddListener(ButtonListener);


    }

    private void ButtonListener()
    {
        Compile();
        Excute();

        
        Marking();
 
    }

    private Button GetSubmitButton()
    {
        Button b = gameObject.GetComponentInChildren<Button>();

        return b;
    }

    private string ReadDefaultText()
    {
        StreamReader reader = new StreamReader(parser.SourcePath);
        string fileText = reader.ReadToEnd();
        //UnityEngine.Debug.Log(fileText);

        reader.Close();

        return fileText;

    }

    private void WriteCFile()
    {

        StreamWriter writer = new StreamWriter(relativePath + "/test.c", false);

        string inputString = GetComponentInChildren<InputField>().text;

        writer.WriteLine(inputString);

        writer.Close();
 } 
    public void Compile()
    {
        WriteCFile();
        compileProcess = new Process();
        compileProcess.StartInfo = new ProcessStartInfo(relativePath + "/gcc.bat", null);
        compileProcess.StartInfo.UseShellExecute = false;
        compileProcess.StartInfo.CreateNoWindow = true;
        compileProcess.StartInfo.RedirectStandardError = true;

        compileProcess.Start();

        string compileError = compileProcess.StandardError.ReadToEnd();

        compileProcess.StandardError.Close();
        errorMsg.text = compileError;
        compileProcess.WaitForExit();

    }
 
    private void Excute()
    {
        excuteProcess = new Process();
        excuteProcess.StartInfo = new ProcessStartInfo(relativePath+ "/redir_input.bat", relativePath + " " + parser.InputPath);
        excuteProcess.StartInfo.RedirectStandardError = true;
        excuteProcess.StartInfo.RedirectStandardOutput = true;

        excuteProcess.StartInfo.CreateNoWindow = true;
        excuteProcess.StartInfo.UseShellExecute =false;
        //File.Delete(relativePath + "/output.txt");

        excuteProcess.Start();
        excuteProcess.WaitForExit(1000);
 
        outputText = File.ReadAllText(relativePath + "/output.txt");

        stdOut.text = outputText;
        File.Delete(relativePath + "/output.txt");

 
    }

    private void Marking()
    {
        Text resultMessage = GameObject.Find("Result").GetComponentInChildren<Text>();
        Marker marker = new Marker(outputText , parser.AnswerPath);

        resultMessage.text = marker.ShowResult();

    }

    void Destroy()
    {
        submitButton.onClick.RemoveAllListeners();

    }
    /* 채점 클래스 */
    public class Marker
    {
        private string userSubmission;
        private string answerPath;
        private string answer;

        string result;

        public Marker(string userSubmission, string answerPath)
        {
            this.userSubmission = userSubmission;
            this.answerPath = answerPath;

            answer = File.ReadAllText(this.answerPath);
            UnityEngine.Debug.Log(userSubmission.Equals(answer));

        }


        private bool IsCorrect()
        {
            if (userSubmission.Equals(answer))
            {
                return true;
            }

            else
            {
                return false;
            }

        }

        public string ShowResult()
        {

            if (String.IsNullOrEmpty(userSubmission))
            {
                result = "시간 초과";
            }

            else if (userSubmission.Equals(answer))
            {
                result = "정답입니다.";
            }

            else
            {
                result = ("틀렸습니다.");
            }

            return result;

        }

    }

    struct DBParser
    {
        string dbPath;
        private string sourcePath;
        private string inputPath;
        string answerPath;

        public DBParser(int problemNumber, string dirPath)
        {
            //dbPath = dirPath + "Problem";
            dbPath = "URI=file:" + dirPath + "Problem.db";

            UnityEngine.Debug.Log(dbPath);
            IDbConnection dbConnection = (IDbConnection) new SqliteConnection(dbPath);

            dbConnection.Open();

            IDbCommand dbCommand = dbConnection.CreateCommand();

            string sqlQuery = "select " + "sourcePath, inputPath, answerPath " + "from Problem " + "where " + "problemNumber=" + problemNumber + ";";
            UnityEngine.Debug.Log(sqlQuery);

            dbCommand.CommandText = sqlQuery;

            IDataReader dataReader = dbCommand.ExecuteReader();

            dataReader.Read();

            sourcePath = dirPath + dataReader.GetString(0);
            inputPath = dirPath + dataReader.GetString(1);
            answerPath = dirPath + dataReader.GetString(2);

            dataReader.Close();
            dataReader = null;

            dbCommand.Dispose();
            dbCommand = null;

            dbConnection.Close();
            dbConnection = null;

        }

        public string InputPath
        {
            get { return inputPath; }
        }

        public string AnswerPath
        {
            get { return answerPath; }
        }

        public string SourcePath
        {
            get { return sourcePath; }
        }

    }

}
