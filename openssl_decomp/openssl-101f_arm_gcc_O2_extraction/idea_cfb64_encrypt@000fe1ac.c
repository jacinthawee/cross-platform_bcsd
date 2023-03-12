
void idea_cfb64_encrypt(uchar *in,uchar *out,long length,IDEA_KEY_SCHEDULE *ks,uchar *iv,int *num,
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
          local_30 = (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[3] | (uint)iv[2] << 8;
          local_2c = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
          idea_encrypt(&local_30,ks);
          iv[3] = (uchar)local_30;
          iv[1] = (uchar)(local_30 >> 0x10);
          iv[7] = (uchar)local_2c;
          iv[2] = (uchar)(local_30 >> 8);
          *iv = (uchar)(local_30 >> 0x18);
          iv[4] = (uchar)(local_2c >> 0x18);
          iv[5] = (uchar)(local_2c >> 0x10);
          iv[6] = (uchar)(local_2c >> 8);
        }
        bVar2 = *in;
        length = length + -1;
        bVar1 = iv[uVar3];
        iv[uVar3] = bVar2;
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
        local_30 = (uint)iv[1] << 0x10 | (uint)*iv << 0x18 | (uint)iv[3] | (uint)iv[2] << 8;
        local_2c = (uint)iv[5] << 0x10 | (uint)iv[4] << 0x18 | (uint)iv[7] | (uint)iv[6] << 8;
        idea_encrypt(&local_30,ks);
        iv[3] = (uchar)local_30;
        iv[1] = (uchar)(local_30 >> 0x10);
        iv[7] = (uchar)local_2c;
        iv[2] = (uchar)(local_30 >> 8);
        *iv = (uchar)(local_30 >> 0x18);
        iv[4] = (uchar)(local_2c >> 0x18);
        iv[5] = (uchar)(local_2c >> 0x10);
        iv[6] = (uchar)(local_2c >> 8);
      }
      bVar1 = iv[uVar3];
      length = length + -1;
      bVar2 = *in;
      *out = bVar2 ^ bVar1;
      iv[uVar3] = bVar2 ^ bVar1;
      uVar3 = uVar3 + 1 & 7;
      in = in + 1;
      out = out + 1;
    } while (length != 0);
  }
  *num = uVar3;
  return;
}

