
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
  EC_METHOD **ppEVar8;
  int iVar9;
  void *pvVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  EC_METHOD *pEVar14;
  char *pcVar15;
  char *pcVar16;
  int iVar17;
  bool bVar18;
  uint local_34;
  uint local_30;
  uint local_2c;
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
  iVar9 = sk_num(param_3);
  if (0 < iVar9) {
    do {
      pvVar10 = sk_value(param_3,iVar17);
      if (((*(byte *)((int)pvVar10 + 0x1c) & 4) == 0) ||
         ((*param_1 >> 8 == 3 && (0x302 < *param_1)))) {
        ssl_set_cert_masks(iVar3,pvVar10);
        local_30 = *(uint *)(iVar3 + 0xc);
        uVar11 = *(uint *)(iVar3 + 8);
        local_34 = *(uint *)(iVar3 + 0x10);
        local_2c = *(uint *)(iVar3 + 0x14);
        if ((*(byte *)((int)param_1 + 0x1d1) & 4) != 0) {
          local_30 = local_30 | 0x400;
          local_34 = local_34 | 0x400;
          local_2c = local_2c | 0x400;
          uVar11 = uVar11 | 0x400;
        }
        uVar4 = *(uint *)((int)pvVar10 + 0xc);
        uVar5 = *(uint *)((int)pvVar10 + 0x10);
        if (((uVar4 & 0x100) == 0) || (param_1[0x38] != 0)) {
          bVar18 = false;
          if ((*(byte *)((int)pvVar10 + 0x20) & 2) == 0) {
            if ((uVar4 & uVar11) != 0) {
              bVar18 = (uVar5 & local_30) != 0;
            }
          }
          else if ((uVar4 & local_34) != 0) {
            bVar18 = (local_2c & uVar5) != 0;
          }
          if ((uVar5 & 0x50) != 0) {
            iVar9 = param_1[0x26];
            if (*(int **)(iVar9 + 0x6c) != (int *)0x0) {
              iVar12 = param_1[0x30];
              if ((((*(int *)(iVar12 + 0xd4) != 0) && (*(int *)(iVar12 + 0xd8) != 0)) &&
                  (iVar6 = **(int **)(iVar9 + 0x6c), iVar6 != 0)) &&
                 (((iVar6 = *(int *)(iVar6 + 0x18), iVar6 != 0 &&
                   (iVar6 = *(int *)(iVar6 + 4), iVar6 != 0)) &&
                  ((pcVar15 = *(char **)(iVar6 + 8), pcVar15 != (char *)0x0 &&
                   ((byte)(*pcVar15 - 2U) < 2)))))) {
                iVar9 = *(int *)(*(int *)(iVar9 + 0x70) + 0x14);
                if (iVar9 == 0) {
                  pEVar14 = *_DAT_00000004;
LAB_080a1092:
                  iVar9 = EC_METHOD_get_field_type(pEVar14);
                  if (iVar9 != 0x197) goto LAB_080a10a5;
                  iVar9 = *(int *)(param_1[0x30] + 0xd4);
                  if (iVar9 == 0) goto LAB_080a10a5;
                  pcVar15 = *(char **)(param_1[0x30] + 0xd8);
                  pcVar16 = pcVar15 + iVar9;
                  cVar2 = *pcVar15;
                  while (cVar2 != '\x02') {
                    pcVar15 = pcVar15 + 1;
                    if (pcVar16 == pcVar15) goto LAB_080a10a5;
                    cVar2 = *pcVar15;
                  }
                }
                else {
                  ppEVar8 = *(EC_METHOD ***)(iVar9 + 4);
                  pEVar14 = _DAT_00000000;
                  if ((ppEVar8 == (EC_METHOD **)0x0) ||
                     (pEVar14 = *ppEVar8, pEVar14 == (EC_METHOD *)0x0)) goto LAB_080a1092;
                  iVar9 = EC_METHOD_get_field_type(pEVar14);
                  if (iVar9 != 0x196) {
                    pEVar14 = **(EC_METHOD ***)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4)
                    ;
                    goto LAB_080a1092;
                  }
                  iVar9 = *(int *)(param_1[0x30] + 0xd4);
                  if (iVar9 != 0) {
                    pcVar15 = *(char **)(param_1[0x30] + 0xd8);
                    pcVar16 = pcVar15 + iVar9;
                    cVar2 = *pcVar15;
                    while (cVar2 != '\x01') {
                      pcVar15 = pcVar15 + 1;
                      if (pcVar16 == pcVar15) goto LAB_080a10a5;
                      cVar2 = *pcVar15;
                    }
                    goto LAB_080a10ad;
                  }
LAB_080a10a5:
                  bVar18 = false;
                }
LAB_080a10ad:
                iVar9 = param_1[0x26];
                if (*(int *)(iVar9 + 0x6c) == 0) goto LAB_080a0dd8;
                iVar12 = param_1[0x30];
              }
              if ((*(int *)(iVar12 + 0xdc) != 0) && (*(int *)(iVar12 + 0xe0) != 0)) {
                iVar9 = *(int *)(*(int *)(iVar9 + 0x70) + 0x14);
                if ((iVar9 != 0) && (pEVar7 = *(EC_GROUP **)(iVar9 + 4), pEVar7 != (EC_GROUP *)0x0))
                {
                  iVar9 = EC_GROUP_get_curve_name(pEVar7);
                  if ((iVar9 == 0) &&
                     (pEVar14 = **(EC_METHOD ***)
                                  (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4),
                     pEVar14 != (EC_METHOD *)0x0)) {
                    iVar9 = EC_METHOD_get_field_type(pEVar14);
                    if (iVar9 == 0x196) {
                      local_26 = 1;
                    }
                    else {
                      iVar9 = EC_METHOD_get_field_type
                                        (**(EC_METHOD ***)
                                           (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4));
                      if (iVar9 != 0x197) goto LAB_080a0ff5;
                      local_26 = 2;
                    }
                    local_25 = 0xff;
                  }
                  else {
                    local_26 = tls1_ec_nid2curve_id(iVar9);
                    local_25 = 0;
LAB_080a0ff5:
                    if ((local_25 | local_26) == 0) {
                      bVar18 = false;
                      local_26 = 0;
                      local_25 = 0;
                      goto LAB_080a0dd8;
                    }
                  }
                  uVar11 = *(uint *)(param_1[0x30] + 0xdc);
                  if (uVar11 >> 1 != 0) {
                    pbVar13 = *(byte **)(param_1[0x30] + 0xe0);
                    pbVar1 = pbVar13 + (uVar11 & 0xfffffffe);
                    do {
                      if ((*pbVar13 == local_25) && (pbVar13[1] == local_26)) goto LAB_080a0dd8;
                      pbVar13 = pbVar13 + 2;
                    } while (pbVar13 != pbVar1);
                    bVar18 = false;
                    goto LAB_080a0dd8;
                  }
                }
                bVar18 = false;
              }
            }
          }
LAB_080a0dd8:
          if (((((uVar4 & 0x80) == 0) || (*(int *)(param_1[0x26] + 0x28) == 0)) ||
              (*(int *)(param_1[0x30] + 0xdc) == 0)) || (*(int *)(param_1[0x30] + 0xe0) == 0)) {
LAB_080a0f38:
            if ((bVar18) && (iVar9 = sk_find(local_24,pvVar10), -1 < iVar9)) {
              if ((((uVar4 & 0x80) == 0) || ((uVar5 & 0x40) == 0)) ||
                 (*(char *)(param_1[0x16] + 0x420) == '\0')) {
                pvVar10 = sk_value(local_24,iVar9);
                return pvVar10;
              }
              if (local_20 == (void *)0x0) {
                local_20 = sk_value(local_24,iVar9);
              }
            }
          }
          else {
            pEVar7 = *(EC_GROUP **)(*(int *)(param_1[0x26] + 0x28) + 4);
            if (pEVar7 != (EC_GROUP *)0x0) {
              iVar9 = EC_GROUP_get_curve_name(pEVar7);
              if ((iVar9 == 0) &&
                 (pEVar14 = **(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4),
                 pEVar14 != (EC_METHOD *)0x0)) {
                iVar9 = EC_METHOD_get_field_type(pEVar14);
                if (iVar9 == 0x196) {
                  local_26 = 1;
                }
                else {
                  iVar9 = EC_METHOD_get_field_type
                                    (**(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4));
                  if (iVar9 != 0x197) goto LAB_080a0ea5;
                  local_26 = 2;
                }
                local_25 = 0xff;
              }
              else {
                local_26 = tls1_ec_nid2curve_id(iVar9);
                local_25 = 0;
LAB_080a0ea5:
                if ((local_25 | local_26) == 0) {
                  local_26 = 0;
                  local_25 = 0;
                  goto LAB_080a0ec0;
                }
              }
              uVar11 = *(uint *)(param_1[0x30] + 0xdc);
              if (uVar11 >> 1 != 0) {
                pbVar13 = *(byte **)(param_1[0x30] + 0xe0);
                pbVar1 = pbVar13 + (uVar11 & 0xfffffffe);
                do {
                  if ((*pbVar13 == local_25) && (pbVar13[1] == local_26)) goto LAB_080a0f38;
                  pbVar13 = pbVar13 + 2;
                } while (pbVar13 != pbVar1);
              }
            }
          }
        }
      }
LAB_080a0ec0:
      iVar17 = iVar17 + 1;
      iVar9 = sk_num(param_3);
    } while (iVar17 < iVar9);
  }
  return local_20;
}

