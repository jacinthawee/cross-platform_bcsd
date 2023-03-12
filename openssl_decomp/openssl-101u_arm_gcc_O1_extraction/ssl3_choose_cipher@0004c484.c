
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * ssl3_choose_cipher(int *param_1,_STACK *param_2,_STACK *param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  EC_GROUP *pEVar5;
  char *pcVar6;
  uint uVar7;
  EC_GROUP *pEVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  EC_GROUP *group;
  EC_METHOD *pEVar12;
  EC_METHOD **ppEVar13;
  char *pcVar14;
  _STACK *p_Var15;
  uint uVar16;
  EC_GROUP *pEVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  EC_GROUP *pEVar22;
  uint uVar23;
  EC_GROUP *pEVar24;
  bool bVar25;
  EC_GROUP *local_34;
  _STACK *local_30;
  void *local_2c;
  
  bVar25 = -1 < (int)(_STACK *)param_1[0x40] << 9;
  p_Var15 = (_STACK *)param_1[0x40];
  if (bVar25) {
    p_Var15 = param_3;
  }
  iVar20 = param_1[0x26];
  local_30 = param_2;
  if (bVar25) {
    param_3 = param_2;
    local_30 = p_Var15;
  }
  pEVar22 = (EC_GROUP *)0x0;
  local_34 = (EC_GROUP *)0x0;
  iVar18 = 0;
  local_2c = (void *)0x0;
  do {
    iVar2 = sk_num(param_3);
    if (iVar2 <= iVar18) {
      return local_2c;
    }
    pvVar3 = sk_value(param_3,iVar18);
    pEVar17 = local_34;
    if ((-1 < *(int *)((int)pvVar3 + 0x1c) << 0x1d) || ((*param_1 >> 8 == 3 && (0x302 < *param_1))))
    {
      ssl_set_cert_masks(iVar20,pvVar3);
      uVar16 = *(uint *)(iVar20 + 8);
      bVar25 = param_1[0x74] << 0x15 < 0;
      uVar23 = *(uint *)(iVar20 + 0xc);
      uVar7 = *(uint *)(iVar20 + 0x10);
      if (bVar25) {
        uVar16 = uVar16 | 0x400;
      }
      uVar9 = *(uint *)(iVar20 + 0x14);
      if (bVar25) {
        uVar23 = uVar23 | 0x400;
      }
      uVar19 = *(uint *)((int)pvVar3 + 0xc);
      if (bVar25) {
        uVar7 = uVar7 | 0x400;
        uVar9 = uVar9 | 0x400;
      }
      uVar21 = *(uint *)((int)pvVar3 + 0x10);
      if ((-1 < (int)(uVar19 << 0x17)) || (param_1[0x38] != 0)) {
        if (*(int *)((int)pvVar3 + 0x20) << 0x1e < 0) {
          pEVar17 = (EC_GROUP *)(uVar7 & uVar19);
          if (pEVar17 != (EC_GROUP *)0x0) {
            if ((uVar9 & uVar21) == 0) {
              pEVar17 = (EC_GROUP *)0x0;
            }
            else {
              pEVar17 = (EC_GROUP *)0x1;
            }
          }
        }
        else {
          pEVar17 = (EC_GROUP *)(uVar16 & uVar19);
          if (pEVar17 != (EC_GROUP *)0x0) {
            pEVar17 = (EC_GROUP *)(uint)((uVar23 & uVar21) != 0);
          }
        }
        group = pEVar17;
        pEVar5 = local_34;
        if ((uVar21 & 0x50) != 0) {
          iVar2 = param_1[0x26];
          if (*(int **)(iVar2 + 0x6c) != (int *)0x0) {
            iVar4 = param_1[0x30];
            if ((((*(int *)(iVar4 + 0xd4) != 0) && (*(int *)(iVar4 + 0xd8) != 0)) &&
                (iVar10 = **(int **)(iVar2 + 0x6c), iVar10 != 0)) &&
               (((iVar10 = *(int *)(iVar10 + 0x18), iVar10 != 0 &&
                 (iVar10 = *(int *)(iVar10 + 4), iVar10 != 0)) &&
                ((pbVar11 = *(byte **)(iVar10 + 8), pbVar11 != (byte *)0x0 && (*pbVar11 - 2 < 2)))))
               ) {
              iVar2 = *(int *)(*(int *)(iVar2 + 0x70) + 0x14);
              if (iVar2 == 0) {
                pEVar12 = *_DAT_00000004;
LAB_0004c7ba:
                iVar2 = EC_METHOD_get_field_type(pEVar12);
                if (iVar2 != 0x197) goto LAB_0004c7ca;
                iVar2 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar2 == 0) goto LAB_0004c7ca;
                pcVar14 = *(char **)(param_1[0x30] + 0xd8);
                if (*pcVar14 != '\x02') {
                  pcVar6 = pcVar14 + iVar2 + -1;
                  do {
                    if (pcVar14 == pcVar6) goto LAB_0004c7ca;
                    pcVar14 = pcVar14 + 1;
                  } while (*pcVar14 != '\x02');
                }
              }
              else {
                ppEVar13 = *(EC_METHOD ***)(iVar2 + 4);
                pEVar12 = *ppEVar13;
                if ((ppEVar13 == (EC_METHOD **)0x0) || (pEVar12 == (EC_METHOD *)0x0))
                goto LAB_0004c7ba;
                iVar2 = EC_METHOD_get_field_type(pEVar12);
                if (iVar2 != 0x196) {
                  pEVar12 = **(EC_METHOD ***)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4);
                  goto LAB_0004c7ba;
                }
                iVar2 = *(int *)(param_1[0x30] + 0xd4);
                if (iVar2 != 0) {
                  pcVar14 = *(char **)(param_1[0x30] + 0xd8);
                  if (*pcVar14 != '\x01') {
                    pcVar6 = pcVar14 + iVar2 + -1;
                    do {
                      if (pcVar14 == pcVar6) goto LAB_0004c7ca;
                      pcVar14 = pcVar14 + 1;
                    } while (*pcVar14 != '\x01');
                  }
                  goto LAB_0004c7cc;
                }
LAB_0004c7ca:
                pEVar17 = (EC_GROUP *)0x0;
              }
LAB_0004c7cc:
              iVar2 = param_1[0x26];
              group = pEVar17;
              if (*(int *)(iVar2 + 0x6c) == 0) goto LAB_0004c622;
              iVar4 = param_1[0x30];
            }
            group = pEVar17;
            if ((((*(int *)(iVar4 + 0xdc) != 0) && (*(int *)(iVar4 + 0xe0) != 0)) &&
                (group = *(EC_GROUP **)(*(int *)(iVar2 + 0x70) + 0x14), group != (EC_GROUP *)0x0))
               && (group = *(EC_GROUP **)(group + 4), group != (EC_GROUP *)0x0)) {
              iVar2 = EC_GROUP_get_curve_name(group);
              if ((iVar2 == 0) &&
                 (pEVar12 = **(EC_METHOD ***)(*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4),
                 pEVar12 != (EC_METHOD *)0x0)) {
                iVar2 = EC_METHOD_get_field_type(pEVar12);
                if (iVar2 == 0x196) {
                  local_34 = (EC_GROUP *)0x1;
                }
                else {
                  iVar2 = EC_METHOD_get_field_type
                                    (**(EC_METHOD ***)
                                       (*(int *)(*(int *)(param_1[0x26] + 0x70) + 0x14) + 4));
                  pEVar24 = pEVar22;
                  if (iVar2 != 0x197) goto LAB_0004c76e;
                  local_34 = (EC_GROUP *)0x2;
                }
                pEVar24 = (EC_GROUP *)0xff;
              }
              else {
                bVar1 = tls1_ec_nid2curve_id();
                pEVar24 = (EC_GROUP *)0x0;
                local_34 = (EC_GROUP *)(uint)bVar1;
LAB_0004c76e:
                pEVar22 = (EC_GROUP *)((uint)local_34 | (uint)pEVar24);
                group = pEVar22;
                pEVar5 = pEVar22;
                if (pEVar22 == (EC_GROUP *)0x0) goto LAB_0004c622;
              }
              pEVar22 = pEVar24;
              pEVar24 = (EC_GROUP *)(*(uint *)(param_1[0x30] + 0xdc) >> 1);
              group = pEVar24;
              pEVar5 = local_34;
              if (pEVar24 != (EC_GROUP *)0x0) {
                pbVar11 = *(byte **)(param_1[0x30] + 0xe0);
                pEVar8 = (EC_GROUP *)0x0;
                do {
                  pEVar8 = pEVar8 + 1;
                  if (((EC_GROUP *)(uint)*pbVar11 == pEVar22) &&
                     (group = pEVar17, (EC_GROUP *)(uint)pbVar11[1] == local_34)) goto LAB_0004c622;
                  pbVar11 = pbVar11 + 2;
                } while (pEVar8 != pEVar24);
                group = (EC_GROUP *)0x0;
              }
            }
          }
        }
LAB_0004c622:
        local_34 = pEVar5;
        if (((((uVar19 & 0x80) == 0) || (*(int *)(param_1[0x26] + 0x28) == 0)) ||
            (*(int *)(param_1[0x30] + 0xdc) == 0)) || (*(int *)(param_1[0x30] + 0xe0) == 0)) {
LAB_0004c6d0:
          pEVar17 = local_34;
          if ((group != (EC_GROUP *)0x0) && (iVar2 = sk_find(local_30,pvVar3), -1 < iVar2)) {
            if ((((uVar19 & 0x80) == 0) || ((uVar21 & 0x40) == 0)) ||
               (*(char *)(param_1[0x16] + 0x420) == '\0')) {
              pvVar3 = sk_value(local_30,iVar2);
              return pvVar3;
            }
            if (local_2c == (void *)0x0) {
              local_2c = sk_value(local_30,iVar2);
            }
          }
        }
        else {
          pEVar5 = *(EC_GROUP **)(*(int *)(param_1[0x26] + 0x28) + 4);
          pEVar17 = local_34;
          if (pEVar5 != (EC_GROUP *)0x0) {
            iVar2 = EC_GROUP_get_curve_name(pEVar5);
            if ((iVar2 == 0) &&
               (pEVar12 = **(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4),
               pEVar12 != (EC_METHOD *)0x0)) {
              iVar2 = EC_METHOD_get_field_type(pEVar12);
              if (iVar2 == 0x196) {
                local_34 = (EC_GROUP *)0x1;
              }
              else {
                iVar2 = EC_METHOD_get_field_type
                                  (**(EC_METHOD ***)(*(int *)(param_1[0x26] + 0x28) + 4));
                pEVar5 = pEVar22;
                if (iVar2 != 0x197) goto LAB_0004c74c;
                local_34 = (EC_GROUP *)0x2;
              }
              pEVar5 = (EC_GROUP *)0xff;
            }
            else {
              bVar1 = tls1_ec_nid2curve_id();
              pEVar5 = (EC_GROUP *)0x0;
              local_34 = (EC_GROUP *)(uint)bVar1;
LAB_0004c74c:
              pEVar22 = (EC_GROUP *)((uint)local_34 | (uint)pEVar5);
              pEVar17 = pEVar22;
              if (pEVar22 == (EC_GROUP *)0x0) goto LAB_0004c4bc;
            }
            pEVar22 = pEVar5;
            uVar7 = *(uint *)(param_1[0x30] + 0xdc) >> 1;
            pEVar17 = local_34;
            if (uVar7 != 0) {
              pbVar11 = *(byte **)(param_1[0x30] + 0xe0);
              uVar16 = 0;
              do {
                uVar16 = uVar16 + 1;
                if (((EC_GROUP *)(uint)*pbVar11 == pEVar22) &&
                   ((EC_GROUP *)(uint)pbVar11[1] == local_34)) goto LAB_0004c6d0;
                pbVar11 = pbVar11 + 2;
              } while (uVar16 != uVar7);
            }
          }
        }
      }
    }
LAB_0004c4bc:
    local_34 = pEVar17;
    iVar18 = iVar18 + 1;
  } while( true );
}

