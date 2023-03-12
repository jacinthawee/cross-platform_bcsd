
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_current_time(ASN1_TIME *s)

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
  uint in_t1;
  code *pcVar12;
  undefined4 local_68;
  undefined4 local_64;
  int local_60;
  char *local_5c;
  uint local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  uchar local_48 [12];
  char local_3c;
  char local_3b;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar9 = s->type;
  iVar6 = s->length;
  puVar2 = (uint *)s->data;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (iVar9 == 0x17) {
    iVar7 = iVar6 + -10;
    if (iVar6 - 0xbU < 7) {
      local_54 = *puVar2;
      local_50 = puVar2[1];
      puVar10 = (uint *)((int)puVar2 + 10);
      puVar4 = (uchar *)((int)&local_4c + 2);
      local_4c = CONCAT13(*(uchar *)(puVar2 + 2),
                          CONCAT12(*(uchar *)((int)puVar2 + 9),(short)local_4c));
      goto LAB_00577c68;
    }
  }
  else {
    iVar7 = iVar6 + -0xc;
    if (iVar6 - 0xdU < 0xb) {
      uVar5 = (uint)puVar2 & 3;
      local_50 = puVar2[1];
      puVar10 = puVar2 + 3;
      local_4c = puVar2[2];
      puVar4 = local_48;
      uVar8 = (uint)(uchar *)((int)puVar2 + 3U) & 3;
      local_54 = (*(int *)((int)puVar2 - uVar5) << uVar5 * 8 |
                 in_t1 & 0xffffffffU >> (4 - uVar5) * 8) & -1 << (uVar8 + 1) * 8 |
                 *(uint *)((uchar *)((int)puVar2 + 3U) + -uVar8) >> (3 - uVar8) * 8;
LAB_00577c68:
      uVar3 = *(uchar *)puVar10;
      if (((uVar3 == 'Z') || (uVar3 == '-')) || (uVar3 == '+')) {
        *puVar4 = '0';
        puVar4[1] = '0';
LAB_00577d30:
        puVar4[3] = '\0';
        puVar4[2] = 'Z';
LAB_00577d3c:
        uVar3 = *(uchar *)puVar10;
LAB_00577d40:
        if (uVar3 == 'Z') {
          iVar6 = 0;
          if (iVar7 != 1) goto LAB_00577ca8;
          iVar6 = 0;
        }
        else {
          if (((((uVar3 != '+') && (uVar3 != '-')) ||
               ((iVar7 != 5 ||
                ((uVar5 = (int)(char)*(uchar *)((int)puVar10 + 1) - 0x30, 9 < (uVar5 & 0xff) ||
                 (uVar8 = (int)(char)*(uchar *)((int)puVar10 + 2) - 0x30, 9 < (uVar8 & 0xff)))))))
              || (uVar11 = (int)(char)*(uchar *)((int)puVar10 + 3) - 0x30, 9 < (uVar11 & 0xff))) ||
             (9 < ((int)(char)*(uchar *)(puVar10 + 1) - 0x30U & 0xff))) goto LAB_00577ca4;
          iVar6 = (uVar5 * 10 + uVar8) * 0x3c +
                  uVar11 * 10 + ((int)(char)*(uchar *)(puVar10 + 1) - 0x30U);
          if (uVar3 == '-') {
            iVar6 = -iVar6;
          }
          iVar6 = iVar6 * 0x3c;
        }
        local_58 = 0;
        local_64 = 0x18;
        local_60 = iVar9;
        local_5c = &local_3c;
        (*(code *)PTR_time_006a9adc)(&local_68);
        if (((local_58 & 0x40) != 0) ||
           ((pcVar12 = (code *)PTR_ASN1_UTCTIME_adj_006a8ca8, local_60 != 0x17 &&
            (pcVar12 = (code *)PTR_ASN1_GENERALIZEDTIME_adj_006a8cac, local_60 != 0x18)))) {
          pcVar12 = (code *)PTR_ASN1_TIME_adj_006a8ef0;
        }
        iVar6 = (*pcVar12)(&local_64,local_68,0,iVar6);
        if (iVar6 != 0) {
          if (s->type == 0x17) {
            iVar6 = (local_54._0_1_ + -0x30) * 10 + local_54._1_1_ + -0x30;
            iVar9 = (local_3c + -0x30) * 10 + local_3b + -0x30;
            if (iVar6 < 0x32) {
              iVar6 = iVar6 + 100;
            }
            if (iVar9 < 0x32) {
              iVar9 = iVar9 + 100;
            }
            if (iVar6 < iVar9) goto LAB_00577fe8;
            if (iVar9 < iVar6) {
              iVar6 = 1;
              goto LAB_00577ca8;
            }
          }
          iVar6 = (*(code *)PTR_strcmp_006a9b18)(&local_54,&local_3c);
          if (iVar6 == 0) {
            iVar6 = -1;
          }
          goto LAB_00577ca8;
        }
      }
      else if (iVar7 != 1) {
        *puVar4 = uVar3;
        puVar4[1] = *(uchar *)((int)puVar10 + 1);
        if (iVar7 + -2 != 0) {
          if (*(uchar *)((int)puVar10 + 2) != '.') {
            puVar10 = (uint *)((int)puVar10 + 2);
            iVar7 = iVar7 + -2;
            goto LAB_00577d30;
          }
          iVar6 = 0;
          if (iVar7 + -3 == 0) goto LAB_00577ca8;
          if (9 < (byte)(*(uchar *)((int)puVar10 + 3) - 0x30)) {
            iVar6 = iVar7 + -3;
            puVar2 = (uint *)((int)puVar10 + 3);
LAB_00577fc8:
            puVar10 = puVar2;
            iVar7 = iVar6;
            puVar4[3] = '\0';
            puVar4[2] = 'Z';
            goto LAB_00577d3c;
          }
          if (iVar7 + -4 == 0) goto LAB_00577ca4;
          iVar6 = iVar7 + -4;
          puVar2 = puVar10 + 1;
          if (9 < (byte)(*(uchar *)(puVar10 + 1) - 0x30)) goto LAB_00577fc8;
          if (iVar7 + -5 == 0) goto LAB_00577ca4;
          iVar6 = iVar7 + -5;
          puVar2 = (uint *)((int)puVar10 + 5);
          if (9 < (byte)(*(uchar *)((int)puVar10 + 5) - 0x30)) goto LAB_00577fc8;
          puVar4[3] = '\0';
          iVar7 = iVar7 + -6;
          puVar10 = (uint *)((int)puVar10 + 6);
          puVar4[2] = 'Z';
          if (iVar7 == 0) goto LAB_00577ca4;
          uVar3 = *(uchar *)puVar10;
          goto LAB_00577d40;
        }
      }
    }
  }
LAB_00577ca4:
  iVar6 = 0;
LAB_00577ca8:
  while (local_24 != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00577fe8:
    iVar6 = -1;
  }
  return iVar6;
}

