/*
 ******************************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2021-2023,2022 Waco Giken Co., Ltd.
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

#include <Windows.h>
#include <stdint.h>
#include "typedef.h"

//============================================================
//�G�N�X�|�[�g����֐����ȒP�Ɉ����ׂ̗v�f
//============================================================

//----------------------------------------
//Windows�ŗL
//----------------------------------------

//�g�p�J�n���ɌĂяo���K�v���L��܂�
typedef void(*CA3_InitInstance)(int32_t);
//�g�p�I�����ɌĂяo���K�v���L��܂�
typedef void (*CA3_ExitInstance)(void);
//�g�p�\��CAN�C���^�[�t�F�[�X�����擾
typedef int32_t(*CA3_GetInterfaceCount)(void);
//���p����C���^�[�t�F�[�X���w��
typedef int32_t(*CA3_SetInterface)(int32_t);
//���݊J���Ă���C���^�[�t�F�[�X�ԍ����擾
typedef int32_t(*CA3_GetCurrentInterface)(void);
//���݃C���^�[�t�F�[�X���J���Ă��邩�H
typedef int32_t(*CA3_IsOpenInterface)(void);
//�C���^�[�t�F�[�X���J���^�C���A�E�g���Ԃ�ݒ�
typedef void(*CA3_SetOpenTimeout)(uint32_t);
//���M�^�C���A�E�g���Ԃ�ݒ�
typedef void(*CA3_SetSendTimeout)(uint32_t);
//��M�^�C���A�E�g���Ԃ�ݒ�
typedef void(*CA3_SetRecvTimeout)(uint32_t);
//�ʐM�z�X�g�̃A�h���X��ݒ�
typedef void(*CA3_SetHostID)(uint8_t);
//�ʐM�z�X�g�̃A�h���X���擾
typedef uint8_t(*CA3_GetHostID)(void);
//�ʐM���x���w��
typedef void(*CA3_SetBaudrate)(uint32_t);
//�ݒ肵���ʐM���x���擾
typedef uint32_t(*CA3_GetBaudrate)(void);
//PC���N�����Ă���̎��Ԃ�[ms]�P�ʂŎ擾
typedef uint32_t(*CA3_GetTm)(void);
//�o�X��L�J�E���^���擾���܂�
typedef uint32_t(*CA3_GetCounter)(void);
//����M�J�E���^���擾���܂�
typedef uint32_t(*CA3_GetTransmitCounter)(uint8_t);
//CAN�o�X�ɃG���[���������Ă��邩���ׂ܂�
typedef uint32_t(*CA3_GetCANerror)(void);
//CAN�o�X�̃G���[�������s���܂�
typedef uint32_t(*CA3_ResetCANerror)(void);

//----------------------------------------
//ABH3�ŗL
//----------------------------------------

//�w�߂̏������{CAN�|�[�g���J��
typedef int32_t(*CA3_abh3_can_init)(uint8_t,pCANABH3_RESULT);
//CAN�|�[�g���J��
typedef int32_t(*CA3_abh3_can_port_init)(void);
//�w�߂̏�����
typedef int32_t(*CA3_abh3_cmd_init)(uint8_t,pCANABH3_RESULT);
//���݂̎�M�f�[�^�󋵂��ꊇ�擾
typedef void(*CA3_abh3_can_copylastdata)(uint8_t,pCANABH3_LASTRECV);
//���݂̎�M�f�[�^�󋵂̍X�V�t���O����������
typedef void(*CA3_abh3_can_resetlastdata)(uint8_t,int32_t);
//��M�Ώۂ��w�肵�Ď�M
typedef int32_t(*CA3_abh3_can_read)(uint8_t,pCANABH3_RESULT,PACKETTYPE,uint8_t);
//��M�ς݃f�[�^����M�f�[�^�󋵂ɔ��f������
typedef int32_t(*CA3_abh3_can_flush)(void);
//�w�߂̑��M�i���ʁj
typedef int32_t(*CA3_abh3_can_cmdAY)(uint8_t,int16_t,pCANABH3_RESULT);
typedef int32_t(*CA3_abh3_can_cmdBX)(uint8_t,int16_t,pCANABH3_RESULT);
//�w�߂̑��M�i�����j
typedef int32_t(*CA3_abh3_can_cmd)(uint8_t,int16_t,int16_t,pCANABH3_RESULT);
//���͂̑��M�i�ꊇ�j
typedef int32_t(*CA3_abh3_can_opSet)(uint8_t,int32_t,int32_t,pCANABH3_RESULT);
//���͂̑��M�i�r�b�g�j
typedef int32_t(*CA3_abh3_can_opBitSet)(uint8_t,int8_t,int8_t,pCANABH3_RESULT);
//�w�߂Ɠ��͂̑��M�i�����j
typedef int32_t(*CA3_abh3_can_cmdAndopSet)(uint8_t,int16_t,int16_t,int32_t,int32_t,pCANABH3_RESULT);
//�u���[�h�L���X�g�p�P�b�g�̃��N�G�X�g
typedef int32_t(*CA3_abh3_can_reqBRD)(uint8_t,uint8_t,uint8_t,pCANABH3_RESULT);
//�}���`�p�P�b�g�ɂ��TelABH3�p�P�b�g�̑���M
typedef int32_t(*CA3_abh3_can_trans)(uint8_t,char*,char*,uint32_t*);
//CAN�����
typedef int32_t(*CA3_abh3_can_finish)(void);
//���x
typedef int16_t(*CA3_cnvVel2CAN)(float vel);
typedef float(*CA3_cnvCAN2Vel)(int16_t vel);
//�d��
typedef int16_t(*CA3_cnvCur2CAN)(float);
typedef float(*CA3_cnvCAN2Cur)(int16_t);
//���ח�
typedef float(*CA3_cnvCAN2Load)(int16_t);
//�A�i���O����
typedef float(*CA3_cnvCAN2Analog)(int16_t);
//�d���d��
typedef float(*CA3_cnvCAN2Volt)(int16_t);
//����
typedef PACK_FLOAT(*CA3_flt_to_pkflt)(float);
typedef float(*CA3_pkflt_to_flt)(PACK_FLOAT);
typedef int(*CA3_str_to_pkfltA)(const char*,PACK_FLOAT*);
typedef int(*CA3_str_to_pkfltW)(const wchar_t*,PACK_FLOAT*);
typedef char*(*CA3_pkflt_to_strA)(PACK_FLOAT,char*);
typedef char*(*CA3_pkflt_to_strW)(PACK_FLOAT,wchar_t*);

//============================================================
//DLL�̑S�֐��������ׂ̍\����
//============================================================

//DLL�t�@���N�V�����֐��A�h���X�Ǘ�
typedef struct _CA3_FUNCLIST
	{
	//----------------------------------------
	//Windows�ŗL
	//----------------------------------------

	//�g�p�J�n���ɌĂяo���K�v���L��܂�
	CA3_InitInstance		InitInstance;
	//�g�p�I�����ɌĂяo���K�v���L��܂�
	CA3_ExitInstance		ExitInstance;
	//�g�p�\��CAN�C���^�[�t�F�[�X�����擾
	CA3_GetInterfaceCount	GetInterfaceCount;
	//�g�p����C���^�[�t�F�[�X���w�肷��
	CA3_SetInterface		SetInterface;
	//���݊J���Ă���C���^�[�t�F�[�X�ԍ����擾
	CA3_GetCurrentInterface	GetCurrentInterface;
	//���݃C���^�[�t�F�[�X���J���Ă��邩�H
	CA3_IsOpenInterface		IsOpenInterface;
	//�C���^�[�t�F�[�X���J���^�C���A�E�g���Ԃ�ݒ�
	CA3_SetOpenTimeout		SetOpenTimeout;
	//���M�^�C���A�E�g���Ԃ�ݒ�
	CA3_SetSendTimeout		SetSendTimeout;
	//��M�^�C���A�E�g���Ԃ�ݒ�
	CA3_SetRecvTimeout		SetRecvTimeout;
	//�ʐM�z�X�g�̃A�h���X��ݒ�
	CA3_SetHostID			SetHostID;
	//�ʐM�z�X�g�̃A�h���X���擾
	CA3_GetHostID			GetHostID;
	//�ʐM���x���w��
	CA3_SetBaudrate			SetBaudrate;
	//�ݒ肵���ʐM���x���擾
	CA3_GetBaudrate			GetBaudrate;
	//PC���N�����Ă���̎��Ԃ�[ms]�P�ʂŎ擾
	CA3_GetTm				GetTm;
	//�o�X�J�E���^�̒l���擾���܂�
	CA3_GetCounter			GetCounter;
	//����M�J�E���^�̒l���擾���܂�
	CA3_GetTransmitCounter	GetTransmitCounter;
	//CAN�o�X�ɃG���[���������Ă��邩���ׂ܂�
	CA3_GetCANerror			GetCANerror;
	//CAN�o�X�̃G���[�������s���܂�
	CA3_ResetCANerror		ResetCANerror;

	//----------------------------------------
	//ABH3�ŗL
	//----------------------------------------

	//�w�߂̏������{CAN�|�[�g���J��
	CA3_abh3_can_init			abh3_can_init;
	//CAN�|�[�g���J��
	CA3_abh3_can_port_init		abh3_can_port_init;
	//�w�߂̏�����
	CA3_abh3_cmd_init			abh3_cmd_init;
	//���݂̎�M�f�[�^�󋵂��ꊇ�擾
	CA3_abh3_can_copylastdata	abh3_can_copylastdata;
	//���݂̎�M�f�[�^�󋵂̍X�V�t���O����������
	CA3_abh3_can_resetlastdata	abh3_can_resetlastdata;
	//��M�Ώۂ��w�肵�Ď�M
	CA3_abh3_can_read			abh3_can_read;
	//��M�o�b�t�@�̓��e����M�f�[�^�󋵂ɔ��f
	CA3_abh3_can_flush			abh3_can_flush;
	//�w�߂̑��M�i���ʁj
	CA3_abh3_can_cmdAY			abh3_can_cmdAY;
	CA3_abh3_can_cmdBX			abh3_can_cmdBX;
	//�w�߂̑��M�i�����j
	CA3_abh3_can_cmd			abh3_can_cmd;
	//���͂̑��M�i�ꊇ�j
	CA3_abh3_can_opSet			abh3_can_opSet;
	//���͂̑��M�i�r�b�g�j
	CA3_abh3_can_opBitSet		abh3_can_opBitSet;
	//�w�߂Ɠ��͂̑��M�i�����j
	CA3_abh3_can_cmdAndopSet	abh3_can_cmdAndopSet;

	//�u���[�h�L���X�g�p�P�b�g�̃��N�G�X�g
	CA3_abh3_can_reqBRD			abh3_can_reqBRD;
	//�}���`�p�P�b�g�ɂ��TelABH3�p�P�b�g�̑���M
	CA3_abh3_can_trans			abh3_can_trans;
	//CAN�����
	CA3_abh3_can_finish			abh3_can_finish;
	//���x
	CA3_cnvVel2CAN				cnvVel2CAN;
	CA3_cnvCAN2Vel				cnvCAN2Vel;
	//�d��
	CA3_cnvCAN2Cur				cnvCAN2Cur;
	CA3_cnvCur2CAN				cnvCur2CAN;
	//���ח�
	CA3_cnvCAN2Load				cnvCAN2Load;
	//�A�i���O����
	CA3_cnvCAN2Analog			cnvCAN2Analog;
	//�d���d��
	CA3_cnvCAN2Volt				cnvCAN2Volt;
	//����
	CA3_flt_to_pkflt			flt_to_pkflt;
	CA3_pkflt_to_flt			pkflt_to_flt;
	CA3_str_to_pkfltA			str_to_pkfltA;
	CA3_str_to_pkfltW			str_to_pkfltW;
	CA3_pkflt_to_strA			pkflt_to_strA;
	CA3_pkflt_to_strW			pkflt_to_strW;
	} CA3_FUNCLIST,*pCA3_FUNCLIST;

//DLL�̊֐����ꊇ�ň����ׂ̊֐���`
int32_t GetFunctions(HMODULE hDLL,pCA3_FUNCLIST pFuncList);
