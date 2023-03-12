
/* WARNING: Restarted to delay deadcode elimination for space: register */

ulonglong bn_GF2m_mul_2x2(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                         undefined4 param_5)

{
  undefined4 *puVar1;
  uint unaff_r4;
  uint uVar2;
  uint unaff_r5;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong extraout_d0;
  ulonglong uVar5;
  ulonglong uVar6;
  
  if ((*(uint *)(DAT_00121500 + 0x1213ec) & 1) != 0) {
    uVar3 = mul_1x1_neon();
    uVar4 = mul_1x1_neon();
    uVar6 = uVar4 ^ uVar3;
    puVar1 = (undefined4 *)mul_1x1_neon();
    uVar5 = VectorShiftLeft(extraout_d0 ^ uVar6,0x20,0x40,0);
    uVar6 = VectorShiftRight(extraout_d0 ^ uVar6,0x20);
    *puVar1 = (int)(uVar4 ^ uVar5);
    puVar1[1] = (int)((uVar4 ^ uVar5) >> 0x20);
    puVar1[2] = (int)(uVar3 ^ uVar6);
    puVar1[3] = (int)((uVar3 ^ uVar6) >> 0x20);
    return uVar6;
  }
  uVar3 = mul_1x1_ialu(param_4,param_2,param_3,param_5);
  param_1[2] = unaff_r5;
  param_1[3] = unaff_r4;
  uVar4 = mul_1x1_ialu(param_5,param_3);
  *param_1 = unaff_r5;
  param_1[1] = unaff_r4;
  uVar3 = mul_1x1_ialu((int)(uVar3 ^ uVar4),(int)((uVar3 ^ uVar4) >> 0x20));
  uVar2 = unaff_r4 ^ param_1[1] ^ param_1[2] ^ param_1[3];
  param_1[2] = uVar2;
  param_1[1] = unaff_r5 ^ unaff_r4 ^ *param_1 ^ param_1[3] ^ uVar2;
  return uVar3;
}

