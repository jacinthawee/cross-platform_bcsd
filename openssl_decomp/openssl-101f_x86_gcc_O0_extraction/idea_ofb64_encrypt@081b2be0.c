
void idea_ofb64_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int *num)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  int in_GS_OFFSET;
  int local_50;
  uint local_48;
  uint local_30;
  uint local_2c;
  byte local_28 [4];
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar2 = *(uint *)iv;
  local_48 = *num;
  local_30 = uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18;
  local_28[3] = (char)(uVar2 >> 0x18);
  uVar3 = *(uint *)(iv + 4);
  local_28[0] = (byte)uVar2;
  local_2c = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  local_28[1] = (char)((uVar2 & 0xff00) >> 8);
  local_24 = (char)uVar3;
  local_28[2] = (char)((uVar2 & 0xff0000) >> 0x10);
  local_21 = (char)(uVar3 >> 0x18);
  local_23 = (char)((uVar3 & 0xff00) >> 8);
  local_22 = (char)((uVar3 & 0xff0000) >> 0x10);
  if (length != 0) {
    local_50 = 0;
    do {
      if (local_48 == 0) {
        idea_encrypt(&local_30,ks);
        local_50 = local_50 + 1;
        local_28[3] = (char)local_30;
        local_28[0] = (byte)(local_30 >> 0x18);
        local_28[1] = (char)(local_30 >> 0x10);
        local_28[2] = (char)(local_30 >> 8);
        local_21 = (char)local_2c;
        local_24 = (char)(local_2c >> 0x18);
        local_23 = (char)(local_2c >> 0x10);
        local_22 = (char)(local_2c >> 8);
      }
      pbVar1 = local_28 + local_48;
      local_48 = local_48 + 1 & 7;
      length = length + -1;
      *out = *in ^ *pbVar1;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
    if (local_50 != 0) {
      iv[3] = (uchar)local_30;
      iv[7] = (uchar)local_2c;
      *iv = (uchar)(local_30 >> 0x18);
      iv[1] = (uchar)(local_30 >> 0x10);
      iv[4] = (uchar)(local_2c >> 0x18);
      iv[2] = (uchar)(local_30 >> 8);
      iv[5] = (uchar)(local_2c >> 0x10);
      iv[6] = (uchar)(local_2c >> 8);
    }
  }
  *num = local_48;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

