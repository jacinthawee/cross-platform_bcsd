
undefined4 genpkey_cb(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined local_15;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_15 = 0x2a;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_EVP_PKEY_CTX_get_app_data_006a7f0c)();
  iVar3 = (*(code *)PTR_EVP_PKEY_CTX_get_keygen_info_006a7f10)(param_1,0);
  if (iVar3 == 0) {
    local_15 = 0x2e;
  }
  else if (iVar3 == 1) {
    local_15 = 0x2b;
  }
  else {
    uVar4 = CONCAT44(iVar3,3);
    if (iVar3 != 2) goto LAB_0044145c;
    local_15 = 0x2a;
  }
  while( true ) {
    (*(code *)PTR_BIO_write_006a7f14)(uVar2,&local_15,1);
    (*(code *)PTR_BIO_ctrl_006a7f18)(uVar2,0xb,0,0);
    if (local_14 == *(int *)puVar1) break;
    uVar4 = (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0044145c:
    if ((int)((ulonglong)uVar4 >> 0x20) == (int)uVar4) {
      local_15 = 10;
    }
  }
  return 1;
}

