
bool get_crl_sk(int param_1,int **param_2,int **param_3,X509 **param_4,uint *param_5,uint *param_6,
               undefined4 param_7)

{
  undefined *puVar1;
  X509 *a;
  int iVar2;
  int *piVar3;
  uint uVar4;
  X509_NAME *pXVar5;
  int iVar6;
  X509 *pXVar7;
  X509_NAME *pXVar8;
  int **ppiVar9;
  int *piVar10;
  int iVar11;
  GENERAL_NAME *a_00;
  GENERAL_NAME *b;
  time_t *ptVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  uint local_58;
  uint local_54;
  int *local_50;
  X509 *local_4c;
  uint local_48;
  X509 *local_44;
  uint local_3c;
  int local_38;
  
  a = *(X509 **)(param_1 + 0x68);
  iVar16 = 0;
  local_4c = (X509 *)0x0;
  local_44 = (X509 *)0x0;
  local_50 = (int *)0x0;
  local_48 = 0;
  local_58 = *param_5;
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_7);
  if (iVar2 < 1) {
LAB_0057c070:
    if (local_50 != (int *)0x0) {
      if (*param_2 != (int *)0x0) {
        (*(code *)PTR_X509_CRL_free_006a8160)();
      }
      puVar1 = PTR_CRYPTO_add_lock_006a9080;
      *param_2 = local_50;
      *param_4 = local_44;
      *param_5 = local_58;
      *param_6 = local_48;
      (*(code *)puVar1)(local_50 + 3,1,6,"x509_vfy.c",0x35f);
      if (*param_3 != (int *)0x0) {
        (*(code *)PTR_X509_CRL_free_006a8160)();
        *param_3 = (int *)0x0;
      }
      if (((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x2000) != 0) &&
         (((*(uint *)(*(int *)(param_1 + 0x68) + 0x28) | local_50[4]) & 0x1000) != 0)) {
        iVar2 = 0;
        while( true ) {
          iVar16 = (*(code *)PTR_sk_num_006a7f2c)(param_7);
          if (iVar16 <= iVar2) {
            *param_3 = (int *)0x0;
            return 0x1bf < (int)local_58;
          }
          piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(param_7,iVar2);
          if (((piVar3[10] != 0) && (local_50[9] != 0)) &&
             ((iVar16 = X509_NAME_cmp(*(X509_NAME **)(*local_50 + 8),*(X509_NAME **)(*piVar3 + 8)),
              iVar16 == 0 &&
              ((((iVar16 = crl_extension_match(piVar3,local_50,0x5a), iVar16 != 0 &&
                 (iVar16 = crl_extension_match(piVar3,local_50,0x302), iVar16 != 0)) &&
                (iVar16 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(piVar3[10],local_50[9]),
                iVar16 < 1)) &&
               (iVar16 = (*(code *)PTR_ASN1_INTEGER_cmp_006a9e58)(piVar3[9],local_50[9]), 0 < iVar16
               )))))) break;
          iVar2 = iVar2 + 1;
        }
        ptVar12 = (time_t *)(*(int *)(param_1 + 0x14) + 4);
        if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2) == 0) {
          ptVar12 = (time_t *)0x0;
        }
        iVar2 = X509_cmp_time(*(ASN1_TIME **)(*piVar3 + 0xc),ptVar12);
        if ((iVar2 < 0) &&
           ((*(ASN1_TIME **)(*piVar3 + 0x10) == (ASN1_TIME *)0x0 ||
            ((iVar2 = X509_cmp_time(*(ASN1_TIME **)(*piVar3 + 0x10),ptVar12), iVar2 != 0 &&
             ((-1 < iVar2 || ((*(uint *)(param_1 + 0x74) & 2) != 0)))))))) {
          *param_5 = *param_5 | 2;
        }
        (*(code *)PTR_CRYPTO_add_lock_006a9080)(piVar3 + 3,1,6,"x509_vfy.c",0x3ca);
        *param_3 = piVar3;
      }
    }
    return 0x1bf < (int)local_58;
  }
LAB_0057be70:
  piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(param_7,iVar16);
  local_54 = *param_6;
  uVar4 = piVar3[7];
  uVar15 = 0;
  if ((uVar4 & 2) == 0) {
    if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x1000) == 0) {
      if ((uVar4 & 0x60) == 0) goto LAB_0057bec8;
      goto LAB_0057c038;
    }
    if ((uVar4 & 0x40) != 0) {
      if ((~local_54 & piVar3[8]) == 0) {
        uVar15 = 0;
        goto LAB_0057c038;
      }
LAB_0057bec8:
      pXVar5 = X509_get_issuer_name(a);
      iVar2 = X509_NAME_cmp(pXVar5,*(X509_NAME **)(*piVar3 + 8));
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_1 + 0x14);
        uVar15 = 0x120;
        if ((piVar3[4] & 0x200U) != 0) {
          uVar15 = 0x20;
        }
        if ((*(uint *)(iVar2 + 0xc) & 2) != 0) goto LAB_0057bf20;
