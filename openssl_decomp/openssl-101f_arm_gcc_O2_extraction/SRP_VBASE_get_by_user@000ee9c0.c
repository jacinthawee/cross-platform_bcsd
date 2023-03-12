
void SRP_VBASE_get_by_user(_STACK **param_1,char *param_2)

{
  int iVar1;
  char **ptr;
  char *pcVar2;
  EVP_MD *type;
  size_t sVar3;
  BIGNUM *a;
  BIGNUM *pBVar4;
  _STACK *p_Var5;
  _STACK *p_Var6;
  int iVar7;
  EVP_MD_CTX EStack_5c;
  uchar auStack_44 [20];
  uchar auStack_30 [20];
  int local_1c;
  
  local_1c = __TMC_END__;
  if (param_1 != (_STACK **)0x0) {
    for (iVar7 = 0; iVar1 = sk_num(*param_1), iVar7 < iVar1; iVar7 = iVar7 + 1) {
      ptr = (char **)sk_value(*param_1,iVar7);
      iVar1 = strcmp(*ptr,param_2);
      if (iVar1 == 0) goto LAB_000eeaba;
    }
    if ((((param_1[2] != (_STACK *)0x0) && (param_1[3] != (_STACK *)0x0)) &&
        (param_1[4] != (_STACK *)0x0)) &&
       (ptr = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc3), ptr != (char **)0x0)) {
      p_Var5 = param_1[3];
      p_Var6 = param_1[4];
      ptr[1] = (char *)0x0;
      ptr[3] = (char *)p_Var5;
      ptr[4] = (char *)p_Var6;
      ptr[2] = (char *)0x0;
      *ptr = (char *)0x0;
      ptr[5] = (char *)0x0;
      if (param_2 == (char *)0x0) {
LAB_000eea4c:
        RAND_pseudo_bytes(auStack_44,0x14);
        EVP_MD_CTX_init(&EStack_5c);
        type = EVP_sha1();
        EVP_DigestInit_ex(&EStack_5c,type,(ENGINE *)0x0);
        p_Var5 = param_1[2];
        sVar3 = strlen((char *)p_Var5);
        EVP_DigestUpdate(&EStack_5c,p_Var5,sVar3);
        sVar3 = strlen(param_2);
        EVP_DigestUpdate(&EStack_5c,param_2,sVar3);
        EVP_DigestFinal_ex(&EStack_5c,auStack_30,(uint *)0x0);
        EVP_MD_CTX_cleanup(&EStack_5c);
        a = BN_bin2bn(auStack_30,0x14,(BIGNUM *)0x0);
        pBVar4 = BN_bin2bn(auStack_44,0x14,(BIGNUM *)0x0);
        ptr[1] = (char *)a;
        ptr[2] = (char *)pBVar4;
        if ((a != (BIGNUM *)0x0) && (pBVar4 != (BIGNUM *)0x0)) goto LAB_000eeaba;
      }
      else {
        pcVar2 = BUF_strdup(param_2);
        *ptr = pcVar2;
        if (pcVar2 != (char *)0x0) goto LAB_000eea4c;
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
LAB_000eeaba:
  if (local_1c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ptr);
  }
  return;
}

