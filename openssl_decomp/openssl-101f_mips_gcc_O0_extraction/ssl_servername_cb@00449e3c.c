
undefined4 ssl_servername_cb(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (*(code *)PTR_SSL_get_servername_006a896c)(param_1,0);
  iVar2 = (*(code *)PTR_SSL_get_servername_type_006a8a6c)(param_1);
  if (iVar2 != -1) {
    iVar2 = (*(code *)PTR_SSL_ctrl_006a8878)(param_1,8,0,0);
    uVar3 = 0;
    if (iVar2 == 0) {
      uVar3 = (uint)(iVar1 != 0);
    }
    *(uint *)(param_3 + 4) = uVar3;
    return 0;
  }
  (*(code *)PTR_BIO_printf_006a7f38)
            (*(undefined4 *)PTR_bio_err_006a7f3c,"Can\'t use SSL_get_servername\n");
  return 0;
}

