
int ssl3_choose_cipher(int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  int *in_zero;
  int iVar3;
  int iVar4;
  char cVar6;
  int *piVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  char cVar19;
  uint uVar20;
  undefined4 local_38;
  int local_30;
  
  iVar18 = param_1[0x26];
  uVar17 = param_3;
  local_38 = param_2;
  if (-1 < param_1[0x40] << 9) {
    uVar17 = param_2;
    local_38 = param_3;
  }
  iVar16 = 0;
  local_30 = 0;
  cVar6 = '\0';
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar17);
  cVar19 = '\0';
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(uVar17,iVar16);
      if (((*(uint *)(iVar3 + 0x1c) & 4) == 0) || ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
        (*(code *)PTR_ssl_set_cert_masks_006a80d4)(iVar18,iVar3);
        uVar7 = *(uint *)(iVar18 + 8);
        uVar14 = *(uint *)(iVar18 + 0xc);
        uVar10 = *(uint *)(iVar18 + 0x10);
        uVar15 = *(uint *)(iVar18 + 0x14);
        if ((param_1[0x74] & 0x400U) != 0) {
          uVar7 = uVar7 | 0x400;
          uVar10 = uVar10 | 0x400;
          uVar14 = uVar14 | 0x400;
          uVar15 = uVar15 | 0x400;
        }
        uVar9 = *(uint *)(iVar3 + 0xc);
        uVar20 = *(uint *)(iVar3 + 0x10);
        if (((uVar9 & 0x100) == 0) || (param_1[0x38] != 0)) {
          if ((*(uint *)(iVar3 + 0x20) & 2) == 0) {
            if ((uVar7 & uVar9) == 0) {
              bVar1 = false;
            }
            else {
              bVar1 = (uVar14 & uVar20) != 0;
            }
          }
          else {
            bVar1 = false;
            if ((uVar10 & uVar9) != 0) {
              bVar1 = (uVar15 & uVar20) != 0;
            }
          }
          if ((uVar20 & 0x50) == 0) {
LAB_004867b4:
            if (((uVar9 & 0x80) != 0) && (iVar8 = *(int *)(param_1[0x26] + 0x28), iVar8 != 0)) {
              iVar4 = param_1[0x30];
              goto LAB_004867d0;
            }
          }
          else {
            iVar8 = param_1[0x26];
            if (*(int **)(iVar8 + 0x6c) == (int *)0x0) goto LAB_004867b4;
            iVar4 = param_1[0x30];
            if (((((*(int *)(iVar4 + 0xd4) != 0) && (*(int *)(iVar4 + 0xd8) != 0)) &&
                 (iVar11 = **(int **)(iVar8 + 0x6c), iVar11 != 0)) &&
                ((iVar11 = *(int *)(iVar11 + 0x18), iVar11 != 0 &&
                 (iVar11 = *(int *)(iVar11 + 4), iVar11 != 0)))) &&
               ((pcVar12 = *(char **)(iVar11 + 8), pcVar12 != (char *)0x0 &&
                ((byte)(*pcVar12 - 2U) < 2)))) {
              iVar8 = *(int *)(*(int *)(iVar8 + 0x70) + 0x14);
              if (iVar8 == 0) {
                iVar8 = *(int *)in_zero[1];
LAB_00486a94:
                iVar8 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)(iVar8);
                if (iVar8 != 0x197) goto LAB_00486ab8;
                iVar8 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar8 == 0) goto LAB_00486ab8;
                pcVar12 = *(char **)(param_1[0x30] + 0xd8);
                if (*pcVar12 != '\x02') {
                  pcVar13 = pcVar12 + iVar8;
                  do {
                    pcVar12 = pcVar12 + 1;
                    if (pcVar12 == pcVar13) goto LAB_00486ab8;
                  } while (*pcVar12 != '\x02');
                }
LAB_00486b2c:
                bVar2 = !bVar1;
                bVar1 = true;
                if (bVar2) goto LAB_00486ab8;
                iVar8 = param_1[0x26];
              }
              else {
                piVar5 = *(int **)(iVar8 + 4);
                if (piVar5 == (int *)0x0) {
                  iVar8 = *in_zero;
                  goto LAB_00486a94;
                }
                iVar8 = *piVar5;
                if (iVar8 == 0) goto LAB_00486a94;
                iVar8 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)();
                if (iVar8 != 0x196) {
                  iVar8 = **(int **)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4);
                  goto LAB_00486a94;
                }
                iVar8 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar8 != 0) {
                  pcVar12 = *(char **)(param_1[0x30] + 0xd8);
                  if (*pcVar12 != '\x01') {
                    pcVar13 = pcVar12 + iVar8;
                    do {
                      pcVar12 = pcVar12 + 1;
                      if (pcVar13 == pcVar12) goto LAB_00486ab8;
                    } while (*pcVar12 != '\x01');
                  }
                  goto LAB_00486b2c;
                }
