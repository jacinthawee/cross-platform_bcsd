
undefined1 * nbiof_write(BIO *param_1,void *param_2,uint param_3)

{
  undefined *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  void *pvVar4;
  byte local_1d;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (((param_2 == (void *)0x0) || ((int)param_3 < 1)) || (param_1->next_bio == (bio_st *)0x0)) {
    puVar3 = (undefined1 *)0x0;
  }
  else {
    pvVar4 = param_1->ptr;
    BIO_clear_flags(param_1,0xf);
    uVar2 = *(uint *)((int)pvVar4 + 4);
    if ((int)uVar2 < 1) {
      RAND_pseudo_bytes(&local_1d,1);
      if (((int)(local_1d & 7) < (int)param_3) && (param_3 = local_1d & 7, (local_1d & 7) == 0)) {
        BIO_set_flags(param_1,10);
        puVar3 = (undefined1 *)0xffffffff;
        goto LAB_0052cc40;
      }
    }
    else {
      *(undefined4 *)((int)pvVar4 + 4) = 0;
      if ((int)uVar2 < (int)param_3) {
        param_3 = uVar2;
      }
    }
    puVar3 = (undefined1 *)BIO_write(param_1->next_bio,param_2,param_3);
    if ((int)puVar3 < 0) {
      BIO_copy_next_retry(param_1);
      *(uint *)((int)pvVar4 + 4) = param_3;
    }
  }
LAB_0052cc40:
  if (local_1c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    return methods_nbiof;
  }
  return puVar3;
}

