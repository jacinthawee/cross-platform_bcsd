
void * ASN1_item_unpack(ASN1_STRING *oct,ASN1_ITEM *it)

{
  undefined *puVar1;
  void *pvVar2;
  uchar *local_10;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_10 = oct->data;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pvVar2 = (void *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0,&local_10,oct->length,it);
  if (pvVar2 == (void *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,199,0x6e,"asn_pack.c",0xcd);
  }
  if (local_c == *(int *)puVar1) {
    return pvVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  pvVar2 = (void *)(*(code *)PTR_OBJ_cleanup_006a6e98)();
  return pvVar2;
}

