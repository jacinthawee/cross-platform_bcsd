
long CONF_get_number(lhash_st_CONF_VALUE *conf,char *group,char *name)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int *piVar4;
  lhash_st_CONF_VALUE *unaff_s2;
  char *unaff_s3;
  char *unaff_s4;
  long local_2c;
  CONF CStack_28;
  int *local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = 0;
  local_1c = *(int **)PTR___stack_chk_guard_006aabf0;
  if (conf == (lhash_st_CONF_VALUE *)0x0) {
    pcVar3 = _CONF_get_string((CONF *)0x0,group,name);
    if (pcVar3 != (char *)0x0) {
      trap(0);
      goto LAB_0059e0d4;
    }
    unaff_s3 = &DAT_0000006d;
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6d,0x6a,"conf_lib.c",0x14b);
  }
  else {
    unaff_s2 = conf;
    unaff_s3 = group;
    unaff_s4 = name;
    if (default_CONF_method == (CONF_METHOD *)0x0) {
LAB_0059e0d4:
      local_2c = 0;
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&CStack_28);
    CStack_28.data = unaff_s2;
    iVar2 = NCONF_get_number_e(&CStack_28,unaff_s3,unaff_s4,&local_2c);
    if (iVar2 != 0) goto LAB_0059e048;
  }
  (*(code *)PTR_ERR_clear_error_006a7fe0)();
LAB_0059e048:
  if (local_1c == *(int **)puVar1) {
    return local_2c;
  }
  piVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = (*(code *)PTR_BIO_new_fp_006a835c)(unaff_s3,0);
  if (iVar2 == 0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6a,7,"conf_lib.c",0x173);
    return 0;
  }
  if (piVar4 == (int *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x69,0x69,"conf_lib.c",0x180);
  }
  else {
    piVar4 = (int *)(**(code **)(*piVar4 + 0x18))(piVar4,iVar2);
  }
  (*(code *)PTR_BIO_free_006a7f70)(iVar2);
  return (long)piVar4;
}

