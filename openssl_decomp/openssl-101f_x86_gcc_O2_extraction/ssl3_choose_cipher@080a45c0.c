
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ssl3_choose_cipher(int *param_1,_STACK *param_2,_STACK *param_3)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  EC_GROUP *pEVar7;
  uint uVar8;
  EC_METHOD **ppEVar9;
  int iVar10;
  void *pvVar11;
  int iVar12;
  byte *pbVar13;
  EC_METHOD *pEVar14;
  char *pcVar15;
  char *pcVar16;
  int iVar17;
  bool bVar18;
  byte local_26;
  byte local_25;
  _STACK *local_24;
  void *local_20;
  
  local_24 = param_2;
  iVar3 = param_1[0x26];
  if ((*(byte *)((int)param_1 + 0x102) & 0x40) == 0) {
    local_24 = param_3;
    param_3 = param_2;
  }
  local_26 = 0;
  local_25 = 0;
  local_20 = (void *)0x0;
  iVar17 = 0;
  iVar10 = sk_num(param_3);
  if (0 < iVar10) {
    do {
      pvVar11 = sk_value(param_3,iVar17);
      if (((*(byte *)((int)pvVar11 + 0x1c) & 4) == 0) ||
         ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
        ssl_set_cert_masks(iVar3,pvVar11);
        uVar4 = *(uint *)((int)pvVar11 + 0xc);
        uVar5 = *(uint *)((int)pvVar11 + 0x10);
        if (((uVar4 & 0x100) == 0) || (param_1[0x38] != 0)) {
          if ((*(byte *)((int)pvVar11 + 0x20) & 2) == 0) {
            bVar18 = false;
            if ((uVar4 & (param_1[0x74] | *(uint *)(iVar3 + 8))) != 0) {
              bVar18 = (*(uint *)(iVar3 + 0xc) & uVar5) != 0;
            }
          }
          else {
            bVar18 = false;
            if ((uVar4 & (param_1[0x74] | *(uint *)(iVar3 + 0x10))) != 0) {
              bVar18 = (*(uint *)(iVar3 + 0x14) & uVar5) != 0;
            }
          }
          if ((uVar5 & 0x50) != 0) {
            iVar10 = param_1[0x26];
            if (*(int **)(iVar10 + 0x6c) != (int *)0x0) {
              iVar12 = param_1[0x30];
              if ((((*(int *)(iVar12 + 0xd4) != 0) && (*(int *)(iVar12 + 0xd8) != 0)) &&
                  (iVar6 = **(int **)(iVar10 + 0x6c), iVar6 != 0)) &&
                 (((iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0 &&
                   (iVar6 = *(int *)(iVar6 + 4), iVar6 != 0)) &&
                  ((pcVar15 = *(char **)(iVar6 + 8), pcVar15 != (char *)0x0 &&
                   ((byte)(*pcVar15 - 2U) < 2)))))) {
                iVar10 = *(int *)(*(int *)(iVar10 + 0x70) + 0x14);
                if (iVar10 == 0) {
                  pEVar14 = *_DAT_00000004;
LAB_080a4af2:
                  iVar10 = EC_METHOD_get_field_type(pEVar14);
                  if (iVar10 != 0x197) goto LAB_080a4b05;
                  iVar10 = *(int *)(param_1[0x30] + 0xd4);
                  if (iVar10 == 0) goto LAB_080a4b05;
                  pcVar15 = *(char **)(param_1[0x30] + 0xd8);
                  pcVar16 = pcVar15 + iVar10;
                  cVar2 = *pcVar15;
                  while (cVar2 != '\x02') {
                    pcVar15 = pcVar15 + 1;
                    if (pcVar16 == pcVar15) goto LAB_080a4b05;
                    cVar2 = *pcVar15;
                  }
                }
                else {
                  ppEVar9 = *(EC_METHOD ***)(iVar10 + 4);
                  pEVar14 = _DAT_00000000;
                  if ((ppEVar9 == (EC_METHOD **)0x0) ||
                     (pEVar14 = *ppEVar9, pEVar14 == (EC_METHOD *)0x0)) goto LAB_080a4af2;
                  iVar10 = EC_METHOD_get_field_type(pEVar14);
                  if (iVar10 != 0x196) {
                    pEVar14 = **(EC_METHOD ***)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4)
                    ;
                    goto LAB_080a4af2;
                  }
                  iVar10 = *(int *)(param_1[0x30] + 0xd4);
                  if (iVar10 != 0) {
                    pcVar15 = *(char **)(param_1[0x30] + 0xd8);
                    pcVar16 = pcVar15 + iVar10;
                    cVar2 = *pcVar15;
                    while (cVar2 != '\x01') {
                      pcVar15 = pcVar15 + 1;
                      if (pcVar16 == pcVar15) goto LAB_080a4b05;
                      cVar2 = *pcVar15;
                    }
                    goto LAB_080a4b0d;
                  }
LAB_080a4b05:
                  bVar18 = false;
                }
LAB_080a4b0d:
                iVar10 = param_1[0x26];
                if (*(int *)(iVar10 + 0x6c) == 0) goto LAB_080a4830;
                iVar12 = param_1[0x30];
              }
              if ((*(int *)(iVar12 + 0xdc) != 0) && (*(int *)(iVar12 + 0xe0) != 0)) {
                iVar10 = *(int *)(*(int *)(iVar10 + 0x70) + 0x14);
                if ((iVar10 != 0) &&
                   (pEVar7 = *(EC_GROUP **)(iVar10 + 4), pEVar7 != (EC_GROUP *)0x0)) {
                  iVar10 = EC_GROUP_get_curve_name(pEVar7);
                  if ((iVar10 == 0) &&
                     (pEVar14 = **(EC_METHOD ***)
                                  (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4),
                     pEVar14 != (EC_METHOD *)0x0)) {
                    iVar10 = EC_METHOD_get_field_type(pEVar14);
                    if (iVar10 == 0x196) {
                      local_26 = 1;
                    }
                    else {
                      iVar10 = EC_METHOD_get_field_type
                                         (**(EC_METHOD ***)
                                            (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4));
                      if (iVar10 != 0x197) goto LAB_080a4a55;
                      local_26 = 2;
                    }
                    local_25 = 0xff;
                  }
                  else {
                    local_26 = tls1_ec_nid2curve_id(iVar10);
                    local_25 = 0;
LAB_080a4a55:
                    if ((local_25 | local_26) == 0) {
                      bVar18 = false;
                      local_26 = 0;
                      local_25 = 0;
                      goto LAB_080a4830;
                    }
                  }
                  uVar8 = *(uint *)(param_1[0x30] + 0xdc);
                  if (uVar8 >> 1 != 0) {
                    pbVar13 = *(byte **)(param_1[0x30] + 0xe0);
                    pbVar1 = pbVar13 + (uVar8 & 0xfffffffe);
                    do {
                      if ((*pbVar13 == local_25) && (pbVar13[1] == local_26)) goto LAB_080a4830;
                      pbVar13 = pbVar13 + 2;
                    } while (pbVar13 != pbVar1);
                    bVar18 = false;
                    goto LAB_080a4830;
                  }
                }
                bVar18 = false;
              }
            }
          }
LAB_080a4830:
          if (((((uVar4 & 0x80) == 0) || (*(int *)(param_1[0x26] + 0x28) == 0)) ||
              (*(int *)(param_1[0x30] + 0xdc) == 0)) || (*(int *)(param_1[0x30] + 0xe0) == 0)) {
LAB_080a4990:
            if ((bVar18) && (iVar10 = sk_find(local_24,pvVar11), -1 < iVar10)) {
              if ((((uVar4 & 0x80) == 0) || ((uVar5 & 0x40) == 0)) ||
                 (*(char *)(param_1[0x16] + 0x420) == '\0')) {
                pvVar11 = sk_value(local_24,iVar10);
                return pvVar11;
              }
              if (local_20 == (void *)0x0) {
                local_20 = sk_value(local_24,iVar10);
              }
            }
          }
          else {
            pEVar7 = *(EC_GROUP **)(*(int *)(param_1[0x26] + 0x28) + 4);
            if (pEVar7 != (EC_GROUP *)0x0) {
              iVar10 = EC_GROUP_get_curve_name(pEVar7);
              if ((iVar10 == 0) &&
                 (pEVar14 = **(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4),
                 pEVar14 != (EC_METHOD *)0x0)) {
                iVar10 = EC_METHOD_get_field_type(pEVar14);
                if (iVar10 == 0x196) {
                  local_26 = 1;
                }
                else {
                  iVar10 = EC_METHOD_get_field_type
                                     (**(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4));
                  if (iVar10 != 0x197) goto LAB_080a48fd;
                  local_26 = 2;
                }
                local_25 = 0xff;
              }
              else {
                local_26 = tls1_ec_nid2curve_id(iVar10);
                local_25 = 0;
LAB_080a48fd:
                if ((local_25 | local_26) == 0) {
                  local_26 = 0;
                  local_25 = 0;
                  goto LAB_080a4918;
                }
              }
              uVar8 = *(uint *)(param_1[0x30] + 0xdc);
              if (uVar8 >> 1 != 0) {
                pbVar13 = *(byte **)(param_1[0x30] + 0xe0);
                pbVar1 = pbVar13 + (uVar8 & 0xfffffffe);
                do {
                  if ((*pbVar13 == local_25) && (pbVar13[1] == local_26)) goto LAB_080a4990;
                  pbVar13 = pbVar13 + 2;
                } while (pbVar13 != pbVar1);
              }
            }
          }
        }
      }
LAB_080a4918:
      iVar17 = iVar17 + 1;
      iVar10 = sk_num(param_3);
    } while (iVar17 < iVar10);
  }
  return local_20;
}

