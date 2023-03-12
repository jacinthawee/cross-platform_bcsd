
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_poll(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  int local_204;
  undefined2 local_200;
  ushort local_1fe;
  int local_1fc [4];
  int local_1ec;
  int local_16c;
  int local_15c;
  int local_dc;
  undefined auStack_4c [32];
  undefined4 *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar8 = 0;
  iVar6 = 0;
  piVar5 = local_1fc;
  puVar7 = randomfiles_9941;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_getpid_006aab70)();
  (*(code *)PTR_memset_006aab00)(piVar5,0,0x1b0);
  while( true ) {
    iVar3 = (*(code *)PTR_open_006aab48)(*(undefined4 *)puVar7,0x880);
    if (-1 < iVar3) {
      iVar4 = (*(code *)PTR___fxstat_006aab5c)(3,iVar3,piVar5);
      if ((iVar4 == 0) &&
         ((iVar6 == 0 ||
          (((local_1ec != piVar5[4] || (local_1fc[0] != *piVar5)) &&
           ((iVar6 != 2 || ((piVar5[4] != local_15c || (local_16c != local_dc)))))))))) {
        local_1fe = 0;
        local_200 = 1;
        local_204 = iVar3;
        iVar4 = (*(code *)PTR_poll_006aab84)(&local_204,1,10);
        if ((-1 < iVar4) &&
           (((local_1fe & 1) != 0 &&
            (iVar4 = (*(code *)PTR_read_006aac18)(iVar3,auStack_4c + iVar8,0x20 - iVar8), 0 < iVar4)
            ))) {
          iVar8 = iVar8 + iVar4;
        }
      }
      (*(code *)PTR_close_006aaa5c)(iVar3);
    }
    iVar6 = iVar6 + 1;
    if (iVar6 == 3) break;
    puVar7 = (undefined1 *)((int)puVar7 + 4);
    piVar5 = piVar5 + 0x24;
    if (0x1f < iVar8) goto LAB_00606884;
  }
  if (egdsockets_9945._0_4_ == 0) goto LAB_006069f4;
  if (0x1f < iVar8) goto LAB_00606884;
  puVar7 = egdsockets_9945;
  iVar6 = egdsockets_9945._0_4_;
  do {
    puVar7 = (undefined1 *)((int)puVar7 + 4);
    iVar3 = (*(code *)PTR_RAND_query_egd_bytes_006aa8b8)(iVar6,auStack_4c + iVar8,0x20 - iVar8);
    iVar6 = *(int *)puVar7;
    while (0 < iVar3) {
      iVar8 = iVar8 + iVar3;
      if (iVar6 == 0) goto LAB_006069f4;
      if (0x1f < iVar8) goto LAB_00606884;
      puVar7 = (undefined1 *)((int)puVar7 + 4);
      iVar3 = (*(code *)PTR_RAND_query_egd_bytes_006aa8b8)(iVar6,auStack_4c + iVar8,0x20 - iVar8);
      iVar6 = *(int *)puVar7;
    }
  } while (iVar6 != 0);
LAB_006069f4:
  if (iVar8 != 0) {
LAB_00606884:
    (*(code *)PTR_RAND_add_006a9020)
              (auStack_4c,0x20,(int)((ulonglong)(double)iVar8 >> 0x20),SUB84((double)iVar8,0));
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(auStack_4c,iVar8);
  }
  local_204 = iVar2;
  (*(code *)PTR_RAND_add_006a9020)(&local_204,4,0,0);
  local_204 = (*(code *)PTR_getuid_006aabac)();
  (*(code *)PTR_RAND_add_006a9020)(&local_204,4,0,0);
  local_204 = (*(code *)PTR_time_006aabe4)(0);
  (*(code *)PTR_RAND_add_006a9020)(&local_204,4,0,0);
  if (local_2c == *(undefined4 **)puVar1) {
    return 1;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  *local_2c = 0;
  local_2c[0x16] = 0;
  local_2c[1] = 0x30;
  return 0x30;
}

