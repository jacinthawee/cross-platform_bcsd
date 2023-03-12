
int ssl3_check_finished(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar5 = &local_18;
  if (*(int *)(*(int *)(param_1 + 0xc0) + 0xe4) != 0) {
    param_3 = 0x1131;
    piVar5 = (int *)0x1130;
    iVar2 = (**(code **)(*(int *)(param_1 + 8) + 0x30))
                      (param_1,0x1130,0x1131,0xffffffff,*(undefined4 *)(param_1 + 0x108),&local_18);
    if (local_18 == 0) goto LAB_00489224;
    iVar3 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar3 + 0x354) = 1;
    iVar2 = 2;
    if ((*(uint *)(iVar3 + 0x340) & 0xffffffef) == 4) goto LAB_00489224;
  }
  iVar2 = 1;
LAB_00489224:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar3 = *(int *)(iVar2 + 0xe4);
  iVar6 = *(int *)(iVar3 + 0xfc);
  if (iVar6 != 0) {
    uVar4 = (*(code *)PTR_SSL_get_client_CA_list_006a8a68)();
    iVar3 = (*(code *)PTR_ENGINE_load_ssl_client_cert_006a91d0)
                      (iVar6,iVar2,uVar4,piVar5,param_3,0,0,0);
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = *(int *)(iVar2 + 0xe4);
  }
  if (*(code **)(iVar3 + 0x74) == (code *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004892f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (**(code **)(iVar3 + 0x74))(iVar2,piVar5,param_3);
  return iVar2;
}

