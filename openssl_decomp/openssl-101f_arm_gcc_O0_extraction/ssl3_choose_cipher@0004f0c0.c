
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ssl3_choose_cipher(int *param_1,_STACK *param_2,_STACK *param_3)

{
  _STACK *p_Var1;
  byte bVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  EC_GROUP *pEVar6;
  char *pcVar7;
  EC_GROUP *pEVar8;
  uint uVar9;
  EC_GROUP *pEVar10;
  int iVar11;
  byte *pbVar12;
  EC_GROUP *group;
  EC_METHOD *pEVar13;
  EC_METHOD **ppEVar14;
  char *pcVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  EC_GROUP *pEVar20;
  EC_GROUP *pEVar21;
  uint uVar22;
  EC_GROUP *local_34;
  _STACK *local_30;
  void *local_2c;
  
  iVar18 = param_1[0x26];
  p_Var1 = param_3;
  local_30 = param_2;
  if (-1 < param_1[0x40] << 9) {
    p_Var1 = param_2;
    local_30 = param_3;
  }
  pEVar20 = (EC_GROUP *)0x0;
  local_34 = (EC_GROUP *)0x0;
  iVar16 = 0;
  local_2c = (void *)0x0;
  do {
    iVar3 = sk_num(p_Var1);
    if (iVar3 <= iVar16) {
      return local_2c;
    }
    pvVar4 = sk_value(p_Var1,iVar16);
    pEVar10 = local_34;
    if ((-1 < *(int *)((int)pvVar4 + 0x1c) << 0x1d) || ((*param_1 >> 8 == 3 && (0x302 < *param_1))))
    {
      ssl_set_cert_masks(iVar18,pvVar4);
      uVar17 = *(uint *)((int)pvVar4 + 0xc);
      uVar19 = *(uint *)((int)pvVar4 + 0x10);
      if ((-1 < (int)(uVar17 << 0x17)) || (param_1[0x38] != 0)) {
        if (*(int *)((int)pvVar4 + 0x20) << 0x1e < 0) {
          pEVar10 = (EC_GROUP *)((param_1[0x74] | *(uint *)(iVar18 + 0x10)) & uVar17);
          if (pEVar10 != (EC_GROUP *)0x0) {
            if ((uVar19 & *(uint *)(iVar18 + 0x14)) == 0) {
              pEVar10 = (EC_GROUP *)0x0;
            }
            else {
              pEVar10 = (EC_GROUP *)0x1;
            }
          }
        }
        else {
          pEVar10 = (EC_GROUP *)((param_1[0x74] | *(uint *)(iVar18 + 8)) & uVar17);
          if (pEVar10 != (EC_GROUP *)0x0) {
            pEVar10 = (EC_GROUP *)(uint)((uVar19 & *(uint *)(iVar18 + 0xc)) != 0);
          }
        }
        group = pEVar10;
        pEVar6 = local_34;
        if ((uVar19 & 0x50) != 0) {
          iVar3 = param_1[0x26];
          if (*(int **)(iVar3 + 0x6c) != (int *)0x0) {
            iVar5 = param_1[0x30];
            if ((((*(int *)(iVar5 + 0xd4) != 0) && (*(int *)(iVar5 + 0xd8) != 0)) &&
                (iVar11 = **(int **)(iVar3 + 0x6c), iVar11 != 0)) &&
               (((iVar11 = *(int *)(iVar11 + 0x18), iVar11 != 0 &&
                 (iVar11 = *(int *)(iVar11 + 4), iVar11 != 0)) &&
                ((pbVar12 = *(byte **)(iVar11 + 8), pbVar12 != (byte *)0x0 && (*pbVar12 - 2 < 2)))))
               ) {
              iVar3 = *(int *)(*(int *)(iVar3 + 0x70) + 0x14);
              if (iVar3 == 0) {
                pEVar13 = *_DAT_00000004;
LAB_0004f3e0:
                iVar3 = EC_METHOD_get_field_type(pEVar13);
                if (iVar3 != 0x197) goto LAB_0004f3f0;
                iVar3 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar3 == 0) goto LAB_0004f3f0;
                pcVar15 = *(char **)(param_1[0x30] + 0xd8);
                if (*pcVar15 != '\x02') {
                  pcVar7 = pcVar15 + iVar3 + -1;
                  do {
                    if (pcVar15 == pcVar7) goto LAB_0004f3f0;
                    pcVar15 = pcVar15 + 1;
                  } while (*pcVar15 != '\x02');
                }
              }
              else {
                ppEVar14 = *(EC_METHOD ***)(iVar3 + 4);
                pEVar13 = *ppEVar14;
                if ((ppEVar14 == (EC_METHOD **)0x0) || (pEVar13 == (EC_METHOD *)0x0))
                goto LAB_0004f3e0;
                iVar3 = EC_METHOD_get_field_type(pEVar13);
                if (iVar3 != 0x196) {
                  pEVar13 = **(EC_METHOD ***)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4);
                  goto LAB_0004f3e0;
                }
                iVar3 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar3 != 0) {
                  pcVar15 = *(char **)(param_1[0x30] + 0xd8);
                  if (*pcVar15 != '\x01') {
                    pcVar7 = pcVar15 + iVar3 + -1;
                    do {
                      if (pcVar15 == pcVar7) goto LAB_0004f3f0;
                      pcVar15 = pcVar15 + 1;
                    } while (*pcVar15 != '\x01');
                  }
                  goto LAB_0004f3f2;
                }
LAB_0004f3f0:
                pEVar10 = (EC_GROUP *)0x0;
              }
LAB_0004f3f2:
              iVar3 = param_1[0x26];
              group = pEVar10;
              if (*(int *)(iVar3 + 0x6c) == 0) goto LAB_0004f246;
              iVar5 = param_1[0x30];
            }
            group = pEVar10;
            if ((((*(int *)(iVar5 + 0xdc) != 0) && (*(int *)(iVar5 + 0xe0) != 0)) &&
                (group = *(EC_GROUP **)(*(int *)(iVar3 + 0x70) + 0x14), group != (EC_GROUP *)0x0))
               && (group = *(EC_GROUP **)(group + 4), group != (EC_GROUP *)0x0)) {
              iVar3 = EC_GROUP_get_curve_name(group);
              if ((iVar3 == 0) &&
                 (pEVar13 = **(EC_METHOD ***)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4),
                 pEVar13 != (EC_METHOD *)0x0)) {
                iVar3 = EC_METHOD_get_field_type(pEVar13);
                if (iVar3 == 0x196) {
                  local_34 = (EC_GROUP *)0x1;
                }
                else {
                  iVar3 = EC_METHOD_get_field_type
                                    (**(EC_METHOD ***)
                                       (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4));
                  pEVar21 = pEVar20;
                  if (iVar3 != 0x197) goto LAB_0004f394;
                  local_34 = (EC_GROUP *)0x2;
                }
                pEVar21 = (EC_GROUP *)0xff;
              }
              else {
                bVar2 = tls1_ec_nid2curve_id();
                pEVar21 = (EC_GROUP *)0x0;
                local_34 = (EC_GROUP *)(uint)bVar2;
LAB_0004f394:
                pEVar20 = (EC_GROUP *)((uint)local_34 | (uint)pEVar21);
                group = pEVar20;
                pEVar6 = pEVar20;
                if (pEVar20 == (EC_GROUP *)0x0) goto LAB_0004f246;
              }
              pEVar20 = pEVar21;
              pEVar21 = (EC_GROUP *)(*(uint *)(param_1[0x30] + 0xdc) >> 1);
              group = pEVar21;
              pEVar6 = local_34;
              if (pEVar21 != (EC_GROUP *)0x0) {
                pbVar12 = *(byte **)(param_1[0x30] + 0xe0);
                pEVar8 = (EC_GROUP *)0x0;
                do {
                  pEVar8 = pEVar8 + 1;
                  if (((EC_GROUP *)(uint)*pbVar12 == pEVar20) &&
                     (group = pEVar10, (EC_GROUP *)(uint)pbVar12[1] == local_34)) goto LAB_0004f246;
                  pbVar12 = pbVar12 + 2;
                } while (pEVar8 != pEVar21);
                group = (EC_GROUP *)0x0;
              }
            }
          }
        }
