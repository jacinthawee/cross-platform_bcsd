
int ssl3_choose_cipher(int *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  int *in_zero;
  int iVar3;
  int iVar4;
  char cVar6;
  int *piVar5;
  int iVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  char *pcVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  char cVar16;
  uint uVar17;
  undefined4 local_38;
  int local_30;
  
  iVar15 = param_1[0x26];
  uVar14 = param_3;
  local_38 = param_2;
  if (-1 < param_1[0x40] << 9) {
    uVar14 = param_2;
    local_38 = param_3;
  }
  iVar13 = 0;
  local_30 = 0;
  cVar6 = '\0';
  iVar3 = (*(code *)PTR_sk_num_006a7f2c)(uVar14);
  cVar16 = '\0';
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a7f24)(uVar14,iVar13);
      if (((*(uint *)(iVar3 + 0x1c) & 4) == 0) || ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
        (*(code *)PTR_ssl_set_cert_masks_006a9208)(iVar15,iVar3);
        uVar8 = *(uint *)(iVar3 + 0xc);
        uVar17 = *(uint *)(iVar3 + 0x10);
        if (((uVar8 & 0x100) == 0) || (param_1[0x38] != 0)) {
          if ((*(uint *)(iVar3 + 0x20) & 2) == 0) {
            if (((*(uint *)(iVar15 + 8) | param_1[0x74]) & uVar8) == 0) {
              bVar1 = false;
            }
            else {
              bVar1 = (*(uint *)(iVar15 + 0xc) & uVar17) != 0;
            }
          }
          else {
            bVar1 = false;
            if (((param_1[0x74] | *(uint *)(iVar15 + 0x10)) & uVar8) != 0) {
              bVar1 = (*(uint *)(iVar15 + 0x14) & uVar17) != 0;
            }
          }
          if ((uVar17 & 0x50) == 0) {
LAB_0048a8b8:
            if (((uVar8 & 0x80) != 0) && (iVar7 = *(int *)(param_1[0x26] + 0x28), iVar7 != 0)) {
              iVar4 = param_1[0x30];
              goto LAB_0048a8d4;
            }
          }
          else {
            iVar7 = param_1[0x26];
            if (*(int **)(iVar7 + 0x6c) == (int *)0x0) goto LAB_0048a8b8;
            iVar4 = param_1[0x30];
            if (((((*(int *)(iVar4 + 0xd4) != 0) && (*(int *)(iVar4 + 0xd8) != 0)) &&
                 (iVar9 = **(int **)(iVar7 + 0x6c), iVar9 != 0)) &&
                ((iVar9 = *(int *)(iVar9 + 0x18), iVar9 != 0 &&
                 (iVar9 = *(int *)(iVar9 + 4), iVar9 != 0)))) &&
               ((pcVar10 = *(char **)(iVar9 + 8), pcVar10 != (char *)0x0 &&
                ((byte)(*pcVar10 - 2U) < 2)))) {
              iVar7 = *(int *)(*(int *)(iVar7 + 0x70) + 0x14);
              if (iVar7 == 0) {
                iVar7 = *(int *)in_zero[1];
LAB_0048ab9c:
                iVar7 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)(iVar7);
                if (iVar7 != 0x197) goto LAB_0048abc0;
                iVar7 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar7 == 0) goto LAB_0048abc0;
                pcVar10 = *(char **)(param_1[0x30] + 0xd8);
                if (*pcVar10 != '\x02') {
                  pcVar12 = pcVar10 + iVar7;
                  do {
                    pcVar10 = pcVar10 + 1;
                    if (pcVar10 == pcVar12) goto LAB_0048abc0;
                  } while (*pcVar10 != '\x02');
                }
LAB_0048ac34:
                bVar2 = !bVar1;
                bVar1 = true;
                if (bVar2) goto LAB_0048abc0;
                iVar7 = param_1[0x26];
              }
              else {
                piVar5 = *(int **)(iVar7 + 4);
                if (piVar5 == (int *)0x0) {
                  iVar7 = *in_zero;
                  goto LAB_0048ab9c;
                }
                iVar7 = *piVar5;
                if (iVar7 == 0) goto LAB_0048ab9c;
                iVar7 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)();
                if (iVar7 != 0x196) {
                  iVar7 = **(int **)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4);
                  goto LAB_0048ab9c;
                }
                iVar7 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar7 != 0) {
                  pcVar10 = *(char **)(param_1[0x30] + 0xd8);
                  if (*pcVar10 != '\x01') {
                    pcVar12 = pcVar10 + iVar7;
                    do {
                      pcVar10 = pcVar10 + 1;
                      if (pcVar10 == pcVar12) goto LAB_0048abc0;
                    } while (*pcVar10 != '\x01');
                  }
                  goto LAB_0048ac34;
                }
