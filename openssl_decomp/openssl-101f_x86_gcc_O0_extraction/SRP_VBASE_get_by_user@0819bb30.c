
char ** SRP_VBASE_get_by_user(_STACK **param_1,char *param_2)

{
  _STACK *p_Var1;
  int iVar2;
  char **ptr;
  char *pcVar3;
  EVP_MD *type;
  size_t sVar4;
  BIGNUM *pBVar5;
  BIGNUM *a;
  int iVar6;
  int in_GS_OFFSET;
  EVP_MD_CTX local_60;
  uchar local_48 [20];
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 != (_STACK **)0x0) {
    for (iVar6 = 0; iVar2 = sk_num(*param_1), iVar6 < iVar2; iVar6 = iVar6 + 1) {
      ptr = (char **)sk_value(*param_1,iVar6);
      iVar2 = strcmp(*ptr,param_2);
      if (iVar2 == 0) goto LAB_0819bcbe;
    }
    if ((((param_1[2] != (_STACK *)0x0) && (param_1[3] != (_STACK *)0x0)) &&
        (param_1[4] != (_STACK *)0x0)) &&
       (ptr = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc3), ptr != (char **)0x0)) {
      ptr[1] = (char *)0x0;
      ptr[2] = (char *)0x0;
      *ptr = (char *)0x0;
      ptr[5] = (char *)0x0;
      p_Var1 = param_1[3];
      ptr[4] = (char *)param_1[4];
      ptr[3] = (char *)p_Var1;
      if (param_2 == (char *)0x0) {
LAB_0819bc19:
        RAND_pseudo_bytes(local_48,0x14);
        EVP_MD_CTX_init(&local_60);
        type = EVP_sha1();
        EVP_DigestInit_ex(&local_60,type,(ENGINE *)0x0);
        p_Var1 = param_1[2];
        sVar4 = strlen((char *)p_Var1);
        EVP_DigestUpdate(&local_60,p_Var1,sVar4);
        sVar4 = strlen(param_2);
        EVP_DigestUpdate(&local_60,param_2,sVar4);
        EVP_DigestFinal_ex(&local_60,local_34,(uint *)0x0);
        EVP_MD_CTX_cleanup(&local_60);
        pBVar5 = BN_bin2bn(local_48,0x14,(BIGNUM *)0x0);
        a = BN_bin2bn(local_34,0x14,(BIGNUM *)0x0);
        ptr[2] = (char *)pBVar5;
        ptr[1] = (char *)a;
        if ((pBVar5 != (BIGNUM *)0x0) && (a != (BIGNUM *)0x0)) goto LAB_0819bcbe;
      }
      else {
        pcVar3 = BUF_strdup(param_2);
        *ptr = pcVar3;
        if (pcVar3 != (char *)0x0) goto LAB_0819bc19;
        a = (BIGNUM *)ptr[1];
      }
      BN_free(a);
      BN_clear_free((BIGNUM *)ptr[2]);
      CRYPTO_free(*ptr);
      CRYPTO_free(ptr[5]);
      CRYPTO_free(ptr);
    }
  }
  ptr = (char **)0x0;
LAB_0819bcbe:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ptr;
}

