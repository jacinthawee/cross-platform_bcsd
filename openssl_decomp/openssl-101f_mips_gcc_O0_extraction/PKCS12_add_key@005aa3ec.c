
PKCS12_SAFEBAG *
PKCS12_add_key(stack_st_PKCS12_SAFEBAG **pbags,EVP_PKEY *key,int key_usage,int iter,int key_nid,
              char *pass)

{
  PKCS8_PRIV_KEY_INFO *p8;
  PKCS12_SAFEBAG *a;
  int iVar1;
  stack_st_PKCS12_SAFEBAG *psVar2;
  
  p8 = (PKCS8_PRIV_KEY_INFO *)(*(code *)PTR_EVP_PKEY2PKCS8_006a9fb8)(key);
  if ((p8 != (PKCS8_PRIV_KEY_INFO *)0x0) &&
     ((key_usage == 0 || (iVar1 = PKCS8_add_keyusage(p8,key_usage), iVar1 != 0)))) {
    if (key_nid == -1) {
      a = PKCS12_MAKE_KEYBAG(p8);
    }
    else {
      a = PKCS12_MAKE_SHKEYBAG(key_nid,pass,-1,(uchar *)0x0,0,iter,p8);
      (*(code *)PTR_PKCS8_PRIV_KEY_INFO_free_006a8340)(p8);
    }
    if (a != (PKCS12_SAFEBAG *)0x0) {
      if (pbags == (stack_st_PKCS12_SAFEBAG **)0x0) {
        return a;
      }
      if (*pbags == (stack_st_PKCS12_SAFEBAG *)0x0) {
        psVar2 = (stack_st_PKCS12_SAFEBAG *)(*(code *)PTR_sk_new_null_006a80a4)();
        *pbags = psVar2;
        if (psVar2 != (stack_st_PKCS12_SAFEBAG *)0x0) {
          iVar1 = (*(code *)PTR_sk_push_006a80a8)(psVar2,a);
          if (iVar1 != 0) {
            return a;
          }
          (*(code *)PTR_sk_free_006a7f80)(*pbags);
          *pbags = (stack_st_PKCS12_SAFEBAG *)0x0;
        }
      }
      else {
        iVar1 = (*(code *)PTR_sk_push_006a80a8)(*pbags,a);
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

