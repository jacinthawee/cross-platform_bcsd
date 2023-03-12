
/* WARNING: Type propagation algorithm not settling */

undefined4 add_cert_dir_isra_0(_STACK **param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  char **ppcVar3;
  size_t sVar4;
  _STACK *p_Var5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  size_t __n;
  char *__s2;
  
  if ((param_2 == (char *)0x0) || (__s2 = param_2, *param_2 == '\0')) {
    ERR_put_error(0xb,100,0x71,"by_dir.c",0xcc);
    return 0;
  }
  do {
    do {
      pcVar8 = param_2;
      param_2 = pcVar8 + 1;
      cVar1 = *pcVar8;
    } while (cVar1 != ':' && cVar1 != '\0');
    __n = (int)pcVar8 - (int)__s2;
    if (__n != 0) {
      for (iVar6 = 0; iVar2 = sk_num(*param_1), iVar6 < iVar2; iVar6 = iVar6 + 1) {
        ppcVar3 = (char **)sk_value(*param_1,iVar6);
        pcVar7 = *ppcVar3;
        sVar4 = strlen(pcVar7);
        if ((sVar4 == __n) && (iVar2 = strncmp(pcVar7,__s2,__n), iVar2 == 0)) break;
      }
      iVar2 = sk_num(*param_1);
      if (iVar2 <= iVar6) {
        if (*param_1 == (_STACK *)0x0) {
          p_Var5 = sk_new_null();
          *param_1 = p_Var5;
          if (p_Var5 == (_STACK *)0x0) {
            ERR_put_error(0xb,100,0x41,"by_dir.c",0xe5);
            return 0;
          }
        }
        ppcVar3 = (char **)CRYPTO_malloc(0xc,"by_dir.c",0xe9);
        if (ppcVar3 == (char **)0x0) {
          return 0;
        }
        ppcVar3[1] = param_3;
        p_Var5 = sk_new(by_dir_hash_cmp + 1);
        ppcVar3[2] = (char *)p_Var5;
        pcVar7 = (char *)CRYPTO_malloc(__n + 1,"by_dir.c",0xee);
        *ppcVar3 = pcVar7;
        if (pcVar7 == (char *)0x0) {
LAB_000cd8da:
          if ((_STACK *)ppcVar3[2] != (_STACK *)0x0) {
            sk_pop_free((_STACK *)ppcVar3[2],by_dir_hash_free + 1);
          }
          CRYPTO_free(ppcVar3);
          return 0;
        }
        if (ppcVar3[2] == (char *)0x0) {
          CRYPTO_free(pcVar7);
          goto LAB_000cd8da;
        }
        strncpy(pcVar7,__s2,__n);
        (*ppcVar3)[__n] = '\0';
        iVar6 = sk_push(*param_1,ppcVar3);
        if (iVar6 == 0) {
          if (*ppcVar3 != (char *)0x0) {
            CRYPTO_free(*ppcVar3);
          }
          if ((_STACK *)ppcVar3[2] != (_STACK *)0x0) {
            sk_pop_free((_STACK *)ppcVar3[2],by_dir_hash_free + 1);
          }
          CRYPTO_free(ppcVar3);
          return 0;
        }
      }
      cVar1 = *pcVar8;
    }
    __s2 = param_2;
    if (cVar1 == '\0') {
      return 1;
    }
  } while( true );
}

