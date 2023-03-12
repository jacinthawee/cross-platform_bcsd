
void idea_ofb64_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int *num)

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
  
  local_40 = (uint)iv[3] | (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[2] << 8;
  local_3c = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
  local_38[3] = iv[3];
  local_2c = __TMC_END__;
  local_38[2] = iv[2];
  local_33 = iv[5];
  local_38[0] = *iv;
  local_38[1] = iv[1];
  local_31 = iv[7];
  local_34 = iv[4];
  local_32 = iv[6];
  uVar2 = *num;
  if (length != 0) {
    iVar3 = 0;
    do {
      if (uVar2 == 0) {
        idea_encrypt(&local_40,ks);
        iVar3 = iVar3 + 1;
        local_38[3] = (byte)local_40;
        local_31 = (byte)local_3c;
        local_38[1] = (byte)(local_40 >> 0x10);
        local_38[2] = (byte)(local_40 >> 8);
        local_38[0] = (byte)(local_40 >> 0x18);
        local_34 = (byte)(local_3c >> 0x18);
        local_33 = (byte)(local_3c >> 0x10);
        local_32 = (byte)(local_3c >> 8);
      }
      length = length + -1;
      pbVar1 = local_38 + uVar2;
      uVar2 = uVar2 + 1 & 7;
      *out = *pbVar1 ^ *in;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
    if (iVar3 != 0) {
      iv[3] = (uchar)local_40;
      iv[1] = (uchar)(local_40 >> 0x10);
      iv[7] = (uchar)local_3c;
      iv[2] = (uchar)(local_40 >> 8);
      *iv = (uchar)(local_40 >> 0x18);
      iv[4] = (uchar)(local_3c >> 0x18);
      iv[5] = (uchar)(local_3c >> 0x10);
      iv[6] = (uchar)(local_3c >> 8);
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

