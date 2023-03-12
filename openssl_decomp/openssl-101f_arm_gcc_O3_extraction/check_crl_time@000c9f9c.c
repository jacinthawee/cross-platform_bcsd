
void check_crl_time(int param_1,int *param_2,int param_3)

{
  byte *pbVar1;
  byte bVar2;
  undefined4 uVar3;
  ASN1_TIME *pAVar4;
  undefined *puVar5;
  uint *puVar6;
  long offset_sec;
  int iVar7;
  undefined *puVar8;
  int *piVar9;
  uint uVar10;
  time_t *t;
  int iVar11;
  uint *puVar12;
  time_t local_74;
  ASN1_TIME local_70;
  uint local_60;
  uint uStack_5c;
  undefined4 local_58;
  undefined auStack_54 [12];
  byte local_48;
  byte local_47;
  int local_2c;
  
  local_2c = __TMC_END__;
  if (param_3 != 0) {
    *(int **)(param_1 + 0x70) = param_2;
  }
  t = (time_t *)(*(uint *)(*(int *)(param_1 + 0x14) + 0xc) & 2);
  if (t != (time_t *)0x0) {
    t = (time_t *)(*(int *)(param_1 + 0x14) + 4);
  }
  piVar9 = *(int **)(*param_2 + 0xc);
  iVar11 = piVar9[1];
  puVar6 = (uint *)piVar9[2];
  if (iVar11 == 0x17) {
    if (*piVar9 - 0xbU < 7) {
      local_60 = *puVar6;
      puVar12 = (uint *)((int)puVar6 + 10);
      uStack_5c = puVar6[1];
      puVar8 = (undefined *)((int)&local_58 + 2);
      local_58 = local_58 & 0xffff0000 | (uint)*(ushort *)(puVar6 + 2);
      uVar10 = (uint)*(byte *)puVar12;
      if (uVar10 != 0x2d && uVar10 != 0x5a) goto LAB_000ca0fe;
      goto LAB_000ca018;
    }
LAB_000c9fdc:
    if (param_3 != 0) {
      uVar3 = 0xf;
LAB_000ca13c:
      *(undefined4 *)(param_1 + 100) = uVar3;
      iVar11 = (**(code **)(param_1 + 0x20))(0,param_1);
      if (iVar11 != 0) {
LAB_000ca14c:
        if (*(ASN1_TIME **)(*param_2 + 0x10) == (ASN1_TIME *)0x0) {
LAB_000ca176:
          if (param_3 == 0) {
            uVar3 = 1;
            goto LAB_000c9fe6;
          }
LAB_000ca17c:
          uVar3 = 1;
          *(undefined4 *)(param_1 + 0x70) = 0;
          goto LAB_000c9fe6;
        }
        iVar11 = X509_cmp_time(*(ASN1_TIME **)(*param_2 + 0x10),t);
        if (iVar11 == 0) {
          if (param_3 != 0) {
            *(undefined4 *)(param_1 + 100) = 0x10;
            iVar11 = (**(code **)(param_1 + 0x20))(0,param_1);
joined_r0x000ca1e4:
            if (iVar11 != 0) goto LAB_000ca17c;
          }
        }
        else {
          if ((-1 < iVar11) || ((*(uint *)(param_1 + 0x74) & 2) != 0)) goto LAB_000ca176;
          if (param_3 != 0) {
            *(undefined4 *)(param_1 + 100) = 0xc;
            iVar11 = (**(code **)(param_1 + 0x20))(0,param_1);
            goto joined_r0x000ca1e4;
          }
        }
      }
    }
  }
  else {
    if (*piVar9 < 0xd) goto LAB_000c9fdc;
    local_58 = puVar6[2];
    local_60 = *puVar6;
    puVar12 = puVar6 + 3;
    uStack_5c = puVar6[1];
    puVar8 = auStack_54;
    uVar10 = (uint)*(byte *)puVar12;
    if (uVar10 == 0x2d || uVar10 == 0x5a) {
LAB_000ca018:
      puVar5 = puVar8 + 2;
      *puVar8 = 0x30;
      puVar8[1] = 0x30;
    }
    else {
LAB_000ca0fe:
      if (uVar10 == 0x2b) goto LAB_000ca018;
      puVar5 = puVar8 + 2;
      *puVar8 = (char)uVar10;
      uVar10 = (uint)*(byte *)((int)puVar12 + 2);
      pbVar1 = (byte *)((int)puVar12 + 1);
      if (uVar10 != 0x2e) {
        puVar12 = (uint *)((int)puVar12 + 2);
      }
      puVar8[1] = *pbVar1;
      if (uVar10 == 0x2e) {
        pbVar1 = (byte *)((int)puVar12 + 3);
        puVar12 = (uint *)((int)puVar12 + 3);
        bVar2 = *pbVar1;
        while (uVar10 = (uint)bVar2, uVar10 - 0x30 < 10) {
          puVar12 = (uint *)((int)puVar12 + 1);
          bVar2 = *(byte *)puVar12;
        }
      }
    }
    offset_sec = 0;
    *puVar5 = 0x5a;
    puVar5[1] = 0;
    if (uVar10 != 0x5a) {
      if (uVar10 != 0x2d && uVar10 != 0x2b) goto LAB_000c9fdc;
      iVar7 = (*(byte *)(puVar12 + 1) - 0x30) + (*(byte *)((int)puVar12 + 3) - 0x30) * 10 +
              ((*(byte *)((int)puVar12 + 2) - 0x30) + (*(byte *)((int)puVar12 + 1) - 0x30) * 10) *
              0x3c;
      if (uVar10 == 0x2d) {
        iVar7 = -iVar7;
      }
      offset_sec = iVar7 * 0x3c;
    }
    local_70.flags = 0;
    local_70.length = 0x18;
    local_70.type = iVar11;
    local_70.data = &local_48;
    if (t == (time_t *)0x0) {
      time(&local_74);
      if ((local_70.flags & 0x40U) == 0) goto LAB_000ca09a;
LAB_000ca0a8:
      pAVar4 = ASN1_TIME_adj(&local_70,local_74,0,offset_sec);
    }
    else {
      local_74 = *t;
LAB_000ca09a:
      if (local_70.type == 0x17) {
        pAVar4 = ASN1_UTCTIME_adj(&local_70,local_74,0,offset_sec);
      }
      else {
        if (local_70.type != 0x18) goto LAB_000ca0a8;
        pAVar4 = ASN1_GENERALIZEDTIME_adj(&local_70,local_74,0,offset_sec);
      }
    }
    if (pAVar4 == (ASN1_TIME *)0x0) goto LAB_000c9fdc;
    if (piVar9[1] == 0x17) {
      iVar11 = ((local_60 >> 8 & 0xff) - 0x30) + ((local_60 & 0xff) - 0x30) * 10;
      if (iVar11 < 0x32) {
        iVar11 = iVar11 + 100;
      }
      iVar7 = (local_47 - 0x30) + (local_48 - 0x30) * 10;
      if (iVar7 < 0x32) {
        iVar7 = iVar7 + 100;
      }
      if (iVar7 <= iVar11) {
        if (iVar11 <= iVar7) goto LAB_000ca0ba;
        goto LAB_000ca0c8;
      }
      goto LAB_000ca14c;
    }
LAB_000ca0ba:
    iVar11 = strcmp((char *)&local_60,(char *)&local_48);
    if ((iVar11 == 0) || (iVar11 < 1)) goto LAB_000ca14c;
LAB_000ca0c8:
    uVar3 = 0xb;
    if (param_3 != 0) goto LAB_000ca13c;
  }
  uVar3 = 0;
LAB_000c9fe6:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar3);
}

