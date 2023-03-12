
int PKCS8_add_keyusage(PKCS8_PRIV_KEY_INFO *p8,int usage)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined local_d;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_d = (undefined)usage;
  uVar4 = 3;
  uVar3 = 0x53;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_X509at_add1_attr_by_NID_006a8c6c)(&p8->attributes,0x53,3,&local_d,1);
  if (local_c == *(int *)puVar1) {
    return (uint)(iVar2 != 0);
  }
  iVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = (*(code *)PTR_X509at_add1_attr_by_NID_006a8c6c)(iVar2 + 8,0x9c,0x1001,uVar3,uVar4);
  return (uint)(iVar2 != 0);
}

