
int dlfcn_bind_func(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0x43;
    uVar3 = 0x109;
  }
  else {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(*(undefined4 *)(param_1 + 4));
    if (iVar1 < 1) {
      uVar2 = 0x69;
      uVar3 = 0x10d;
    }
    else {
      uVar3 = *(undefined4 *)(param_1 + 4);
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
      iVar1 = (*(code *)PTR_sk_value_006a6e24)(uVar3,iVar1 + -1);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_dlsym_006a9a0c)(iVar1,param_2);
        if (iVar1 == 0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(0x25,100,0x6a,"dso_dlfcn.c",0x117);
          uVar3 = (*(code *)PTR_dlerror_006a9a9c)();
          (*(code *)PTR_ERR_add_error_data_006a813c)(4,"symname(",param_2,"): ",uVar3);
        }
        return iVar1;
      }
      uVar2 = 0x68;
      uVar3 = 0x112;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x25,100,uVar2,"dso_dlfcn.c",uVar3);
  return 0;
}

