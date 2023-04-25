/*
 ******************************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2021-2023, Waco Giken Co., Ltd.
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

//���d�C���N���[�h�h�~
#ifndef _TYPEDEF_H_INCLUDED_
#define _TYPEDEF_H_INCLUDED_

//�v���b�g�t�H�[���ˑ�
#include <Windows.h>
#include <stdint.h>

//================================================================================
//���[�U�[�����p�\�Ȍ^
//================================================================================

//�p�P�b�g��ނ̎w��p
typedef enum
	{
	UNKNOWN_PACKET		= 0,	//�����p�i���[�U�[�ł͗��p���Ȃ��j
	SINGLE_PACKET		= 1,	//�ԓ��F�V���O���p�P�b�g
	BROADCAST_PACKET	= 2,	//�ԓ��F�u���[�h�L���X�g�p�P�b�g
	//SINGLE_PACKET_W		= 3,	//�v���F�V���O���p�P�b�g
	//BROADCAST_PACKET_W	= 4,	//�v���F�u���[�h�L���X�g�p�P�b�g
	ANY_PACKET			= 0,	//�p�P�b�g��ނ���Ȃ�
	} PACKETTYPE;

//��M�Ɏg�p����\���́i��M���{��M�f�[�^8�o�C�g�j
typedef struct _CANABH3_RESULT
	{
	//��M�f�[�^��CAN-ID
	uint32_t	nID;

	//���L��
	union
		{
		//�����p
		uint8_t		raw[8];

		//�V���O���p�P�b�g(DP0)
		struct _DP0R
			{
			int16_t		nBackAY;			//	A/Y�A��
			int16_t		nBackBX;			//	B/X�A��
			uint32_t	nCtrlBit;			//	����t���O
			} DP0R;
		//�u���[�h�L���X�g�p�P�b�g(0)
		struct _BR0
			{
			uint32_t	nErrorBit;			//	�ُ�t���O
			uint32_t	nWarnBit;			//	�x���t���O
			} BR0;
		//�u���[�h�L���X�g�p�P�b�g(1)
		struct _BR1
			{
			uint32_t	nIoBit;				//	IO�t���O
			uint32_t	nCtrlBit;			//	���̓t���O
			} BR1;
		//�u���[�h�L���X�g�p�P�b�g(2)
		struct _BR2
			{
			int16_t		nOrderSpeedAY;		//	A/Y���x�w��
			int16_t		nOrderSpeedBX;		//	B/X���x�w��
			int16_t		nBackSpeedAY;		//	A/Y���x�A��
			int16_t		nBackSpeedBX;		//	B/X���x�A��
			} BR2;
		//�u���[�h�L���X�g�p�P�b�g(3)
		struct _BR3
			{	
			int16_t		nOrderCurrentAY;	//	A/Y�d���w��
			int16_t		nOrderCurrentBX;	//	B/X�d���w��
			int16_t		nLoadA;				//	A���ח�
			int16_t		nLoadB;				//	B���ח�
			} BR3;
		//�u���[�h�L���X�g�p�P�b�g(4)
		struct _BR4
			{
			int32_t		nCountPulseA;		//	A�p���X�ώZ�l
			int32_t		nCountPulseB;		//	B�p���X�ώZ�l
			} BR4;
		//�u���[�h�L���X�g�p�P�b�g(5)
		struct _BR5
			{
			int16_t		nAnalog0;			//	�A�i���O����0
			int16_t		nAnalog1;			//	�A�i���O����1
			int16_t		nPowerMain;			//	��d���d��
			int16_t		nPowerCtrl;			//	����d���d��
			} BR5;
		//�u���[�h�L���X�g�p�P�b�g(6)
		struct _BR6
			{
			float		nMonitor0;			//	���j�^0�f�[�^
			float		nMonitor1;			//	���j�^1�f�[�^
			} BR6;
		} u;
	} CANABH3_RESULT,*pCANABH3_RESULT;

//�ŏI��M�f�[�^�p�\����
typedef struct _CANABH3_LASTRECV
	{
	//�V���O���p�P�b�g(DP0)
	struct _DP0R
		{
		int16_t		nBackAY;				//	A/Y�A��
		int16_t		nBackBX;				//	B/X�A��
		uint32_t	nCtrlBit;				//	����t���O
		} DP0R;
	//�u���[�h�L���X�g�p�P�b�g(0)
	struct _BR0
		{
		uint32_t	nErrorBit;				//	�ُ�t���O
		uint32_t	nWarnBit;				//	�x���t���O
		} BR0;
	//�u���[�h�L���X�g�p�P�b�g(1)
	struct _BR1
		{
		uint32_t	nIoBit;					//	IO�t���O
		uint32_t	nCtrlBit;				//	���̓t���O
		} BR1;
	//�u���[�h�L���X�g�p�P�b�g(2)
	struct _BR2
		{
		int16_t		nOrderSpeedAY;			//	A/Y���x�w��
		int16_t		nOrderSpeedBX;			//	B/X���x�w��
		int16_t		nBackSpeedAY;			//	A/Y���x�A��
		int16_t		nBackSpeedBX;			//	B/X���x�A��
		} BR2;
	//�u���[�h�L���X�g�p�P�b�g(3)
	struct _BR3
		{	
		int16_t		nOrderCurrentAY;		//	A/Y�d���w��
		int16_t		nOrderCurrentBX;		//	B/X�d���w��
		int16_t		nLoadA;					//	A���ח�
		int16_t		nLoadB;					//	B���ח�
		} BR3;
	//�u���[�h�L���X�g�p�P�b�g(4)
	struct _BR4
		{
		int32_t		nCountPulseA;			//	A�p���X�ώZ�l
		int32_t		nCountPulseB;			//	B�p���X�ώZ�l
		} BR4;
	//�u���[�h�L���X�g�p�P�b�g(5)
	struct _BR5
		{
		int16_t		nAnalog0;				//	�A�i���O����0
		int16_t		nAnalog1;				//	�A�i���O����1
		int16_t		nPowerMain;				//	��d���d��
		int16_t		nPowerCtrl;				//	����d���d��
		} BR5;
	//�u���[�h�L���X�g�p�P�b�g(6)
	struct _BR6
		{
		float		nMonitor0;				//	���j�^0�f�[�^
		float		nMonitor1;				//	���j�^1�f�[�^
		} BR6;
	//�e�i�[�ꏊ�̍X�V�t���O
	struct _UPDATE
		{
		uint8_t		nUpdate;				//0�ȊO�Œl���X�V����Ă���i��M���Ă���j
		} update[8];						//0..DP0R  1..BR0  2..BR1  ....  7..BR6
	} CANABH3_LASTRECV,*pCANABH3_LASTRECV;

//PACK_FLOAT�\����
typedef struct _PACK_FLOAT
	{
	union
		{
		struct _PACK_FLOAT_INFO
			{
			//LSB������L��(�����n�ɒ���)
			int32_t kasuu:21;			// ������(-999999�`0�`99999)
			int32_t shousuutenn:4;		// �����_(-8�`0�`7)
			int32_t shisuu:7;			// �w����(-64�`0�`63)
			//�����炪MSB��
			} info;
		int32_t	nDirectData;			// ���ڃA�N�Z�X�p
		} u;
	} *pPACK_FLOAT,PACK_FLOAT;

#endif	//���d�C���N���[�h�h�~
