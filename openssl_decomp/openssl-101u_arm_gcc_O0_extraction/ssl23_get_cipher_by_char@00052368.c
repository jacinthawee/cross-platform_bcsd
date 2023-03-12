
int * ssl23_get_cipher_by_char(byte *param_1)

{
  int *piVar1;
  undefined auStack_38 [8];
  uint uStack_30;
  
  uStack_30 = param_1[1] | 0x3000000 | (uint)*param_1 << 8;
  piVar1 = (int *)OBJ_bsearch_ssl_cipher_id(auStack_38,&ssl3_ciphers,0x7d);
  if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

