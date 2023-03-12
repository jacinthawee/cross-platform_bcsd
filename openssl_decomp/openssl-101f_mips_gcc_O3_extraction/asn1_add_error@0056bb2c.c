
void asn1_add_error(uchar *address,int offset)

{
  undefined *puVar1;
  undefined auStack_34 [16];
  undefined auStack_24 [16];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_34,0xd,&DAT_0066b2cc,address);
  (*(code *)PTR_BIO_snprintf_006a8060)(auStack_24,0xd,"%d",offset);
  (*(code *)PTR_ERR_add_error_data_006a9264)(4,"address=",auStack_34," offset=",auStack_24);
  if (local_14 == *(int *)puVar1) {
    return;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return;
}

