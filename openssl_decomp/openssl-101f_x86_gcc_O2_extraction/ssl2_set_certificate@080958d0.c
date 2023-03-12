
uint ssl2_set_certificate(int param_1,undefined4 param_2,long param_3)

{
  X509 *x;
  _STACK *st;
  int iVar1;
  uint uVar2;
  EVP_PKEY *pkey;
  int iVar3;
  
  x = d2i_X509((X509 **)0x0,(uchar **)&stack0x00000010,param_3);
  if (x == (X509 *)0x0) {
    uVar2 = 0;
    pkey = (EVP_PKEY *)0x0;
    st = (_STACK *)0x0;
    ERR_put_error(0x14,0x7e,0xb,"s2_clnt.c",0x40f);
    goto LAB_08095933;
  }
  st = sk_new_null();
  if (st == (_STACK *)0x0) {
LAB_08095914:
    iVar3 = 0x415;
    iVar1 = 0x41;
  }
  else {
    iVar1 = sk_push(st,x);
    if (iVar1 == 0) goto LAB_08095914;
    iVar1 = ssl_verify_cert_chain(param_1,st);
    if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
      ERR_clear_error();
      *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xa0) = *(undefined4 *)(param_1 + 0xec);
      iVar1 = ssl_sess_cert_new();
      if (iVar1 == 0) {
        uVar2 = 0xffffffff;
        pkey = (EVP_PKEY *)0x0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0xc0);
        if (*(int *)(iVar3 + 0x98) != 0) {
          ssl_sess_cert_free(*(int *)(iVar3 + 0x98));
          iVar3 = *(int *)(param_1 + 0xc0);
        }
        *(int *)(iVar3 + 0x98) = iVar1;
        *(X509 **)(iVar1 + 0xc) = x;
        *(int *)(iVar1 + 8) = iVar1 + 0xc;
        pkey = X509_get_pubkey(x);
        if (pkey == (EVP_PKEY *)0x0) {
          iVar3 = 0x434;
          iVar1 = 0xed;
        }
        else {
          if (pkey->type == 6) {
            iVar1 = ssl_set_peer_cert_type(iVar1,1);
            x = (X509 *)0x0;
            uVar2 = (uint)(iVar1 != 0);
            goto LAB_08095933;
          }
          iVar3 = 0x439;
          iVar1 = 0xd2;
        }
        uVar2 = 0;
        x = (X509 *)0x0;
        ERR_put_error(0x14,0x7e,iVar1,"s2_clnt.c",iVar3);
      }
      goto LAB_08095933;
    }
    iVar3 = 0x41d;
    iVar1 = 0x86;
  }
  uVar2 = 0;
  pkey = (EVP_PKEY *)0x0;
  ERR_put_error(0x14,0x7e,iVar1,"s2_clnt.c",iVar3);
LAB_08095933:
  sk_free(st);
  X509_free(x);
  EVP_PKEY_free(pkey);
  return uVar2;
}

