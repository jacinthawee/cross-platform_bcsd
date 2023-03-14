
void idea_ecb_encrypt(uchar *in,uchar *out,IDEA_KEY_SCHEDULE *ks)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  uint local_18;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = *(uint *)in;
  local_18 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  uVar1 = *(uint *)(in + 4);
  local_14 = uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18;
  idea_encrypt(&local_18,ks);
  out[3] = (uchar)local_18;
  *out = (uchar)(local_18 >> 0x18);
  out[1] = (uchar)(local_18 >> 0x10);
  out[2] = (uchar)(local_18 >> 8);
  out[7] = (uchar)local_14;
  out[4] = (uchar)(local_14 >> 0x18);
  out[5] = (uchar)(local_14 >> 0x10);
  iVar2 = *(int *)(in_GS_OFFSET + 0x14);
  out[6] = (uchar)(local_14 >> 8);
  if (local_10 == iVar2) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}