LAB_0048abc0:
                bVar1 = false;
                iVar7 = param_1[0x26];
              }
              if (*(int *)(iVar7 + 0x6c) == 0) goto LAB_0048a8b8;
              iVar4 = param_1[0x30];
            }
            if ((*(int *)(iVar4 + 0xdc) == 0) || (*(int *)(iVar4 + 0xe0) == 0)) goto LAB_0048a8b8;
            iVar7 = *(int *)(*(int *)(iVar7 + 0x70) + 0x14);
            if ((iVar7 != 0) && (*(int *)(iVar7 + 4) != 0)) {
              iVar7 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)();
              if ((iVar7 == 0) &&
                 (**(int **)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4) != 0)) {
                iVar7 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)();
                if (iVar7 == 0x196) {
                  cVar6 = '\x01';
                  cVar16 = -1;
                }
                else {
                  iVar7 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)
                                    (**(undefined4 **)
                                       (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4));
                  if (iVar7 == 0x197) {
                    cVar6 = '\x02';
                    cVar16 = -1;
                  }
                  else if (cVar16 == '\0') goto LAB_0048aa34;
                }
              }
              else {
                cVar6 = tls1_ec_nid2curve_id(iVar7);
LAB_0048aa34:
                cVar16 = '\0';
                if (cVar6 == '\0') goto LAB_0048aa40;
              }
              uVar11 = *(uint *)(param_1[0x30] + 0xdc);
              if (uVar11 >> 1 != 0) {
                pcVar10 = *(char **)(param_1[0x30] + 0xe0);
                pcVar12 = pcVar10 + (uVar11 & 0xfffffffe);
                do {
                  if ((*pcVar10 == cVar16) && (pcVar10[1] == cVar6)) goto LAB_0048a8b8;
                  pcVar10 = pcVar10 + 2;
                } while (pcVar10 != pcVar12);
              }
            }
LAB_0048aa40:
            if ((uVar8 & 0x80) == 0) goto LAB_0048a66c;
            iVar7 = *(int *)(param_1[0x26] + 0x28);
            bVar1 = false;
            if (iVar7 == 0) goto LAB_0048a66c;
            iVar4 = param_1[0x30];
LAB_0048a8d4:
            if ((*(int *)(iVar4 + 0xdc) != 0) && (*(int *)(iVar4 + 0xe0) != 0)) {
              if (*(int *)(iVar7 + 4) != 0) {
                iVar7 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)();
                if ((iVar7 == 0) && (**(int **)(*(int *)(param_1[0x26] + 0x28) + 4) != 0)) {
                  iVar7 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)();
                  if (iVar7 == 0x196) {
                    cVar6 = '\x01';
                    cVar16 = -1;
                  }
                  else {
                    iVar7 = (*(code *)PTR_EC_METHOD_get_field_type_006a82b8)
                                      (**(undefined4 **)(*(int *)(param_1[0x26] + 0x28) + 4));
                    if (iVar7 == 0x197) {
                      cVar6 = '\x02';
                      cVar16 = -1;
                    }
                    else if (cVar16 == '\0') goto LAB_0048aab8;
                  }
                }
                else {
                  cVar6 = tls1_ec_nid2curve_id(iVar7);
LAB_0048aab8:
                  cVar16 = '\0';
                  if (cVar6 == '\0') goto LAB_0048a66c;
                }
                uVar8 = *(uint *)(param_1[0x30] + 0xdc);
                if (uVar8 >> 1 != 0) {
                  pcVar10 = *(char **)(param_1[0x30] + 0xe0);
                  pcVar12 = pcVar10 + (uVar8 & 0xfffffffe);
                  do {
                    if ((*pcVar10 == cVar16) && (pcVar10[1] == cVar6)) {
                      if ((bVar1) &&
                         (iVar3 = (*(code *)PTR_sk_find_006a906c)(local_38,iVar3), -1 < iVar3))
                      goto LAB_0048a9a4;
                      break;
                    }
                    pcVar10 = pcVar10 + 2;
                  } while (pcVar10 != pcVar12);
                }
              }
              goto LAB_0048a66c;
            }
          }
          if ((bVar1) && (iVar3 = (*(code *)PTR_sk_find_006a906c)(local_38,iVar3), -1 < iVar3)) {
            if ((uVar8 & 0x80) == 0) {
LAB_0048aa60:
                    /* WARNING: Could not recover jumptable at 0x0048aa90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              iVar15 = (*(code *)PTR_sk_value_006a7f24)(local_38,iVar3);
              return iVar15;
            }
LAB_0048a9a4:
            if (((uVar17 & 0x40) == 0) || (*(char *)(param_1[0x16] + 0x420) == '\0'))
            goto LAB_0048aa60;
            if (local_30 == 0) {
              local_30 = (*(code *)PTR_sk_value_006a7f24)(local_38,iVar3);
            }
          }
        }
      }
LAB_0048a66c:
      iVar13 = iVar13 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(uVar14);
    } while (iVar13 < iVar3);
  }
  return local_30;
}

