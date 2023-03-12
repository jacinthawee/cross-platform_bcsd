
void get_crl_sk(int param_1,X509_CRL **param_2,X509_CRL **param_3,X509 **param_4,
               ASN1_INTEGER **param_5,uint *param_6,_STACK *param_7)

{
  int iVar1;
  X509_CRL *pXVar2;
  X509_NAME *pXVar3;
  X509 *pXVar4;
  X509_NAME *pXVar5;
  int **ppiVar6;
  _STACK *p_Var7;
  int *piVar8;
  GENERAL_NAME *a;
  GENERAL_NAME *b;
  X509 *a_00;
  ASN1_INTEGER *pAVar9;
  uint uVar10;
  X509_CRL_INFO *pXVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  time_t *t;
  DIST_POINT_NAME *pDVar15;
  ASN1_INTEGER *pAVar16;
  int iVar17;
  uint local_68;
  ASN1_INTEGER *local_64;
  X509 *local_60;
  X509_CRL *local_5c;
  uint local_58;
  X509 *local_54;
  int local_44;
  uint local_30;
  
  local_60 = (X509 *)0x0;
  local_54 = (X509 *)0x0;
  a_00 = *(X509 **)(param_1 + 0x68);
  local_64 = *param_5;
  iVar17 = 0;
  local_5c = (X509_CRL *)0x0;
  local_58 = 0;
  iVar1 = sk_num(param_7);
  if (iVar1 < 1) {
LAB_000c81ba:
    if (local_5c != (X509_CRL *)0x0) {
      if (*param_2 != (X509_CRL *)0x0) {
        X509_CRL_free(*param_2);
      }
      *param_2 = local_5c;
      *param_4 = local_54;
      *param_5 = local_64;
      *param_6 = local_58;
      CRYPTO_add_lock(&local_5c->references,1,6,"x509_vfy.c",0x3de);
      if (*param_3 != (X509_CRL *)0x0) {
        X509_CRL_free(*param_3);
        *param_3 = (X509_CRL *)0x0;
      }
      if ((*(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x12 < 0) &&
         ((int)((local_5c->flags | *(uint *)(*(int *)(param_1 + 0x68) + 0x28)) << 0x13) < 0)) {
        for (iVar1 = 0; iVar17 = sk_num(param_7), iVar1 < iVar17; iVar1 = iVar1 + 1) {
          pXVar2 = (X509_CRL *)sk_value(param_7,iVar1);
          if ((((pXVar2->base_crl_number != (ASN1_INTEGER *)0x0) &&
               (local_5c->crl_number != (ASN1_INTEGER *)0x0)) &&
              ((iVar17 = X509_NAME_cmp(local_5c->crl->issuer,pXVar2->crl->issuer), iVar17 == 0 &&
               (((iVar17 = crl_extension_match(pXVar2,local_5c,0x5a), iVar17 != 0 &&
                 (iVar17 = crl_extension_match(pXVar2,local_5c,0x302), iVar17 != 0)) &&
                (iVar17 = ASN1_INTEGER_cmp(pXVar2->base_crl_number,local_5c->crl_number), iVar17 < 1
                )))))) &&
             (iVar17 = ASN1_INTEGER_cmp(pXVar2->crl_number,local_5c->crl_number), 0 < iVar17)) {
            iVar1 = check_crl_time(param_1,pXVar2,0);
            if (iVar1 != 0) {
              *param_5 = (ASN1_INTEGER *)((uint)*param_5 | 2);
            }
            CRYPTO_add_lock(&pXVar2->references,1,6,"x509_vfy.c",0x442);
            *param_3 = pXVar2;
            return;
          }
        }
        *param_3 = (X509_CRL *)0x0;
      }
    }
    return;
  }
LAB_000c8092:
  pXVar2 = (X509_CRL *)sk_value(param_7,iVar17);
  local_68 = *param_6;
  uVar10 = pXVar2->idp_flags;
  if (-1 < (int)(uVar10 << 0x1e)) {
    pAVar9 = (ASN1_INTEGER *)(*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x1000);
    if (pAVar9 == (ASN1_INTEGER *)0x0) {
      pAVar16 = (ASN1_INTEGER *)(uVar10 & 0x60);
    }
    else {
      pAVar9 = (ASN1_INTEGER *)(uVar10 & 0x40);
      if (pAVar9 == (ASN1_INTEGER *)0x0) {
        pAVar16 = pXVar2->base_crl_number;
      }
      else {
        pAVar9 = (ASN1_INTEGER *)(pXVar2->idp_reasons & ~local_68);
        pAVar16 = pAVar9;
      }
    }
    if (pAVar16 != (ASN1_INTEGER *)0x0) goto LAB_000c8196;
    pXVar3 = X509_get_issuer_name(a_00);
    iVar1 = X509_NAME_cmp(pXVar3,pXVar2->crl->issuer);
    if (iVar1 == 0) {
      pAVar9 = (ASN1_INTEGER *)0x120;
      pAVar16 = (ASN1_INTEGER *)0x20;
    }
    else {
      pAVar9 = (ASN1_INTEGER *)(pXVar2->idp_flags & 0x20);
      if (pAVar9 == (ASN1_INTEGER *)0x0) goto LAB_000c8196;
      pAVar9 = (ASN1_INTEGER *)0x100;
      pAVar16 = (ASN1_INTEGER *)0x0;
    }
    if ((pXVar2->flags & 0x200U) == 0) {
      pAVar16 = pAVar9;
    }
    t = (time_t *)(*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2);
    if (t != (time_t *)0x0) {
      t = (time_t *)(*(int *)(param_1 + 0x14) + 4);
    }
    iVar1 = X509_cmp_time(pXVar2->crl->lastUpdate,t);
    if (iVar1 < 0) {
      pXVar11 = pXVar2->crl;
      if (pXVar11->nextUpdate != (ASN1_TIME *)0x0) {
        iVar1 = X509_cmp_time(pXVar11->nextUpdate,t);
        if ((iVar1 == 0) || ((iVar1 < 0 && (-1 < *(int *)(param_1 + 0x74) << 0x1e))))
        goto LAB_000c8112;
        pXVar11 = pXVar2->crl;
      }
      pAVar16 = (ASN1_INTEGER *)((uint)pAVar16 | 0x40);
    }
    else {
LAB_000c8112:
      pXVar11 = pXVar2->crl;
    }
    pXVar3 = pXVar11->issuer;
    iVar12 = *(int *)(param_1 + 0x60);
    iVar1 = sk_num(*(_STACK **)(param_1 + 0x54));
    if (iVar12 != iVar1 + -1) {
      iVar12 = iVar12 + 1;
    }
    pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar12);
    iVar1 = X509_check_akid(pXVar4,pXVar2->akid);
    if ((iVar1 == 0) && (((uint)pAVar16 & 0x20) != 0)) {
      pAVar16 = (ASN1_INTEGER *)((uint)pAVar16 | 0x1c);
      local_60 = pXVar4;
    }
    else {
      iVar1 = iVar12 + 1;
      do {
        iVar12 = sk_num(*(_STACK **)(param_1 + 0x54));
        iVar13 = iVar1 + 1;
        if (iVar12 <= iVar1) {
          if (-1 < *(int *)(*(int *)(param_1 + 0x14) + 0xc) << 0x13) goto LAB_000c818c;
          iVar1 = 0;
          goto LAB_000c8418;
        }
        pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0x54),iVar1);
        pXVar5 = X509_get_subject_name(pXVar4);
        iVar12 = X509_NAME_cmp(pXVar5,pXVar3);
        iVar1 = iVar13;
      } while ((iVar12 != 0) || (iVar12 = X509_check_akid(pXVar4,pXVar2->akid), iVar12 != 0));
      pAVar16 = (ASN1_INTEGER *)((uint)pAVar16 | 0xc);
      local_60 = pXVar4;
    }
