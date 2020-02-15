#pragma once


// CDlgWriteConfig dialog

class CDlgWriteConfig : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgWriteConfig)

public:
	CDlgWriteConfig(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgWriteConfig();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CVSListBox m_ebFileName;
	CMFCEditBrowseCtrl m_btnLoad;
	CButton m_btnSave;
	CMFCEditBrowseCtrl m_ebLoadFile;
	CEdit m_FileName;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedCancel();
};
