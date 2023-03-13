
void RC2_cfb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num,
                      int enc)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int in_GS_OFFSET;
  int local_38;
  ulong local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar4 = *num;
  if (enc == 0) {
    local_38 = length;
    if (length != 0) {
      do {
        if (uVar4 == 0) {
          local_28 = *(ulong *)ivec;
          local_24 = *(undefined4 *)(ivec + 4);
          RC2_encrypt(&local_28,schedule);
          *ivec = (uchar)local_28;
          ivec[1] = (uchar)(local_28 >> 8);
          ivec[3] = (uchar)(local_28 >> 0x18);
          ivec[2] = (uchar)(local_28 >> 0x10);
          ivec[4] = (uchar)local_24;
          ivec[5] = (uchar)((uint)local_24 >> 8);
          ivec[7] = (uchar)((uint)local_24 >> 0x18);
          ivec[6] = (uchar)((uint)local_24 >> 0x10);
        }
        pbVar1 = ivec + uVar4;
        bVar3 = *in;
        bVar2 = *pbVar1;
        uVar4 = uVar4 + 1 & 7;
        *pbVar1 = bVar3;
        local_38 = local_38 + -1;
        *out = bVar2 ^ bVar3;
        out = out + 1;
        in = in + 1;
      } while (local_38 != 0);
    }
  }
  else if (length != 0) {
    do {
      if (uVar4 == 0) {
        local_28 = *(ulong *)ivec;
        local_24 = *(undefined4 *)(ivec + 4);
        RC2_encrypt(&local_28,schedule);
        *ivec = (uchar)local_28;
        ivec[1] = (uchar)(local_28 >> 8);
        ivec[3] = (uchar)(local_28 >> 0x18);
        ivec[2] = (uchar)(local_28 >> 0x10);
        ivec[4] = (uchar)local_24;
        ivec[5] = (uchar)((uint)local_24 >> 8);
        ivec[7] = (uchar)((uint)local_24 >> 0x18);
        ivec[6] = (uchar)((uint)local_24 >> 0x10);
      }
      pbVar1 = ivec + uVar4;
      bVar3 = *in ^ *pbVar1;
      uVar4 = uVar4 + 1 & 7;
      length = length + -1;
      *out = bVar3;
      *pbVar1 = bVar3;
      out = out + 1;
      in = in + 1;
    } while (length != 0);
  }
  *num = uVar4;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

