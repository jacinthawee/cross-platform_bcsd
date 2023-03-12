
PKCS12_SAFEBAG *
PKCS12_add_key(stack_st_PKCS12_SAFEBAG **pbags,EVP_PKEY *key,int key_usage,int iter,int key_nid,
              char *pass)

{
  PKCS8_PRIV_KEY_INFO *p8;
  PKCS12_SAFEBAG *a;
  int iVar1;
  _STACK *st;
  
  p8 = EVP_PKEY2PKCS8(key);
  if ((p8 != (PKCS8_PRIV_KEY_INFO *)0x0) &&
     ((key_usage == 0 || (iVar1 = PKCS8_add_keyusage(p8,key_usage), iVar1 != 0)))) {
    if (key_nid == -1) {
      a = PKCS12_MAKE_KEYBAG(p8);
    }
    else {
      a = PKCS12_MAKE_SHKEYBAG(key_nid,pass,-1,(uchar *)0x0,0,iter,p8);
      PKCS8_PRIV_KEY_INFO_free(p8);
    }
    if (a != (PKCS12_SAFEBAG *)0x0) {
      if (pbags == (stack_st_PKCS12_SAFEBAG **)0x0) {
        return a;
      }
      if ((_STACK *)*pbags == (_STACK *)0x0) {
        st = sk_new_null();
        *pbags = (stack_st_PKCS12_SAFEBAG *)st;
        if (st != (_STACK *)0x0) {
          iVar1 = sk_push(st,a);
          if (iVar1 != 0) {
            return a;
          }
          sk_free((_STACK *)*pbags);
          *pbags = (stack_st_PKCS12_SAFEBAG *)0x0;
        }
      }
      else {
        iVar1 = sk_push((_STACK *)*pbags,a);
        if (iVar1 != 0) {
          return a;
        }
      }
      PKCS12_SAFEBAG_free(a);
      return (PKCS12_SAFEBAG *)0x0;
    }
  }
  return (PKCS12_SAFEBAG *)0x0;
}

