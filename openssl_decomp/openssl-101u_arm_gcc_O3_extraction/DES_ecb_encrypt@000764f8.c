
void DES_ecb_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks,int enc)

{
  uint local_20;
  uint local_1c;
  
  local_20 = (uint)(*input)[2] << 0x10 | (uint)(*input)[1] << 8 | (uint)(*input)[0] |
             (uint)(*input)[3] << 0x18;
  local_1c = (uint)(*input)[6] << 0x10 | (uint)(*input)[5] << 8 | (uint)(*input)[4] |
             (uint)(*input)[7] << 0x18;
  DES_encrypt1(&local_20,ks,enc);
  (*output)[0] = (uchar)local_20;
  (*output)[2] = (uchar)(local_20 >> 0x10);
  (*output)[4] = (uchar)local_1c;
  (*output)[3] = (uchar)(local_20 >> 0x18);
  (*output)[1] = (uchar)(local_20 >> 8);
  (*output)[5] = (uchar)(local_1c >> 8);
  (*output)[6] = (uchar)(local_1c >> 0x10);
  (*output)[7] = (uchar)(local_1c >> 0x18);
  return;
}

