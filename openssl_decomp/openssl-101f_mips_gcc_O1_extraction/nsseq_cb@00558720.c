
undefined4 nsseq_cb(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 1) {
    return 1;
  }
  param_2 = (undefined4 *)*param_2;
  uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x4f);
  *param_2 = uVar1;
  return 1;
}

