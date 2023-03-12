
void SRP_gN_new_init(char *param_1)

{
  char **ptr;
  char *pcVar1;
  int len;
  BIGNUM *pBVar2;
  uchar auStack_9d8 [2500];
  int local_14;
  
  local_14 = __stack_chk_guard;
  ptr = (char **)CRYPTO_malloc(8,"srp_vfy.c",0x132);
  if (ptr != (char **)0x0) {
    pcVar1 = BUF_strdup(param_1);
    *ptr = pcVar1;
    if (pcVar1 != (char *)0x0) {
      len = t_fromb64(auStack_9d8,param_1);
      pBVar2 = BN_bin2bn(auStack_9d8,len,(BIGNUM *)0x0);
      ptr[1] = (char *)pBVar2;
      if (pBVar2 != (BIGNUM *)0x0) goto LAB_000ec5a2;
      CRYPTO_free(*ptr);
    }
    CRYPTO_free(ptr);
  }
  ptr = (char **)0x0;
LAB_000ec5a2:
  if (local_14 != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ptr);
  }
  return;
}

