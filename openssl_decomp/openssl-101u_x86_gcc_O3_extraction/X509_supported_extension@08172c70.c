
int X509_supported_extension(X509_EXTENSION *ex)

{
  ASN1_OBJECT *o;
  uint uVar1;
  void *pvVar2;
  int in_GS_OFFSET;
  uint local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  o = X509_EXTENSION_get_object(ex);
  uVar1 = OBJ_obj2nid(o);
  local_14 = uVar1;
  if (uVar1 != 0) {
    pvVar2 = OBJ_bsearch_(&local_14,supported_nids_13619,0xb,4,nid_cmp_BSEARCH_CMP_FN);
    uVar1 = (uint)(pvVar2 != (void *)0x0);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

