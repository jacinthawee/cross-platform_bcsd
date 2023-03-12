
void look_str_cb(_STACK *param_1,_STACK *param_2,undefined4 param_3,void **param_4)

{
  undefined *puVar1;
  void *pvVar2;
  int iVar3;
  void *pvVar4;
  void *pvVar5;
  int iVar6;
  _STACK *p_Var7;
  void *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar6 = 0;
  p_Var7 = param_1;
  if (param_4[1] == (void *)0x0) {
    while( true ) {
      p_Var7 = param_2;
      iVar3 = sk_num(param_2);
      if (iVar3 <= iVar6) break;
      pvVar4 = sk_value(param_2,iVar6);
      (**(code **)((int)pvVar4 + 0x30))(pvVar4,&local_30,0,param_1);
      pvVar2 = local_30;
      p_Var7 = *(_STACK **)((int)local_30 + 0xc);
      pvVar5 = (void *)(*(code *)PTR_strlen_006a9a24)(p_Var7);
      if (pvVar5 == param_4[3]) {
        iVar3 = (*(code *)PTR_strncasecmp_006a99d4)(p_Var7,param_4[2],pvVar5);
        if (iVar3 == 0) {
          *param_4 = pvVar4;
          param_4[1] = pvVar2;
          break;
        }
      }
      iVar6 = iVar6 + 1;
    }
  }
  if (local_2c == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x0051cacc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_engine_table_unregister_006a885c)(&pkey_asn1_meth_table,p_Var7);
  return;
}

