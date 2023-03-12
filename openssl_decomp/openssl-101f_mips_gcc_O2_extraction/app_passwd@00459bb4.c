
bool app_passwd(undefined4 param_1,int param_2,int param_3,int *param_4,int *param_5)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  
  if (param_3 == 0) {
    bVar3 = false;
    if (param_2 != 0) goto LAB_00459c1c;
    if (param_4 == (int *)0x0) goto LAB_00459dd0;
LAB_00459d24:
    *param_4 = 0;
    if (param_3 == 0) goto LAB_00459dd0;
  }
  else if (param_2 == 0) {
    if (param_4 != (int *)0x0) goto LAB_00459d24;
  }
  else {
    iVar1 = (*(code *)PTR_strcmp_006aac20)(param_2,param_3);
    bVar3 = iVar1 == 0;
LAB_00459c1c:
    iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_2,"pass:",5);
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(param_2 + 5);
    }
    else {
      iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_2,&DAT_0063ff8c,4);
      if (iVar1 == 0) {
        iVar1 = (*(code *)PTR_getenv_006aab6c)(param_2 + 4);
        if (iVar1 == 0) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (param_1,"Can\'t read environment variable %s\n",param_2 + 4);
          *param_4 = 0;
          return false;
        }
        iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(iVar1);
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
LAB_00459dd0:
      if (param_5 != (int *)0x0) {
        *param_5 = 0;
        return true;
      }
      return true;
    }
    if (bVar3 != false) {
      iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_3,"pass:",5);
      uVar2 = 2;
      goto joined_r0x00459d48;
    }
  }
  iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_3,"pass:",5);
  uVar2 = 0;
joined_r0x00459d48:
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(param_3 + 5);
    *param_5 = iVar1;
  }
  else {
    iVar1 = (*(code *)PTR_strncmp_006aaa7c)(param_3,&DAT_0063ff8c,4);
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_getenv_006aab6c)(param_3 + 4);
      if (iVar1 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)
                  (param_1,"Can\'t read environment variable %s\n",param_3 + 4);
        *param_5 = 0;
        return false;
      }
      iVar1 = (*(code *)PTR_BUF_strdup_006a80dc)(iVar1);
      *param_5 = iVar1;
    }
    else {
      iVar1 = app_get_pass_part_0(param_1,param_3,uVar2);
      *param_5 = iVar1;
    }
  }
  return iVar1 != 0;
}

