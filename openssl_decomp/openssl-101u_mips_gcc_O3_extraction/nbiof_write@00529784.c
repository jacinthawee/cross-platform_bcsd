
undefined1 * nbiof_write(BIO *param_1,void *param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  int iVar4;
  void *pvVar5;
  byte local_1d;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (((param_2 == (void *)0x0) || ((int)param_3 < 1)) || (param_1->next_bio == (bio_st *)0x0)) {
    puVar3 = (undefined1 *)0x0;
    goto LAB_0052981c;
  }
  pvVar5 = param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  uVar2 = *(uint *)((int)pvVar5 + 4);
  if ((int)uVar2 < 1) {
    iVar4 = RAND_bytes(&local_1d,1);
    if (iVar4 < 1) {
      puVar3 = (undefined1 *)0xffffffff;
      goto LAB_0052981c;
    }
    if (((int)(local_1d & 7) < (int)param_3) && (param_3 = local_1d & 7, (local_1d & 7) == 0)) {
      BIO_set_flags(param_1,10);
      puVar3 = (undefined1 *)0xffffffff;
      goto LAB_0052981c;
    }
  }
  else {
    *(undefined4 *)((int)pvVar5 + 4) = 0;
    if ((int)uVar2 < (int)param_3) {
      param_3 = uVar2;
    }
  }
  puVar3 = (undefined1 *)BIO_write(param_1->next_bio,param_2,param_3);
  if ((int)puVar3 < 0) {
    BIO_copy_next_retry(param_1);
    *(uint *)((int)pvVar5 + 4) = param_3;
  }
LAB_0052981c:
  if (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    return methods_nbiof;
  }
  return puVar3;
}

