// dicom_reader.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/libi2d/i2d.h"
#include "dcmtk/dcmdata/libi2d/i2djpgs.h"
#include "dcmtk/dcmdata/libi2d/i2dplsc.h"
#include "dcmtk/dcmdata/dctk.h"

using namespace std;

// void createDicomImage()
// {
//     char uid[100];
//     I2DImgSource *inputPlug = new I2DJpegSource();
//     I2DOutputPlug *outPlug = new I2DOutputPlugSC();
//     Image2Dcm i2d;
//     E_TransferSyntax writeXfer;
//     DcmDataset *resultDset = NULL;

//     inputPlug->setImageFile("test.jpg");
//     i2d.convert(inputPlug, outPlug, resultDset, writeXfer);
//     resultDset->putAndInsertString(DCM_PatientName, "Brandon Lara");
//     resultDset->putAndInsertString(DCM_SOPClassUID, UID_SecondaryCaptureImageStorage);
//     resultDset->putAndInsertString(DCM_SOPInstanceUID, dcmGenerateUniqueIdentifier(uid, SITE_INSTANCE_UID_ROOT));
//     DcmFileFormat dcmff(resultDset);
//     dcmff.saveFile("test.dcm", writeXfer, EET_ExplicitLength, EGL_recalcGL, EPD_noChange, OFstatic_cast(Uint32, 0), OFstatic_cast(Uint32, 0), EWM_fileformat);
// }

void loadDicom()
{
    DcmFileFormat fileformat;
    // OFCondition status = fileformat.loadFile("test.dcm");
    OFCondition status = fileformat.loadFile("/home/harito/Documents/Tutorial_C/DCMTK/docs/Dicom_example/CT3/1.2.840.113704.9.1000.16.1.2024100908461626200010001/1.2.840.113704.9.1000.16.2.20241009084633828000100010001.dcm");

    if (status.good())
    {
        OFString patientName;
        if (fileformat.getDataset()->findAndGetOFString(DCM_PatientName, patientName).good())
        {
            cout << "Patient's Name: " << patientName << endl;
        }
        else
            cerr << "Error: cannot access Patient's Name!" << endl;
    }
    else
        cerr << "Error: cannot read DICOM file (" << status.text() << ")" << endl;
}

int main()
{
    cout << "Hello World!\n";
    // createDicomImage();
    loadDicom();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file