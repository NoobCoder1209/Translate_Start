// DlgWriteConfig.cpp : implementation file
//

#include "pch.h"
#include "Translate.h"
#include "DlgWriteConfig.h"
#include "afxdialogex.h"

// CDlgWriteConfig dialog

IMPLEMENT_DYNAMIC(CDlgWriteConfig, CDialogEx)

CDlgWriteConfig::CDlgWriteConfig(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDlgWriteConfig::~CDlgWriteConfig()
{
}

void CDlgWriteConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCVSLISTBOX1, m_ebFileName);
	DDX_Control(pDX, IDC_MFCEDITBROWSE2, m_btnLoad);
	DDX_Control(pDX, IDC_BUTTON2, m_btnSave);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_ebLoadFile);
	DDX_Control(pDX, IDC_EDIT1, m_FileName);
}


BEGIN_MESSAGE_MAP(CDlgWriteConfig, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgWriteConfig::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgWriteConfig::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgWriteConfig::OnEnChangeEdit1)
	ON_BN_CLICKED(IDCANCEL, &CDlgWriteConfig::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgWriteConfig message handlers


void CDlgWriteConfig::OnBnClickedButton1()
{
	CString csLoadFile;
	m_ebLoadFile.GetWindowTextA(csLoadFile);
	m_ebLoadFile.EnableFileBrowseButton(_T("txt"), _T("Text files|*.txt||"));
	if (csLoadFile != "")
	{
		theApp.m_csConfig = csLoadFile;
		MessageBox(_T("The file has been saved"), _T("Message"), MB_ICONEXCLAMATION);
	}
	else
	{
		MessageBox(_T("Please, select a config file"), _T("Warning"), MB_ICONEXCLAMATION);
	}
}

void CDlgWriteConfig::OnBnClickedButton2()
{
	CString csBtnLoad;
	m_btnLoad.GetWindowTextA(csBtnLoad);
	m_ebLoadFile.EnableFileBrowseButton(_T("txt"), _T("Text files|*.txt||"));
	if (csBtnLoad == "")
	{
		MessageBox(_T("Please, select the directory"), _T("Warning"), MB_ICONEXCLAMATION);
		return;
	}

	CString FileName;
	m_FileName.GetWindowTextA(FileName);

	if (FileName == "")
	{
		MessageBox(_T("Please, write the config file"), _T("Warning"), MB_ICONEXCLAMATION);
		return;
	}

	CStdioFile file;
	if (!file.Open(csBtnLoad + "\\" + FileName, CStdioFile::modeReadWrite | CStdioFile::modeCreate | CFile::shareDenyNone))
	{
		MessageBox(_T("Can not open the config file"), _T("Warning"), MB_ICONEXCLAMATION);
		return;
	}
	else
	{
		for (int y = 0; y < theApp.COL * 2; y++)
		{
			CString csword = m_ebFileName.GetItemText(y);
			if (csword != "")
				file.WriteString(m_ebFileName.GetItemText(y) + _T("\n"));
		}
		file.Close();
		MessageBox(_T("The file has been saved"), _T("Message"), MB_ICONEXCLAMATION);
	}
}

void CDlgWriteConfig::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CDlgWriteConfig::OnBnClickedCancel()
{
	MessageBox(_T("Hello, World!"), _T("Hello"));
	CDialogEx::OnCancel();
}
