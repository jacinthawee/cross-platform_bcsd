
PKCS12_SAFEBAG * PKCS12_add_cert(stack_st_PKCS12_SAFEBAG **pbags,X509 *cert)

{
  PKCS12_SAFEBAG *bag;
  uchar *puVar1;
  int iVar2;
  _STACK *st;
  int local_18;
  int local_14;
  
  local_18 = -1;
  local_14 = -1;
  bag = PKCS12_x5092certbag(cert);
  if (bag == (PKCS12_SAFEBAG *)0x0) {
    return (PKCS12_SAFEBAG *)0x0;
  }
  puVar1 = X509_alias_get0(cert,&local_18);
  if (((puVar1 == (uchar *)0x0) ||
      (iVar2 = PKCS12_add_friendlyname_asc(bag,(char *)puVar1,local_18), iVar2 != 0)) &&
     ((puVar1 = X509_keyid_get0(cert,&local_14), puVar1 == (uchar *)0x0 ||
      (iVar2 = PKCS12_add_localkeyid(bag,puVar1,local_14), iVar2 != 0)))) {
    if (pbags == (stack_st_PKCS12_SAFEBAG **)0x0) {
      return bag;
    }
    if ((_STACK *)*pbags == (_STACK *)0x0) {
      st = sk_new_null();
      *pbags = (stack_st_PKCS12_SAFEBAG *)st;
      if (st != (_STACK *)0x0) {
        iVar2 = sk_push(st,bag);
        if (iVar2 != 0) {
          return bag;
        }
        sk_free((_STACK *)*pbags);
        *pbags = (stack_st_PKCS12_SAFEBAG *)0x0;
      }
    }
    else {
      iVar2 = sk_push((_STACK *)*pbags,bag);
      if (iVar2 != 0) {
        return bag;
      }
    }
  }
  PKCS12_SAFEBAG_free(bag);
  return (PKCS12_SAFEBAG *)0x0;
}

