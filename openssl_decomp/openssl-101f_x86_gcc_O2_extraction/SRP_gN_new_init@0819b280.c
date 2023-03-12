
char ** __regparm3 SRP_gN_new_init(char *param_1)

{
  char **ptr;
  char *pcVar1;
  int len;
  BIGNUM *pBVar2;
  int in_GS_OFFSET;
  uchar local_9d4 [2500];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  ptr = (char **)CRYPTO_malloc(8,"srp_vfy.c",0x11e);
  if (ptr == (char **)0x0) {
    ptr = (char **)0x0;
  }
  else {
    pcVar1 = BUF_strdup(param_1);
    *ptr = pcVar1;
    if (pcVar1 != (char *)0x0) {
      len = t_fromb64();
      pBVar2 = BN_bin2bn(local_9d4,len,(BIGNUM *)0x0);
      ptr[1] = (char *)pBVar2;
      if (pBVar2 != (BIGNUM *)0x0) goto LAB_0819b2eb;
      CRYPTO_free(*ptr);
    }
    CRYPTO_free(ptr);
    ptr = (char **)0x0;
  }
LAB_0819b2eb:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ptr;
}

