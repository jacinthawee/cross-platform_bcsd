
void SRP_VBASE_get1_by_user(_STACK **param_1,char *param_2)

{
  char **ppcVar1;
  int iVar2;
  char **ptr;
  char *pcVar3;
  EVP_MD *type;
  size_t sVar4;
  BIGNUM *a;
  BIGNUM *pBVar5;
  _STACK *p_Var6;
  _STACK *p_Var7;
  char *pcVar8;
  int iVar9;
  EVP_MD_CTX EStack_64;
  uchar auStack_4c [20];
  uchar auStack_38 [20];
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (param_1 != (_STACK **)0x0) {
    for (iVar9 = 0; iVar2 = sk_num(*param_1), iVar9 < iVar2; iVar9 = iVar9 + 1) {
      ppcVar1 = (char **)sk_value(*param_1,iVar9);
      iVar2 = strcmp(*ppcVar1,param_2);
      if (iVar2 == 0) {
        ptr = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9);
        if (ptr == (char **)0x0) goto LAB_000ecc5e;
        ptr[4] = (char *)0x0;
        ptr[3] = (char *)0x0;
        pcVar3 = ppcVar1[4];
        pcVar8 = ppcVar1[3];
        *ptr = (char *)0x0;
        ptr[4] = pcVar3;
        ptr[3] = pcVar8;
        pcVar3 = *ppcVar1;
        ptr[5] = (char *)0x0;
        ptr[1] = (char *)0x0;
        ptr[2] = (char *)0x0;
        pcVar8 = ppcVar1[5];
        if (pcVar3 != (char *)0x0) {
          pcVar3 = BUF_strdup(pcVar3);
          *ptr = pcVar3;
          if (pcVar3 == (char *)0x0) goto LAB_000ecc62;
        }
        if (pcVar8 != (char *)0x0) {
          pcVar3 = BUF_strdup(pcVar8);
          ptr[5] = pcVar3;
          if (pcVar3 == (char *)0x0) goto LAB_000ecc62;
        }
        a = BN_dup((BIGNUM *)ppcVar1[1]);
        pBVar5 = BN_dup((BIGNUM *)ppcVar1[2]);
        ptr[1] = (char *)a;
        ptr[2] = (char *)pBVar5;
        goto joined_r0x000ecc3e;
      }
    }
    if ((((param_1[2] != (_STACK *)0x0) && (param_1[3] != (_STACK *)0x0)) &&
        (param_1[4] != (_STACK *)0x0)) &&
       (ptr = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9), ptr != (char **)0x0)) {
      p_Var6 = param_1[3];
      p_Var7 = param_1[4];
      ptr[1] = (char *)0x0;
      ptr[3] = (char *)p_Var6;
      ptr[4] = (char *)p_Var7;
      ptr[2] = (char *)0x0;
      *ptr = (char *)0x0;
      ptr[5] = (char *)0x0;
      if (param_2 == (char *)0x0) {
LAB_000ecb60:
        iVar9 = RAND_bytes(auStack_4c,0x14);
        if (iVar9 < 1) goto LAB_000ecc62;
        EVP_MD_CTX_init(&EStack_64);
        type = EVP_sha1();
        EVP_DigestInit_ex(&EStack_64,type,(ENGINE *)0x0);
        p_Var6 = param_1[2];
        sVar4 = strlen((char *)p_Var6);
        EVP_DigestUpdate(&EStack_64,p_Var6,sVar4);
        sVar4 = strlen(param_2);
        EVP_DigestUpdate(&EStack_64,param_2,sVar4);
        EVP_DigestFinal_ex(&EStack_64,auStack_38,(uint *)0x0);
        EVP_MD_CTX_cleanup(&EStack_64);
        a = BN_bin2bn(auStack_38,0x14,(BIGNUM *)0x0);
        pBVar5 = BN_bin2bn(auStack_4c,0x14,(BIGNUM *)0x0);
        ptr[1] = (char *)a;
        ptr[2] = (char *)pBVar5;
joined_r0x000ecc3e:
        if ((a != (BIGNUM *)0x0) && (pBVar5 != (BIGNUM *)0x0)) goto LAB_000ecbd6;
      }
      else {
        pcVar3 = BUF_strdup(param_2);
        *ptr = pcVar3;
        if (pcVar3 != (char *)0x0) goto LAB_000ecb60;
LAB_000ecc62:
        a = (BIGNUM *)ptr[1];
      }
      BN_free(a);
      BN_clear_free((BIGNUM *)ptr[2]);
      CRYPTO_free(*ptr);
      CRYPTO_free(ptr[5]);
      CRYPTO_free(ptr);
    }
  }
LAB_000ecc5e:
  ptr = (char **)0x0;
LAB_000ecbd6:
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(ptr);
}

