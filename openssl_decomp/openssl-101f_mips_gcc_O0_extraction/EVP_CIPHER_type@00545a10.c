
int EVP_CIPHER_type(EVP_CIPHER *ctx)

{
  ASN1_OBJECT *a;
  int iVar1;
  
  iVar1 = ctx->nid;
  if (iVar1 == 0x1ad) {
    return 0x1ad;
  }
  if (iVar1 < 0x1ae) {
    if (iVar1 == 0x61) {
      return 5;
    }
    if (iVar1 < 0x62) {
      if (iVar1 == 0x1e) {
        return 0x1e;
      }
      if (iVar1 < 0x1f) {
        if (iVar1 == 5) {
          return 5;
        }
      }
      else {
        if (iVar1 == 0x25) {
          return 0x25;
        }
        if (iVar1 == 0x3d) {
          return 0x1e;
        }
      }
    }
    else {
      if (iVar1 == 0xa6) {
        return 0x25;
      }
      if (iVar1 < 0xa7) {
        if (iVar1 == 0x62) {
          return 0x25;
        }
      }
      else {
        if (iVar1 == 0x1a5) {
          return 0x1a5;
        }
        if (iVar1 == 0x1a9) {
          return 0x1a9;
        }
      }
    }
  }
  else {
    if (iVar1 == 0x28e) {
      return 0x1a9;
    }
    if (iVar1 < 0x28f) {
      if (iVar1 == 0x28b) {
        return 0x1a9;
      }
      if (iVar1 < 0x28c) {
        if (iVar1 == 0x28a) {
          return 0x1a5;
        }
      }
      else {
        if (iVar1 == 0x28c) {
          return 0x1ad;
        }
        if (iVar1 == 0x28d) {
          return 0x1a5;
        }
      }
    }
    else {
      if (iVar1 < 0x292) {
        if (iVar1 < 0x290) {
          return 0x1ad;
        }
        return 0x1e;
      }
      if (iVar1 < 0x294) {
        return 0x1e;
      }
    }
  }
  a = (ASN1_OBJECT *)(*(code *)PTR_OBJ_nid2obj_006a8240)(iVar1);
  if (a == (ASN1_OBJECT *)0x0) {
    iVar1 = 0;
  }
  else if (a->data == (uchar *)0x0) {
    iVar1 = 0;
  }
  ASN1_OBJECT_free(a);
  return iVar1;
}

