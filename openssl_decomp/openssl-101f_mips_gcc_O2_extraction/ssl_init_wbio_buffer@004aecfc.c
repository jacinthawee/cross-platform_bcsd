
undefined4 ssl_init_wbio_buffer(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  if (iVar3 == 0) {
    uVar2 = (*(code *)PTR_BIO_f_buffer_006a8940)();
    iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
    if (iVar3 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0x14) = iVar3;
  }
  else if (iVar3 == *(int *)(param_1 + 0x10)) {
    uVar2 = (*(code *)PTR_BIO_pop_006a8ab4)(iVar3);
    *(undefined4 *)(param_1 + 0x10) = uVar2;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,1,0,0);
  iVar1 = (*(code *)PTR_BIO_int_ctrl_006a8948)(iVar3,0x75,1,0);
  if (iVar1 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0xb8,7,"ssl_lib.c",0xb30);
    return 0;
  }
  if (param_2 == 0) {
    if (iVar3 == *(int *)(param_1 + 0x10)) {
      uVar2 = (*(code *)PTR_BIO_pop_006a8ab4)(iVar3);
      *(undefined4 *)(param_1 + 0x10) = uVar2;
    }
    return 1;
  }
  if (iVar3 == *(int *)(param_1 + 0x10)) {
    return 1;
  }
  uVar2 = (*(code *)PTR_BIO_push_006a85c0)(iVar3);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  return 1;
}

