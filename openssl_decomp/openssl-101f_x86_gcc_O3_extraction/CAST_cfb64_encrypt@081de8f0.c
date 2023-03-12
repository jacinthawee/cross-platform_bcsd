
void CAST_cfb64_encrypt(uchar *in,uchar *out,long length,CAST_KEY *schedule,uchar *ivec,int *num,
                       int enc)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  int in_GS_OFFSET;
  int local_38;
  uint local_28;
  uint local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar5 = *num;
  if (enc == 0) {
    local_38 = length;
    if (length != 0) {
      do {
        if (uVar5 == 0) {
          uVar3 = *(uint *)ivec;
          local_28 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18
          ;
          uVar3 = *(uint *)(ivec + 4);
          local_24 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18
          ;
          CAST_encrypt(&local_28,schedule);
          ivec[3] = (uchar)local_28;
          *ivec = (uchar)(local_28 >> 0x18);
          ivec[1] = (uchar)(local_28 >> 0x10);
          ivec[2] = (uchar)(local_28 >> 8);
          ivec[7] = (uchar)local_24;
          ivec[4] = (uchar)(local_24 >> 0x18);
          ivec[5] = (uchar)(local_24 >> 0x10);
          ivec[6] = (uchar)(local_24 >> 8);
        }
        pbVar1 = ivec + uVar5;
        bVar4 = *in;
        bVar2 = *pbVar1;
        uVar5 = uVar5 + 1 & 7;
        *pbVar1 = bVar4;
        local_38 = local_38 + -1;
        *out = bVar2 ^ bVar4;
        out = out + 1;
        in = in + 1;
      } while (local_38 != 0);
    }
  }
  else if (length != 0) {
    do {
      if (uVar5 == 0) {
        uVar3 = *(uint *)ivec;
        local_28 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
        uVar3 = *(uint *)(ivec + 4);
        local_24 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
        CAST_encrypt(&local_28,schedule);
        ivec[3] = (uchar)local_28;
        *ivec = (uchar)(local_28 >> 0x18);
        ivec[1] = (uchar)(local_28 >> 0x10);
        ivec[2] = (uchar)(local_28 >> 8);
        ivec[7] = (uchar)local_24;
        ivec[4] = (uchar)(local_24 >> 0x18);
        ivec[5] = (uchar)(local_24 >> 0x10);
        ivec[6] = (uchar)(local_24 >> 8);
      }
      pbVar1 = ivec + uVar5;
      bVar4 = *in ^ *pbVar1;
      uVar5 = uVar5 + 1 & 7;
      length = length + -1;
      *out = bVar4;
      *pbVar1 = bVar4;
      out = out + 1;
      in = in + 1;
    } while (length != 0);
  }
  *num = uVar5;
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

