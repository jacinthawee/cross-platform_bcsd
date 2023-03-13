
undefined4 __regparm3 add_cert_dir_isra_0(_STACK **param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char **ppcVar4;
  char *pcVar5;
  _STACK *p_Var6;
  char *pcVar7;
  int iVar8;
  char *__n;
  char *local_2c;
  char *local_28;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    local_2c = param_2 + 1;
    local_28 = param_2;
    do {
      cVar2 = local_2c[-1];
      pcVar1 = local_2c;
      while ((cVar2 != ':' && (cVar2 != '\0'))) {
        cVar2 = *pcVar1;
        pcVar1 = pcVar1 + 1;
      }
      __n = pcVar1 + (-1 - (int)local_28);
      if (__n != (char *)0x0) {
        for (iVar8 = 0; iVar3 = sk_num(*param_1), iVar8 < iVar3; iVar8 = iVar8 + 1) {
          ppcVar4 = (char **)sk_value(*param_1,iVar8);
          pcVar7 = *ppcVar4;
          pcVar5 = (char *)strlen(pcVar7);
          if ((pcVar5 == __n) && (iVar3 = strncmp(pcVar7,local_28,(size_t)__n), iVar3 == 0)) break;
        }
        iVar3 = sk_num(*param_1);
        if (iVar3 <= iVar8) {
          if (*param_1 == (_STACK *)0x0) {
            p_Var6 = sk_new_null();
            *param_1 = p_Var6;
            if (p_Var6 == (_STACK *)0x0) {
              iVar3 = 0xe5;
              iVar8 = 0x41;
              goto LAB_08166a81;
            }
          }
          ppcVar4 = (char **)CRYPTO_malloc(0xc,"by_dir.c",0xe9);
          if (ppcVar4 == (char **)0x0) {
            return 0;
          }
          ppcVar4[1] = param_3;
          p_Var6 = sk_new(by_dir_hash_cmp);
          ppcVar4[2] = (char *)p_Var6;
          pcVar7 = (char *)CRYPTO_malloc((int)(__n + 1),"by_dir.c",0xee);
          *ppcVar4 = pcVar7;
          if (pcVar7 == (char *)0x0) {
LAB_08166ad0:
            if ((_STACK *)ppcVar4[2] != (_STACK *)0x0) {
              sk_pop_free((_STACK *)ppcVar4[2],by_dir_hash_free);
            }
            CRYPTO_free(ppcVar4);
            return 0;
          }
          if (ppcVar4[2] == (char *)0x0) {
            CRYPTO_free(pcVar7);
            goto LAB_08166ad0;
          }
          strncpy(pcVar7,local_28,(size_t)__n);
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
        }
        cVar2 = pcVar1[-1];
      }
      local_2c = pcVar1 + 1;
      local_28 = pcVar1;
      if (cVar2 == '\0') {
        return 1;
      }
    } while( true );
  }
  iVar3 = 0xcc;
  iVar8 = 0x71;
LAB_08166a81:
  ERR_put_error(0xb,100,iVar8,"by_dir.c",iVar3);
  return 0;
}

