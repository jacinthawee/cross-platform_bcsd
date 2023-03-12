
undefined4 def_load(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_BIO_new_file_006a6eac)(param_2,&DAT_00633e40);
  if (iVar1 != 0) {
    uVar2 = def_load_bio(param_1,iVar1,param_3);
    (*(code *)PTR_BIO_free_006a6e70)(iVar1);
    return uVar2;
  }
  uVar3 = (*(code *)PTR_ERR_peek_last_error_006a7408)();
  if ((uVar3 & 0xfff) == 0x80) {
    uVar4 = 0x72;
    uVar2 = 0xc3;
  }
  else {
    uVar4 = 2;
    uVar2 = 0xc5;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xe,0x78,uVar4,"conf_def.c",uVar2);
  return 0;
}

