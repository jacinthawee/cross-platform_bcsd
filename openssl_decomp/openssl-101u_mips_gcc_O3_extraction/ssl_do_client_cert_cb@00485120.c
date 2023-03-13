
int ssl_do_client_cert_cb(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xe4);
  iVar3 = *(int *)(iVar1 + 0xfc);
  if (iVar3 != 0) {
    uVar2 = (*(code *)PTR_SSL_get_client_CA_list_006a797c)();
    iVar1 = (*(code *)PTR_ENGINE_load_ssl_client_cert_006a8090)
                      (iVar3,param_1,uVar2,param_2,param_3,0,0,0);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = *(int *)(param_1 + 0xe4);
  }
  if (*(code **)(iVar1 + 0x74) == (code *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x004851c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(iVar1 + 0x74))(param_1,param_2,param_3);
  return iVar1;
}

