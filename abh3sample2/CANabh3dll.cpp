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

#pragma once

//���̃t�@�C���́A���[�U�[���ł̂ݎg�p���܂�
//�iDLL�\�z���ɂ͕s�v�j

//#include "pch.h"			//todo:���p����v���R���p�C���t�@�C�����ɏ��������Ă�������
#include "CANabh3dll.h"

//DLL����֐��̃G���g�����擾����֐��i�{�t�@�C�����ɑ��݁j
static FARPROC GetDllFunc(HMODULE hModule,const char* pFuncName);

//DLL�̊֐����\���̂ɓǂݍ��݂܂�
int32_t GetFunctions(HMODULE hDLL,pCA3_FUNCLIST pFuncList)
	{
	if (hDLL && pFuncList)
		{
		//----------------------------------------
		//Windows�ŗL
		//----------------------------------------

		//�g�p�J�n���ɌĂяo���K�v���L��܂�
		pFuncList->InitInstance				= (CA3_InitInstance)GetDllFunc(hDLL,"InitInstance");
		//�g�p�I�����ɌĂяo���K�v���L��܂�
		pFuncList->ExitInstance				= (CA3_ExitInstance)GetDllFunc(hDLL,"ExitInstance");
		//�g�p�\��CAN�C���^�[�t�F�[�X�����擾
		pFuncList->GetInterfaceCount		= (CA3_GetInterfaceCount)GetDllFunc(hDLL,"GetInterfaceCount");
		//���p����C���^�[�t�F�[�X���w��
		pFuncList->SetInterface				= (CA3_SetInterface)GetDllFunc(hDLL,"SetInterface");
		//���݊J���Ă���C���^�[�t�F�[�X�ԍ����擾
		pFuncList->GetCurrentInterface		= (CA3_GetCurrentInterface)GetDllFunc(hDLL,"GetCurrentInterface");
		//���݃C���^�[�t�F�[�X���J���Ă��邩�H
		pFuncList->IsOpenInterface			= (CA3_IsOpenInterface)GetDllFunc(hDLL,"IsOpenInterface");
		//�C���^�[�t�F�[�X���J���^�C���A�E�g���Ԃ�ݒ�
		pFuncList->SetOpenTimeout			= (CA3_SetOpenTimeout)GetDllFunc(hDLL,"SetOpenTimeout");
		//���M�^�C���A�E�g���Ԃ�ݒ�
		pFuncList->SetSendTimeout			= (CA3_SetSendTimeout)GetDllFunc(hDLL,"SetSendTimeout");
		//��M�^�C���A�E�g���Ԃ�ݒ�
		pFuncList->SetRecvTimeout			= (CA3_SetRecvTimeout)GetDllFunc(hDLL,"SetRecvTimeout");
		//�ʐM�z�X�g�̃A�h���X��ݒ�
		pFuncList->SetHostID				= (CA3_SetHostID)GetDllFunc(hDLL,"SetHostID");
		//�ʐM�z�X�g�̃A�h���X���擾
		pFuncList->GetHostID				= (CA3_GetHostID)GetDllFunc(hDLL,"GetHostID");
		//�ʐM���x���w��
		pFuncList->SetBaudrate				= (CA3_SetBaudrate)GetDllFunc(hDLL,"SetBaudrate");
		//�ݒ肵���ʐM���x���擾
		pFuncList->GetBaudrate				= (CA3_GetBaudrate)GetDllFunc(hDLL,"GetBaudrate");
		//PC���N�����Ă���̎��Ԃ�[ms]�P�ʂŎ擾
		pFuncList->GetTm					= (CA3_GetTm)GetDllFunc(hDLL,"GetTm");
		//�o�X��L�J�E���^�̒l���擾���܂�
		pFuncList->GetCounter				= (CA3_GetCounter)GetDllFunc(hDLL,"GetCounter");
		//����M�J�E���^�̒l���擾���܂�
		pFuncList->GetTransmitCounter		= (CA3_GetTransmitCounter)GetDllFunc(hDLL,"GetTransmitCounter");
		//CAN�o�X�ɃG���[���������Ă��邩���ׂ܂�
		pFuncList->GetCANerror				= (CA3_GetCANerror)GetDllFunc(hDLL,"GetCANerror");
		//CAN�o�X�̃G���[�������s���܂�
		pFuncList->ResetCANerror			= (CA3_ResetCANerror)GetDllFunc(hDLL,"ResetCANerror");

		//----------------------------------------
		//ABH3�ŗL
		//----------------------------------------

		//�w�߂̏������{CAN�|�[�g���J��
		pFuncList->abh3_can_init			= (CA3_abh3_can_init)GetDllFunc(hDLL,"abh3_can_init");
		//CAN�|�[�g���J��
		pFuncList->abh3_can_port_init		= (CA3_abh3_can_port_init)GetDllFunc(hDLL,"abh3_can_port_init");
		//�w�߂̏�����
		pFuncList->abh3_cmd_init			= (CA3_abh3_cmd_init)GetDllFunc(hDLL,"abh3_cmd_init");
		//�w�߂̑��M�i���ʁj
		pFuncList->abh3_can_cmdAY			= (CA3_abh3_can_cmdAY)GetDllFunc(hDLL,"abh3_can_cmdAY");
		pFuncList->abh3_can_cmdBX			= (CA3_abh3_can_cmdBX)GetDllFunc(hDLL,"abh3_can_cmdBX");
		//�w�߂̑��M�i�����j
		pFuncList->abh3_can_cmd				= (CA3_abh3_can_cmd)GetDllFunc(hDLL,"abh3_can_cmd");
		//���͂̑��M�i�ꊇ�j
		pFuncList->abh3_can_opSet			= (CA3_abh3_can_opSet)GetDllFunc(hDLL,"abh3_can_opSet");
		//���͂̑��M�i�r�b�g�j
		pFuncList->abh3_can_opBitSet		= (CA3_abh3_can_opBitSet)GetDllFunc(hDLL,"abh3_can_opBitSet");
		//�w�߂Ɠ��͂̑��M�i�����j
		pFuncList->abh3_can_cmdAndopSet		= (CA3_abh3_can_cmdAndopSet)GetDllFunc(hDLL,"abh3_can_cmdAndopSet");
		//�u���[�h�L���X�g�p�P�b�g�̃��N�G�X�g
		pFuncList->abh3_can_reqBRD			= (CA3_abh3_can_reqBRD)GetDllFunc(hDLL,"abh3_can_reqBRD");
		//�}���`�p�P�b�g�ɂ��TelABH3�p�P�b�g�̑���M
		pFuncList->abh3_can_trans			= (CA3_abh3_can_trans)GetDllFunc(hDLL,"abh3_can_trans");
		//���݂̎�M�f�[�^�󋵂��ꊇ�擾
		pFuncList->abh3_can_copylastdata	= (CA3_abh3_can_copylastdata)GetDllFunc(hDLL,"abh3_can_copylastdata");
		//���݂̎�M�f�[�^�󋵂̍X�V�t���O����������
		pFuncList->abh3_can_resetlastdata	= (CA3_abh3_can_resetlastdata)GetDllFunc(hDLL,"abh3_can_resetlastdata");
		//��M�Ώۂ��w�肵�Ď�M
		pFuncList->abh3_can_read			= (CA3_abh3_can_read)GetDllFunc(hDLL,"abh3_can_read");
		//��M�o�b�t�@�̑S���e����M�f�[�^�󋵂ɔ��f������
		pFuncList->abh3_can_flush			= (CA3_abh3_can_flush)GetDllFunc(hDLL,"abh3_can_flush");
		//CAN�����
		pFuncList->abh3_can_finish			= (CA3_abh3_can_finish)GetDllFunc(hDLL,"abh3_can_finish");
		//���x
		pFuncList->cnvVel2CAN				= (CA3_cnvVel2CAN)GetDllFunc(hDLL,"cnvVel2CAN");
		pFuncList->cnvCAN2Vel				= (CA3_cnvCAN2Vel)GetDllFunc(hDLL,"cnvCAN2Vel");
		//�d��
		pFuncList->cnvCur2CAN				= (CA3_cnvCur2CAN)GetDllFunc(hDLL,"cnvCur2CAN");
		pFuncList->cnvCAN2Cur				= (CA3_cnvCAN2Cur)GetDllFunc(hDLL,"cnvCAN2Cur");
		//���ח�
		pFuncList->cnvCAN2Load				= (CA3_cnvCAN2Load)GetDllFunc(hDLL,"cnvCAN2Load");
		//�A�i���O����
		pFuncList->cnvCAN2Analog			= (CA3_cnvCAN2Analog)GetDllFunc(hDLL,"cnvCAN2Analog");
		//�d���d��
		pFuncList->cnvCAN2Volt				= (CA3_cnvCAN2Volt)GetDllFunc(hDLL,"cnvCAN2Volt");
		//����
		pFuncList->flt_to_pkflt				= (CA3_flt_to_pkflt)GetDllFunc(hDLL,"flt_to_pkflt");
		pFuncList->pkflt_to_flt				= (CA3_pkflt_to_flt)GetDllFunc(hDLL,"pkflt_to_flt");
		pFuncList->str_to_pkfltA			= (CA3_str_to_pkfltA)GetDllFunc(hDLL,"str_to_pkfltA");
		pFuncList->str_to_pkfltW			= (CA3_str_to_pkfltW)GetDllFunc(hDLL,"str_to_pkfltW");
		pFuncList->pkflt_to_strA			= (CA3_pkflt_to_strA)GetDllFunc(hDLL,"pkflt_to_strA");
		pFuncList->pkflt_to_strW			= (CA3_pkflt_to_strW)GetDllFunc(hDLL,"pkflt_to_strW");
		}
	return(0);
	}

//DLL����֐��̃G���g�����擾
FARPROC GetDllFunc(HMODULE hModule,const char* pFuncName)
	{
	FARPROC nResult = GetProcAddress(hModule,pFuncName);
	return(nResult);
	}
