
int * ssl2_get_cipher_by_char(byte *param_1)

{
  int *piVar1;
  undefined auStack_40 [8];
  uint local_38;
  
  local_38 = param_1[2] | 0x2000000 | (uint)*param_1 << 0x10 | (uint)param_1[1] << 8;
  piVar1 = (int *)OBJ_bsearch_ssl_cipher_id(auStack_40,&ssl2_ciphers,7);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

