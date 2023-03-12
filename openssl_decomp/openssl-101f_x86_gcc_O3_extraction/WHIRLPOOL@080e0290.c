
uchar * WHIRLPOOL(void *inp,size_t bytes,uchar *md)

{
  int iVar1;
  uint uVar2;
  WHIRLPOOL_CTX *pWVar3;
  void *inp_00;
  int in_GS_OFFSET;
  void *local_d0;
  WHIRLPOOL_CTX local_c4;
  int local_20;
  
  iVar1 = 0x29;
  local_d0 = inp;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  pWVar3 = &local_c4;
  if (md == (uchar *)0x0) {
    md = m_3879;
  }
  for (; iVar1 != 0; iVar1 = iVar1 + -1) {
    *(undefined4 *)&pWVar3->H = 0;
    pWVar3 = (WHIRLPOOL_CTX *)((int)&pWVar3->H + 4);
  }
  uVar2 = bytes;
  inp_00 = inp;
  if (0xfffffff < bytes) {
    do {
      uVar2 = uVar2 + 0xf0000000;
      WHIRLPOOL_BitUpdate(&local_c4,inp_00,0x80000000);
      inp_00 = (void *)((int)inp_00 + 0x10000000);
    } while (0xfffffff < uVar2);
    uVar2 = bytes + 0xf0000000;
    bytes = bytes & 0xfffffff;
    local_d0 = (void *)((int)inp + (uVar2 & 0xf0000000) + 0x10000000);
  }
  if (bytes != 0) {
    WHIRLPOOL_BitUpdate(&local_c4,local_d0,bytes << 3);
  }
  WHIRLPOOL_Final(md,&local_c4);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return md;
}