LAB_0004f246:
        local_34 = pEVar6;
        if (((((uVar17 & 0x80) == 0) || (*(int *)(param_1[0x26] + 0x28) == 0)) ||
            (*(int *)(param_1[0x30] + 0xdc) == 0)) || (*(int *)(param_1[0x30] + 0xe0) == 0)) {
LAB_0004f2f4:
          pEVar10 = local_34;
          if ((group != (EC_GROUP *)0x0) && (iVar3 = sk_find(local_30,pvVar4), -1 < iVar3)) {
            if ((((uVar17 & 0x80) == 0) || ((uVar19 & 0x40) == 0)) ||
               (*(char *)(param_1[0x16] + 0x420) == '\0')) {
              pvVar4 = sk_value(local_30,iVar3);
              return pvVar4;
            }
            if (local_2c == (void *)0x0) {
              local_2c = sk_value(local_30,iVar3);
            }
          }
        }
        else {
          pEVar6 = *(EC_GROUP **)(*(int *)(param_1[0x26] + 0x28) + 4);
          pEVar10 = local_34;
          if (pEVar6 != (EC_GROUP *)0x0) {
            iVar3 = EC_GROUP_get_curve_name(pEVar6);
            if ((iVar3 == 0) &&
               (pEVar13 = **(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4),
               pEVar13 != (EC_METHOD *)0x0)) {
              iVar3 = EC_METHOD_get_field_type(pEVar13);
              if (iVar3 == 0x196) {
                local_34 = (EC_GROUP *)0x1;
              }
              else {
                iVar3 = EC_METHOD_get_field_type
                                  (**(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4));
                pEVar6 = pEVar20;
                if (iVar3 != 0x197) goto LAB_0004f372;
                local_34 = (EC_GROUP *)0x2;
              }
              pEVar6 = (EC_GROUP *)0xff;
            }
            else {
              bVar2 = tls1_ec_nid2curve_id();
              pEVar6 = (EC_GROUP *)0x0;
              local_34 = (EC_GROUP *)(uint)bVar2;
LAB_0004f372:
              pEVar20 = (EC_GROUP *)((uint)local_34 | (uint)pEVar6);
              pEVar10 = pEVar20;
              if (pEVar20 == (EC_GROUP *)0x0) goto LAB_0004f0f8;
            }
            pEVar20 = pEVar6;
            uVar22 = *(uint *)(param_1[0x30] + 0xdc) >> 1;
            pEVar10 = local_34;
            if (uVar22 != 0) {
              pbVar12 = *(byte **)(param_1[0x30] + 0xe0);
              uVar9 = 0;
              do {
                uVar9 = uVar9 + 1;
                if (((EC_GROUP *)(uint)*pbVar12 == pEVar20) &&
                   ((EC_GROUP *)(uint)pbVar12[1] == local_34)) goto LAB_0004f2f4;
                pbVar12 = pbVar12 + 2;
              } while (uVar9 != uVar22);
            }
          }
        }
      }
    }
LAB_0004f0f8:
    local_34 = pEVar10;
    iVar16 = iVar16 + 1;
  } while( true );
}

