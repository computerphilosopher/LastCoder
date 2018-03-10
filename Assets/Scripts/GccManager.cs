using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

using System.Diagnostics;

using UnityEngine;
using UnityEngine.UI;
using System.Threading;

class GccManager : MonoBehaviour
{
    private Process compileProcess;
    private Process excuteProcess;
    private string relativePath;
 
    private Button submitButton;

    private Text errorMsg;
    private Text stdOut;
    string outputText;
    //StringBuilder outputText;

    private InputField codingField;
 
    void Start()
    {


        relativePath = Application.dataPath + "/../bin";

        errorMsg = GameObject.Find("ErrorMSG").GetComponentInChildren<Text>();
        errorMsg.text = "initial text";

        stdOut = GameObject.Find("Output").GetComponentInChildren<Text>();
        stdOut.text = "initial text";
 
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
        StreamReader reader = new StreamReader(relativePath + "/test.c");
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

    public void testWrite()
    {
        FileStream writestream = new FileStream(relativePath + "/input.ck", FileMode.Create);
        writestream.WriteByte(30);
        writestream.Close();
    }

    private void Excute()
    {
        excuteProcess = new Process();
        excuteProcess.StartInfo = new ProcessStartInfo(relativePath+ "/redir_input.bat", relativePath);
        excuteProcess.StartInfo.RedirectStandardError = true;
        excuteProcess.StartInfo.RedirectStandardOutput = true;

        excuteProcess.StartInfo.CreateNoWindow = true;
        excuteProcess.StartInfo.UseShellExecute =false;
        //File.Delete(relativePath + "/test.txt");

        excuteProcess.Start();
        excuteProcess.WaitForExit(1000);
 
        outputText = File.ReadAllText(relativePath + "/output.txt");

        string ot = excuteProcess.StandardOutput.ReadToEnd();
        string er = excuteProcess.StandardError.ReadToEnd();
        UnityEngine.Debug.Log(ot);
        UnityEngine.Debug.Log(er);
        stdOut.text = outputText;
        File.Delete(relativePath + "/test.txt");

 
    }

    private void Marking()
    {
        Text resultMessage = GameObject.Find("Result").GetComponentInChildren<Text>();
        Marker marker = new Marker(outputText , relativePath + "/answer.txt");

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
        private string AnswerPath;
        private string Answer;

        string result;

        public Marker(string userSubmission, string AnswerPath)
        {
            this.userSubmission = userSubmission;
            this.AnswerPath = AnswerPath;

            Answer = File.ReadAllText(AnswerPath);

        }


        private bool IsCorrect()
        {
            if (userSubmission.Equals(Answer))
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

            else if (userSubmission.Equals(Answer))
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

}
