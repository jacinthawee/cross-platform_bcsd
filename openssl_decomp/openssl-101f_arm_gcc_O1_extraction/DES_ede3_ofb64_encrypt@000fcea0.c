
void DES_ede3_ofb64_encrypt
               (uchar *in,uchar *out,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint local_60;
  uint local_40;
  uint local_3c;
  byte local_38 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  int local_2c;
  
  uVar8 = (uint)(*ivec)[3];
  uVar2 = (uint)(*ivec)[2] << 0x10 | (uint)(*ivec)[1] << 8 | (uint)(*ivec)[0] | uVar8 << 0x18;
  local_2c = __TMC_END__;
  uVar4 = *num;
  uVar6 = uVar2 >> 0x10;
  uVar10 = (uint)(*ivec)[7];
  local_60 = uVar2 >> 8;
  uVar3 = (uint)(*ivec)[6] << 0x10 | (uint)(*ivec)[5] << 8 | (uint)(*ivec)[4] | uVar10 << 0x18;
  uVar7 = uVar3 >> 8;
  uVar9 = uVar3 >> 0x10;
  local_38[0] = (*ivec)[0];
  local_38[1] = (*ivec)[1];
  local_38[2] = (*ivec)[2];
  local_38[3] = (*ivec)[3];
  local_34 = (*ivec)[4];
  local_33 = (*ivec)[5];
  local_32 = (*ivec)[6];
  local_31 = (*ivec)[7];
  local_40 = uVar2;
  local_3c = uVar3;
  if (length != 0) {
    iVar5 = 0;
    do {
      if (uVar4 == 0) {
        iVar5 = iVar5 + 1;
        DES_encrypt3(&local_40,ks1,ks2,ks3);
        local_60 = local_40 >> 8;
        uVar6 = local_40 >> 0x10;
        uVar8 = local_40 >> 0x18;
        uVar7 = local_3c >> 8;
        uVar9 = local_3c >> 0x10;
        uVar10 = local_3c >> 0x18;
        local_38[0] = (byte)local_40;
        local_38[1] = (byte)(local_40 >> 8);
        local_38[2] = (byte)(local_40 >> 0x10);
        local_34 = (byte)local_3c;
        local_38[3] = (byte)(local_40 >> 0x18);
        local_33 = (byte)(local_3c >> 8);
        local_32 = (byte)(local_3c >> 0x10);
        local_31 = (byte)(local_3c >> 0x18);
        uVar2 = local_40;
        uVar3 = local_3c;
      }
      length = length + -1;
      pbVar1 = local_38 + uVar4;
      uVar4 = uVar4 + 1 & 7;
      *out = *in ^ *pbVar1;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
    if (iVar5 != 0) {
      (*ivec)[0] = (uchar)uVar2;
      (*ivec)[2] = (uchar)uVar6;
      (*ivec)[1] = (uchar)local_60;
      (*ivec)[3] = (uchar)uVar8;
      (*ivec)[4] = (uchar)uVar3;
      (*ivec)[5] = (uchar)uVar7;
      (*ivec)[6] = (uchar)uVar9;
      (*ivec)[7] = (uchar)uVar10;
    }
  }
  bVar11 = local_2c == __TMC_END__;
  *num = uVar4;
  if (bVar11) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

