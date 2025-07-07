#include "MyForm.h"
using namespace System::Net;
using namespace System::IO;
using namespace System::Web::Script::Serialization;

using namespace System;
using namespace System::Windows::Forms;

void main(array<System::String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	// Create the main form and run it
	CppWeatherGUI::MyForm form;
	Application::Run(%form);
}



System::Void CppWeatherGUI::MyForm::Checkweather_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ city = maskedTextBox1->Text;
    String^ apiKey = "a02356cb388ab8415bc127df326b2388"; // Replace with your actual API key
    String^ url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";

    try
    {
        HttpWebRequest^ request = dynamic_cast<HttpWebRequest^>(WebRequest::Create(url));
        HttpWebResponse^ response = dynamic_cast<HttpWebResponse^>(request->GetResponse());
        Stream^ dataStream = response->GetResponseStream();
        StreamReader^ reader = gcnew StreamReader(dataStream);
        String^ responseFromServer = reader->ReadToEnd();

        // Parse JSON and update textBoxtemp and textBoxweather
        // Requires reference to System.Web.Extensions for JavaScriptSerializer
        auto serializer = gcnew System::Web::Script::Serialization::JavaScriptSerializer();
        auto jsonObj = safe_cast<System::Collections::Generic::Dictionary<String^, Object^>^>(serializer->DeserializeObject(responseFromServer));

        // Extract temperature
       // Extract temperature
        auto mainObj = safe_cast<System::Collections::Generic::Dictionary<String^, Object^>^>(jsonObj["main"]);
        double temp = System::Convert::ToDouble(mainObj["temp"]);
        textBoxtemp->Text = temp.ToString() + " °C";

        // Extract weather description
        auto weatherArr = safe_cast<cli::array<Object^>^>(jsonObj["weather"]);
        String^ description = "";
        if (weatherArr != nullptr && weatherArr->Length > 0) {
            auto weatherObj = safe_cast<System::Collections::Generic::Dictionary<String^, Object^>^>(weatherArr[0]);
            if (weatherObj->ContainsKey("description")) {
                description = safe_cast<String^>(weatherObj["description"]);
            }
        }
        textBoxweather->Text = description;

        reader->Close();
        dataStream->Close();
        response->Close();
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Error: " + ex->Message);
    }
}