LAB_0057c3e0:
        ptVar12 = (time_t *)0x0;
        iVar2 = X509_cmp_time(*(ASN1_TIME **)(*piVar3 + 0xc),(time_t *)0x0);
        if (iVar2 < 0) goto LAB_0057c3fc;
LAB_0057bf3c:
        iVar2 = *piVar3;
      }
      else {
        uVar15 = 0x100;
        if ((piVar3[7] & 0x20U) == 0) goto LAB_0057c02c;
        iVar2 = *(int *)(param_1 + 0x14);
        if ((piVar3[4] & 0x200U) != 0) {
          uVar15 = 0;
        }
        if ((*(uint *)(iVar2 + 0xc) & 2) == 0) goto LAB_0057c3e0;
LAB_0057bf20:
        ptVar12 = (time_t *)(iVar2 + 4);
        iVar2 = X509_cmp_time(*(ASN1_TIME **)(*piVar3 + 0xc),ptVar12);
        if (-1 < iVar2) goto LAB_0057bf3c;
LAB_0057c3fc:
        iVar2 = *piVar3;
        if (*(ASN1_TIME **)(iVar2 + 0x10) != (ASN1_TIME *)0x0) {
          iVar2 = X509_cmp_time(*(ASN1_TIME **)(iVar2 + 0x10),ptVar12);
          if (iVar2 == 0) goto LAB_0057bf3c;
          if (iVar2 < 0) {
            if ((*(uint *)(param_1 + 0x74) & 2) == 0) goto LAB_0057bf3c;
            iVar2 = *piVar3;
          }
          else {
            iVar2 = *piVar3;
          }
        }
        uVar15 = uVar15 | 0x40;
      }
      iVar13 = *(int *)(param_1 + 0x60);
      pXVar5 = *(X509_NAME **)(iVar2 + 8);
      iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 0x54));
      iVar2 = iVar6 + -1;
      if (iVar13 != iVar6 + -1) {
        iVar2 = iVar13 + 1;
      }
      pXVar7 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(param_1 + 0x54),iVar2);
      iVar6 = X509_check_akid(pXVar7,(AUTHORITY_KEYID *)piVar3[5]);
      if ((iVar6 == 0) && ((uVar15 & 0x20) != 0)) {
        uVar15 = uVar15 | 0x1c;
        local_4c = pXVar7;
        goto LAB_0057c1bc;
      }
      iVar2 = iVar2 + 1;
      do {
        iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 0x54));
        iVar13 = iVar2 + 1;
        if (iVar6 <= iVar2) {
          iVar2 = 0;
          if ((*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 0x1000) == 0) goto LAB_0057c1bc;
          goto LAB_0057c33c;
        }
        pXVar7 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(param_1 + 0x54),iVar2);
        pXVar8 = X509_get_subject_name(pXVar7);
        iVar6 = X509_NAME_cmp(pXVar8,pXVar5);
        iVar2 = iVar13;
      } while ((iVar6 != 0) ||
              (iVar6 = X509_check_akid(pXVar7,(AUTHORITY_KEYID *)piVar3[5]), iVar6 != 0));
      uVar15 = uVar15 | 0xc;
      local_4c = pXVar7;
      goto LAB_0057c1c8;
    }
    if (piVar3[10] == 0) goto LAB_0057bec8;
    goto LAB_0057c02c;
  }
  goto LAB_0057c038;
  while( true ) {
    pXVar7 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(*(undefined4 *)(param_1 + 0xc),iVar2);
    pXVar8 = X509_get_subject_name(pXVar7);
    iVar6 = X509_NAME_cmp(pXVar8,pXVar5);
    iVar2 = iVar13;
    if ((iVar6 == 0) && (iVar6 = X509_check_akid(pXVar7,(AUTHORITY_KEYID *)piVar3[5]), iVar6 == 0))
    break;
LAB_0057c33c:
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 0xc));
    iVar13 = iVar2 + 1;
    if (iVar6 <= iVar2) goto LAB_0057c1bc;
  }
  uVar15 = uVar15 | 4;
  local_4c = pXVar7;
