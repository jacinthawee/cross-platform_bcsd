
bool app_passwd(undefined4 param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    bVar3 = false;
    if (param_2 != 0) goto LAB_0045a650;
    if (param_4 == (int *)0x0) goto LAB_0045a804;
LAB_0045a758:
    *param_4 = 0;
    if (param_3 == 0) goto LAB_0045a804;
  }
  else if (param_2 == 0) {
    if (param_4 != (int *)0x0) goto LAB_0045a758;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006a9b18)(param_2,param_3);
    bVar3 = iVar1 == 0;
LAB_0045a650:
    iVar1 = (*(code *)PTR_strncmp_006a9970)(param_2,"pass:",5);
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_2 + 5);
    }
    else {
      iVar1 = (*(code *)PTR_strncmp_006a9970)(param_2,&DAT_0063fa00,4);
      if (iVar1 == 0) {
        iVar1 = (*(code *)PTR_getenv_006a9a60)(param_2 + 4);
        if (iVar1 == 0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (param_1,"Can\'t read environment variable %s\n",param_2 + 4);
          *param_4 = 0;
          return false;
        }
        iVar1 = (*(code *)PTR_BUF_strdup_006a6fdc)(iVar1);
      }
      else {
        iVar1 = app_get_pass_part_0(param_1,param_2,bVar3);
      }
    }
    *param_4 = iVar1;
    if (iVar1 == 0) {
      return false;
    }
    if (param_3 == 0) {
LAB_0045a804:
      if (param_5 != (int *)0x0) {
        *param_5 = 0;
        return true;
      }
      return true;
    }
    if (bVar3 != false) {
      iVar1 = (*(code *)PTR_strncmp_006a9970)(param_3,"pass:",5);
      uVar2 = 2;
      goto joined_r0x0045a77c;
    }
  }
  iVar1 = (*(code *)PTR_strncmp_006a9970)(param_3,"pass:",5);
  uVar2 = 0;
joined_r0x0045a77c:
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_BUF_strdup_006a6fdc)(param_3 + 5);
    *param_5 = iVar1;
  }
  else {
    iVar1 = (*(code *)PTR_strncmp_006a9970)(param_3,&DAT_0063fa00,4);
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_getenv_006a9a60)(param_3 + 4);
      if (iVar1 == 0) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (param_1,"Can\'t read environment variable %s\n",param_3 + 4);
        *param_5 = 0;
        return false;
      }
      iVar1 = (*(code *)PTR_BUF_strdup_006a6fdc)(iVar1);
      *param_5 = iVar1;
    }
    else {
      iVar1 = app_get_pass_part_0(param_1,param_3,uVar2);
      *param_5 = iVar1;
    }
  }
  return iVar1 != 0;
}

