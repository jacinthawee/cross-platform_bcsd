
void RC2_ofb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  uint local_40;
  uint local_3c;
  byte local_38 [4];
  byte local_34;
  byte local_33;
  byte local_32;
  byte local_31;
  int local_2c;
  
  local_40 = (uint)*ivec | (uint)ivec[2] << 0x10 | (uint)ivec[1] << 8 | (uint)ivec[3] << 0x18;
  local_3c = (uint)ivec[6] << 0x10 | (uint)ivec[5] << 8 | (uint)ivec[4] | (uint)ivec[7] << 0x18;
  local_38[0] = *ivec;
  local_2c = __TMC_END__;
  local_38[3] = ivec[3];
  local_32 = ivec[6];
  local_38[1] = ivec[1];
  local_38[2] = ivec[2];
  local_34 = ivec[4];
  local_33 = ivec[5];
  local_31 = ivec[7];
  uVar2 = *num;
  if (length != 0) {
    iVar3 = 0;
    do {
      if (uVar2 == 0) {
        RC2_encrypt(&local_40,schedule);
        iVar3 = iVar3 + 1;
        local_38[0] = (byte)local_40;
        local_34 = (byte)local_3c;
        local_38[2] = (byte)(local_40 >> 0x10);
        local_38[3] = (byte)(local_40 >> 0x18);
        local_38[1] = (byte)(local_40 >> 8);
        local_33 = (byte)(local_3c >> 8);
        local_32 = (byte)(local_3c >> 0x10);
        local_31 = (byte)(local_3c >> 0x18);
      }
      length = length + -1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      *out = *pbVar1 ^ *in;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
    if (iVar3 != 0) {
      *ivec = (uchar)local_40;
      ivec[2] = (uchar)(local_40 >> 0x10);
      ivec[4] = (uchar)local_3c;
      ivec[3] = (uchar)(local_40 >> 0x18);
      ivec[1] = (uchar)(local_40 >> 8);
      ivec[5] = (uchar)(local_3c >> 8);
      ivec[6] = (uchar)(local_3c >> 0x10);
      ivec[7] = (uchar)(local_3c >> 0x18);
    }
  }
  bVar4 = local_2c == __TMC_END__;
  *num = uVar2;
  if (bVar4) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

