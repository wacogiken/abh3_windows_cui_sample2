/*
 ******************************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2021, Waco Giken Co., Ltd.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/o2r other materials provided
 *     with the distribution.
 *   * Neither the name of the Waco Giken nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************
*/
/*
******************************************************************************
@file           abh3sample2.cpp
******************************************************************************
@brief          ABH3用CAN サンプルソフト(アプリケーション)
******************************************************************************
@date           2022.04.25
@author         Y.Ogawa
@note			1st release
@note           This sourcecode is based by "test_canABH3.c"
******************************************************************************
*/

//#include "stdafx.h"
#include <SDKDDKVer.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <tchar.h>
#include <stdint.h>
#include "typedef.h"
#include "CANabh3dll.h"


//読み込むDLLファイル
#define DLLFILE1		_T("canABH3.dll")		//HMS社 USB-to-CAN v2
#define	DLLFILE2		_T("CANwacousb.dll");	//WACOGIKEN社 USB-to-CAN

//設定要素
static uint8_t g_USEIF = 0;		//0..HMS USB-to-CAN V2デバイスを使用	1..wacousbcanデバイスを使用
static uint8_t g_IFNUM = 0;		//USB-to-CANの場合何本目か(0開始)、wacousbcanの場合COMポート番号(1開始)
static uint8_t g_TGTID = 1;		//ターゲット(ABH3)側で使用するID
static uint8_t g_HOSTID = 2;	//ホスト(PC)側で使用するID
static uint8_t g_BRDGRP = 5;	//ブロードキャストグループ番号
#define	OPENMS		(1000)		//回線を開く場合のタイムアウト値[ms]
#define SENDMS		(1000)		//送信する場合のタイムアウト値[ms]
#define RECVMS		(1000)		//受信する場合のタイムアウト値[ms]
#define	BAUDRATE	(250)		//CAN通信に使用するボーレート[kbps]

//DLLの関数を簡単に使う為の構造体
CA3_FUNCLIST funcList;

//コンソール入力用
uint8_t ValueInput(uint8_t nDefaultValue)
	{
	uint8_t nResult = nDefaultValue;
	_tprintf(_T("入力（リターンキーのみの場合、%d）"),nDefaultValue);
	char* pBuffer = new char[16]();
	fgets(pBuffer,16,stdin);
	if(::strlen(pBuffer) > 1)
		nResult = (uint8_t)::strtoul(pBuffer,NULL,10);
	delete [] pBuffer;
	return(nResult);
	}

//
void broadCastLoop(int ms)
	{
	//送信データと受信データの格納先
	CANABH3_RESULT res;

	int i,j;

	for (i = 0; i < 1; i++)
		{
		for (j = 0; j < 7; j++)
			{
			funcList.abh3_can_reqBRD(g_TGTID,g_BRDGRP * 8 + j,0,&res);
			switch (j)
				{
				case 0:
					::_tprintf(_T("Error: %08x  Alarm: %08x\n")
						,res.u.BR0.nErrorBit
						,res.u.BR0.nWarnBit
						);
					break;
				case 1:
					::_tprintf(_T("control: %08x  in_out: %08x\n")
						,res.u.BR1.nCtrlBit
						,res.u.BR1.nIoBit
						);
					break;
				case 2:
					::_tprintf(_T("velCmdAY: %10.6f  velCmdBX: %10.6f  velFbkAY: %10.6f  velFbkBX: %10.6f\n")
						,funcList.cnvCAN2Vel(res.u.BR2.nOrderSpeedAY)
						,funcList.cnvCAN2Vel(res.u.BR2.nOrderSpeedBX)
						,funcList.cnvCAN2Vel(res.u.BR2.nBackSpeedAY)
						,funcList.cnvCAN2Vel(res.u.BR2.nBackSpeedBX)
						);
					break;
				case 3:
					::_tprintf(_T("curCmdAY: %10.6f  curCmdBX: %10.6f  loadA: %10.6f  loadB: %10.6f\n")
						,funcList.cnvCAN2Cur(res.u.BR3.nOrderCurrentAY)
						,funcList.cnvCAN2Cur(res.u.BR3.nOrderCurrentBX)
						,funcList.cnvCAN2Load(res.u.BR3.nLoadA)
						,funcList.cnvCAN2Load(res.u.BR3.nLoadB)
						);
					break;
				case 4:
					::_tprintf(_T("pulseA: %d  pulseB: %d\n")
						,res.u.BR4.nCountPulseA
						,res.u.BR4.nCountPulseB
						);
					break;
				case 5:
					::_tprintf(_T("analog0: %10.6f  analog1: %10.6f  mainVolt: %10.6f  controlVolt: %10.6f\n")
						,funcList.cnvCAN2Analog(res.u.BR5.nAnalog0)
						,funcList.cnvCAN2Analog(res.u.BR5.nAnalog1)
						,funcList.cnvCAN2Volt(res.u.BR5.nPowerMain)
						,funcList.cnvCAN2Volt(res.u.BR5.nPowerCtrl)
						);
					break;
				case 6:
					::_tprintf(_T("monitor0: %10.6f  monitor1: %10.6f\n")
						,res.u.BR6.nMonitor0
						,res.u.BR6.nMonitor1
					);
					break;
				case 7:
					::_tprintf(_T("BRD7: %d %d %d %d %d %d %d %d\n")
						,res.u.raw[0]
						,res.u.raw[1]
						,res.u.raw[2]
						,res.u.raw[3]
						,res.u.raw[4]
						,res.u.raw[5]
						,res.u.raw[6]
						,res.u.raw[7]
						);
					break;
				}

			Sleep(ms);
			}
		::_tprintf(_T("\n"));
		}
	}

