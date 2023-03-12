
void RC2_cfb64_encrypt(uchar *in,uchar *out,long length,RC2_KEY *schedule,uchar *ivec,int *num,
                      int enc)

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
          local_30 = (uint)ivec[2] << 0x10 | (uint)ivec[1] << 8 | (uint)*ivec |
                     (uint)ivec[3] << 0x18;
          local_2c = (uint)ivec[6] << 0x10 | (uint)ivec[5] << 8 | (uint)ivec[4] |
                     (uint)ivec[7] << 0x18;
          RC2_encrypt(&local_30,schedule);
          *ivec = (uchar)local_30;
          ivec[2] = (uchar)(local_30 >> 0x10);
          ivec[4] = (uchar)local_2c;
          ivec[3] = (uchar)(local_30 >> 0x18);
          ivec[1] = (uchar)(local_30 >> 8);
          ivec[5] = (uchar)(local_2c >> 8);
          ivec[6] = (uchar)(local_2c >> 0x10);
          ivec[7] = (uchar)(local_2c >> 0x18);
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
        local_30 = (uint)ivec[2] << 0x10 | (uint)ivec[1] << 8 | (uint)*ivec | (uint)ivec[3] << 0x18;
        local_2c = (uint)ivec[6] << 0x10 | (uint)ivec[5] << 8 | (uint)ivec[4] |
                   (uint)ivec[7] << 0x18;
        RC2_encrypt(&local_30,schedule);
        *ivec = (uchar)local_30;
        ivec[2] = (uchar)(local_30 >> 0x10);
        ivec[4] = (uchar)local_2c;
        ivec[3] = (uchar)(local_30 >> 0x18);
        ivec[1] = (uchar)(local_30 >> 8);
        ivec[5] = (uchar)(local_2c >> 8);
        ivec[6] = (uchar)(local_2c >> 0x10);
        ivec[7] = (uchar)(local_2c >> 0x18);
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

