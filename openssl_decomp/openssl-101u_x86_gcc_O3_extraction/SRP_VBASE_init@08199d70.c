
undefined4 SRP_VBASE_init(_STACK **param_1,void *param_2)

{
  _STACK *p_Var1;
  _STACK *sk;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  TXT_DB *db;
  char **ppcVar3;
  int iVar4;
  char **ppcVar5;
  char *pcVar6;
  int iVar7;
  void **ppvVar8;
  char **ppcVar9;
  char *pcVar10;
  int local_40;
  undefined4 local_2c;
  char *local_24;
  
  sk = sk_new_null();
  type = BIO_s_file();
  bp = BIO_new(type);
  if ((bp == (BIO *)0x0) || (lVar2 = BIO_ctrl(bp,0x6c,3,param_2), lVar2 < 1)) {
    local_2c = 3;
LAB_08199db6:
    if (bp == (BIO *)0x0) goto LAB_08199dbe;
  }
  else {
    db = TXT_DB_read(bp,6);
    if (db == (TXT_DB *)0x0) {
      local_2c = 1;
      goto LAB_08199db6;
    }
    local_24 = (char *)0x0;
    if (param_1[2] != (_STACK *)0x0) {
      ppcVar3 = (char **)SRP_get_default_gN(0);
      local_24 = *ppcVar3;
    }
    local_2c = 4;
    for (local_40 = 0; iVar4 = sk_num((_STACK *)db->data), local_40 < iVar4; local_40 = local_40 + 1
        ) {
      ppcVar3 = (char **)sk_value((_STACK *)db->data,local_40);
      if (**ppcVar3 == 'I') {
        ppcVar5 = (char **)CRYPTO_malloc(0xc,"srp_vfy.c",0x19c);
        if (ppcVar5 != (char **)0x0) {
          pcVar6 = BUF_strdup(ppcVar3[3]);
          *ppcVar5 = pcVar6;
          if (pcVar6 != (char *)0x0) {
            pcVar10 = ppcVar3[1];
            p_Var1 = param_1[1];
            if (p_Var1 != (_STACK *)0x0) {
              for (iVar4 = 0; iVar7 = sk_num(p_Var1), iVar4 < iVar7; iVar4 = iVar4 + 1) {
                ppcVar9 = (char **)sk_value(p_Var1,iVar4);
                iVar7 = strcmp(*ppcVar9,pcVar10);
                if (iVar7 == 0) {
                  pcVar6 = ppcVar9[1];
                  goto LAB_08199f85;
                }
              }
              ppvVar8 = (void **)SRP_gN_new_init();
              if (ppvVar8 == (void **)0x0) {
                pcVar6 = *ppcVar5;
              }
              else {
                iVar4 = sk_insert(p_Var1,ppvVar8,0);
                if (0 < iVar4) {
                  pcVar6 = (char *)ppvVar8[1];
LAB_08199f85:
                  ppcVar5[2] = pcVar6;
                  if (pcVar6 == (char *)0x0) {
LAB_08199dd6:
                    pcVar6 = *ppcVar5;
                  }
                  else {
                    pcVar6 = ppcVar3[2];
                    p_Var1 = param_1[1];
                    if (p_Var1 != (_STACK *)0x0) {
                      for (iVar4 = 0; iVar7 = sk_num(p_Var1), iVar4 < iVar7; iVar4 = iVar4 + 1) {
                        ppcVar9 = (char **)sk_value(p_Var1,iVar4);
                        iVar7 = strcmp(*ppcVar9,pcVar6);
                        if (iVar7 == 0) {
                          pcVar6 = ppcVar9[1];
                          goto LAB_0819a01d;
                        }
                      }
                      ppvVar8 = (void **)SRP_gN_new_init();
                      if (ppvVar8 != (void **)0x0) {
                        iVar4 = sk_insert(p_Var1,ppvVar8,0);
                        if (0 < iVar4) {
                          pcVar6 = (char *)ppvVar8[1];
LAB_0819a01d:
                          ppcVar5[1] = pcVar6;
                          if (pcVar6 != (char *)0x0) {
                            iVar4 = sk_insert(sk,ppcVar5,0);
                            if (iVar4 != 0) {
                              if (param_1[2] != (_STACK *)0x0) {
                                local_24 = ppcVar3[3];
                              }
                              goto LAB_08199e80;
                            }
                            pcVar6 = *ppcVar5;
                            goto LAB_08199de0;
                          }
                          goto LAB_08199dd6;
                        }
                        CRYPTO_free(*ppvVar8);
                        BN_free((BIGNUM *)ppvVar8[1]);
                        CRYPTO_free(ppvVar8);
                      }
                    }
                    ppcVar5[1] = (char *)0x0;
                    pcVar6 = *ppcVar5;
                  }
                  goto LAB_08199de0;
                }
                CRYPTO_free(*ppvVar8);
                BN_free((BIGNUM *)ppvVar8[1]);
                CRYPTO_free(ppvVar8);
                pcVar6 = *ppcVar5;
              }
            }
            ppcVar5[2] = (char *)0x0;
          }
LAB_08199de0:
          CRYPTO_free(pcVar6);
          CRYPTO_free(ppcVar5);
        }
        goto LAB_08199df6;
      }
      if (**ppcVar3 == 'V') {
        pcVar6 = ppcVar3[4];
        if (sk != (_STACK *)0x0) {
          iVar4 = 0;
          if (pcVar6 == (char *)0x0) {
            for (; iVar7 = sk_num(sk), iVar4 < iVar7; iVar4 = iVar4 + 1) {
              ppcVar5 = (char **)sk_value(sk,iVar4);
              if (ppcVar5 != (char **)0x0) goto LAB_0819a0f0;
            }
          }
          else {
            for (; iVar7 = sk_num(sk), iVar4 < iVar7; iVar4 = iVar4 + 1) {
              ppcVar5 = (char **)sk_value(sk,iVar4);
              if ((ppcVar5 != (char **)0x0) && (iVar7 = strcmp(*ppcVar5,pcVar6), iVar7 == 0))
              goto LAB_0819a0f0;
            }
          }
        }
        ppcVar5 = (char **)SRP_get_default_gN(pcVar6);
        if (ppcVar5 != (char **)0x0) {
LAB_0819a0f0:
          ppcVar9 = (char **)CRYPTO_malloc(0x18,"srp_vfy.c",0xc9);
          if (ppcVar9 == (char **)0x0) {
            local_2c = 4;
          }
          else {
            ppcVar9[1] = (char *)0x0;
            ppcVar9[2] = (char *)0x0;
            *ppcVar9 = (char *)0x0;
            ppcVar9[5] = (char *)0x0;
            pcVar6 = ppcVar5[1];
            ppcVar9[4] = ppcVar5[2];
            ppcVar9[3] = pcVar6;
            pcVar6 = ppcVar3[5];
            if (ppcVar3[3] == (char *)0x0) {
LAB_0819a158:
              if (pcVar6 != (char *)0x0) {
                pcVar6 = BUF_strdup(pcVar6);
                ppcVar9[5] = pcVar6;
                if (pcVar6 == (char *)0x0) goto LAB_0819a2c0;
              }
              iVar4 = SRP_user_pwd_set_sv_isra_4(ppcVar3[1]);
              if ((iVar4 != 0) && (iVar4 = sk_insert(*param_1,ppcVar9,0), iVar4 != 0)) {
                local_2c = 2;
                goto LAB_08199e80;
              }
              local_2c = 2;
            }
            else {
              pcVar10 = BUF_strdup(ppcVar3[3]);
              *ppcVar9 = pcVar10;
              if (pcVar10 != (char *)0x0) goto LAB_0819a158;
LAB_0819a2c0:
              local_2c = 4;
            }
            BN_free((BIGNUM *)ppcVar9[1]);
            BN_clear_free((BIGNUM *)ppcVar9[2]);
            CRYPTO_free(*ppcVar9);
            CRYPTO_free(ppcVar9[5]);
            CRYPTO_free(ppcVar9);
          }
          goto LAB_08199df6;
        }
      }
LAB_08199e80:
    }
    local_2c = 0;
    if (local_24 != (char *)0x0) {
      if (sk != (_STACK *)0x0) {
        for (iVar4 = 0; iVar7 = sk_num(sk), iVar4 < iVar7; iVar4 = iVar4 + 1) {
          ppcVar3 = (char **)sk_value(sk,iVar4);
          if ((ppcVar3 != (char **)0x0) && (iVar7 = strcmp(*ppcVar3,local_24), iVar7 == 0))
          goto LAB_0819a2a3;
        }
      }
      ppcVar3 = (char **)SRP_get_default_gN(local_24);
      local_2c = 2;
      if (ppcVar3 != (char **)0x0) {
LAB_0819a2a3:
        p_Var1 = (_STACK *)ppcVar3[2];
        local_2c = 0;
        param_1[3] = (_STACK *)ppcVar3[1];
        param_1[4] = p_Var1;
      }
    }
LAB_08199df6:
    TXT_DB_free(db);
  }
  BIO_free_all(bp);
LAB_08199dbe:
  sk_free(sk);
  return local_2c;
}