LAB_00486ab8:
                bVar1 = false;
                iVar8 = param_1[0x26];
              }
              if (*(int *)(iVar8 + 0x6c) == 0) goto LAB_004867b4;
              iVar4 = param_1[0x30];
            }
            if ((*(int *)(iVar4 + 0xdc) == 0) || (*(int *)(iVar4 + 0xe0) == 0)) goto LAB_004867b4;
            iVar8 = *(int *)(*(int *)(iVar8 + 0x70) + 0x14);
            if ((iVar8 != 0) && (*(int *)(iVar8 + 4) != 0)) {
              iVar8 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)();
              if ((iVar8 == 0) &&
                 (**(int **)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4) != 0)) {
                iVar8 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)();
                if (iVar8 == 0x196) {
                  cVar6 = '\x01';
                  cVar19 = -1;
                }
                else {
                  iVar8 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)
                                    (**(undefined4 **)
                                       (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4));
                  if (iVar8 == 0x197) {
                    cVar6 = '\x02';
                    cVar19 = -1;
                  }
                  else if (cVar19 == '\0') goto LAB_0048692c;
                }
              }
              else {
                cVar6 = tls1_ec_nid2curve_id(iVar8);
LAB_0048692c:
                cVar19 = '\0';
                if (cVar6 == '\0') goto LAB_00486938;
              }
              uVar7 = *(uint *)(param_1[0x30] + 0xdc);
              if (uVar7 >> 1 != 0) {
                pcVar12 = *(char **)(param_1[0x30] + 0xe0);
                pcVar13 = pcVar12 + (uVar7 & 0xfffffffe);
                do {
                  if ((*pcVar12 == cVar19) && (pcVar12[1] == cVar6)) goto LAB_004867b4;
                  pcVar12 = pcVar12 + 2;
                } while (pcVar12 != pcVar13);
              }
            }
LAB_00486938:
            if ((uVar9 & 0x80) == 0) goto LAB_00486558;
            iVar8 = *(int *)(param_1[0x26] + 0x28);
            bVar1 = false;
            if (iVar8 == 0) goto LAB_00486558;
            iVar4 = param_1[0x30];
LAB_004867d0:
            if ((*(int *)(iVar4 + 0xdc) != 0) && (*(int *)(iVar4 + 0xe0) != 0)) {
              if (*(int *)(iVar8 + 4) != 0) {
                iVar8 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)();
                if ((iVar8 == 0) && (**(int **)(*(int *)(param_1[0x26] + 0x28) + 4) != 0)) {
                  iVar8 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)();
                  if (iVar8 == 0x196) {
                    cVar6 = '\x01';
                    cVar19 = -1;
                  }
                  else {
                    iVar8 = (*(code *)PTR_EC_METHOD_get_field_type_006a71b8)
                                      (**(undefined4 **)(*(int *)(param_1[0x26] + 0x28) + 4));
                    if (iVar8 == 0x197) {
                      cVar6 = '\x02';
                      cVar19 = -1;
                    }
                    else if (cVar19 == '\0') goto LAB_004869b0;
                  }
                }
                else {
                  cVar6 = tls1_ec_nid2curve_id(iVar8);
LAB_004869b0:
                  cVar19 = '\0';
                  if (cVar6 == '\0') goto LAB_00486558;
                }
                uVar7 = *(uint *)(param_1[0x30] + 0xdc);
                if (uVar7 >> 1 != 0) {
                  pcVar12 = *(char **)(param_1[0x30] + 0xe0);
                  pcVar13 = pcVar12 + (uVar7 & 0xfffffffe);
                  do {
                    if ((*pcVar12 == cVar19) && (pcVar12[1] == cVar6)) {
                      if ((bVar1) &&
                         (iVar3 = (*(code *)PTR_sk_find_006a8044)(local_38,iVar3), -1 < iVar3))
                      goto LAB_004868a0;
                      break;
                    }
                    pcVar12 = pcVar12 + 2;
                  } while (pcVar12 != pcVar13);
                }
              }
              goto LAB_00486558;
            }
          }
          if ((bVar1) && (iVar3 = (*(code *)PTR_sk_find_006a8044)(local_38,iVar3), -1 < iVar3)) {
            if ((uVar9 & 0x80) == 0) {
LAB_00486958:
                    /* WARNING: Could not recover jumptable at 0x00486988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              iVar18 = (*(code *)PTR_sk_value_006a6e24)(local_38,iVar3);
              return iVar18;
            }
LAB_004868a0:
            if (((uVar20 & 0x40) == 0) || (*(char *)(param_1[0x16] + 0x420) == '\0'))
            goto LAB_00486958;
            if (local_30 == 0) {
              local_30 = (*(code *)PTR_sk_value_006a6e24)(local_38,iVar3);
            }
          }
        }
      }
LAB_00486558:
      iVar16 = iVar16 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar17);
    } while (iVar16 < iVar3);
  }
  return local_30;
}

