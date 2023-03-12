
int gost_imit_final(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint unaff_s1;
  int unaff_s5;
  undefined4 *unaff_s6;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar4 = *(int *)(param_1 + 0xc);
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar3 = *(int *)(iVar4 + 0x103c);
  if (iVar3 == 0) {
    ERR_GOST_error(0x8c,0x74,"gost_crypt.c",0x240);
    goto LAB_0061e87c;
  }
  unaff_s1 = *(uint *)(iVar4 + 0x1038);
  if (*(int *)(iVar4 + 0x1030) == 0) {
    if (unaff_s1 != 0) {
      unaff_s6 = &local_2c;
      local_2c = 0;
      local_28 = 0;
      if (7 < unaff_s1) {
        unaff_s5 = iVar4 + 0x1028;
        if (unaff_s1 == 8) goto LAB_0061ea0c;
        *(uint *)(iVar4 + 0x1038) = unaff_s1;
        goto LAB_0061e8bc;
      }
      *(undefined *)(iVar4 + unaff_s1 + 0x1028) = 0;
      if (unaff_s1 + 1 != 8) {
        *(undefined *)(iVar4 + unaff_s1 + 1 + 0x1028) = 0;
        if (unaff_s1 + 2 != 8) {
          *(undefined *)(iVar4 + unaff_s1 + 2 + 0x1028) = 0;
          if (unaff_s1 + 3 != 8) {
            *(undefined *)(iVar4 + unaff_s1 + 3 + 0x1028) = 0;
            if (unaff_s1 + 4 != 8) {
              *(undefined *)(iVar4 + unaff_s1 + 4 + 0x1028) = 0;
              if ((unaff_s1 + 5 != 8) &&
                 (*(undefined *)(iVar4 + unaff_s1 + 5 + 0x1028) = 0, unaff_s1 == 1)) {
                *(undefined *)(iVar4 + 0x102f) = 0;
              }
            }
          }
        }
      }
      unaff_s5 = iVar4 + 0x1028;
      unaff_s6 = (undefined4 *)((int)&local_24 - unaff_s1);
      goto LAB_0061ea0c;
    }
  }
  else if (unaff_s1 != 0) {
    unaff_s5 = iVar4 + 0x1028;
    goto LAB_0061e8bc;
  }
  while( true ) {
    get_mac(iVar4 + 0x1020,0x20,param_2);
    iVar3 = 1;
LAB_0061e87c:
    if (local_24 == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0061ea0c:
    mac_block(iVar4,iVar4 + 0x1020,unaff_s5);
    puVar2 = PTR_memcpy_006aabf4;
    *(uint *)(iVar4 + 0x1030) = (*(uint *)(iVar4 + 0x1030) & 0x3ff) + 8;
    (*(code *)puVar2)(unaff_s5,unaff_s6,unaff_s1);
    *(uint *)(iVar4 + 0x1038) = unaff_s1;
LAB_0061e8bc:
    if ((int)unaff_s1 < 8) {
      (*(code *)PTR_memset_006aab00)(iVar4 + unaff_s1 + 0x1028,0,8 - unaff_s1);
    }
    if ((*(int *)(iVar4 + 0x1034) != 0) && (*(int *)(iVar4 + 0x1030) == 0x400)) {
      cryptopro_key_meshing(iVar4,&local_2c);
    }
    mac_block(iVar4,iVar4 + 0x1020,unaff_s5);
    *(uint *)(iVar4 + 0x1030) = (*(uint *)(iVar4 + 0x1030) & 0x3ff) + 8;
  }
  return iVar3;
}

