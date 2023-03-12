
int dlfcn_bind_var(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0x43;
    uVar3 = 0xee;
  }
  else {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(*(undefined4 *)(param_1 + 4));
    if (iVar1 < 1) {
      uVar2 = 0x69;
      uVar3 = 0xf3;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 4);
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(uVar3);
      iVar1 = (*(code *)PTR_sk_value_006a7f24)(uVar3,iVar1 + -1);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_dlsym_006aab18)(iVar1,param_2);
        if (iVar1 == 0) {
          (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x65,0x6a,"dso_dlfcn.c",0xff);
          uVar3 = (*(code *)PTR_dlerror_006aaba4)();
          (*(code *)PTR_ERR_add_error_data_006a9264)(4,"symname(",param_2,"): ",uVar3);
        }
        return iVar1;
      }
      uVar2 = 0x68;
      uVar3 = 0xf9;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x25,0x65,uVar2,"dso_dlfcn.c",uVar3);
  return 0;
}

