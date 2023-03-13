
int i2d_ASN1_BOOLEAN(int a,uchar **pp)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  byte **ppbVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  byte *pbStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  int iStack_54;
  uchar **ppuStack_50;
  undefined *puStack_4c;
  int iStack_48;
  code *pcStack_44;
  undefined4 local_30;
  undefined *local_28;
  int local_1c;
  uchar *local_18;
  uint *local_14;
  
  puStack_4c = PTR___stack_chk_guard_006a9ae8;
  uVar7 = 1;
  ppbVar5 = (byte **)0x1;
  local_28 = &_gp;
  local_14 = *(uint **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_ASN1_object_size_006a83e4)(0);
  if (pp != (uchar **)0x0) {
    local_18 = *pp;
    uVar7 = 1;
    ppbVar5 = (byte **)0x0;
    local_30 = 0;
    local_1c = iVar2;
    (**(code **)(local_28 + -0x69f8))(&local_18,0,1,1);
    *local_18 = (uchar)a;
    *pp = local_18 + 1;
    iVar2 = local_1c;
    local_18 = local_18 + 1;
  }
  if (local_14 == *(uint **)puStack_4c) {
    return iVar2;
  }
  pcStack_44 = d2i_ASN1_BOOLEAN;
  puVar4 = local_14;
  (**(code **)(local_28 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pbStack_64 = *ppbVar5;
  pcVar9 = (char *)&iStack_58;
  piVar6 = &iStack_60;
  iStack_54 = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_50 = pp;
  iStack_48 = a;
  uVar3 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&pbStack_64,piVar6,&iStack_5c,pcVar9,uVar7);
  if ((uVar3 & 0x80) == 0) {
    if (iStack_5c == 1) {
      puVar8 = (undefined4 *)&DAT_0000006a;
      if (iStack_60 == 1) {
        uVar3 = (uint)*pbStack_64;
        if (puVar4 != (uint *)0x0) {
          *puVar4 = uVar3;
        }
        *ppbVar5 = pbStack_64 + 1;
        pbStack_64 = pbStack_64 + 1;
        goto LAB_0060ad48;
      }
    }
    else {
      puVar8 = (undefined4 *)0x75;
    }
  }
  else {
    puVar8 = (undefined4 *)0x66;
  }
  piVar6 = (int *)0x8e;
  pcVar9 = "a_bool.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  uVar3 = 0xffffffff;
LAB_0060ad48:
  if (iStack_54 == *(int *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((int *)pcVar9 != (int *)0x0) {
    iVar2 = *(int *)pcVar9;
    if (*(int *)(iVar2 + 0x14) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *piVar6 = 0;
    *puVar8 = 0;
    return 1;
  }
  return 0;
}

