
/* WARNING: Could not reconcile some variable overlaps */

int X509_cmp_time(ASN1_TIME *s,time_t *t)

{
  uchar uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  char *unaff_s3;
  time_t local_60;
  undefined4 local_5c;
  int local_58;
  char *local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uchar local_40 [12];
  char local_34;
  char local_33;
  int local_1c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  iVar7 = s->type;
  puVar3 = (undefined4 *)s->data;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (iVar7 == 0x17) {
    if (6 < s->length - 0xbU) goto LAB_0057b70c;
    local_4c = *puVar3;
    local_48 = puVar3[1];
    puVar4 = (undefined4 *)((int)puVar3 + 10);
    puVar6 = (uchar *)((int)&local_44 + 2);
    local_44 = CONCAT13(*(uchar *)(puVar3 + 2),CONCAT12(*(uchar *)((int)puVar3 + 9),(short)local_44)
                       );
  }
  else {
    if (s->length < 0xd) goto LAB_0057b70c;
    local_4c = *puVar3;
    local_48 = puVar3[1];
    puVar4 = puVar3 + 3;
    local_44 = puVar3[2];
    puVar6 = local_40;
  }
  uVar1 = *(uchar *)puVar4;
  if (((uVar1 == 'Z') || (uVar1 == '-')) || (uVar1 == '+')) {
    *puVar6 = '0';
    puVar6[1] = '0';
    puVar3 = puVar4;
  }
  else {
    *puVar6 = uVar1;
    puVar6[1] = *(uchar *)((int)puVar4 + 1);
    if (*(uchar *)((int)puVar4 + 2) == '.') {
      puVar3 = (undefined4 *)((int)puVar4 + 3);
      if ((byte)(*(uchar *)((int)puVar4 + 3) - 0x30) < 10) {
        puVar4 = puVar4 + 1;
        do {
          uVar1 = *(uchar *)puVar4;
          puVar3 = puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        } while ((byte)(uVar1 - 0x30) < 10);
      }
    }
    else {
      puVar3 = (undefined4 *)((int)puVar4 + 2);
    }
  }
  puVar6[3] = '\0';
  puVar6[2] = 'Z';
  uVar1 = *(uchar *)puVar3;
  if (((uVar1 != 'Z') && (uVar1 != '+')) && (uVar1 != '-')) goto LAB_0057b70c;
  unaff_s3 = &local_34;
  local_50 = 0;
  local_5c = 0x18;
  local_58 = iVar7;
  local_54 = unaff_s3;
  if (t != (time_t *)0x0) {
    local_60 = *t;
    goto LAB_0057b870;
  }
  (*(code *)PTR_time_006aabe4)(&local_60);
  if ((local_50 & 0x40) == 0) goto LAB_0057b870;
LAB_0057b888:
  iVar7 = (*(code *)PTR_ASN1_TIME_adj_006aa00c)(&local_5c,local_60,0);
LAB_0057b89c:
  do {
    if (iVar7 == 0) {
LAB_0057b70c:
      iVar7 = 0;
    }
    else if (s->type == 0x17) {
      iVar7 = (local_4c._0_1_ + -0x30) * 10 + local_4c._1_1_ + -0x30;
      iVar5 = (local_34 + -0x30) * 10 + local_33 + -0x30;
      if (iVar7 < 0x32) {
        iVar7 = iVar7 + 100;
      }
      if (iVar5 < 0x32) {
        iVar5 = iVar5 + 100;
      }
      if (iVar7 < iVar5) {
        iVar7 = -1;
      }
      else {
        if (iVar7 <= iVar5) goto LAB_0057b8b4;
        iVar7 = 1;
      }
    }
    else {
LAB_0057b8b4:
      iVar7 = (*(code *)PTR_strcmp_006aac20)(&local_4c,unaff_s3);
      if (iVar7 == 0) {
        iVar7 = -1;
      }
    }
    if (local_1c == *(int *)puVar2) {
      return iVar7;
    }
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0057b870:
    if (local_58 == 0x17) {
      iVar7 = (*(code *)PTR_ASN1_UTCTIME_adj_006a9dc8)(&local_5c,local_60,0);
      goto LAB_0057b89c;
    }
    if (local_58 != 0x18) goto LAB_0057b888;
    iVar7 = (*(code *)PTR_ASN1_GENERALIZEDTIME_adj_006a9dcc)(&local_5c,local_60,0);
  } while( true );
}

