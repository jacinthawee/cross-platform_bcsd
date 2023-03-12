
void RC2_ecb_encrypt(uchar *in,uchar *out,RC2_KEY *key,int enc)

{
  int iVar1;
  int in_GS_OFFSET;
  ulong local_18;
  undefined4 local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_18 = *(ulong *)in;
  local_14 = *(undefined4 *)(in + 4);
  if (enc == 0) {
    RC2_decrypt(&local_18,key);
  }
  else {
    RC2_encrypt(&local_18,key);
  }
  *out = (uchar)local_18;
  out[1] = (uchar)(local_18 >> 8);
  out[3] = (uchar)(local_18 >> 0x18);
  out[2] = (uchar)(local_18 >> 0x10);
  out[4] = (uchar)local_14;
  out[5] = (uchar)((uint)local_14 >> 8);
  out[7] = (uchar)((uint)local_14 >> 0x18);
  iVar1 = *(int *)(in_GS_OFFSET + 0x14);
  out[6] = (uchar)((uint)local_14 >> 0x10);
  if (local_10 == iVar1) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

