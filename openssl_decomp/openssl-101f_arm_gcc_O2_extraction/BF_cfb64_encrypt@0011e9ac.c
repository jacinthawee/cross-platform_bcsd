
void BF_cfb64_encrypt(uchar *in,uchar *out,long length,BF_KEY *schedule,uchar *ivec,int *num,int enc
                     )

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint local_30;
  uint local_2c;
  
  uVar3 = *num;
  if (enc == 0) {
    if (length != 0) {
      do {
        if (uVar3 == 0) {
          local_30 = (uint)ivec[1] << 0x10 | (uint)*ivec << 0x18 | (uint)ivec[3] |
                     (uint)ivec[2] << 8;
          local_2c = (uint)ivec[5] << 0x10 | (uint)ivec[4] << 0x18 | (uint)ivec[7] |
                     (uint)ivec[6] << 8;
          BF_encrypt(&local_30,schedule);
          ivec[3] = (uchar)local_30;
          ivec[1] = (uchar)(local_30 >> 0x10);
          ivec[7] = (uchar)local_2c;
          ivec[2] = (uchar)(local_30 >> 8);
          *ivec = (uchar)(local_30 >> 0x18);
          ivec[4] = (uchar)(local_2c >> 0x18);
          ivec[5] = (uchar)(local_2c >> 0x10);
          ivec[6] = (uchar)(local_2c >> 8);
        }
        bVar2 = *in;
        length = length + -1;
        bVar1 = ivec[uVar3];
        ivec[uVar3] = bVar2;
        uVar3 = uVar3 + 1 & 7;
        *out = bVar2 ^ bVar1;
        in = in + 1;
        out = out + 1;
      } while (length != 0);
    }
  }
  else if (length != 0) {
    do {
      if (uVar3 == 0) {
        local_30 = (uint)ivec[1] << 0x10 | (uint)*ivec << 0x18 | (uint)ivec[3] | (uint)ivec[2] << 8;
        local_2c = (uint)ivec[5] << 0x10 | (uint)ivec[4] << 0x18 | (uint)ivec[7] |
                   (uint)ivec[6] << 8;
        BF_encrypt(&local_30,schedule);
        ivec[3] = (uchar)local_30;
        ivec[1] = (uchar)(local_30 >> 0x10);
        ivec[7] = (uchar)local_2c;
        ivec[2] = (uchar)(local_30 >> 8);
        *ivec = (uchar)(local_30 >> 0x18);
        ivec[4] = (uchar)(local_2c >> 0x18);
        ivec[5] = (uchar)(local_2c >> 0x10);
        ivec[6] = (uchar)(local_2c >> 8);
      }
      bVar1 = ivec[uVar3];
      length = length + -1;
      bVar2 = *in;
      *out = bVar2 ^ bVar1;
      ivec[uVar3] = bVar2 ^ bVar1;
      uVar3 = uVar3 + 1 & 7;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
  }
  *num = uVar3;
  return;
}

