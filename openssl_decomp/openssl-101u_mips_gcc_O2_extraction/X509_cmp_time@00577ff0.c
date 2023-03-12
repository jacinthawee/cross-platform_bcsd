
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  undefined *puVar1;
  uint *puVar2;
  uchar uVar3;
  uchar *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint in_t2;
  time_t local_60;
  undefined4 local_5c;
  int local_58;
  char *local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 local_44;
  uchar local_40 [12];
  char local_34;
  char local_33;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar9 = s->type;
  iVar6 = s->length;
  puVar2 = (uint *)s->data;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iVar9 == 0x17) {
    iVar7 = iVar6 + -10;
    if (iVar6 - 0xbU < 7) {
      local_4c = *puVar2;
      local_48 = puVar2[1];
      puVar10 = (uint *)((int)puVar2 + 10);
      puVar4 = (uchar *)((int)&local_44 + 2);
      local_44 = CONCAT13(*(uchar *)(puVar2 + 2),
                          CONCAT12(*(uchar *)((int)puVar2 + 9),(short)local_44));
      goto LAB_00578078;
    }
  }
  else {
    iVar7 = iVar6 + -0xc;
    if (iVar6 - 0xdU < 0xb) {
      uVar5 = (uint)puVar2 & 3;
      local_48 = puVar2[1];
      puVar10 = puVar2 + 3;
      local_44 = puVar2[2];
      puVar4 = local_40;
      uVar8 = (uint)(uchar *)((int)puVar2 + 3U) & 3;
      local_4c = (*(int *)((int)puVar2 - uVar5) << uVar5 * 8 |
                 in_t2 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar8 + 1) * 8 |
                 *(uint *)((uchar *)((int)puVar2 + 3U) + -uVar8) >> (3 - uVar8) * 8;
LAB_00578078:
      uVar3 = *(uchar *)puVar10;
      if (((uVar3 == 'Z') || (uVar3 == '-')) || (uVar3 == '+')) {
        *puVar4 = '0';
        puVar4[1] = '0';
LAB_00578138:
        puVar4[3] = '\0';
        puVar4[2] = 'Z';
LAB_00578144:
        uVar3 = *(uchar *)puVar10;
LAB_00578148:
        if (uVar3 == 'Z') {
          iVar6 = 0;
          if (iVar7 != 1) goto LAB_005780b8;
          iVar6 = 0;
        }
        else {
          if (((((uVar3 != '+') && (uVar3 != '-')) ||
               ((iVar7 != 5 ||
                ((uVar5 = (int)(char)*(uchar *)((int)puVar10 + 1) - 0x30, 9 < (uVar5 & 0xff) ||
                 (uVar8 = (int)(char)*(uchar *)((int)puVar10 + 2) - 0x30, 9 < (uVar8 & 0xff)))))))
              || (uVar11 = (int)(char)*(uchar *)((int)puVar10 + 3) - 0x30, 9 < (uVar11 & 0xff))) ||
             (9 < ((int)(char)*(uchar *)(puVar10 + 1) - 0x30U & 0xff))) goto LAB_005780b4;
          iVar6 = (uVar5 * 10 + uVar8) * 0x3c +
                  uVar11 * 10 + ((int)(char)*(uchar *)(puVar10 + 1) - 0x30U);
          if (uVar3 == '-') {
            iVar6 = -iVar6;
          }
          iVar6 = iVar6 * 0x3c;
        }
        local_50 = 0;
        local_5c = 0x18;
        local_58 = iVar9;
        local_54 = &local_34;
        if (t == (time_t *)0x0) {
          (*(code *)PTR_time_006a9adc)(&local_60);
          if ((local_50 & 0x40) == 0) goto LAB_0057821c;
LAB_00578234:
          iVar6 = (*(code *)PTR_ASN1_TIME_adj_006a8ef0)(&local_5c,local_60,0);
        }
        else {
          local_60 = *t;
LAB_0057821c:
          if (local_58 == 0x17) {
            iVar6 = (*(code *)PTR_ASN1_UTCTIME_adj_006a8ca8)(&local_5c,local_60,0,iVar6);
          }
          else {
            if (local_58 != 0x18) goto LAB_00578234;
            iVar6 = (*(code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac)(&local_5c,local_60,0);
          }
        }
        if (iVar6 != 0) {
          if (s->type == 0x17) {
            iVar6 = (local_4c._0_1_ + -0x30) * 10 + local_4c._1_1_ + -0x30;
            iVar9 = (local_34 + -0x30) * 10 + local_33 + -0x30;
            if (iVar6 < 0x32) {
              iVar6 = iVar6 + 100;
            }
            if (iVar9 < 0x32) {
              iVar9 = iVar9 + 100;
            }
            if (iVar6 < iVar9) goto LAB_0057842c;
            if (iVar9 < iVar6) {
              iVar6 = 1;
              goto LAB_005780b8;
            }
          }
          iVar6 = (*(code *)PTR_strcmp_006a9b18)(&local_4c,&local_34);
          if (iVar6 == 0) {
            iVar6 = -1;
          }
          goto LAB_005780b8;
        }
      }
      else if (iVar7 != 1) {
        *puVar4 = uVar3;
        puVar4[1] = *(uchar *)((int)puVar10 + 1);
        if (iVar7 + -2 != 0) {
          if (*(uchar *)((int)puVar10 + 2) != '.') {
            puVar10 = (uint *)((int)puVar10 + 2);
            iVar7 = iVar7 + -2;
            goto LAB_00578138;
          }
          iVar6 = 0;
          if (iVar7 + -3 == 0) goto LAB_005780b8;
          if (9 < (byte)(*(uchar *)((int)puVar10 + 3) - 0x30)) {
            iVar6 = iVar7 + -3;
            puVar2 = (uint *)((int)puVar10 + 3);
LAB_005783e4:
            puVar10 = puVar2;
            iVar7 = iVar6;
            puVar4[3] = '\0';
            puVar4[2] = 'Z';
            goto LAB_00578144;
          }
          if (iVar7 + -4 == 0) goto LAB_005780b4;
          iVar6 = iVar7 + -4;
          puVar2 = puVar10 + 1;
          if (9 < (byte)(*(uchar *)(puVar10 + 1) - 0x30)) goto LAB_005783e4;
          if (iVar7 + -5 == 0) goto LAB_005780b4;
          iVar6 = iVar7 + -5;
          puVar2 = (uint *)((int)puVar10 + 5);
          if (9 < (byte)(*(uchar *)((int)puVar10 + 5) - 0x30)) goto LAB_005783e4;
          puVar4[3] = '\0';
          iVar7 = iVar7 + -6;
          puVar10 = (uint *)((int)puVar10 + 6);
          puVar4[2] = 'Z';
          if (iVar7 == 0) goto LAB_005780b4;
          uVar3 = *(uchar *)puVar10;
          goto LAB_00578148;
        }
      }
    }
  }
LAB_005780b4:
  iVar6 = 0;
LAB_005780b8:
  while (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0057842c:
    iVar6 = -1;
  }
  return iVar6;
}

