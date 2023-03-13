
/* WARNING: Removing unreachable block (ram,0x00525f0c) */
/* WARNING: Removing unreachable block (ram,0x00525f18) */
/* WARNING: Removing unreachable block (ram,0x00525a38) */
/* WARNING: Removing unreachable block (ram,0x00525a5c) */
/* WARNING: Removing unreachable block (ram,0x00525a80) */
/* WARNING: Removing unreachable block (ram,0x00525a48) */
/* WARNING: Removing unreachable block (ram,0x00525bec) */
/* WARNING: Removing unreachable block (ram,0x00525bfc) */
/* WARNING: Removing unreachable block (ram,0x00525c08) */
/* WARNING: Removing unreachable block (ram,0x00525c28) */
/* WARNING: Removing unreachable block (ram,0x00525c44) */
/* WARNING: Removing unreachable block (ram,0x00525c14) */
/* WARNING: Removing unreachable block (ram,0x00525c20) */
/* WARNING: Removing unreachable block (ram,0x00525a54) */

uint _dopr(undefined4 param_1,int param_2,uint *param_3,int *param_4,uint *param_5,char *param_6)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  uint local_78 [11];
  int local_4c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  pcVar5 = param_6 + 1;
  local_4c = *(int *)PTR___stack_chk_guard_006a9ae8;
  cVar1 = *param_6;
  local_78[0] = 0;
  while( true ) {
    if (cVar1 == '\0') {
      uVar3 = (uint)(*param_3 - 1 < local_78[0]);
      *param_5 = uVar3;
    }
    else {
      if ((param_2 != 0) || (local_78[0] < *param_3)) {
                    /* WARNING: Could not recover jumptable at 0x0052500c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (*(code *)switchD_0052500c::switchdataD_00667620)();
        return uVar3;
      }
      uVar3 = (uint)(*param_3 - 1 < local_78[0]);
      *param_5 = uVar3;
    }
    if (uVar3 != 0) {
      local_78[0] = *param_3 - 1;
    }
    iVar4 = doapr_outch(param_1,param_2,local_78,param_3,0);
    if (iVar4 != 0) {
      *param_4 = local_78[0] - 1;
    }
    if (local_4c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  }
  return (uint)(iVar4 != 0);
}