//メイン
int main()
	{
	//戻り値
	int nResult = 0;

	//========================================
	//動作環境依存要素
	//========================================

	//コンソールに日本語表示する為に必要な設定
	::_tsetlocale(LC_ALL,_T(""));

	//DLLを選択する
	TCHAR* pDLLFILENAME = NULL;
	_tprintf(_T("使用ケーブル種類\n"));
	_tprintf(_T("　(0)HMS社 USB-to-CAN V2\n"));
	_tprintf(_T("　(1)WACOGIKEN社 USB-to-CAN\n"));
	g_USEIF = ValueInput(g_USEIF);
	if(g_USEIF == 0)
		{
		_tprintf(_T("貴方の選択：(0)HMS社 USB-to-CAN V2\n\n"));
		pDLLFILENAME = (TCHAR*)DLLFILE1;
		}
	else
		{
		_tprintf(_T("貴方の選択：(1)WACOGIKEN社 USB-to-CAN\n\n"));
		pDLLFILENAME = (TCHAR*)DLLFILE2;
		}

	//ケーブル番号又はCOMポート番号を指定する
	if(g_USEIF == 0)
		{
		_tprintf(_T("使用ケーブル番号\n"));
		_tprintf(_T("　0で最初の1本目を指定\n"));
		_tprintf(_T("　1で2本目を指定（以下同様）\n"));
		g_IFNUM = ValueInput(g_IFNUM);
		_tprintf(_T("貴方の選択：%d本目のケーブルを指定\n\n"),g_IFNUM + 1);
		}
	else
		{
		_tprintf(_T("使用COMポート番号\n"));
		_tprintf(_T("　1でCOM1を指定\n"));
		_tprintf(_T("　2でCOM2を指定（以下同様にポート番号を指定）\n"));
		g_IFNUM = ValueInput(1);
		_tprintf(_T("貴方の選択：COM%dを指定\n\n"),g_IFNUM);
		}

	//ホストのID
	_tprintf(_T("接続元ID番号\n"));
	_tprintf(_T("　接続元となる、このPCで使うCAN-ID番号（1～254）を指定して下さい\n"));
	g_HOSTID = ValueInput(g_HOSTID);
	_tprintf(_T("貴方の選択：接続元CAN-ID:%d\n\n"),g_HOSTID);

	//接続先のID
	_tprintf(_T("接続先ID番号\n"));
	_tprintf(_T("　接続先となる、ABH3のCAN-ID番号（1～254）を指定して下さい\n"));
	g_TGTID = ValueInput(g_TGTID);
	_tprintf(_T("貴方の選択：接続先CAN-ID:%d\n\n"),g_TGTID);

	//グループ番号
	_tprintf(_T("接続先グループ番号\n"));
	_tprintf(_T("　接続先のブロードキャストグループ番号（0～31）を指定して下さい\n"));
	g_BRDGRP = ValueInput(g_BRDGRP);
	_tprintf(_T("貴方の選択：接続先ブロードキャスト番号:%d\n\n"),g_BRDGRP);

	//DLL読み込み
	_tprintf(_T("DLL(%s)を読み込みます\n"),pDLLFILENAME);
	HMODULE hDLL = ::LoadLibrary(pDLLFILENAME);
	if (hDLL == NULL)
		{
		::_tprintf(_T("異常：DLLが読み込めません\n"));
		return(1);
		}
	_tprintf(_T("DLLを読み込みました\n"));

	//DLLの関数を楽に扱う為、用意された構造体にエントリを一括設定
	GetFunctions(hDLL,&funcList);


	//DLLの使い始めに1回だけ呼び出す関数
	funcList.InitInstance(g_USEIF);
	_tprintf(_T("DLLの利用を開始しました\n\n"));

	//インターフェースが使用するボーレートを設定
	funcList.SetBaudrate(BAUDRATE);
	::_tprintf(_T("ボーレートを、%d [Kbps]で設定しました\n\n"),BAUDRATE);

	//処理開始
	do
		{
		//通信のタイムアウト時間を設定
		funcList.SetOpenTimeout(OPENMS);
		funcList.SetSendTimeout(SENDMS);
		funcList.SetRecvTimeout(RECVMS);
		_tprintf(_T("タイムアウト設定を行いました\n\n"));

		//ホスト(PC)のIDを設定
		funcList.SetHostID(g_HOSTID);
		_tprintf(_T("送信元のCAN-IDを設定しました\n\n"));

		//利用するCANインターフェースを指定
		funcList.SetInterface(g_IFNUM);
		_tprintf(_T("利用するインターフェースを設定しました\n"));

		//CANインターフェースを開いて指令の初期化
		nResult = funcList.abh3_can_port_init();
		if (nResult)
			{
			::_tprintf(_T("初期設定コマンド(abh3_can_portinit)が失敗(%d)しました\n\n"),nResult);
			break;
			}
		else
			{
			::_tprintf(_T("初期設定コマンド(abh3_can_init)が成功しました\n\n"));
			::_tprintf(_T("初期設定コマンド(abh3_can_init)で開いたインターフェース番号は、%dです\n\n"),g_IFNUM);
			}

		//
		broadCastLoop(10);

		break;
		} while (1);

	//通信回線を閉じる
	funcList.abh3_can_finish();
	_tprintf(_T("インターフェースの利用を終了しました\n\n"));

	//終了処理
	funcList.ExitInstance();
	_tprintf(_T("DLLの利用を終了しました\n\n"));

	//========================================
	//動作環境依存要素
	//========================================

	//DLL開放
	::FreeLibrary(hDLL);
	_tprintf(_T("DLLを解放しました\n\n"));

	//終了
	return nResult;
	}

