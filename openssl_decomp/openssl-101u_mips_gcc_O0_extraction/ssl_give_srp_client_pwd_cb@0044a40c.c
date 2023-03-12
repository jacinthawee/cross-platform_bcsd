
int ssl_give_srp_client_pwd_cb(undefined4 param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 local_1c;
  char *local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iVar6 = 0x224;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x401,"s_client.c");
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,"Malloc failure\n");
    iVar2 = 0;
  }
  else {
    local_1c = *param_2;
    iVar6 = 0;
    local_18 = "SRP user";
    iVar3 = password_callback(iVar2,0x400,0,&local_1c);
    if (iVar3 < 0) {
      (*(code *)PTR_BIO_printf_006a6e38)
                (*(undefined4 *)PTR_bio_err_006a6e3c,"Can\'t read Password\n");
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
      iVar2 = 0;
    }
    else {
      *(undefined *)(iVar2 + iVar3) = 0;
    }
  }
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar3 = (*(code *)PTR_SSL_get_servername_006a7884)();
  iVar4 = (*(code *)PTR_SSL_get_servername_type_006a7980)(iVar2);
  if (iVar4 != -1) {
    iVar2 = (*(code *)PTR_SSL_ctrl_006a7788)(iVar2,8,0,0);
    uVar5 = 0;
    if (iVar2 == 0) {
      uVar5 = (uint)(iVar3 != 0);
    }
    *(uint *)(iVar6 + 4) = uVar5;
    return 0;
  }
  (*(code *)PTR_BIO_printf_006a6e38)
            (*(undefined4 *)PTR_bio_err_006a6e3c,"Can\'t use SSL_get_servername\n");
  return 0;
}

