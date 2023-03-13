
void DES_ede3_ofb64_encrypt
               (uchar *in,uchar *out,long length,DES_key_schedule *ks1,DES_key_schedule *ks2,
               DES_key_schedule *ks3,DES_cblock *ivec,int *num)

{
  byte *pbVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  int local_54;
  uint local_30;
  undefined4 local_2c;
  byte local_28 [4];
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar4 = *num;
  uVar2 = *(uint *)*ivec;
  uVar3 = *(undefined4 *)(*ivec + 4);
  local_28[0] = (byte)uVar2;
  local_24 = (char)uVar3;
  local_28[1] = (char)(uVar2 >> 8);
  local_28[2] = (char)(uVar2 >> 0x10);
  local_28[3] = (char)(uVar2 >> 0x18);
  local_23 = (char)((uint)uVar3 >> 8);
  local_22 = (char)((uint)uVar3 >> 0x10);
  local_21 = (char)((uint)uVar3 >> 0x18);
  local_30 = uVar2;
  local_2c = uVar3;
  if (length != 0) {
    local_54 = 0;
    do {
      if (uVar4 == 0) {
        DES_encrypt3(&local_30,ks1,ks2,ks3);
        local_54 = local_54 + 1;
        local_28[0] = (byte)local_30;
        local_24 = (char)local_2c;
        local_28[1] = (char)(local_30 >> 8);
        local_28[2] = (char)(local_30 >> 0x10);
        local_28[3] = (char)(local_30 >> 0x18);
        local_23 = (char)((uint)local_2c >> 8);
        local_22 = (char)((uint)local_2c >> 0x10);
        local_21 = (char)((uint)local_2c >> 0x18);
        uVar2 = local_30;
        uVar3 = local_2c;
      }
      pbVar1 = local_28 + uVar4;
      uVar4 = uVar4 + 1 & 7;
      length = length + -1;
      *out = *in ^ *pbVar1;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
    if (local_54 != 0) {
      (*ivec)[1] = (uchar)(uVar2 >> 8);
      (*ivec)[0] = (uchar)uVar2;
      (*ivec)[4] = (uchar)uVar3;
      (*ivec)[2] = (uchar)(uVar2 >> 0x10);
      (*ivec)[3] = (uchar)(uVar2 >> 0x18);
      (*ivec)[5] = (uchar)((uint)uVar3 >> 8);
      (*ivec)[7] = (uchar)((uint)uVar3 >> 0x18);
      (*ivec)[6] = (uchar)((uint)uVar3 >> 0x10);
    }
  }
  *num = uVar4;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

