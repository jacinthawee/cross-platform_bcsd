
_STACK * SRP_VBASE_init(_STACK **param_1,void *param_2)

{
  _STACK *sk;
  BIO_METHOD *type;
  BIO *bp;
  long lVar1;
  TXT_DB *db;
  _STACK **pp_Var2;
  int iVar3;
  char **ppcVar4;
  char **ppcVar5;
  char *pcVar6;
  int iVar7;
  void **ppvVar8;
  char **ppcVar9;
  int iVar10;
  _STACK *p_Var11;
  int iVar12;
  char *pcVar13;
  _STACK *local_3c;
  _STACK *local_2c;
  
  sk = sk_new_null();
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((bp == (BIO *)0x0) || (lVar1 = BIO_ctrl(bp,0x6c,3,param_2), lVar1 < 1)) {
    local_3c = (_STACK *)0x3;
    goto LAB_000ec70a;
  }
  db = TXT_DB_read(bp,6);
  if (db == (TXT_DB *)0x0) {
    local_3c = (_STACK *)0x1;
    goto LAB_000ec70a;
  }
  local_2c = param_1[2];
  if (local_2c != (_STACK *)0x0) {
    pp_Var2 = (_STACK **)SRP_get_default_gN(0);
    local_2c = *pp_Var2;
  }
  local_3c = (_STACK *)&DAT_00000004;
  for (iVar10 = 0; iVar3 = sk_num((_STACK *)db->data), iVar10 < iVar3; iVar10 = iVar10 + 1) {
    ppcVar4 = (char **)sk_value((_STACK *)db->data,iVar10);
    if (**ppcVar4 == 'I') {
      ppcVar5 = (char **)CRYPTO_malloc(0xc,"srp_vfy.c",0x19c);
      if (ppcVar5 == (char **)0x0) goto LAB_000ec8d8;
      pcVar6 = BUF_strdup(ppcVar4[3]);
      *ppcVar5 = pcVar6;
      if (pcVar6 != (char *)0x0) {
        pcVar13 = ppcVar4[1];
        p_Var11 = param_1[1];
        if (p_Var11 == (_STACK *)0x0) {
          ppcVar5[2] = (char *)0x0;
        }
        else {
          iVar3 = 0;
          do {
            iVar7 = sk_num(p_Var11);
            if (iVar7 <= iVar3) {
              ppvVar8 = (void **)SRP_gN_new_init(pcVar13);
              if (ppvVar8 != (void **)0x0) {
                iVar3 = sk_insert(p_Var11,ppvVar8,0);
                if (iVar3 < 1) {
                  CRYPTO_free(*ppvVar8);
                  BN_free((BIGNUM *)ppvVar8[1]);
                  CRYPTO_free(ppvVar8);
                  ppvVar8 = (void **)0x0;
                }
                else {
                  ppvVar8 = (void **)ppvVar8[1];
                }
              }
              goto LAB_000ec7fe;
            }
            ppcVar9 = (char **)sk_value(p_Var11,iVar3);
            iVar7 = strcmp(*ppcVar9,pcVar13);
            iVar3 = iVar3 + 1;
          } while (iVar7 != 0);
          ppvVar8 = (void **)ppcVar9[1];
LAB_000ec7fe:
          ppcVar5[2] = (char *)ppvVar8;
          if (ppvVar8 == (void **)0x0) {
            pcVar6 = *ppcVar5;
          }
          else {
            pcVar6 = ppcVar4[2];
            p_Var11 = param_1[1];
            if (p_Var11 == (_STACK *)0x0) {
              ppcVar5[1] = (char *)0x0;
              pcVar6 = *ppcVar5;
            }
            else {
              iVar3 = 0;
              do {
                iVar7 = sk_num(p_Var11);
                if (iVar7 <= iVar3) {
                  ppvVar8 = (void **)SRP_gN_new_init(pcVar6);
                  if (ppvVar8 != (void **)0x0) {
                    iVar3 = sk_insert(p_Var11,ppvVar8,0);
                    if (iVar3 < 1) {
                      CRYPTO_free(*ppvVar8);
                      BN_free((BIGNUM *)ppvVar8[1]);
                      CRYPTO_free(ppvVar8);
                      ppvVar8 = (void **)0x0;
                    }
                    else {
                      ppvVar8 = (void **)ppvVar8[1];
                    }
                  }
                  goto LAB_000ec864;
                }
                ppcVar9 = (char **)sk_value(p_Var11,iVar3);
                iVar7 = strcmp(*ppcVar9,pcVar6);
                iVar3 = iVar3 + 1;
              } while (iVar7 != 0);
              ppvVar8 = (void **)ppcVar9[1];
LAB_000ec864:
              ppcVar5[1] = (char *)ppvVar8;
              if (ppvVar8 == (void **)0x0) {
                pcVar6 = *ppcVar5;
              }
              else {
                iVar3 = sk_insert(sk,ppcVar5,0);
                if (iVar3 != 0) {
                  if (param_1[2] != (_STACK *)0x0) {
                    local_2c = (_STACK *)ppcVar4[3];
                  }
                  goto LAB_000ec754;
                }
                pcVar6 = *ppcVar5;
              }
            }
          }
        }
      }
      CRYPTO_free(pcVar6);
      CRYPTO_free(ppcVar5);
      goto LAB_000ec8e0;
    }
    if (**ppcVar4 == 'V') {
      pcVar6 = ppcVar4[4];
      if (sk == (_STACK *)0x0) {
LAB_000ec9ec:
        ppcVar5 = (char **)SRP_get_default_gN(pcVar6);
        if (ppcVar5 == (char **)0x0) goto LAB_000ec754;
      }
      else {
        pcVar13 = pcVar6;
        if (pcVar6 == (char *)0x0) {
          for (; iVar3 = sk_num(sk), (int)pcVar13 < iVar3; pcVar13 = pcVar13 + 1) {
            ppcVar5 = (char **)sk_value(sk,(int)pcVar13);
            if (ppcVar5 != (char **)0x0) goto LAB_000ec944;
          }
          goto LAB_000ec9ec;
        }
        iVar3 = 0;
        do {
          iVar7 = sk_num(sk);
          iVar12 = iVar3 + 1;
          if (iVar7 <= iVar3) goto LAB_000ec9ec;
          ppcVar5 = (char **)sk_value(sk,iVar3);
          iVar3 = iVar12;
        } while ((ppcVar5 == (char **)0x0) || (iVar7 = strcmp(*ppcVar5,pcVar6), iVar7 != 0));
      }
LAB_000ec944:
      ppcVar9 = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9);
      if (ppcVar9 == (char **)0x0) {
        local_3c = (_STACK *)&DAT_00000004;
        goto LAB_000ec8d8;
      }
      pcVar6 = ppcVar5[1];
      pcVar13 = ppcVar5[2];
      ppcVar9[1] = (char *)0x0;
      ppcVar9[2] = (char *)0x0;
      *ppcVar9 = (char *)0x0;
      ppcVar9[5] = (char *)0x0;
      ppcVar9[4] = pcVar13;
      ppcVar9[3] = pcVar6;
      pcVar6 = ppcVar4[5];
      if (ppcVar4[3] == (char *)0x0) {
LAB_000ec980:
        if (pcVar6 != (char *)0x0) {
          pcVar6 = BUF_strdup(pcVar6);
          ppcVar9[5] = pcVar6;
          if (pcVar6 == (char *)0x0) goto LAB_000ec9ba;
        }
        iVar3 = SRP_user_pwd_set_sv_isra_4(ppcVar9 + 1,ppcVar9 + 2,ppcVar4[2],ppcVar4[1]);
        if (iVar3 == 0) {
          local_3c = (_STACK *)0x2;
        }
        else {
          iVar3 = sk_insert(*param_1,ppcVar9,0);
          local_3c = (_STACK *)0x2;
          if (iVar3 != 0) goto LAB_000ec754;
        }
      }
      else {
        pcVar13 = BUF_strdup(ppcVar4[3]);
        *ppcVar9 = pcVar13;
        if (pcVar13 != (char *)0x0) goto LAB_000ec980;
LAB_000ec9ba:
        local_3c = (_STACK *)&DAT_00000004;
      }
      BN_free((BIGNUM *)ppcVar9[1]);
      BN_clear_free((BIGNUM *)ppcVar9[2]);
      CRYPTO_free(*ppcVar9);
      CRYPTO_free(ppcVar9[5]);
      CRYPTO_free(ppcVar9);
      goto LAB_000ec8e0;
    }
LAB_000ec754:
  }
  local_3c = local_2c;
  if (local_2c != (_STACK *)0x0) {
    iVar10 = 0;
    if (sk == (_STACK *)0x0) {
LAB_000eca16:
      ppcVar4 = (char **)SRP_get_default_gN(local_2c);
      if (ppcVar4 == (char **)0x0) {
        local_3c = (_STACK *)0x2;
        goto LAB_000ec8d8;
      }
    }
    else {
      do {
        iVar3 = sk_num(sk);
        iVar7 = iVar10 + 1;
        if (iVar3 <= iVar10) goto LAB_000eca16;
        ppcVar4 = (char **)sk_value(sk,iVar10);
        iVar10 = iVar7;
      } while ((ppcVar4 == (char **)0x0) || (iVar3 = strcmp(*ppcVar4,(char *)local_2c), iVar3 != 0))
      ;
    }
    local_3c = (_STACK *)0x0;
    p_Var11 = (_STACK *)ppcVar4[2];
    param_1[3] = (_STACK *)ppcVar4[1];
    param_1[4] = p_Var11;
  }
LAB_000ec8d8:
  if (db != (TXT_DB *)0x0) {
LAB_000ec8e0:
    TXT_DB_free(db);
  }
LAB_000ec70a:
  if (bp != (BIO *)0x0) {
    BIO_free_all(bp);
  }
  sk_free(sk);
  return local_3c;
}