LAB_000c818c:
    pAVar9 = (ASN1_INTEGER *)((uint)pAVar16 & 4);
    if (pAVar9 == (ASN1_INTEGER *)0x0) goto LAB_000c8196;
    goto LAB_000c82fc;
  }
  pAVar9 = (ASN1_INTEGER *)0x0;
  goto LAB_000c8196;
  while( true ) {
    pXVar4 = (X509 *)sk_value(*(_STACK **)(param_1 + 0xc),iVar1);
    pXVar5 = X509_get_subject_name(pXVar4);
    iVar12 = X509_NAME_cmp(pXVar5,pXVar3);
    iVar1 = iVar13;
    if ((iVar12 == 0) && (iVar12 = X509_check_akid(pXVar4,pXVar2->akid), iVar12 == 0)) break;
LAB_000c8418:
    iVar12 = sk_num(*(_STACK **)(param_1 + 0xc));
    iVar13 = iVar1 + 1;
    if (iVar12 <= iVar1) goto LAB_000c818c;
  }
  pAVar16 = (ASN1_INTEGER *)((uint)pAVar16 | 4);
  local_60 = pXVar4;
LAB_000c82fc:
  iVar1 = pXVar2->idp_flags;
  pAVar9 = pAVar16;
  if (-1 < iVar1 << 0x1b) {
    if ((int)(a_00->ex_flags << 0x1b) < 0) {
      iVar1 = iVar1 << 0x1d;
    }
    else {
      iVar1 = iVar1 << 0x1c;
    }
    if (-1 < iVar1) {
      local_30 = pXVar2->idp_reasons;
      iVar12 = 0;
      iVar1 = sk_num((_STACK *)a_00->crldp);
      if (0 < iVar1) {
        do {
          ppiVar6 = (int **)sk_value((_STACK *)a_00->crldp,iVar12);
          pXVar3 = pXVar2->crl->issuer;
          p_Var7 = (_STACK *)ppiVar6[2];
          if (p_Var7 == (_STACK *)0x0) {
            if (((uint)pAVar16 & 0x20) != 0) {
LAB_000c8388:
              if (pXVar2->idp != (ISSUING_DIST_POINT *)0x0) {
                pDVar15 = pXVar2->idp->distpoint;
                piVar8 = *ppiVar6;
                if (piVar8 != (int *)0x0 && pDVar15 != (DIST_POINT_NAME *)0x0) {
                  if (*piVar8 == 1) {
                    pXVar3 = (X509_NAME *)piVar8[2];
                    if (pXVar3 != (X509_NAME *)0x0) {
                      if (pDVar15->type != 1) {
                        p_Var7 = (_STACK *)(pDVar15->name).fullname;
                        goto LAB_000c84da;
                      }
                      if ((pDVar15->dpname != (X509_NAME *)0x0) &&
                         (iVar1 = X509_NAME_cmp(pXVar3,pDVar15->dpname), iVar1 == 0))
                      goto LAB_000c8504;
                    }
                  }
                  else if (pDVar15->type == 1) {
                    pXVar3 = pDVar15->dpname;
                    if (pXVar3 != (X509_NAME *)0x0) {
                      p_Var7 = (_STACK *)piVar8[1];
LAB_000c84da:
                      iVar1 = 0;
                      while( true ) {
                        iVar13 = sk_num(p_Var7);
                        iVar14 = iVar1 + 1;
                        if (iVar13 <= iVar1) break;
                        piVar8 = (int *)sk_value(p_Var7,iVar1);
                        iVar1 = iVar14;
                        if ((*piVar8 == 4) &&
                           (iVar13 = X509_NAME_cmp(pXVar3,(X509_NAME *)piVar8[1]), iVar13 == 0))
                        goto LAB_000c8504;
                      }
                    }
                  }
                  else {
                    for (local_44 = 0; iVar1 = sk_num((_STACK *)piVar8[1]), local_44 < iVar1;
                        local_44 = local_44 + 1) {
                      a = (GENERAL_NAME *)sk_value((_STACK *)piVar8[1],local_44);
                      iVar1 = 0;
                      while( true ) {
                        iVar13 = sk_num((_STACK *)(pDVar15->name).fullname);
                        if (iVar13 <= iVar1) break;
                        b = (GENERAL_NAME *)sk_value((_STACK *)(pDVar15->name).fullname,iVar1);
                        iVar13 = GENERAL_NAME_cmp(a,b);
                        iVar1 = iVar1 + 1;
                        if (iVar13 == 0) goto LAB_000c8504;
                      }
                    }
                  }
                  goto LAB_000c8490;
                }
              }
LAB_000c8504:
              local_30 = local_30 & (uint)ppiVar6[3];
              goto LAB_000c851c;
            }
          }
          else {
            iVar1 = 0;
            while( true ) {
              iVar13 = sk_num(p_Var7);
              if (iVar13 <= iVar1) break;
              piVar8 = (int *)sk_value((_STACK *)ppiVar6[2],iVar1);
              if ((*piVar8 == 4) &&
                 (iVar13 = X509_NAME_cmp((X509_NAME *)piVar8[1],pXVar3), iVar13 == 0))
              goto LAB_000c8388;
              p_Var7 = (_STACK *)ppiVar6[2];
              iVar1 = iVar1 + 1;
            }
          }
LAB_000c8490:
          iVar12 = iVar12 + 1;
          iVar1 = sk_num((_STACK *)a_00->crldp);
        } while (iVar12 < iVar1);
      }
      if (((pXVar2->idp == (ISSUING_DIST_POINT *)0x0) ||
          (pXVar2->idp->distpoint == (DIST_POINT_NAME *)0x0)) && (((uint)pAVar16 & 0x20) != 0)) {
LAB_000c851c:
        pAVar9 = (ASN1_INTEGER *)(local_30 & ~local_68);
        if (pAVar9 != (ASN1_INTEGER *)0x0) {
          local_68 = local_68 | local_30;
          pAVar9 = (ASN1_INTEGER *)((uint)pAVar16 | 0x80);
        }
      }
    }
  }
LAB_000c8196:
  if ((int)local_64 < (int)pAVar9) {
    local_58 = local_68;
    local_54 = local_60;
    local_64 = pAVar9;
    local_5c = pXVar2;
  }
  iVar17 = iVar17 + 1;
  iVar1 = sk_num(param_7);
  if (iVar1 <= iVar17) goto LAB_000c81ba;
  goto LAB_000c8092;
}

