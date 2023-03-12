
int X509_supported_extension(X509_EXTENSION *ex)

{
  ASN1_OBJECT *o;
  void *local_c [3];
  
  o = X509_EXTENSION_get_object(ex);
  local_c[0] = (void *)OBJ_obj2nid(o);
  if (local_c[0] != (void *)0x0) {
    local_c[0] = OBJ_bsearch_(local_c,&supported_nids_16260,0xb,4,nid_cmp_BSEARCH_CMP_FN + 1);
    if (local_c[0] != (void *)0x0) {
      local_c[0] = (void *)0x1;
    }
  }
  return (int)local_c[0];
}

