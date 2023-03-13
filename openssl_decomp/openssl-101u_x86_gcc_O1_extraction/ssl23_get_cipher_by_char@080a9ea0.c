
int * ssl23_get_cipher_by_char(byte *param_1)

{
  int *piVar1;
  int in_GS_OFFSET;
  undefined auStack_40 [8];
  uint uStack_38;
  int iStack_10;
  
  iStack_10 = *(int *)(in_GS_OFFSET + 0x14);
  uStack_38 = param_1[1] | 0x3000000 | (uint)*param_1 << 8;
  piVar1 = (int *)OBJ_bsearch_ssl_cipher_id(auStack_40,ssl3_ciphers,0x7d);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else if (*piVar1 == 0) {
    piVar1 = (int *)0x0;
  }
  if (iStack_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return piVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

