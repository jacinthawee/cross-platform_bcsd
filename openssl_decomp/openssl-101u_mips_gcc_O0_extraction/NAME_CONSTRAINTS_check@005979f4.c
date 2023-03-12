
int NAME_CONSTRAINTS_check(X509 *x,NAME_CONSTRAINTS *nc)

{
  undefined *puVar1;
  X509_NAME *name;
  int iVar2;
  uint uVar3;
  X509_NAME_ENTRY *ne;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_34;
  X509_NAME *local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  name = (X509_NAME *)(*(code *)PTR_X509_get_subject_name_006a6f00)();
  iVar2 = X509_NAME_entry_count(name);
  if (iVar2 < 1) {
LAB_00597b04:
    iVar2 = 0;
    while( true ) {
      iVar5 = (*(code *)PTR_sk_num_006a6e2c)(x->altname);
      uVar3 = (uint)(iVar2 < iVar5);
      if (uVar3 == 0) break;
      uVar4 = (*(code *)PTR_sk_value_006a6e24)(x->altname,iVar2);
      uVar3 = nc_match(uVar4,nc);
      if (uVar3 != 0) break;
      iVar2 = iVar2 + 1;
    }
  }
  else {
    local_34 = 4;
    local_30 = name;
    uVar3 = nc_match(&local_34,nc);
    if (uVar3 == 0) {
      iVar2 = -1;
      local_34 = 1;
      do {
        iVar2 = X509_NAME_get_index_by_NID(name,0x30,iVar2);
        if (iVar2 == -1) goto LAB_00597b04;
        ne = X509_NAME_get_entry(name,iVar2);
        local_30 = (X509_NAME *)X509_NAME_ENTRY_get_data(ne);
        if (local_30->modified != 0x16) {
          uVar3 = 0x35;
          break;
        }
        uVar3 = nc_match(&local_34,nc);
      } while (uVar3 == 0);
    }
  }
  if (local_2c == *(int *)puVar1) {
    return uVar3;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x00597bb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_ASN1_item_d2i_006a8674)();
  return iVar2;
}

