
void * ASN1_item_unpack(ASN1_STRING *oct,ASN1_ITEM *it)

{
  undefined *puVar1;
  void *pvVar2;
  uchar *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_10 = oct->data;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  pvVar2 = (void *)(*(code *)PTR_ASN1_item_d2i_006a9798)(0,&local_10,oct->length,it);
  if (pvVar2 == (void *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,199,0x6e,"asn_pack.c",0xbd);
  }
  if (local_c == *(int *)puVar1) {
    return pvVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  pvVar2 = (void *)(*(code *)PTR_OBJ_cleanup_006a7f98)();
  return pvVar2;
}