LAB_0057c1bc:
  if ((uVar15 & 4) != 0) {
LAB_0057c1c8:
    uVar4 = piVar3[7];
    if ((uVar4 & 0x10) != 0) goto LAB_0057c038;
    if ((a->ex_flags & 0x10) == 0) {
      uVar4 = uVar4 & 8;
    }
    else {
      uVar4 = uVar4 & 4;
    }
    if (uVar4 != 0) goto LAB_0057c038;
    local_3c = piVar3[8];
    iVar6 = 0;
    iVar2 = (*(code *)PTR_sk_num_006a7f2c)(a->crldp);
    if (0 < iVar2) {
      do {
        ppiVar9 = (int **)(*(code *)PTR_sk_value_006a7f24)(a->crldp,iVar6);
        pXVar5 = *(X509_NAME **)(*piVar3 + 8);
        if (ppiVar9[2] == (int *)0x0) {
          if ((uVar15 & 0x20) != 0) {
LAB_0057c564:
            if ((int **)piVar3[6] != (int **)0x0) {
              piVar14 = *ppiVar9;
              piVar10 = *(int **)piVar3[6];
              if ((piVar14 != (int *)0x0) && (piVar10 != (int *)0x0)) {
                if (*piVar14 == 1) {
                  pXVar5 = (X509_NAME *)piVar14[2];
                  if (pXVar5 != (X509_NAME *)0x0) {
                    if (*piVar10 != 1) {
                      iVar2 = piVar10[1];
                      goto LAB_0057c6b0;
                    }
                    if (((X509_NAME *)piVar10[2] != (X509_NAME *)0x0) &&
                       (iVar2 = X509_NAME_cmp(pXVar5,(X509_NAME *)piVar10[2]), iVar2 == 0))
                    goto LAB_0057c654;
                  }
                }
                else if (*piVar10 == 1) {
                  pXVar5 = (X509_NAME *)piVar10[2];
                  if (pXVar5 != (X509_NAME *)0x0) {
                    iVar2 = piVar14[1];
LAB_0057c6b0:
                    iVar13 = 0;
                    while (iVar11 = (*(code *)PTR_sk_num_006a7f2c)(iVar2), iVar13 < iVar11) {
                      iVar11 = iVar13 + 1;
                      piVar10 = (int *)(*(code *)PTR_sk_value_006a7f24)(iVar2,iVar13);
                      iVar13 = iVar11;
                      if ((*piVar10 == 4) &&
                         (iVar11 = X509_NAME_cmp(pXVar5,(X509_NAME *)piVar10[1]), iVar11 == 0))
                      goto LAB_0057c654;
                    }
                  }
                }
                else {
                  for (local_38 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(piVar14[1]),
                      local_38 < iVar2; local_38 = local_38 + 1) {
                    a_00 = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a7f24)(piVar14[1],local_38);
                    iVar2 = 0;
                    while( true ) {
                      iVar13 = (*(code *)PTR_sk_num_006a7f2c)(piVar10[1]);
                      if (iVar13 <= iVar2) break;
                      b = (GENERAL_NAME *)(*(code *)PTR_sk_value_006a7f24)(piVar10[1],iVar2);
                      iVar13 = GENERAL_NAME_cmp(a_00,b);
                      iVar2 = iVar2 + 1;
                      if (iVar13 == 0) goto LAB_0057c654;
                    }
                  }
                }
                goto LAB_0057c2b4;
              }
            }
LAB_0057c654:
            local_3c = local_3c & (uint)ppiVar9[3];
            goto LAB_0057c670;
          }
        }
        else {
          iVar13 = (*(code *)PTR_sk_num_006a7f2c)();
          iVar2 = 0;
          if (0 < iVar13) {
            do {
              iVar13 = iVar2 + 1;
              piVar10 = (int *)(*(code *)PTR_sk_value_006a7f24)(ppiVar9[2],iVar2);
              if ((*piVar10 == 4) &&
                 (iVar2 = X509_NAME_cmp((X509_NAME *)piVar10[1],pXVar5), iVar2 == 0))
              goto LAB_0057c564;
              iVar11 = (*(code *)PTR_sk_num_006a7f2c)(ppiVar9[2]);
              iVar2 = iVar13;
            } while (iVar13 < iVar11);
          }
        }
LAB_0057c2b4:
        iVar6 = iVar6 + 1;
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(a->crldp);
      } while (iVar6 < iVar2);
    }
    if ((((int *)piVar3[6] != (int *)0x0) && (*(int *)piVar3[6] != 0)) || ((uVar15 & 0x20) == 0))
    goto LAB_0057c038;
LAB_0057c670:
    if ((~local_54 & local_3c) != 0) {
      uVar15 = uVar15 | 0x80;
      local_54 = local_54 | local_3c;
      goto LAB_0057c038;
    }
  }
LAB_0057c02c:
  uVar15 = 0;
LAB_0057c038:
  if ((int)local_58 < (int)uVar15) {
    local_44 = local_4c;
    local_48 = local_54;
    local_58 = uVar15;
    local_50 = piVar3;
  }
  iVar16 = iVar16 + 1;
  iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_7);
  if (iVar2 <= iVar16) goto LAB_0057c070;
  goto LAB_0057be70;
}

