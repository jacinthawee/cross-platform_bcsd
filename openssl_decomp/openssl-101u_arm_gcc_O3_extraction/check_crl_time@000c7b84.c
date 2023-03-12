
void check_crl_time(int param_1,int *param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  ASN1_TIME *pAVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  time_t *t;
  undefined4 *puVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  long offset_sec;
  uint uVar14;
  byte *local_7c;
  time_t local_74;
  ASN1_TIME local_70;
  byte local_60;
  byte local_5f;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  byte local_54 [12];
  byte local_48;
  byte local_47;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (param_3 != 0) {
    *(int **)(param_1 + 0x70) = param_2;
  }
  t = (time_t *)(*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2);
  if (t != (time_t *)0x0) {
    t = (time_t *)(*(int *)(param_1 + 0x14) + 4);
  }
  piVar10 = *(int **)(*param_2 + 0xc);
  iVar8 = *piVar10;
  iVar9 = piVar10[1];
  puVar11 = (undefined4 *)piVar10[2];
  if (iVar9 == 0x17) {
    if (iVar8 - 0xbU < 7) {
      iVar5 = -10;
      uStack_5c = puVar11[1];
      pbVar13 = (byte *)((int)&uStack_58 + 2);
      puVar12 = (undefined4 *)((int)puVar11 + 10);
      local_5f = (byte)((uint)*puVar11 >> 8);
      local_60 = (byte)*puVar11;
      uStack_58 = uStack_58 & 0xffff0000 | (uint)*(ushort *)(puVar11 + 2);
      goto LAB_000c7c02;
    }
joined_r0x000c7bc8:
    if (param_3 != 0) {
      uVar2 = 0xf;
LAB_000c7de4:
      *(undefined4 *)(param_1 + 100) = uVar2;
      iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar8 != 0) {
LAB_000c7df4:
        if (*(ASN1_TIME **)(*param_2 + 0x10) == (ASN1_TIME *)0x0) {
LAB_000c7e1c:
          if (param_3 == 0) {
            uVar2 = 1;
            goto LAB_000c7bce;
          }
LAB_000c7e1e:
          uVar2 = 1;
          *(undefined4 *)(param_1 + 0x70) = 0;
          goto LAB_000c7bce;
        }
        iVar8 = X509_cmp_time(*(ASN1_TIME **)(*param_2 + 0x10),t);
        if (iVar8 == 0) {
          if (param_3 != 0) {
            *(undefined4 *)(param_1 + 100) = 0x10;
            iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
joined_r0x000c7e50:
            if (iVar8 != 0) goto LAB_000c7e1e;
          }
        }
        else {
          if ((-1 < iVar8) || ((*(uint *)(param_1 + 0x74) & 2) != 0)) goto LAB_000c7e1c;
          if (param_3 != 0) {
            *(undefined4 *)(param_1 + 100) = 0xc;
            iVar8 = (**(code **)(param_1 + 0x20))(0,param_1);
            goto joined_r0x000c7e50;
          }
        }
      }
    }
  }
  else {
    if (10 < iVar8 - 0xdU) goto joined_r0x000c7bc8;
    iVar5 = -0xc;
    uStack_5c = puVar11[1];
    pbVar13 = local_54;
    uStack_58 = puVar11[2];
    puVar12 = puVar11 + 3;
    local_5f = (byte)((uint)*puVar11 >> 8);
    local_60 = (byte)*puVar11;
LAB_000c7c02:
    local_7c = &local_60;
    iVar8 = iVar8 + iVar5;
    bVar7 = *(byte *)puVar12;
    if ((bVar7 != 0x2d && bVar7 != 0x5a) && (iVar5 = 0, bVar7 != 0x2b)) {
      if (iVar8 != 1) {
        bVar1 = *(byte *)((int)puVar12 + 1);
        *pbVar13 = bVar7;
        pbVar13[1] = bVar1;
        if (iVar8 + -2 == 0) {
          pbVar13[3] = 0;
          pbVar13[2] = 0x5a;
        }
        else {
          bVar7 = *(byte *)((int)puVar12 + 2);
          if (bVar7 != 0x2e) {
            puVar11 = (undefined4 *)((int)puVar12 + 2);
            iVar8 = iVar8 + -2;
            goto LAB_000c7cb4;
          }
          iVar8 = iVar8 + -3;
          puVar11 = (undefined4 *)((int)puVar12 + 3);
          if (iVar8 != 0) {
            if (*(byte *)((int)puVar12 + 3) - 0x30 < 10) {
              puVar12 = puVar12 + 1;
              do {
                puVar11 = puVar12;
                iVar8 = iVar8 + -1;
                iVar5 = iVar5 + 1;
                if (2 < iVar5 || iVar8 == 0) break;
                puVar12 = (undefined4 *)((int)puVar11 + 1);
              } while (*(byte *)puVar11 - 0x30 < 10);
              pbVar13[2] = 0x5a;
              pbVar13[3] = 0;
              if (iVar8 == 0) goto joined_r0x000c7bc8;
            }
            else {
              pbVar13[3] = 0;
              pbVar13[2] = 0x5a;
            }
            bVar7 = *(byte *)puVar11;
            goto LAB_000c7cbc;
          }
          pbVar13[3] = 0;
          pbVar13[2] = 0x5a;
        }
      }
      goto joined_r0x000c7bc8;
    }
    *pbVar13 = 0x30;
    pbVar13[1] = 0x30;
    puVar11 = puVar12;
LAB_000c7cb4:
    pbVar13[2] = 0x5a;
    pbVar13[3] = 0;
LAB_000c7cbc:
    if (bVar7 != 0x5a) {
      if (((((bVar7 == 0x2d || bVar7 == 0x2b) && (iVar8 == 5)) &&
           (uVar6 = *(byte *)((int)puVar11 + 1) - 0x30, (uVar6 & 0xff) < 10)) &&
          ((uVar3 = *(byte *)((int)puVar11 + 2) - 0x30, (uVar3 & 0xff) < 10 &&
           (uVar14 = *(byte *)((int)puVar11 + 3) - 0x30, (uVar14 & 0xff) < 10)))) &&
         ((*(byte *)(puVar11 + 1) - 0x30 & 0xff) < 10)) {
        if (bVar7 == 0x2d) {
          iVar8 = -0x3c;
        }
        else {
          iVar8 = 0x3c;
        }
        offset_sec = ((*(byte *)(puVar11 + 1) - 0x30) + uVar14 * 10 + (uVar3 + uVar6 * 10) * 0x3c) *
                     iVar8;
        goto LAB_000c7d44;
      }
      goto joined_r0x000c7bc8;
    }
    if (iVar8 != 1) goto joined_r0x000c7bc8;
    offset_sec = 0;
LAB_000c7d44:
    local_70.flags = 0;
    local_70.length = 0x18;
    local_70.type = iVar9;
    local_70.data = &local_48;
    if (t == (time_t *)0x0) {
      time(&local_74);
      if (-1 < local_70.flags << 0x19) goto LAB_000c7d64;
LAB_000c7d72:
      pAVar4 = ASN1_TIME_adj(&local_70,local_74,0,offset_sec);
    }
    else {
      local_74 = *t;
LAB_000c7d64:
      if (local_70.type == 0x17) {
        pAVar4 = ASN1_UTCTIME_adj(&local_70,local_74,0,offset_sec);
      }
      else {
        if (local_70.type != 0x18) goto LAB_000c7d72;
        pAVar4 = ASN1_GENERALIZEDTIME_adj(&local_70,local_74,0,offset_sec);
      }
    }
    if (pAVar4 == (ASN1_TIME *)0x0) goto joined_r0x000c7bc8;
    if (piVar10[1] == 0x17) {
      iVar8 = (local_5f - 0x30) + (local_60 - 0x30) * 10;
      if (iVar8 < 0x32) {
        iVar8 = iVar8 + 100;
      }
      iVar9 = (local_47 - 0x30) + (local_48 - 0x30) * 10;
      if (iVar9 < 0x32) {
        iVar9 = iVar9 + 100;
      }
      if (iVar9 <= iVar8) {
        if (iVar8 <= iVar9) goto LAB_000c7d88;
        goto LAB_000c7d96;
      }
      goto LAB_000c7df4;
    }
LAB_000c7d88:
    iVar8 = strcmp((char *)local_7c,(char *)&local_48);
    if ((iVar8 == 0) || (iVar8 < 1)) goto LAB_000c7df4;
LAB_000c7d96:
    uVar2 = 0xb;
    if (param_3 != 0) goto LAB_000c7de4;
  }
  uVar2 = 0;
LAB_000c7bce:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar2);
}

