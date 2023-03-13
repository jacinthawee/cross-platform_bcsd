
void DES_ecb3_encrypt(const_DES_cblock *input,DES_cblock *output,DES_key_schedule *ks1,
                     DES_key_schedule *ks2,DES_key_schedule *ks3,int enc)

{
  int iVar1;
  int in_GS_OFFSET;
  uint local_18;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = *(undefined4 *)(*input + 4);
  local_18 = *(uint *)*input;
  if (enc == 0) {
    DES_decrypt3(&local_18,ks1,ks2,ks3);
  }
  else {
    DES_encrypt3(&local_18,ks1,ks2,ks3);
  }
  (*output)[0] = (uchar)local_18;
  (*output)[4] = (uchar)local_14;
  (*output)[1] = (uchar)(local_18 >> 8);
  (*output)[3] = (uchar)(local_18 >> 0x18);
  (*output)[2] = (uchar)(local_18 >> 0x10);
  (*output)[5] = (uchar)((uint)local_14 >> 8);
  (*output)[7] = (uchar)((uint)local_14 >> 0x18);
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  (*output)[6] = (uchar)((uint)local_14 >> 0x10);
  if (local_10 == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

