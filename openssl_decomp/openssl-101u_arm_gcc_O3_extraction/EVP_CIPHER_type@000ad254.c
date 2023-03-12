
int EVP_CIPHER_type(EVP_CIPHER *ctx)

{
  ASN1_OBJECT *a;
  ASN1_OBJECT *n;
  ASN1_OBJECT *pAVar1;
  
  n = (ASN1_OBJECT *)ctx->nid;
  if (n == (ASN1_OBJECT *)0x1ad) {
    return 0x1ad;
  }
  if ((int)n < 0x1ae) {
    if (n == (ASN1_OBJECT *)0x61) {
      return 5;
    }
    if ((int)n < 0x62) {
      if (n == (ASN1_OBJECT *)0x1e) {
        return 0x1e;
      }
      if ((int)n < 0x1f) {
        if (n == (ASN1_OBJECT *)0x5) {
          return 5;
        }
      }
      else {
        if (n == (ASN1_OBJECT *)0x25) {
          return 0x25;
        }
        if (n == (ASN1_OBJECT *)0x3d) {
          return 0x1e;
        }
      }
    }
    else {
      if (n == (ASN1_OBJECT *)0xa6) {
        return 0x25;
      }
      if ((int)n < 0xa7) {
        if (n == (ASN1_OBJECT *)0x62) {
          return 0x25;
        }
      }
      else {
        if (n == (ASN1_OBJECT *)0x1a5) {
          return 0x1a5;
        }
        if (n == (ASN1_OBJECT *)0x1a9) {
          return 0x1a9;
        }
      }
    }
  }
  else {
    if (n == (ASN1_OBJECT *)0x28e) {
      return 0x1a9;
    }
    if ((int)n < 0x28f) {
      if (n == (ASN1_OBJECT *)0x28b) {
        return 0x1a9;
      }
      if ((int)n < 0x28c) {
        if (n == (ASN1_OBJECT *)0x28a) {
          return 0x1a5;
        }
      }
      else {
        if (n == (ASN1_OBJECT *)0x28c) {
          return 0x1ad;
        }
        if (n == (ASN1_OBJECT *)0x28d) {
          return 0x1a5;
        }
      }
    }
    else {
      if ((int)n < 0x292) {
        if ((int)n < 0x290) {
          return 0x1ad;
        }
        return 0x1e;
      }
      if ((int)n < 0x294) {
        return 0x1e;
      }
    }
  }
  a = OBJ_nid2obj((int)n);
  pAVar1 = a;
  if ((a != (ASN1_OBJECT *)0x0) && (pAVar1 = n, a->data == (uchar *)0x0)) {
    pAVar1 = (ASN1_OBJECT *)0x0;
  }
  ASN1_OBJECT_free(a);
  return (int)pAVar1;
}

