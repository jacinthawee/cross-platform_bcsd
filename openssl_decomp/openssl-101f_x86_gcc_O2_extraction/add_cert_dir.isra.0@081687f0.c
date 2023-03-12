
undefined4 __regparm3 add_cert_dir_isra_0(_STACK **param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char **ppcVar4;
  char *pcVar5;
  _STACK *p_Var6;
  char *pcVar7;
  int iVar8;
  char *__n;
  char *local_24;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    pcVar2 = param_2 + 1;
    local_24 = param_2;
    do {
      if (((pcVar2[-1] == ':') || (pcVar1 = local_24, pcVar2[-1] == '\0')) &&
         (__n = pcVar2 + (-1 - (int)local_24), pcVar1 = pcVar2, __n != (char *)0x0)) {
        for (iVar8 = 0; iVar3 = sk_num(*param_1), iVar8 < iVar3; iVar8 = iVar8 + 1) {
          ppcVar4 = (char **)sk_value(*param_1,iVar8);
          pcVar7 = *ppcVar4;
          pcVar5 = (char *)strlen(pcVar7);
          if ((pcVar5 == __n) && (iVar3 = strncmp(pcVar7,local_24,(size_t)__n), iVar3 == 0)) break;
        }
        iVar3 = sk_num(*param_1);
        if (iVar3 <= iVar8) {
          if (*param_1 == (_STACK *)0x0) {
            p_Var6 = sk_new_null();
            *param_1 = p_Var6;
            if (p_Var6 == (_STACK *)0x0) {
              iVar3 = 0xf4;
              iVar8 = 0x41;
              goto LAB_0816899f;
            }
          }
          ppcVar4 = (char **)CRYPTO_malloc(0xc,"by_dir.c",0xf8);
          if (ppcVar4 == (char **)0x0) {
            return 0;
          }
          ppcVar4[1] = param_3;
          p_Var6 = sk_new(by_dir_hash_cmp);
          ppcVar4[2] = (char *)p_Var6;
          pcVar7 = (char *)CRYPTO_malloc((int)(__n + 1),"by_dir.c",0xfd);
          *ppcVar4 = pcVar7;
          if (pcVar7 == (char *)0x0) {
LAB_081689c1:
            if ((_STACK *)ppcVar4[2] != (_STACK *)0x0) {
              sk_pop_free((_STACK *)ppcVar4[2],by_dir_hash_free);
            }
            CRYPTO_free(ppcVar4);
            return 0;
          }
          if (ppcVar4[2] == (char *)0x0) {
            CRYPTO_free(pcVar7);
            goto LAB_081689c1;
          }
          strncpy(pcVar7,local_24,(size_t)__n);
          (*ppcVar4)[(int)__n] = '\0';
          iVar8 = sk_push(*param_1,ppcVar4);
          if (iVar8 == 0) {
            if (*ppcVar4 != (char *)0x0) {
              CRYPTO_free(*ppcVar4);
            }
            if ((_STACK *)ppcVar4[2] != (_STACK *)0x0) {
              sk_pop_free((_STACK *)ppcVar4[2],by_dir_hash_free);
            }
            CRYPTO_free(ppcVar4);
            return 0;
          }
          if (pcVar2[-1] == '\0') {
            return 1;
          }
        }
      }
      local_24 = pcVar1;
      pcVar2 = pcVar2 + 1;
    } while( true );
  }
  iVar3 = 0xd7;
  iVar8 = 0x71;
LAB_0816899f:
  ERR_put_error(0xb,100,iVar8,"by_dir.c",iVar3);
  return 0;
}

