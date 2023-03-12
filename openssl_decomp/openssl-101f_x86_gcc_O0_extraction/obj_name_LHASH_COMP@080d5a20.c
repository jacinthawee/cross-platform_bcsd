
void obj_name_LHASH_COMP(int *param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  
  if (*param_1 != *param_2) {
    return;
  }
  if (name_funcs_stack != (_STACK *)0x0) {
    iVar1 = sk_num(name_funcs_stack);
    if (*param_1 < iVar1) {
      pvVar2 = sk_value(name_funcs_stack,*param_1);
                    /* WARNING: Could not recover jumptable at 0x080d5aa5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)((int)pvVar2 + 4))();
      return;
    }
  }
  strcmp((char *)param_1[2],(char *)param_2[2]);
  return;
}

