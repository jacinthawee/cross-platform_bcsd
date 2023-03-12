
undefined4 TS_RESP_CTX_set_certs(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    (*(code *)PTR_sk_pop_free_006a7058)(*(int *)(param_1 + 8),PTR_X509_free_006a6e90);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  uVar1 = 1;
  if (param_2 != 0) {
    iVar2 = (*(code *)PTR_sk_dup_006a7f54)(param_2);
    *(int *)(param_1 + 8) = iVar2;
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2f,0x81,0x41,"ts_rsp_sign.c",0xfa);
      uVar1 = 0;
    }
    else {
      iVar3 = 0;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar2);
        if (iVar2 <= iVar3) break;
        iVar2 = (*(code *)PTR_sk_value_006a6e24)(*(undefined4 *)(param_1 + 8),iVar3);
        (*(code *)PTR_CRYPTO_add_lock_006a805c)(iVar2 + 0x10,1,3,"ts_rsp_sign.c",0xff);
        iVar2 = *(int *)(param_1 + 8);
        iVar3 = iVar3 + 1;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}

