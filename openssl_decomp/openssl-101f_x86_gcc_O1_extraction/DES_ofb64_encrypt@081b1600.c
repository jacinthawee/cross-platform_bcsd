
void DES_ofb64_encrypt(uchar *in,uchar *out,long length,DES_key_schedule *schedule,DES_cblock *ivec,
                      int *num)

{
  byte *pbVar1;
  int in_GS_OFFSET;
  int local_50;
  uint local_48;
  uint local_30;
  undefined4 local_2c;
  byte local_28 [4];
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_21;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_30 = *(uint *)*ivec;
  local_48 = *num;
  local_28[0] = (byte)local_30;
  local_2c = *(undefined4 *)(*ivec + 4);
  local_28[1] = (char)(local_30 >> 8);
  local_28[3] = (char)(local_30 >> 0x18);
  local_24 = (char)local_2c;
  local_28[2] = (char)(local_30 >> 0x10);
  local_23 = (char)((uint)local_2c >> 8);
  local_21 = (char)((uint)local_2c >> 0x18);
  local_22 = (char)((uint)local_2c >> 0x10);
  if (length != 0) {
    local_50 = 0;
    do {
      if (local_48 == 0) {
        DES_encrypt1(&local_30,schedule,1);
        local_50 = local_50 + 1;
        local_28[0] = (byte)local_30;
        local_28[1] = (char)(local_30 >> 8);
        local_28[3] = (char)(local_30 >> 0x18);
        local_28[2] = (char)(local_30 >> 0x10);
        local_24 = (char)local_2c;
        local_23 = (char)((uint)local_2c >> 8);
        local_21 = (char)((uint)local_2c >> 0x18);
        local_22 = (char)((uint)local_2c >> 0x10);
      }
      pbVar1 = local_28 + local_48;
      local_48 = local_48 + 1 & 7;
      length = length + -1;
      *out = *in ^ *pbVar1;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
    if (local_50 != 0) {
      (*ivec)[0] = (uchar)local_30;
      (*ivec)[4] = (uchar)local_2c;
      (*ivec)[3] = (uchar)(local_30 >> 0x18);
      (*ivec)[1] = (uchar)(local_30 >> 8);
      (*ivec)[5] = (uchar)((uint)local_2c >> 8);
      (*ivec)[2] = (uchar)(local_30 >> 0x10);
      (*ivec)[7] = (uchar)((uint)local_2c >> 0x18);
      (*ivec)[6] = (uchar)((uint)local_2c >> 0x10);
    }
  }
  *num = local_48;
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

