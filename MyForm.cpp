#include "MyForm.h"
#include "json.hpp"
#include <string>
#include <msclr/marshal_cppstd.h>

using json = nlohmann::json;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::IO;

// Entry point
void main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    CppWeatherGUI::MyForm form;
    Application::Run(% form);
}

System::Void CppWeatherGUI::MyForm::Checkweather_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ city = maskedTextBox1->Text;
    String^ apiKey = "a02356cb388ab8415bc127df326b2388";
    String^ url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    try
    {
        // Create and send HTTP request
        auto request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(url));
        auto response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
        auto dataStream = response->GetResponseStream();
        auto reader = gcnew StreamReader(dataStream);
        String^ responseFromServer = reader->ReadToEnd();

        // Convert System::String^ to std::string for nlohmann::json
        std::string jsonStr = msclr::interop::marshal_as<std::string>(responseFromServer);

        // Parse JSON using nlohmann::json
        json j = json::parse(jsonStr);

        // Extract values
        double temp = j["main"]["temp"];
        std::string description = j["weather"][0]["description"];

        // Set values to textboxes
        textBoxtemp->Text = temp.ToString("F1") + " °C";
        textBoxweather->Text = gcnew String(description.c_str());

        // Clean up
        reader->Close();
        dataStream->Close();
        response->Close();
    }
    catch (Exception^ ex)
    {
        textBoxtemp->Text = "";
        textBoxweather->Text = "";
        MessageBox::Show("Error: " + ex->Message);
    }
}