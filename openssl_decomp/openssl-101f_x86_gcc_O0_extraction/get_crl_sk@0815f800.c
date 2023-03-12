
bool __regparm3
get_crl_sk(int param_1_00,X509_CRL **param_2_00,X509_CRL **param_3_00,X509 **param_1,uint *param_2,
          uint *param_3,_STACK *param_4)

{
  X509 *a;
  DIST_POINT_NAME *pDVar1;
  ASN1_INTEGER *pAVar2;
  ASN1_TIME *s;
  int iVar3;
  X509_CRL *pXVar4;
  X509_NAME *pXVar5;
  uint uVar6;
  int iVar7;
  X509 *pXVar8;
  int **ppiVar9;
  _STACK *p_Var10;
  int *piVar11;
  GENERAL_NAME *a_00;
  GENERAL_NAME *b;
  X509_CRL_INFO *pXVar12;
  X509_NAME *pXVar13;
  time_t *ptVar14;
  int iVar15;
  bool bVar16;
  uint local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  X509_CRL *local_4c;
  X509 *local_48;
  uint local_44;
  X509 *local_40;
  uint local_38;
  int local_2c;
  
  local_48 = (X509 *)0x0;
  local_40 = (X509 *)0x0;
  local_4c = (X509_CRL *)0x0;
  local_58 = *param_2;
  local_44 = 0;
  local_5c = 0;
  a = *(X509 **)(param_1_00 + 0x68);
  for (; iVar3 = sk_num(param_4), local_5c < iVar3; local_5c = local_5c + 1) {
    pXVar4 = (X509_CRL *)sk_value(param_4,local_5c);
    uVar6 = pXVar4->idp_flags;
    local_54 = *param_3;
    local_60 = 0;
    if ((uVar6 & 2) == 0) {
      if ((*(byte *)(*(int *)(param_1_00 + 0x14) + 0xd) & 0x10) == 0) {
        pAVar2 = (ASN1_INTEGER *)(uVar6 & 0x60);
joined_r0x0815fc91:
        if (pAVar2 != (ASN1_INTEGER *)0x0) goto LAB_0815fa08;
      }
      else {
        if ((uVar6 & 0x40) == 0) {
          pAVar2 = pXVar4->base_crl_number;
          goto joined_r0x0815fc91;
        }
        if ((pXVar4->idp_reasons & ~local_54) == 0) goto LAB_0815fa08;
      }
      pXVar13 = pXVar4->crl->issuer;
      pXVar5 = X509_get_issuer_name(a);
      iVar3 = X509_NAME_cmp(pXVar5,pXVar13);
      if (iVar3 == 0) {
        local_60 = 0x120;
        uVar6 = 0x20;
      }
      else {
        local_60 = 0;
        if ((*(byte *)&pXVar4->idp_flags & 0x20) == 0) goto LAB_0815fa08;
        local_60 = 0x100;
        uVar6 = 0;
      }
      if ((*(byte *)((int)&pXVar4->flags + 1) & 2) == 0) {
        uVar6 = local_60;
      }
      ptVar14 = (time_t *)(*(int *)(param_1_00 + 0x14) + 4);
      if ((*(byte *)(*(int *)(param_1_00 + 0x14) + 0xc) & 2) == 0) {
        ptVar14 = (time_t *)0x0;
      }
      iVar3 = X509_cmp_time(pXVar4->crl->lastUpdate,ptVar14);
      if (iVar3 < 0) {
        pXVar12 = pXVar4->crl;
        if (pXVar12->nextUpdate != (ASN1_TIME *)0x0) {
          iVar3 = X509_cmp_time(pXVar12->nextUpdate,ptVar14);
          if (iVar3 == 0) goto LAB_0815f93c;
          if (iVar3 < 0) {
            if ((*(byte *)(param_1_00 + 0x74) & 2) == 0) goto LAB_0815f93c;
            pXVar12 = pXVar4->crl;
          }
          else {
            pXVar12 = pXVar4->crl;
          }
        }
        local_60 = uVar6 | 0x40;
      }
      else {
LAB_0815f93c:
        pXVar12 = pXVar4->crl;
        local_60 = uVar6;
      }
      iVar3 = *(int *)(param_1_00 + 0x60);
      pXVar13 = pXVar12->issuer;
      iVar7 = sk_num(*(_STACK **)(param_1_00 + 0x54));
      iVar15 = iVar7 + -1;
      if (iVar3 != iVar7 + -1) {
        iVar15 = iVar3 + 1;
      }
      pXVar8 = (X509 *)sk_value(*(_STACK **)(param_1_00 + 0x54),iVar15);
      iVar3 = X509_check_akid(pXVar8,pXVar4->akid);
      if ((iVar3 == 0) && ((local_60 & 0x20) != 0)) {
        local_60 = local_60 | 0x1c;
        local_48 = pXVar8;
      }
      else {
        do {
          iVar15 = iVar15 + 1;
          iVar3 = sk_num(*(_STACK **)(param_1_00 + 0x54));
          if (iVar3 <= iVar15) {
            iVar3 = 0;
            if ((*(byte *)(*(int *)(param_1_00 + 0x14) + 0xd) & 0x10) != 0) goto LAB_0815fa73;
            goto LAB_0815f9f0;
          }
          pXVar8 = (X509 *)sk_value(*(_STACK **)(param_1_00 + 0x54),iVar15);
          pXVar5 = X509_get_subject_name(pXVar8);
          iVar3 = X509_NAME_cmp(pXVar5,pXVar13);
        } while ((iVar3 != 0) || (iVar3 = X509_check_akid(pXVar8,pXVar4->akid), iVar3 != 0));
        local_60 = local_60 | 0xc;
        local_48 = pXVar8;
      }
LAB_0815f9f0:
      bVar16 = (local_60 & 4) != 0;
joined_r0x0815fad4:
      if (bVar16) {
        uVar6 = pXVar4->idp_flags;
        if ((uVar6 & 0x10) == 0) {
          if ((*(byte *)&a->ex_flags & 0x10) == 0) {
            uVar6 = uVar6 & 8;
          }
          else {
            uVar6 = uVar6 & 4;
          }
          if (uVar6 == 0) {
            local_38 = pXVar4->idp_reasons;
            for (iVar3 = 0; iVar15 = sk_num((_STACK *)a->crldp), iVar3 < iVar15; iVar3 = iVar3 + 1)
            {
              ppiVar9 = (int **)sk_value((_STACK *)a->crldp,iVar3);
              pXVar13 = pXVar4->crl->issuer;
              p_Var10 = (_STACK *)ppiVar9[2];
              if (p_Var10 == (_STACK *)0x0) {
                if ((local_60 & 0x20) != 0) {
LAB_0815fbb1:
                  if (pXVar4->idp != (ISSUING_DIST_POINT *)0x0) {
                    pDVar1 = pXVar4->idp->distpoint;
                    piVar11 = *ppiVar9;
                    if ((piVar11 != (int *)0x0) && (pDVar1 != (DIST_POINT_NAME *)0x0)) {
                      if (*piVar11 == 1) {
                        pXVar13 = (X509_NAME *)piVar11[2];
                        if (pXVar13 != (X509_NAME *)0x0) {
                          if (pDVar1->type != 1) {
                            p_Var10 = (_STACK *)(pDVar1->name).fullname;
                            goto LAB_0815ff01;
                          }
                          if ((pDVar1->dpname != (X509_NAME *)0x0) &&
                             (iVar15 = X509_NAME_cmp(pXVar13,pDVar1->dpname), iVar15 == 0))
                          goto LAB_0815feb4;
                        }
                      }
                      else if (pDVar1->type == 1) {
                        pXVar13 = pDVar1->dpname;
                        if (pXVar13 != (X509_NAME *)0x0) {
                          p_Var10 = (_STACK *)piVar11[1];
LAB_0815ff01:
                          for (iVar15 = 0; iVar7 = sk_num(p_Var10), iVar15 < iVar7;
                              iVar15 = iVar15 + 1) {
                            piVar11 = (int *)sk_value(p_Var10,iVar15);
                            if ((*piVar11 == 4) &&
                               (iVar7 = X509_NAME_cmp(pXVar13,(X509_NAME *)piVar11[1]), iVar7 == 0))
                            goto LAB_0815feb4;
                          }
                        }
                      }
                      else {
                        for (local_2c = 0; iVar15 = sk_num((_STACK *)piVar11[1]), local_2c < iVar15;
                            local_2c = local_2c + 1) {
                          a_00 = (GENERAL_NAME *)sk_value((_STACK *)piVar11[1],local_2c);
                          for (iVar15 = 0; iVar7 = sk_num((_STACK *)(pDVar1->name).fullname),
                              iVar15 < iVar7; iVar15 = iVar15 + 1) {
                            b = (GENERAL_NAME *)sk_value((_STACK *)(pDVar1->name).fullname,iVar15);
                            iVar7 = GENERAL_NAME_cmp(a_00,b);
                            if (iVar7 == 0) goto LAB_0815feb4;
                          }
                        }
                      }
                      goto LAB_0815fe90;
                    }
                  }
LAB_0815feb4:
                  local_38 = local_38 & (uint)ppiVar9[3];
                  goto LAB_0815febb;
                }
              }
              else {
                for (iVar15 = 0; iVar7 = sk_num(p_Var10), iVar15 < iVar7; iVar15 = iVar15 + 1) {
                  piVar11 = (int *)sk_value((_STACK *)ppiVar9[2],iVar15);
                  if ((*piVar11 == 4) &&
                     (iVar7 = X509_NAME_cmp((X509_NAME *)piVar11[1],pXVar13), iVar7 == 0))
                  goto LAB_0815fbb1;
                  p_Var10 = (_STACK *)ppiVar9[2];
                }
              }
LAB_0815fe90:
            }
            if (((pXVar4->idp == (ISSUING_DIST_POINT *)0x0) ||
                (pXVar4->idp->distpoint == (DIST_POINT_NAME *)0x0)) && ((local_60 & 0x20) != 0)) {
LAB_0815febb:
              if ((local_38 & ~local_54) == 0) goto LAB_0815f9fb;
              local_60 = local_60 | 0x80;
              local_54 = local_54 | local_38;
            }
          }
        }
      }
      else {
LAB_0815f9fb:
        local_60 = 0;
      }
    }
LAB_0815fa08:
    if ((int)local_58 < (int)local_60) {
      local_58 = local_60;
      local_40 = local_48;
      local_44 = local_54;
      local_4c = pXVar4;
    }
  }
  if (local_4c != (X509_CRL *)0x0) {
    if (*param_2_00 != (X509_CRL *)0x0) {
      X509_CRL_free(*param_2_00);
    }
    *param_2_00 = local_4c;
    *param_1 = local_40;
    *param_2 = local_58;
    *param_3 = local_44;
    CRYPTO_add_lock(&local_4c->references,1,6,"x509_vfy.c",0x35f);
    if (*param_3_00 != (X509_CRL *)0x0) {
      X509_CRL_free(*param_3_00);
      *param_3_00 = (X509_CRL *)0x0;
    }
    if (((*(byte *)(*(int *)(param_1_00 + 0x14) + 0xd) & 0x20) != 0) &&
       (((*(uint *)(*(int *)(param_1_00 + 0x68) + 0x28) | local_4c->flags) & 0x1000) != 0)) {
      for (iVar3 = 0; iVar15 = sk_num(param_4), iVar3 < iVar15; iVar3 = iVar3 + 1) {
        pXVar4 = (X509_CRL *)sk_value(param_4,iVar3);
        if (((pXVar4->base_crl_number != (ASN1_INTEGER *)0x0) &&
            (local_4c->crl_number != (ASN1_INTEGER *)0x0)) &&
           ((ptVar14 = (time_t *)X509_NAME_cmp(local_4c->crl->issuer,pXVar4->crl->issuer),
            ptVar14 == (time_t *)0x0 &&
            ((((iVar15 = crl_extension_match(), iVar15 != 0 &&
               (iVar15 = crl_extension_match(), iVar15 != 0)) &&
              (iVar15 = ASN1_INTEGER_cmp(pXVar4->base_crl_number,local_4c->crl_number), iVar15 < 1))
             && (iVar15 = ASN1_INTEGER_cmp(pXVar4->crl_number,local_4c->crl_number), 0 < iVar15)))))
           ) {
          if ((*(byte *)(*(int *)(param_1_00 + 0x14) + 0xc) & 2) != 0) {
            ptVar14 = (time_t *)(*(int *)(param_1_00 + 0x14) + 4);
          }
          iVar3 = X509_cmp_time(pXVar4->crl->lastUpdate,ptVar14);
          if (iVar3 < 0) {
            s = pXVar4->crl->nextUpdate;
            if (s != (ASN1_TIME *)0x0) {
              iVar3 = X509_cmp_time(s,ptVar14);
              if ((iVar3 == 0) || ((iVar3 < 0 && ((*(byte *)(param_1_00 + 0x74) & 2) == 0))))
              goto LAB_0815fe38;
            }
            *param_2 = *param_2 | 2;
          }
LAB_0815fe38:
          CRYPTO_add_lock(&pXVar4->references,1,6,"x509_vfy.c",0x3ca);
          *param_3_00 = pXVar4;
          goto LAB_0815fe5b;
        }
      }
      *param_3_00 = (X509_CRL *)0x0;
    }
  }
LAB_0815fe5b:
  return 0x1bf < (int)local_58;
LAB_0815fa73:
  iVar15 = sk_num(*(_STACK **)(param_1_00 + 0xc));
  if (iVar15 <= iVar3) goto LAB_0815f9f0;
  pXVar8 = (X509 *)sk_value(*(_STACK **)(param_1_00 + 0xc),iVar3);
  pXVar5 = X509_get_subject_name(pXVar8);
  iVar15 = X509_NAME_cmp(pXVar5,pXVar13);
  if ((iVar15 == 0) && (iVar15 = X509_check_akid(pXVar8,pXVar4->akid), iVar15 == 0)) {
    local_60 = local_60 | 4;
    bVar16 = true;
    local_48 = pXVar8;
    goto joined_r0x0815fad4;
  }
  iVar3 = iVar3 + 1;
  goto LAB_0815fa73;
}

