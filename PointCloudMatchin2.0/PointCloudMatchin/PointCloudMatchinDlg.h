
// PointCloudMatchinDlg.h: 头文件
#include "OpenGLControl.h"
#include "RoamingScenceManager.h"

#pragma once
// CPointCloudMatchinDlg 对话框
const double M_PI = 3.1415926;
class CPointCloudMatchinDlg : public CDialogEx
{
// 构造
public:
	CPointCloudMatchinDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POINTCLOUDMATCHIN_DIALOG };
#endif
	BOOL SetWindowPixelFormat(HDC hDC);  //设定像素格式
	BOOL CreateViewGLContext(HDC hDC);   //view GL Context
	void RenderScene();  //绘制场景


	//BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	/*void OnMButtonDown(UINT nFlags, CPoint point);
	void OnMButtonUp(UINT nFlags, CPoint point);*/
	void OnMouseMove(UINT nFlags, CPoint point); 
	//void OnLButtonDown(UINT nFlags, CPoint point);
	//void OnRButtonDown(UINT nFlags, CPoint point);
	void CPointCloudMatchinDlg::OnMButtonDown(UINT nFlags, CPoint point);
	void CPointCloudMatchinDlg::OnMButtonUp(UINT nFlags, CPoint point);
	//  void CPointCloudMatchinDlg::OnMouseMove(UINT nFlags, CPoint point);
	BOOL CPointCloudMatchinDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	BOOL CPointCloudMatchinDlg::PreTranslateMessage(MSG* pMsg);




	BOOL midButtonState;
	BOOL ctrlKeyState;

	HDC hrenderDC;  //设备上下文
	 HGLRC hrenderRC;  //渲染上下文
	float m_yRotate;  //转速
	int PixelFormat;    //像素格式
	RoamingScenceManager * manager;

	// 对话框数据
	enum { IDD = IDD_opengl };

	float c; //弧度和角度转换参数
	int du , oldmy , oldmx ; //du是视点绕y轴的角度,opengl里默认y轴是上方向
	float r , h; //r是视点绕y轴的半径,h是视点高度即在y轴上的坐标


	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持



// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnSize(UINT nType, int cx, int cy);

	afx_msg void OnTimer(UINT nIDEvent);
private:
	COpenGL  m_oglWindow;

public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
