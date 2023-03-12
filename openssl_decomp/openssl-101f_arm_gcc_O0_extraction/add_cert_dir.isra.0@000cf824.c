
/* WARNING: Type propagation algorithm not settling */

undefined4 add_cert_dir_isra_0(_STACK **param_1,char *param_2,char *param_3)

{
  int iVar1;
  char **ppcVar2;
  size_t sVar3;
  _STACK *p_Var4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  size_t __n;
  char *__s2;
  
  if ((param_2 == (char *)0x0) || (pcVar6 = param_2, *param_2 == '\0')) {
    ERR_put_error(0xb,100,0x71,"by_dir.c",0xd7);
    return 0;
  }
  do {
    do {
      do {
        do {
          __s2 = pcVar6;
          pcVar7 = param_2;
          param_2 = pcVar7 + 1;
          pcVar6 = __s2;
        } while (*pcVar7 != ':' && *pcVar7 != '\0');
        __n = (int)pcVar7 - (int)__s2;
        pcVar6 = param_2;
      } while (__n == 0);
      for (iVar5 = 0; iVar1 = sk_num(*param_1), iVar5 < iVar1; iVar5 = iVar5 + 1) {
        ppcVar2 = (char **)sk_value(*param_1,iVar5);
        pcVar6 = *ppcVar2;
        sVar3 = strlen(pcVar6);
        if ((sVar3 == __n) && (iVar1 = strncmp(pcVar6,__s2,__n), iVar1 == 0)) break;
      }
      iVar1 = sk_num(*param_1);
      pcVar6 = param_2;
    } while (iVar5 < iVar1);
    if (*param_1 == (_STACK *)0x0) {
      p_Var4 = sk_new_null();
      *param_1 = p_Var4;
      if (p_Var4 == (_STACK *)0x0) {
        ERR_put_error(0xb,100,0x41,"by_dir.c",0xf4);
        return 0;
      }
    }
    ppcVar2 = (char **)CRYPTO_malloc(0xc,"by_dir.c",0xf8);
    if (ppcVar2 == (char **)0x0) {
      return 0;
    }
    ppcVar2[1] = param_3;
    p_Var4 = sk_new(by_dir_hash_cmp + 1);
    ppcVar2[2] = (char *)p_Var4;
    pcVar6 = (char *)CRYPTO_malloc(__n + 1,"by_dir.c",0xfd);
    *ppcVar2 = pcVar6;
    if (pcVar6 == (char *)0x0) {
LAB_000cf958:
      if ((_STACK *)ppcVar2[2] != (_STACK *)0x0) {
        sk_pop_free((_STACK *)ppcVar2[2],by_dir_hash_free + 1);
      }
      CRYPTO_free(ppcVar2);
      return 0;
    }
    if (ppcVar2[2] == (char *)0x0) {
      CRYPTO_free(pcVar6);
      goto LAB_000cf958;
    }
    strncpy(pcVar6,__s2,__n);
    (*ppcVar2)[__n] = '\0';
    iVar5 = sk_push(*param_1,ppcVar2);
    if (iVar5 == 0) {
      if (*ppcVar2 != (char *)0x0) {
        CRYPTO_free(*ppcVar2);
      }
      if ((_STACK *)ppcVar2[2] != (_STACK *)0x0) {
        sk_pop_free((_STACK *)ppcVar2[2],by_dir_hash_free + 1);
      }
      CRYPTO_free(ppcVar2);
      return 0;
    }
    pcVar6 = param_2;
    if (*pcVar7 == '\0') {
      return 1;
    }
  } while( true );
}

