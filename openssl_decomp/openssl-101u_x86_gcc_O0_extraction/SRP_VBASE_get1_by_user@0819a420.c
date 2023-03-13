
char ** SRP_VBASE_get1_by_user(_STACK **param_1,char *param_2)

{
  _STACK *p_Var1;
  char **ppcVar2;
  int iVar3;
  char **ptr;
  char *pcVar4;
  EVP_MD *type;
  size_t sVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  char *pcVar8;
  int iVar9;
  int in_GS_OFFSET;
  EVP_MD_CTX local_60;
  uchar local_48 [20];
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (param_1 != (_STACK **)0x0) {
    iVar9 = 0;
    while( true ) {
      iVar3 = sk_num(*param_1);
      if (iVar3 <= iVar9) break;
      ppcVar2 = (char **)sk_value(*param_1,iVar9);
      iVar3 = strcmp(*ppcVar2,param_2);
      if (iVar3 == 0) {
        ptr = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9);
        if (ptr == (char **)0x0) goto LAB_0819a703;
        ptr[4] = (char *)0x0;
        ptr[3] = (char *)0x0;
        pcVar4 = ppcVar2[4];
        pcVar8 = ppcVar2[3];
        *ptr = (char *)0x0;
        ptr[5] = (char *)0x0;
        ptr[1] = (char *)0x0;
        ptr[2] = (char *)0x0;
        ptr[4] = pcVar4;
        ptr[3] = pcVar8;
        pcVar4 = ppcVar2[5];
        if (*ppcVar2 == (char *)0x0) {
LAB_0819a655:
          if (pcVar4 != (char *)0x0) {
            pcVar4 = BUF_strdup(pcVar4);
            ptr[5] = pcVar4;
            if (pcVar4 == (char *)0x0) goto LAB_0819a70a;
          }
          pBVar6 = BN_dup((BIGNUM *)ppcVar2[2]);
          pBVar7 = BN_dup((BIGNUM *)ppcVar2[1]);
          ptr[2] = (char *)pBVar6;
          ptr[1] = (char *)pBVar7;
          if ((pBVar6 != (BIGNUM *)0x0) && (pBVar7 != (BIGNUM *)0x0)) goto LAB_0819a5bd;
        }
        else {
          pcVar8 = BUF_strdup(*ppcVar2);
          *ptr = pcVar8;
          if (pcVar8 != (char *)0x0) goto LAB_0819a655;
LAB_0819a70a:
          pBVar7 = (BIGNUM *)ptr[1];
        }
        BN_free(pBVar7);
        BN_clear_free((BIGNUM *)ptr[2]);
        CRYPTO_free(*ptr);
        CRYPTO_free(ptr[5]);
        CRYPTO_free(ptr);
        ptr = (char **)0x0;
        goto LAB_0819a5bd;
      }
      iVar9 = iVar9 + 1;
    }
    if (((param_1[2] != (_STACK *)0x0) && (param_1[3] != (_STACK *)0x0)) &&
       (param_1[4] != (_STACK *)0x0)) {
      ptr = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9);
      if (ptr != (char **)0x0) {
        ptr[1] = (char *)0x0;
        ptr[2] = (char *)0x0;
        *ptr = (char *)0x0;
        ptr[5] = (char *)0x0;
        p_Var1 = param_1[3];
        ptr[4] = (char *)param_1[4];
        ptr[3] = (char *)p_Var1;
        if (param_2 == (char *)0x0) {
LAB_0819a509:
          iVar9 = RAND_bytes(local_48,0x14);
          if (iVar9 < 1) goto LAB_0819a6d2;
          EVP_MD_CTX_init(&local_60);
          type = EVP_sha1();
          EVP_DigestInit_ex(&local_60,type,(ENGINE *)0x0);
          p_Var1 = param_1[2];
          sVar5 = strlen((char *)p_Var1);
          EVP_DigestUpdate(&local_60,p_Var1,sVar5);
          sVar5 = strlen(param_2);
          EVP_DigestUpdate(&local_60,param_2,sVar5);
          EVP_DigestFinal_ex(&local_60,local_34,(uint *)0x0);
          EVP_MD_CTX_cleanup(&local_60);
          pBVar6 = BN_bin2bn(local_48,0x14,(BIGNUM *)0x0);
          pBVar7 = BN_bin2bn(local_34,0x14,(BIGNUM *)0x0);
          ptr[2] = (char *)pBVar6;
          ptr[1] = (char *)pBVar7;
          if ((pBVar6 != (BIGNUM *)0x0) && (pBVar7 != (BIGNUM *)0x0)) goto LAB_0819a5bd;
        }
        else {
          pcVar4 = BUF_strdup(param_2);
          *ptr = pcVar4;
          if (pcVar4 != (char *)0x0) goto LAB_0819a509;
LAB_0819a6d2:
          pBVar7 = (BIGNUM *)ptr[1];
        }
        BN_free(pBVar7);
        BN_clear_free((BIGNUM *)ptr[2]);
        CRYPTO_free(*ptr);
        CRYPTO_free(ptr[5]);
        CRYPTO_free(ptr);
      }
    }
  }
LAB_0819a703:
  ptr = (char **)0x0;
LAB_0819a5bd:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

