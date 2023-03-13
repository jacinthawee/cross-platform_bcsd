
int d2i_ASN1_BOOLEAN(int *a,uchar **pp,long length)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  byte *local_24;
  int local_20;
  int local_1c;
  int iStack_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_24 = *pp;
  pcVar5 = (char *)&iStack_18;
  piVar3 = &local_20;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = (*(code *)PTR_ASN1_get_object_006a7fb0)(&local_24,piVar3,&local_1c,pcVar5,length);
  if ((uVar2 & 0x80) == 0) {
    if (local_1c == 1) {
      puVar4 = (undefined4 *)&DAT_0000006a;
      if (local_20 == 1) {
        uVar2 = (uint)*local_24;
        if (a != (int *)0x0) {
          *a = uVar2;
        }
        *pp = local_24 + 1;
        local_24 = local_24 + 1;
        goto LAB_0060ad48;
      }
    }
    else {
      puVar4 = (undefined4 *)0x75;
    }
  }
  else {
    puVar4 = (undefined4 *)0x66;
  }
  piVar3 = (int *)0x8e;
  pcVar5 = "a_bool.c";
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
  uVar2 = 0xffffffff;
LAB_0060ad48:
  if (local_14 == *(int *)puVar1) {
    return uVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if ((int *)pcVar5 != (int *)0x0) {
    iVar6 = *(int *)pcVar5;
    if (*(int *)(iVar6 + 0x14) != 0) {
      (*(code *)PTR_CRYPTO_free_006a6e88)();
    }
    *(undefined4 *)(iVar6 + 0x14) = 0;
    *piVar3 = 0;
    *puVar4 = 0;
    return 1;
  }
  return 0;
}

